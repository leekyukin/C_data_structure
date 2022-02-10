#include<stdio.h>
#define MAX 5

typedef struct stack {
	int data[MAX];
	int top;
}Stack;

void init(Stack* stack) {
	stack->top = -1;
}

void push(Stack* stack, int data) {
	if (stack->top >= MAX - 1) {
		printf("Stack Overflow!!!\n");
		return;
	}
	stack->top++;
	stack->data[stack->top] = data;		//	data[top] = data;
}

void printStack(Stack stack) {
	for (int i = stack.top; i >= 0; i--) {
		printf("%d\n", stack.data[i]);
	}
}

void pop(Stack* stack) {
	if (stack->top <= -1) {
		printf("Stack UnderFlow!!!\n");
		return;
	}

	stack->data[stack->top] = 0;
	stack->top--;
}

int main() {
	Stack stack;

	init(&stack);

	push(&stack, 10);
	push(&stack, 20);
	push(&stack, 30);
	push(&stack, 40);
	push(&stack, 50);
	push(&stack, 60);

//	printf("%d -> %d -> %d\n", stack.data[2], stack.data[1], stack.data[0]);
	printStack(stack);
	printf("\n");

	pop(&stack);
	pop(&stack);
	pop(&stack);
	pop(&stack);
	printStack(stack);

	pop(&stack);	
	pop(&stack);	// 데이터가 없는 상태

}