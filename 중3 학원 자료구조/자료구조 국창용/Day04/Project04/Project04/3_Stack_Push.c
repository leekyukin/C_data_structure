#include<stdio.h>
#include<stdlib.h>
#define EMPTY 0

typedef struct stack {
	int data;
	struct stack* link;
}Stack;

Stack* getNode() {
	Stack* tmp = (Stack*)malloc(sizeof(Stack));
	tmp->link = NULL;

	return tmp;
}

void push(Stack** top, int data) {
	Stack* tmp = *top;		// top은 이중 pointer, 현재 한번 참조(*)시 main의 top값(= 주소)
	// ㄴ> 현재 main의 top값을 백업

	*top = getNode();		// main의 top에 동적할당 공간을 생성한다

	(*top)->data = data;	//	(**top).data = data;
	(*top)->link = tmp;
}

int main() {
	Stack* top = NULL;	// Stack의 가장 위를 가리키는 포인터

	push(&top, 10);		// Stack에 10을 쌓겠다
	push(&top, 20);
	push(&top, 30);

	printf("%d -> %d -> %d\n", top->data, top->link->data, top->link->link->data);
	// 결과 : 30 -> 20 -> 10;
}