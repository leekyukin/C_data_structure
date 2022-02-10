#include<stdio.h>
#include<stdlib.h>

typedef struct queue {
	int data;
	struct queue* link;
}Queue;

Queue* getNode(){
	Queue* tmp = (Queue*)malloc(sizeof(Queue));
	tmp->link = NULL;
	return tmp;
}
void enqueue(Queue** front, Queue** rear, int data) {
	if (*front == NULL) {

		*front = getNode();
		*rear = *front;

		(*front)->data = data;
	}
	else {
		Queue* tmp = *rear;

		*rear = getNode;
		tmp->link = *rear;
		(*rear)->data = data;
		
	}
}


int main() {
	Queue* front, * rear;
	front = rear = NULL;

	for (int i = 10; i <= 100; i += 10) {
		enqueue(&front, &rear, i);

	}
	printQueue(front);

	dequeue(&front);

	printQueue(front);

	clear(&front);
	dequeue(&front);

}