#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct queue {
	char food[20];
	struct queue* link;
}Queue;

Queue* getNode() {
	Queue* newnode = (Queue*)malloc(sizeof(Queue));
	newnode->link = NULL;
	return newnode;
}

void enqueue(Queue** front, Queue** rear, char* food) {
	if (*front == NULL) {
		*front = getNode();
		*rear = *front;

		strcpy((*front)->food, food);
	}

	else {
		Queue* tmp = *rear;
		*rear = getNode();
		strcpy((*rear)->food, food);

		tmp->link = *rear;
	}
}

void printQueue(Queue* front) {
	while (front != NULL) {
		printf("%s -> ", front->food); 
		front = front->link;
	}

	printf("\b\b\b  \n");
}

void dequeue(Queue** front) {
	if (*front == NULL) {
		printf("주문이 하나도 없습니다!!\n");
		return;
	}

	printf("%s 주문 완료~\n", (*front)->food);

	Queue* tmp = *front;
	*front = (*front)->link;

	free(tmp);
}

void clear(Queue** front) {
	while (*front != NULL) {
		printf("%s 주문 취소!!!\n", (*front)->food);

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
		printf("┌ ========= 메뉴 ==========┐\n");
		printf("│\t 1. 짜장면\t   │\n");
		printf("│\t 2. 짬뽕  \t   │\n");
		printf("│\t 3. 볶음밥\t   │\n");
		printf("│\t 4. 탕수육\t   │\n");
		printf("│\t 5. 주문완료\t   │\n");
		printf("└ =========================┘\n");
		printf("주문 >>> ");
		scanf_s("%d", &menu);

		switch (menu) {
		case 1:
			enqueue(&front, &rear, "짜장면");
			break;
		case 2:
			enqueue(&front, &rear, "짬뽕");
			break;
		case 3:
			enqueue(&front, &rear, "볶음밥");
			break;
		case 4:
			enqueue(&front, &rear, "탕수육");
			break;
		case 5:
			dequeue(&front);
			break;
		case 0:	// 종료
			clear(&front);
			return;
		default :
			printf("없는 메뉴입니다!!!\n");
		}

		system("pause");
		system("cls");
	}
}