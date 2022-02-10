#include<stdio.h>
#include<stdlib.h>
#define MAX 5

typedef struct stack {
	int data[MAX];
	int top;
}Stack;

void init(Stack* stack) {
	stack->top = -1;
}

void push(Stack* stack,int data) {
	if (stack->top >= MAX-1) {
		printf("Stack Overflow!!!\n");
		return;
	}

	stack->top++;

	stack->data[stack->top] = data;   // data[top] = data;
	
}

void pop(Stack* stack) {
	stack->data[stack->top] = 0;
	stack->top--;
}

void printStack(Stack stack) {
	for (int i = stack.top; i >= 0; i--) {
		printf("%d\n", stack.data[i]);
	}
}

int main() {
	Stack stack;

	push(&stack,10);
	push(&stack, 20);
	push(&stack, 30);

//	printf("%d -> %d -> %d\n", stack.data[0], stack.data[1], stack.data[2]);
	printStack(stack);
	pop(&stack);


}

