#include<stdio.h>
#define MAX 4

typedef struct queue {
	int data[MAX];
	int front, rear;
}Queue;

void init(Queue* queue) {
	queue->front = queue->rear = 0;
}

int index(int i) {
	if (i == MAX - 1)	return 0;
	else			return i + 1;
}

void enqueue(Queue* queue, int num) {

	if (index(queue->rear) == queue->front) {
		printf("Queue OverFlow\n");
		return;
	}

	queue->rear = index(queue->rear);
	queue->data[queue->rear] = num;
}

void dequeue(Queue* queue) {
	if (index(queue->front) == queue->rear) {
		printf("Queue UnderFlow\n");
		return;
	}

	queue->front = index(queue->front);
}

int main() {
	Queue queue;

	init(&queue);
	
	enqueue(&queue, 10);
	enqueue(&queue, 20);
	enqueue(&queue, 30);

	dequeue(&queue);
	enqueue(&queue, 50);

	dequeue(&queue);
	enqueue(&queue, 60);
}