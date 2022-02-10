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

void push(Stack** top, int num) {
	Stack* tmp = *top;   

	*top = getNode();

	(*top)->data = num;
	(*top)->link = tmp;
}

int pop(Stack** top) {
	if (*top == NULL) {
		printf("������ ����ֽ��ϴ�!!!\n");
		return -1;
	}

	int num;
	Stack* tmp = *top;

	num = (*top)->data;		// tmp->data
	*top = (*top)->link;	// tmp->link

	free(tmp);

	return num;
}

int main() {
	Stack* top = NULL;	// Stack�� ���� ���� ����Ű�� ������
	
	push(&top, 10);		// Stack�� 10�� �װڴ�
	push(&top, 20);
	push(&top, 30);

	printf("%d -> %d -> %d\n", top->data, top->link->data, top->link->link->data);
	// ��� : 30 -> 20 -> 10;

	printf("���� �� : %d\n", pop(&top));		// ���� �� : 30
	printf("���� �� : %d\n", pop(&top));		// ���� �� : 20
	printf("���� �� : %d\n", pop(&top));		// ���� �� : 10
	printf("���� �� : %d\n", pop(&top));		// ���� �� : -1
}