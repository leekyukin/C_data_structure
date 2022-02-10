#include <stdio.h>
#include <stdlib.h>

typedef int ELEMENT;
typedef struct queue {
	ELEMENT* buf;
	int front;
	int rear;
	int size;
}QUEUE;

QUEUE* createQueue(int n);
int isFull(QUEUE* q);
void enQueue(QUEUE* q, ELEMENT data);
int isEmpty(QUEUE* q);
ELEMENT deQueue(QUEUE* q);
void destroyQueue(QUEUE* q);
void printAll(QUEUE* q);

int main() {
	QUEUE* q;
	ELEMENT data;
	int menu = 1;
	q = createQueue(5);

	while (menu) {
		printf("1:enQueue, 2:deQueue, 3:printAll... ");
		scanf_s("%d", &menu);
		switch (menu) {
		case 1: scanf_s("%d", &data);
			enQueue(q, data);
			break;
		case 2: data = deQueue(q);
			if (data)printf("%d\n", data);
			break;
		case 3: printAll(q);
			break;
		default: break;
		}
	}
}

QUEUE* createQueue(int n) {
	QUEUE* temp = (QUEUE*)malloc(sizeof(QUEUE));
	temp->size = n;
	temp->front = 0;
	temp->rear = 0;
	temp->buf = (ELEMENT*)malloc(sizeof(ELEMENT) * temp->size);
	return temp;
}
int isFull(QUEUE* q) {
	return (q->rear + 1) % q->size == q->front;
}
int isEmpty(QUEUE* q) {
	return q->rear == q->front;
}
void enQueue(QUEUE* q, ELEMENT data) {
	if (isFull(q)) {
		printf("Queue is full!\n");
		return;
	}
	q->rear = (q->rear + 1) % q->size;
	q->buf[q->rear] = data;
}

ELEMENT deQueue(QUEUE* q) {
	if (isEmpty(q)) {
		printf("Queue is empty!\n");
		return 0;
	}
	q->front = (q->front + 1) % q->size;
	return q->buf[q->front - 1];
}

void destroyQueue(QUEUE* q) {
	free(q->buf);
	free(q);
}

void printAll(QUEUE* q) {
	int i = q->front;
	if (isEmpty(q)) return;
	while (1) {
		printf("%d", q->buf[i]);
		if (i == q->rear)
			break;
		i = i + 1 % q->size;
	}
	printf("\n");
}