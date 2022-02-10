#include<stdio.h>
#include<stdlib.h>

typedef struct stack {
	int data;
	struct stack* link;
}Stack;

Stack* getNode() {
	Stack* newnode = (Stack*)malloc(sizeof(Stack));

	newnode->link = NULL;
	return newnode;
}

void push(Stack** top, int data) {
	Stack* tmp = *top;

	*top = getNode();

	(*top)->data = data;
	(*top)->link = tmp;
}


int main() {
	Stack* top = NULL;  // Stack�� ���� ���� ����Ű�� ������

	push(&top, 10); // Stack��10�� �װڴ�,
	push(&top, 20);
	push(&top, 30);

	printf("%d -> %d -> %d\n", top->data, top->link->data, top->link->link->data);
	// ��� : 30 -> 20 -> 10 ;

	printf("���� �� : %d\n", pop(&top));   // 30
	printf("���� �� : %d\n", pop(&top));   // 20
	printf("���� �� : %d\n", pop(&top));   // 10


}