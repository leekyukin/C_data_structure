#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct queue {
	char menu[20];
	struct queue* link;
}Queue;

Queue* getNode() {
	Queue* tmp = (Queue*)malloc(sizeof(Queue));
	tmp->link = NULL;
	return tmp;
}
void enqueue(Queue** front, Queue** rear, char* food) {
	if (*front == NULL) {
		*front = getNode();
		*rear = *front;
		strcpy((*front)->menu ,food);
	}
	else {
		Queue* tmp = *rear;
		*rear = getNode;
		strcpy((*rear)->menu, food);

		tmp->link = *rear;
	}
}

void dequeue(Queue** front) {
	if (*front == NULL) {
		printf("주문이 하나도 없습니다!!\n");
		return;
	}
	printf("%s 주문 완료~\n", (*front)->menu);
	Queue* tmp = *front;
	*front = (*front)->link;

	free(tmp);
}

void printQueue(Queue* front) {
	while (front != NULL) {
		printf("%s - > ", front->menu);
		front = front->link;
	}
	printf("\b\b\b  \n");
}

void clear(Queue** front) {
	whlie (*front != NULL) {
		printf("%s 주문취소!!!\n", (*front)->menu);
		Queue* tmp = *front;
		*front = (*front)->link;

		free(tmp);
	}
}

int main() {
	int menu;
	Queue* front, * rear;
	front = rear = NULL;

	while (1) {
		printf("주문 현황 : ");
		printQueue(front);
		printf("┌===========메뉴===========\n");
		printf("│\t1. 짜장면\n");
		printf("│\t2. 짬뽕\n");
		printf("│\t3. 볶음밥\n");
		printf("│\t4. 탕수육\n");
		printf("│\t5. 주문완료\n");
		printf("└=========================\n");
		printf("주문 >>> ");
		scanf_s("%d", &menu);

		char food[20];

		switch (menu) {
		case 1:
			enqueue(&front, &rear, "짜장면");
			break;
		case 2:
			enqueue(&front, &rear, "짬뽕");
			break;
		case 3:
			enqueue(&front, &rear,"볶음밥");
			break;
		case 4:
			enqueue(&front, &rear, "탕수육");
			break;
		case 5:
			//dequeue(&front);
			break;
		case 0:
			return;
		default :
			printf("없는 메뉴입니다!!\n");
		}

		system("pause");
		system("cls");

	}
	
}