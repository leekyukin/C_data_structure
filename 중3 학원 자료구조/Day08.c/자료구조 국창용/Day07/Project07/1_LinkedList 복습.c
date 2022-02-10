#include<stdio.h>
#include<stdlib.h>

typedef struct list {
	int data;
	struct list* link;
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

	add(&(*head)->link, num);
}

void printList(List* head) {
	while (head != NULL) {
		printf("%d -> ", head->data);
		head = head->link;
	}
	printf("\b\b\b  \n");
}

void del(List** head, int num) {
	if (*head == NULL) {
		printf("%d(은)는 존재 하지 않음\n", num);
		return;
	}

	if ((*head)->data == num) {
		List* tmp = *head;
		*head = (*head)->link;
		free(tmp);

		return;
	}

	del(&(*head)->link, num);
}

void modify(List** head, int src, int dst) {
	if (*head == NULL) {
		printf("%d(은)는 존재 하지 않음\n", src);
		return;
	}

	if ((*head)->data == src) {
		(*head)->data = dst;

		return;
	}

	modify(&(*head)->link, src, dst);
}

void insert(List** head, int src, int dst) {
	if (*head == NULL) {
		printf("%d(은)는 존재 하지 않음\n", src);
		return;
	}

	if ((*head)->data == src) {
		List* newnode = getNode();
		newnode->data = dst;

		newnode->link = (*head)->link;
		(*head)->link = newnode;

		return;
	}

	insert(&(*head)->link, src, dst);
}

void clear(List** head) {
	while (*head != NULL) {
		List* tmp = *head;
		*head = (*head)->link;
		free(tmp);
	}
}

int main() {
	List* head = NULL;

	for (int i = 10; i <= 100; i += 10) {
		add(&head, i);
	}

	printList(head);

	del(&head, 10);		printList(head);
	del(&head, 100);	printList(head);
	del(&head, 50);		printList(head);

	// 없는 데이터 삭제
	del(&head, 200);	printList(head);
		
	modify(&head, 60, 66);	// 60을 66으로
	printList(head);

	insert(&head, 30, 35);	// 30뒤에 35를 추가
	printList(head);


	// 없는 데이터 수정, 추가
	modify(&head, 200, 33);
	insert(&head, 120, 400);
	printList(head);


	clear(&head);
	printList(head);
}