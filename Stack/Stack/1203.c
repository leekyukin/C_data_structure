#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

typedef int ELEMENT;
typedef struct stack {
	ELEMENT data[SIZE];
	int top;
}STACK;

void createStack(STACK* s);
int isEmpty(STACK* s);
int isFull(STACK* s);
void Push(STACK* s, ELEMENT data);
ELEMENT Pop(STACK* s);

int main(void) {
	int menu;
	ELEMENT data;
	STACK stack;

	createStack(&stack);
	do {
		printf("1:push, 2:pop, 0:exit : ");
		scanf_s("%d", &menu);
		switch (menu) {
		case 1:
			printf("������ �Է� : ");
			scanf_s("%d", &data);
			Push(&stack, data);
			break;
		case 2:
			data = Pop(&stack);
			if (data)
				printf("pop ������ : %d\n", data);
			break;
		case 0:
			break;
		default:
			printf("�߸��� �Է� �Դϴ�. \n");
			break;
		}
	} while (menu);
}

void createStack(STACK* s) {
	s->top = -1;
}

int isEmpty(STACK* s) {
	return s->top == -1;
}
int isFull(STACK* s) {
	return s->top == SIZE - 1;
}

void Push(STACK* s, ELEMENT data) {
	if (isFull(s)) {
		printf("Stack is full!\n");
		return;
	}
	s->data[++s->top] = data;
}
ELEMENT Pop(STACK* s) {
	if (isEmpty(s)) {
		printf("Stack is empty!\n");
		return 0;
	}
	s->top--;
	return s->data[s->top + 1];
}