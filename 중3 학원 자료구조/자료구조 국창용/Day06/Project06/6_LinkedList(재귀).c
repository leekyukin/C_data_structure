#include<stdio.h>
#include<stdlib.h>

typedef struct list {
	int data;
	struct list* link;	// List*
}List;

List* getNode() {
	List* newnode = (List*)malloc(sizeof(List));
	newnode->link = NULL;

	return newnode;
}

void add(List** head, int num) {
	if (*head == NULL) {
		*head = getNode();
		(*head)->data = num;
		return;
	}

//  add(List** head, int num)
	add(&(*head)->link, num);

	// �ǹ� : ���� ������ ������ ��������
	// ��> ���� ��ġ�� �����ض�~
}

void del(List** head, int num) {

	if ((*head)->data == num) {
		List* tmp = *head;
		*head = (*head)->link;
		free(tmp);
		return;
	}

//	del(List** head, int num)
	del(&(*head)->link, num);
}


void printList(List* head) {
	while (head != NULL) {
		printf("%d -> ", head->data);
		head = head->link;
	}
	printf("\b\b\b  \n");

}

int main() {
	List* head = NULL;

	for (int i = 10; i <= 100; i += 10) {
		add(&head, i);
	}

	printList(head);

	del(&head, 100);	// �� ���� ����
	printList(head);

	del(&head, 10);		// �� ó���� ����
	printList(head);

	del(&head, 50);		// �߰��� ����
	printList(head);

}