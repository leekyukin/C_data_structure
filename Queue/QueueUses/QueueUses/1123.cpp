#include <stdio.h>
#include <stdlib.h>

typedef int ELEMENT;
typedef struct queue {
	ELEMENT* buf;
	int size;
	int rear;
	int front;
}QUEUE;

QUEUE* createQueue(int n);
int isEmpty(QUEUE* q);
int isFull(QUEUE* q);
void enQueue(QUEUE* q, ELEMENT data);
int deQueue(QUEUE* q);
void printAll(QUEUE* q);
void destroyQueue(QUEUE* q);

int main(void) {
	ELEMENT data;
	QUEUE* q = createQueue(5);

	enQueue(q, 10);
	printAll(q);

	enQueue(q, 20);
	printAll(q);

	data = deQueue(q);
	if (!data) printf("%d\n", data);
	printAll(q);

	enQueue(q, 10);
	printAll(q);

	destroyQueue(q);
	printAll(q);
}

QUEUE* createQueue(int n) {
	QUEUE* q = (QUEUE*)malloc(sizeof(QUEUE));
	
	q->front = 0;
	q->rear = 0;
	q->size = n;
	q->buf = (ELEMENT*)malloc(sizeof(ELEMENT) * q->size);
	return q;
}

int isEmpty(QUEUE* q) {
	return q->rear == q->front;
}
int isFull(QUEUE* q) {
	return (q->rear + 1) % q->size == q->front;
}
void enQueue(QUEUE* q, ELEMENT data) {
	if (isFull(q)) {
		printf("Queue is full!\n");
		return;
	}
	q->rear = (q->rear + 1) % q->size;
	q->buf[q->rear] = data;
}

int deQueue(QUEUE* q) {
	if (isEmpty(q)) {
		printf("Queue is empty!\n");
		return 0;
	}
	q->front = (q->front + 1) % q->size;
	return q->buf[q->front - 1];
}

void printAll(QUEUE* q) {
	int i = q->front+1;
	if (isEmpty(q)) return;
	while (1) {
		printf("%d ", q->buf[i]);
		if (i == q->rear) break;
		i = (i + 1) % q->size;
	}
	printf("\n");
}

void destroyQueue(QUEUE* q) {
	free(q->buf);
	free(q);
}