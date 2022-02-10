#include<stdio.h>

typedef struct node {
	int data;
	struct node* link;	// Node* link;
}Node;

int main() {
	Node n1 = { 10, 0 };		// ※ pointer변수에 0은 아무것도 가리키지 않음을 의미
	Node n2 = { 20, NULL };		// C언어에서 NULL이라는 매크로 상수는 0에 매칭되어있다
	Node n3 = { 30, NULL };		// 아무것도 가리키지 않는 pointer 변수를 NULL-Pointer 라고 한다

	n1.link = &n2;	// n1 -> n2
	n2.link = &n3;	// n2 -> n3
	n3.link = &n1;	// n3 -> n1

					// n1 -> n2 -> n3 -> n1 .....

	printf("%d -> %d\n", n1.data, n1.link->data);	// (&n2)->data
	printf("%d -> %d\n", n2.data, n2.link->data);
	printf("%d -> %d\n", n3.data, n3.link->data);

	// n1만 가지고 아래와같이 출력
	// 10 -> 20 -> 30
	printf("%d -> %d -> %d\n", n1.data, n1.link->data, n1.link->link->data);
}