#include<stdio.h>
#include<stdlib.h>

typedef struct stack {
	int data;
	struct stack* link;
}Stack;

Stack* getNode() {
	Stack* newnode = (Stack*)malloc(sizeof(Stack));
	newnode->data = 0;
	newnode->link = NULL;

	return newnode;
}

void push(Stack** top, int num) {
	Stack* tmp = *top;

	*top = getNode();

	(*top)->data = num;
	(*top)->link = tmp;
}

void printStack(Stack* top) {
	while (top != NULL) {
		printf("%d ", top->data);
		top = top->link;
	}
	printf("\n");
}

void pop(Stack** top) {
	if (*top == NULL) {
		printf("스택이 비었습니다!!!\n");
		return;
	}

	Stack* tmp = *top;

	printf("제거한 값 : %d\n", (*top)->data);

	*top = (*top)->link;
	free(tmp);
}

void clear(Stack** top) {
	while (*top != NULL) {
		pop(top);

	}
}

void showStack(Stack** top) {
	Stack* tmp = *top;

	if (*top != NULL)
		printf("┌──────┐\n");

	while (tmp != NULL) {
		printf("│  %3d │\n", tmp->data);
		tmp = tmp->link;
	}
	
	if(*top != NULL)
		printf("└──────┘\n");
}


int main() {
	int menu, num;
	Stack* top = NULL;

	do {
		
		showStack(&top);
		printf("<==메뉴==>\n");
		printf("1. push\n");
		printf("2. pop\n");
		printf("3. print\n");
		printf("4. exit\n");
		printf(">>> ");
		scanf_s("%d", &menu);

		switch (menu) {
		case 1:
			printf("추가할 데이터 : ");
			scanf_s("%d", &num);

			push(&top, num);
			break;
		case 2:
			pop(&top);
			break;
		case 3:
			printStack(top);
			break;
		case 4:
			clear(&top);
			break;
		default:
			printf("없는 메뉴입니다!!!\n");
		}

		system("pause");
		system("cls");

	} while (menu != 4);
}