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

	//	printf("%d�� �����Ҵ� ����~\n", (*top)->data);

		*top = (*top)->link;
		free(tmp);
	}
}

int main() {
	Stack* top = NULL;

	for (int i = 10; i <= 100; i += 10) {
		push(&top, i);		// 10 ~ 100���� 10�� �߰�
	}

	printStack(&top);		// ������ ���� ��ü�� ���
	printStack2(top);

	printf("���� �� : %d\n", pop(&top));		// ���� �� : 100
	printf("���� �� : %d\n", pop(&top));		// ���� �� : 90
	printf("���� �� : %d\n", pop(&top));		// ���� �� : 80

	clear(&top);		// ���ÿ� ���� �����͸� ��� �����ϴ� �Լ�

	// ���ÿ� ������ �� ��
	printf("���� �� : %d\n", pop(&top));		// ���� �� : -1
}