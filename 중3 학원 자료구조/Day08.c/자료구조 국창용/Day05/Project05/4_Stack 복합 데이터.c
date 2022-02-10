#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct stack {
	char name[20];
	int age;
	double height;
	struct stack* link;
	
}Stack;

Stack* getNode() {
	Stack* newnode = (Stack*)malloc(sizeof(Stack));
	newnode->link = NULL;

	return newnode;
}

void push(Stack** top, char* name, int age, double height) {
	Stack* tmp = *top;

	*top = getNode();

	strcpy((*top)->name, name);
	(*top)->age = age;
	(*top)->height = height;
	(*top)->link = tmp;
}

void printStack(Stack* top) {
	while (top != NULL) {
		printf("이름 : %s(%d세, %.1lfcm)\n", top->name,
			top->age, top->height);

		top = top->link;
	}
	printf("\n");
}

void pop(Stack** top) {
	if (*top == NULL) {
		printf("Stack is Empty!!!\n");
		return;
	}

	Stack* tmp = *top;

	printf("꺼낸 값) 이름 : %s(%d세, %.1lfcm)\n", 
		(*top)->name, (*top)->age, (*top)->height);

	*top = (*top)->link;
	free(tmp);
}

void clear(Stack** top) {
	while (*top != NULL) {
		pop(top);
	}
}

int main() {
	Stack* top = NULL;

	push(&top, "홍길동", 22, 176.3);
	push(&top, "김길동", 32, 186.1);
	push(&top, "이길동", 12, 166.7);

	printStack(top);

	pop(&top); printf("\n");

	printStack(top);
	clear(&top);
}