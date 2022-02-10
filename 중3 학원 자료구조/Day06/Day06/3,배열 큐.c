#include<stdio.h>
#include<stdlib.h>
#define MAX 4


typedef struct queue {
	int data[MAX];
	int front, rear;
}Queue;
void init(Queue* queue) {
	queue->front = queue->rear = -1;
}

int index(int i) {
	if (i == MAX)  return 0;
	else                 return i + 1;
}

void enqueue(Queue* queue, int num) {
	
	queue->rear = index(queue->rear);
	queue->data[queue->rear] = num;
	}

void printQueue(Queue queue) {
	if (queue->rear==queue->front)



	for (int i = queue.front; i <= queue.rear; i++) {
		printf("%d -> ", queue.data[i]);
	}
	printf("\b\b\b  \n");
}
void dequeue(Queue* queue) {
	
	queue->front = index(queue->front);

}

int main() {
	Queue queue;

	init(&queue);

	enqueue(&queue, 10);
	enqueue(&queue, 20);
	enqueue(&queue, 30);


	dequeue(&queue);
}