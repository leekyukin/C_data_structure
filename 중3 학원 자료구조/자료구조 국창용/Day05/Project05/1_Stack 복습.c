#include<stdio.h>
#include<stdlib.h>

typedef struct stack {
	int data;
	struct stack* link;
}Stack;

Stack* getNode() {
	Stack* tmp = (Stack*)malloc(sizeof(Stack));
	tmp->data = 0;
	tmp->link = NULL;

	return tmp;
}

void push(Stack** top, int data) {
	Stack* tmp = *top;

	*top = getNode();

	(*top)->data = data;
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
	Stack* tmp = *top;
	
	*top = (*top)->link;

	free(tmp);
}

void clear(Stack** top) {
	while (*top != NULL) {
		//Stack* tmp = *top;
		//*top = (*top)->link;

		//free(tmp);

		pop(top);
	}
}

int main() {
	Stack* top = NULL;

	for (int i = 0; i < 10; i++) {
		push(&top, i);
	}

	printStack(top);

	pop(&top);
	pop(&top);

	printStack(top);
	
	clear(&top);

	printStack(top);
}