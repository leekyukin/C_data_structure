#include<stdio.h>
#include<stdlib.h>

typedef struct stack {
	int data;
	struct stack* link;
}Stack;

Stack* getNode() {
	Stack* tmp = (Stack*)malloc(sizeof(Stack*));
	tmp->link = NULL;

	return tmp;
}

void push(Stack** top, int data) { // &�� ������ ���������ͷ� ����
	
	Stack* tmp = *top; // top�� ����pointer, ������ �ѹ� ����(*)�� main�� top��(=�ּ�)
	// ��> ���� main�� top���� ���
	
	*top = getNode(); //main�� top�� �����Ҵ� ������ �����Ѵ�


	(*top)->data = data; // 	(**top).data = data;
	(*top) -> link = tmp; // ������ ž�� ��� (��ũ��)
}

int main() {
	Stack* top = NULL;  // Stack�� ���� ���� ����Ű�� ������

	push(&top, 10); // Stack��10�� �װڴ�,
	push(&top, 20);
	push(&top, 30);

	printf("%d -> %d -> %d\n", top->data, top->link->data, top->link->link->data);
	// ��� : 30 -> 20 -> 10 ;
}