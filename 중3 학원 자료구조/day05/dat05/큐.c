#include<stdio.h>
#include<stdlib.h>

typedef struct queue {
	int data;
	struct queue* link;
}Queue;

Queue* getNode() {
	Queue* tmp = (Queue*)malloc(sizeof(Queue));

	tmp->data = 0;
	tmp->link = NULL;
	return tmp;
}

void enqueue(Queue** front, Queue** rear, int num) {
	if (*front == NULL) { //Å¥°¡ ºñ¾úÀ»¶§
		*front = getNode();
		*rear = *front;

		(*front)->data = num;
	}
	else {
		Queue* tmp = *rear;

		*rear = getNode();
		tmp->link = *rear;

		(*rear)->data = num;
	}

}

int dequeue(Queue** front) {
	if (*front == NULL) {
		printf("Queue is Empty!!\n");
		return;
	}
	Queue* tmp = *front;
	int num = (*front)->data;

	*front = (*front)->link;
	free(tmp);
}

int main() {
	Queue* front=NULL;
	Queue* rear=NULL;

	enqueue(&front, &rear, 10);
	enqueue(&front, &rear, 20);
	enqueue(&front, &rear, 30);

	printf("%d - > %d - > %d\n", front->data, front->link->data, front->link->link->data);

	printf("²¨³½ °ª : %d\n", dequeue(&front)); 
	printf("²¨³½ °ª : %d\n", dequeue(&front));
	printf("²¨³½ °ª : %d\n", dequeue(&front));
	printf("²¨³½ °ª : %d\n", dequeue(&front));

}