#include<stdio.h>
#include<stdlib.h>

typedef struct queue {
	int data;
	struct queue* link;
}Queue;

Queue* getNode() {
	Queue* newnode = (Queue*)malloc(sizeof(Queue));
	newnode->link = NULL;

	return newnode;
}

void enqueue(Queue** front, Queue** rear, int num) {
	if (*front == NULL) {	// �Ǿտ� �����Ͱ� ����? ==> ť�� ����ٴ� �ǹ�
		*front = getNode();
		*rear = *front;
		
		(*front)->data = num;
	}

	else {
		Queue* tmp = *rear;		// rear���� ���

		*rear = getNode();
		tmp->link = *rear;		// ���� rear ��ġ(= �� ������)�� ���� rear(= ���� ���� ������)�� �ּ� ����

		(*rear)->data = num;
	}

}

int dequeue(Queue** front) {
	if (*front == NULL) {
		printf("Queue is Empty!!!\n");
		return;
	}

	Queue* tmp = *front;
	int num = (*front)->data;

	*front = (*front)->link;
	free(tmp);

	return num;
}

int main() {
	Queue* front = NULL;	// ť�� ���� ���� ����Ű�� ������
	Queue* rear = NULL;	// ť�� ���� �ڸ� ����Ű�� ������

	enqueue(&front, &rear, 10);
	enqueue(&front, &rear, 20);
	enqueue(&front, &rear, 30);

	printf("%d -> %d -> %d\n", front->data, front->link->data, front->link->link->data);

	printf("���� �� : %d\n", dequeue(&front));
	printf("���� �� : %d\n", dequeue(&front));
	printf("���� �� : %d\n", dequeue(&front));
	printf("���� �� : %d\n", dequeue(&front));	// ���� �����͸� ������ ������ �����϶�
}