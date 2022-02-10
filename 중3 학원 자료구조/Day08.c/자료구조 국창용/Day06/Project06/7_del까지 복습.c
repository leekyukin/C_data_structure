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
	if ((*head)->data == num) {
		List* tmp = *head;
		*head = (*head)->link;
		free(tmp);
		return;
	}

	del(&(*head)->link, num);
}

int main() {
	List* head = NULL;

	for (int i = 10; i <= 50; i += 10) {
		add(&head, i);
	}

	printList(head);

	//del(&head, 50); printList(head);
	//del(&head, 10); printList(head);
	//del(&head, 30); printList(head);

	// 데이터 수정
	modify(&head, 30, 35);	// 30을 35로 바꿔라

	// 중간값 추가
	insert(&head, 40, 42);	// 40뒤에 42를 추가
							// 40 -> 42 -> 50
}