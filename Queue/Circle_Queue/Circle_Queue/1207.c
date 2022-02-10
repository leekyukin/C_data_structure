#include <stdio.h>
#include <stdlib.h>

typedef int ELEMENT;
typedef struct queue {
	ELEMENT* buf;
	int front;
	int rear;
	int size;
}QUEUE;

QUEUE* createQueue(int size) {
	QUEUE* q = (QUEUE*)malloc(sizeof(QUEUE));
	q->front = 0;
	q->rear = 0;
	q->size = size;
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
		printf("========Stack is full!! ============\n");
		return;
	}
	q->rear = (q->rear + 1) % q->size;
	q->buf[q->rear] = data;
}

int deQueue(QUEUE* q) {
	if (isEmpty(q)) {
		printf("=========Queue is empty!! ==========\n");
		return 0;
	}
	q->front = (q->front + 1) % q->size;
	return q->buf[q->front - 1];
}

void printAll(QUEUE* q) {
	if (isEmpty(q)) printf("==========Queue is empty!! ===========\n");
	int i = (q->front + 1) % q->size;

	while (q) {
		printf("%d ", q->buf[i]);
		i = (i + 1) % q->size;
	}
	printf("\n");
}

void destroyQueue(QUEUE* q) {
	free(q->buf);
	free(q);
}

int main(void) {
	QUEUE* q = createQueue(5);
	ELEMENT data;
	int menu, result;
	while (1) {
		printf("1.enQueue 2.deQueue 0.exit() : ");
		scanf_s("%d", &menu);
		switch (menu) {
		case 1:
			printf("data : ");
			scanf_s("%d", &data);
			enQueue(q, data);
			break;
		case 2:
			result = deQueue(q);
			if (result) printf("%d\n", result);
			break;
		case 3:
			printAll(q);
			break;
		case 0:
			exit(1);
			break;
		default:
			break;
		}
	};
}