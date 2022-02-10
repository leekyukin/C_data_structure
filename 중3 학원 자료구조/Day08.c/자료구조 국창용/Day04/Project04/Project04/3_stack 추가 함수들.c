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

int pop(Stack** top) {
	if (*top == NULL) {
		printf("Stack is Empty!!!\n");
		return -1;
	}

	Stack* tmp = *top;
	
	int num = (*top)->data;
	*top = (*top)->link;

	free(tmp);

	return num;
}

void printStack(Stack** top) {
	Stack* tmp = *top;

	while (tmp != NULL) {
		printf("%d ", tmp->data);
		tmp = tmp->link;
	}
	printf("\n");
}

void printStack2(Stack* top) {

	while (top != NULL) {
		printf("%d ", top->data);
		top = top->link;
	}
	printf("\n");
}

void clear(Stack** top) {

	while (*top != NULL) {
		Stack* tmp = *top;

	//	printf("%d가 동적할당 해제~\n", (*top)->data);

		*top = (*top)->link;
		free(tmp);
	}
}

int main() {
	Stack* top = NULL;

	for (int i = 10; i <= 100; i += 10) {
		push(&top, i);		// 10 ~ 100까지 10개 추가
	}

	printStack(&top);		// 스택의 내용 전체를 출력
	printStack2(top);

	printf("꺼낸 값 : %d\n", pop(&top));		// 꺼낸 값 : 100
	printf("꺼낸 값 : %d\n", pop(&top));		// 꺼낸 값 : 90
	printf("꺼낸 값 : %d\n", pop(&top));		// 꺼낸 값 : 80

	clear(&top);		// 스택에 남은 데이터를 모두 제거하는 함수

	// 스택에 모조리 빈 후
	printf("꺼낸 값 : %d\n", pop(&top));		// 꺼낸 값 : -1
}