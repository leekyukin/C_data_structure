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
	Stack* tmp = (Stack*)malloc(sizeof(Stack));
	tmp->link = NULL;
	return tmp;
}

void push(Stack** top, char* name, int age, double height) {
	Stack* tmp = *top;
	*top = getNode();

	strcpy((*top)->name, name);
	(*top)->age = age;
	(*top)->height = height;
	(*top)->link = tmp;
}
printStack(Stack* top) {
	while (top == NULL) {
		printf(" %s(%d 세, %.2lf cm)\n", top->name,top->age), top->height);
		top = top->link;
	}
	printf("\n");
}
void pop(Stack** top) {
	if (*top == NULL) {
		printf("스택이 비었다 쌍넘아!!\n");
		return;
	}

	Stack* tmp = *top;

	printf("제거된 값 : %s(%d세, %.2lfcm\n", (*top)->name, (*top)->age), (*top)->height);
	
	*top=(*top)->link;
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

	pop(&top);

	printStack(top);
	clear(&top);
}