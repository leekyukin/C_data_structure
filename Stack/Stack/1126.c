#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STACK_SIZE 10

typedef int ELEMENT;
typedef struct Stack {
	ELEMENT buf[STACK_SIZE];
	int top;
}STACK;

void createStack(STACK* s);
int isFull(STACK* s);
int isEmpty(STACK* s);
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
			printf("데이터 입력 : ");
			scanf_s("%d", &data);
			Push(&stack, data);
			break;
		case 2:
			data = Pop(&stack);
			if (data)
				printf("pop 데이터 : %d\n", data);
			break;
		case 0:
			break;
		default:
			printf("잘못된 입력 입니다. \n");
			break;
		}
	} while (menu);
}

void createStack(STACK* s) {
	s->top = -1;
}
int isFull(STACK* s) {
	return s->top == STACK_SIZE - 1;
}
int isEmpty(STACK* s) {
	return s->top == -1;
}

void Push(STACK* s, ELEMENT data) {
	if (isFull(s)) {
		printf("Stack is full!!\n");
		return;
	}
	s->buf[s->top++] = data;
}
ELEMENT Pop(STACK* s) {
	if (isEmpty(s)) {
		printf("Stack is empty!!\n");
		return 0;
	}
	s->top--;
	return s->buf[s->top];
}
