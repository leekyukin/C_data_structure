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
int isEmpty(QUEUE* q);
int isFull(QUEUE* q);
void enQueue(QUEUE* q, ELEMENT data);
ELEMENT deQueue(QUEUE* q);
void printAll(QUEUE* q);
void destroyQueue(QUEUE* q);

int main(void) {
	int menu;
	ELEMENT data;

	QUEUE* q = createQueue(5);
	do {
		printf("1.enQueue 2.deQueue 3.destroy 4.exit()");
		scanf_s("%d", &menu);
		switch (menu)
		{
		case 1:
			printf("data : ");
			scanf_s("%d", &data);
			enQueue(q, data);
			printAll(q);
			break;
		case 2:
			data = deQueue(q);
			if (!data) printf("%d \n", data);
			break;
		case 3: 
			destroyQueue(q);
			break;
		case 4: 
			exit(1);
			break;
		default:
			printf("다시 입력해주세요\n");
			break;
		}
	} while (1);


}

QUEUE* createQueue(int n) {
	QUEUE* q = (QUEUE*)malloc(sizeof(QUEUE));
	int size = n;
	int front = 0;
	int rear = 0;
	q->buf = (ELEMENT*)malloc(sizeof(ELEMENT) * q->size);
	return q;
}

int isEmpty(QUEUE* q) {
	return q->front == q->rear;
}
int isFull(QUEUE* q) {
	return (q->rear+1) % q->size == q->front;
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
void printAll(QUEUE* q) {
	int i = q->front + 1;
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