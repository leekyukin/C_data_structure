#include<stdio.h>

typedef struct node{
	int  data;
	struct node* link; // Node* link;
}Node;


int main() {//| data |  link |
	Node n1 = { 10, 0 };			// ������ ������ 0�� �ƹ��͵� ����Ű�� ����.
	Node n2 = { 20, NULL };	// c���� NULL�̶�� ��ũ�� ����� 0�� ��Ī�Ǿ��ִ�.
	Node n3 = { 30, NULL };  // �ƹ��͵� ����Ű�� �ʴ� pointer ������ NULL - Pointer ��� �Ѵ�.

	n1.link = &n2;  // n1 - > n2
	n2.link = &n3; //  n2 -> n3
	n3.link = &n1; //  n3 -> n1

	printf("%d -> %d\n", n1.data, n1.link->data); 
	printf("%d -> %d\n", n2.data, n2.link->data);
	printf("%d -> %d\n", n3.data, n3.link->data);

	printf("%d->%d->%d\n", n1.data, n1.link->data, n1.link->link->data);
}