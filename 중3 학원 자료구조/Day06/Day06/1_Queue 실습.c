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
		printf("�ֹ��� �ϳ��� �����ϴ�!!\n");
		return;
	}
	printf("%s �ֹ� �Ϸ�~\n", (*front)->menu);
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
		printf("%s �ֹ����!!!\n", (*front)->menu);
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
		printf("�ֹ� ��Ȳ : ");
		printQueue(front);
		printf("��===========�޴�===========\n");
		printf("��\t1. ¥���\n");
		printf("��\t2. «��\n");
		printf("��\t3. ������\n");
		printf("��\t4. ������\n");
		printf("��\t5. �ֹ��Ϸ�\n");
		printf("��=========================\n");
		printf("�ֹ� >>> ");
		scanf_s("%d", &menu);

		char food[20];

		switch (menu) {
		case 1:
			enqueue(&front, &rear, "¥���");
			break;
		case 2:
			enqueue(&front, &rear, "«��");
			break;
		case 3:
			enqueue(&front, &rear,"������");
			break;
		case 4:
			enqueue(&front, &rear, "������");
			break;
		case 5:
			//dequeue(&front);
			break;
		case 0:
			return;
		default :
			printf("���� �޴��Դϴ�!!\n");
		}

		system("pause");
		system("cls");

	}
	
}