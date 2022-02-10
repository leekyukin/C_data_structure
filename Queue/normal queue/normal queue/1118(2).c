#include <stdio.h>
#include <stdlib.h>
typedef int ELEMENT;

typedef struct queue {
	ELEMENT* buf;
	int front;
	int rear;
	int size;
}Queue;

Queue* createQueue(int n) {
	Queue* temp = (Queue*)malloc(sizeof(Queue));
	temp->size = n;
	temp->front = -1;
	temp->rear = -1;
	temp->buf = (ELEMENT*)malloc(sizeof(ELEMENT) * n);
}

int isFull(Queue* q) {
	return q->rear == q->size - 1;
}

void enQueue(Queue* q, ELEMENT data) {
	if (isFull(q)) {
		printf("Queue is full!\n");
		return;
	}
	q->buf[++(q->rear)] = data;
}
int isEmpty(Queue* q) {
	return q->rear == -1;
}

ELEMENT deQueue(Queue* q) {
	if (isEmpty(q)) {
		printf("Queue is empty!");
		return 0;
	}
	return q->buf[++q->front];
}
void printAll(Queue* q) {
	for (int i = q->front; i < q->rear; i++) {
		printf("%d ", q->buf[i]);
	}
}
void destroyQueue(Queue* q) {
	free(q->buf);
	free(q);
}
int main(void) {
	Queue* q;
	ELEMENT data;

	q = createQueue(5);
	enQueue(q, 10);
	enQueue(q, 20);
	enQueue(q, 30);
	enQueue(q, 40);
	enQueue(q, 50);
	data = deQueue(q);
	if (data) printf("%d\n", data);
	enQueue(q, 60);
	printAll(q);
	destroyQueue(q);
	return 0;
}