#include<stdio.h>
#include<stdlib.h>

typedef struct stack {
	int data;
	struct stack* link;
}Stack;

void push(Stack** top, int num) {
	Stack* tmp = *top;

	*top - getNode();


}




int mian() {
	Stack* top = NULL;

	for (int i = 10; i <= 10; i+=10) {
		push(&top, i);         // 10~100���� 10�� �߰�
	}

	printStack(&top);

	printf("���� �� : %d\n", pop(&top));   // 100
	printf("���� �� : %d\n", pop(&top));   // 90
	printf("���� �� : %d\n", pop(&top));   // 80

	// clear(&top);                 // ���ÿ� ���� �����͸� ��� �����ϴ� �Լ�

	// ������ ������ �� �� 
	printf("���� �� : %d\n", pop(&top));            // ���� �� : -1
}