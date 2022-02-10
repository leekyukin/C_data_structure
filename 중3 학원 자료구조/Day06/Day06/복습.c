#include<stdio.h>
#include<stdlib.h>
typedef struct queue {
	int data;
	struct queue* link;
}Queue;

Queue* getNode() {
	Queue* tmp = (Queue*)malloc(sizeof(Queue));
	tmp->link = NULL;
	return tmp;
}

void enqueue(Queue** front, Queue** rear, int num) {
	if (*front == NULL) {
		*front = getNode();
		*front = *rear;
		(*front)->data = num;
	}
	else {
		Queue* tmp = *rear;
		*rear = getNode();
		(*rear)->data = num;
		tmp->link = *rear;
	}
}

void printQueue(Queue* front) {
	while (front != NULL) {
		printf("%d", front->data);
		front = front->link;
	}
	printf("\n");
}

void dequeue(Queue** front) {
	if (*front == NULL) {
		printf("Queue is Empty!!\n");
		return;
	}

	Queue* tmp = *front;
	*front = (*front)->link;

	free(tmp);
}

void claer(Queue** front) {
	while (*front != NULL) {
		dequeue(front);
	}
}

int main() {
	Queue* front = NULL;
	Queue* rear = NULL;   
	for (int i = 10; i <= 100; i += 10){
		enqueue(&front, &rear, i);
	}
	

	dequeue(&front);
	dequeue(&front);
	dequeue(&front);
}