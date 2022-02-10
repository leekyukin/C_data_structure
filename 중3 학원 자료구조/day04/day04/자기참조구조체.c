#include<stdio.h>

typedef struct node{
	int  data;
	struct node* link; // Node* link;
}Node;


int main() {//| data |  link |
	Node n1 = { 10, 0 };			// 포인터 변수의 0은 아무것도 가리키지 않음.
	Node n2 = { 20, NULL };	// c언어에서 NULL이라는 매크로 상수는 0에 매칭되어있다.
	Node n3 = { 30, NULL };  // 아무것도 가리키지 않는 pointer 변수를 NULL - Pointer 라고 한다.

	n1.link = &n2;  // n1 - > n2
	n2.link = &n3; //  n2 -> n3
	n3.link = &n1; //  n3 -> n1

	printf("%d -> %d\n", n1.data, n1.link->data); 
	printf("%d -> %d\n", n2.data, n2.link->data);
	printf("%d -> %d\n", n3.data, n3.link->data);

	printf("%d->%d->%d\n", n1.data, n1.link->data, n1.link->link->data);
}