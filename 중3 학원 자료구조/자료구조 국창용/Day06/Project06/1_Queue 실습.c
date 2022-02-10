#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct queue {
	char food[20];
	struct queue* link;
}Queue;

Queue* getNode() {
	Queue* newnode = (Queue*)malloc(sizeof(Queue));
	newnode->link = NULL;
	return newnode;
}

void enqueue(Queue** front, Queue** rear, char* food) {
	if (*front == NULL) {
		*front = getNode();
		*rear = *front;

		strcpy((*front)->food, food);
	}

	else {
		Queue* tmp = *rear;
		*rear = getNode();
		strcpy((*rear)->food, food);

		tmp->link = *rear;
	}
}

void printQueue(Queue* front) {
	while (front != NULL) {
		printf("%s -> ", front->food); 
		front = front->link;
	}

	printf("\b\b\b  \n");
}

void dequeue(Queue** front) {
	if (*front == NULL) {
		printf("�ֹ��� �ϳ��� �����ϴ�!!\n");
		return;
	}

	printf("%s �ֹ� �Ϸ�~\n", (*front)->food);

	Queue* tmp = *front;
	*front = (*front)->link;

	free(tmp);
}

void clear(Queue** front) {
	while (*front != NULL) {
		printf("%s �ֹ� ���!!!\n", (*front)->food);

		Queue* tmp = *front;
		*front = (*front)->link;

		free(tmp);
	}
}

int main() {
	int menu;
	Queue* front, * rear;
	front = rear = NULL;

	while (1) {
		printf("�ֹ� ��Ȳ : ");
		printQueue(front);
		printf("�� ========= �޴� ==========��\n");
		printf("��\t 1. ¥���\t   ��\n");
		printf("��\t 2. «��  \t   ��\n");
		printf("��\t 3. ������\t   ��\n");
		printf("��\t 4. ������\t   ��\n");
		printf("��\t 5. �ֹ��Ϸ�\t   ��\n");
		printf("�� =========================��\n");
		printf("�ֹ� >>> ");
		scanf_s("%d", &menu);

		switch (menu) {
		case 1:
			enqueue(&front, &rear, "¥���");
			break;
		case 2:
			enqueue(&front, &rear, "«��");
			break;
		case 3:
			enqueue(&front, &rear, "������");
			break;
		case 4:
			enqueue(&front, &rear, "������");
			break;
		case 5:
			dequeue(&front);
			break;
		case 0:	// ����
			clear(&front);
			return;
		default :
			printf("���� �޴��Դϴ�!!!\n");
		}

		system("pause");
		system("cls");
	}
}