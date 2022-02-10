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
	if (*front == NULL) {	// 맨앞에 데이터가 없다? ==> 큐가 비었다는 의미
		*front = getNode();
		*rear = *front;
		
		(*front)->data = num;
	}

	else {
		Queue* tmp = *rear;		// rear값을 백업

		*rear = getNode();
		tmp->link = *rear;		// 이전 rear 위치(= 앞 데이터)에 현재 rear(= 새로 생긴 데이터)의 주소 저장

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
	Queue* front = NULL;	// 큐의 가장 앞을 가리키는 포인터
	Queue* rear = NULL;	// 큐의 가장 뒤를 가리키는 포인터

	enqueue(&front, &rear, 10);
	enqueue(&front, &rear, 20);
	enqueue(&front, &rear, 30);

	printf("%d -> %d -> %d\n", front->data, front->link->data, front->link->link->data);

	printf("꺼낸 값 : %d\n", dequeue(&front));
	printf("꺼낸 값 : %d\n", dequeue(&front));
	printf("꺼낸 값 : %d\n", dequeue(&front));
	printf("꺼낸 값 : %d\n", dequeue(&front));	// 없는 데이터를 꺼낼때 에러를 방지하라
}