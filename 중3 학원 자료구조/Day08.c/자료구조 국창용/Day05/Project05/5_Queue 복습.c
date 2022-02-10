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
	if (*front == NULL) {
		*front = getNode();
		*rear = *front;
		
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
		printf("%d -> ", front->data);
		front = front->link;
	}

	printf("\b\b\b  \n");
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

void clear(Queue** front) {
	while (*front != NULL) {
		dequeue(front);
	}
}

int main() {
	Queue* front, * rear;

	front = rear = NULL;

	for (int i = 10; i <= 100; i += 10) {
		enqueue(&front, &rear, i);
	}

	printQueue(front);	// 10 20 30 40 .... 100

	dequeue(&front);

	printQueue(front);	// 20 30 40 .... 100

	clear(&front);
	dequeue(&front);	// Queue is Empty!!
}