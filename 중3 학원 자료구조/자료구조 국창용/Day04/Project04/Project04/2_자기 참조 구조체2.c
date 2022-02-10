#include<stdio.h>
#include<stdlib.h>

typedef struct node {
	int data;
	struct node* link;
}Node;

Node* getNode() {
	Node* tmp = (Node*)malloc(sizeof(Node));

	tmp->data = 0;
	tmp->link = NULL;

	return tmp;
}

int main() {
	Node* n1 = getNode();	// data = 0, link = NULL 로 초기화하며 동적할당
	Node* n2 = getNode();
	Node* n3 = getNode();

	n1->data = 10;
	n1->link = n2;

	n2->data = 20;
	n2->link = n3;

	n3->data = 30;
	n3->link = n1;
	
	// n1만 가지고 아래와 같이 출력
	// 10 -> 20 -> 30
	printf("%d -> %d -> %d\n", n1->data, n1->link->data, n1->link->link->data);

	// 동적할당 모두 해제~
	free(n1);
	free(n2);
	free(n3);
}