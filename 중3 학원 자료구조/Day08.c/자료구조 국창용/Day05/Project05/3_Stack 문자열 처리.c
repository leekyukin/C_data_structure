#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct stack {
	char url[20];
	struct stack* link;
}Stack;

Stack* getNode() {
	Stack* newnode = (Stack*)malloc(sizeof(Stack));
	newnode->link = NULL;

	return newnode;
}

void push(Stack** top, char* url) {
	// printf("%s\n", url);

	Stack* tmp = *top;
	*top = getNode();

	// (*top)->url = url;
	strcpy((*top)->url, url);
	(*top)->link = tmp;
}

void printStack(Stack* top) {
	while (top != NULL) {
		printf("url : %s\n", top->url);
		top = top->link;
	}
	printf("\n");
}

void pop(Stack** top) {
	if (*top == NULL) {
		printf("스택이 비어있습니다!!\n");
		return;
	}

	Stack* tmp = *top;
	
	printf("꺼낸 값 : %s\n", (*top)->url);
	*top = (*top)->link;

	free(tmp);
}

void clear(Stack** top) {
	while (*top != NULL) {
		pop(top);
	}
}


// 문자열을 리턴하는 pop함수
char url[20];

char* pop_R(Stack** top) {
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
	push(&top, "www.google.com");

	printStack(top);

	pop(&top);

	printf("꺼낸 값 : %s\n", pop_R(&top));

	printStack(top);
	clear(&top);
}