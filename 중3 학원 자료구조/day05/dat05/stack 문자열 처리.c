#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct stack {
	char url[20];
	struct stack* link;
}Stack;

Stack* getnode() {
	Stack* tmp = (Stack*)malloc(sizeof(Stack));

	// strcpy(tmp->url, "����");
	tmp->link = NULL;
	return tmp;
}

void push(Stack** top, char* data) {
	Stack* tmp = *top;
	*top = getnode();
	strcpy((*top)->url, data);
	(*top)->link = tmp;
}

void printStack(Stack* top) {
	while (top != NULL) {
		printf("url : %s\n ", top->url);
		top = top->link;
	}
	printf("\n");
}

void pop(Stack** top) {
	if (*top == NULL) {
		printf("������ ����ֽ��ϴ�!!\n");
		return;
	}

	Stack* tmp = *top;

	printf("���� �� : %s\n", (*top)->url);

	*top = (*top)->link;
	free(tmp);


}


void clear(Stack** top) {
	while (*top != NULL) {
		pop(top);
	}
}

//���ڿ��� �����ϴ� pop�Լ�
char url[20];
char pop_R(Stack** top) {
	Stack* tmp = *top;

	
	strcpy(url, (*top)->url);

	*top = (*top)->link;
	free(tmp);

	return url;
}

int main() {
	Stack* top = NULL;

	push(&top, "www.naver.com");
	push(&top, "www.daum.net");
	push(&top,"www.googel.com");

	printStack(top);

	pop(&top);

	printStack(top);
	clear(&top);
}