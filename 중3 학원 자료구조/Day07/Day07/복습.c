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

void add(List** head, int data) {
	if (*head == NULL) {
		*head = getNode();
		(*head)->data = data;
		return;
	}
	
	add(&(*head)->link, data);
	
}
void del(List** head, int data) {
	if (*head == NULL) {
		printf("%d(은)는 존재 하지 않음\n",data);
		return;
	}
	if ((*head)->data == data) {
		List* tmp = *head;
		*head = (*head)->link;
		free(tmp);
		return;
	}

	del(&(*head)->link, data);
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
		newnode->link = (*head)->link;
		newnode->data = dst;
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

printList(List* head) {
	while ( head != NULL) {
		printf("%d ",head ->data);
		head = head->link;
	}
	printf("\n");
}

int main() {
	List* head = NULL;

	for (int i = 10; i <= 100; i+=10) {
		add(&head, i);
	}

	printList(head);

	del(&head, 10);		printList(head);
	del(&head, 100);	printList(head);
	del(&head, 50);		printList(head);

	modify(&head, 60, 66);
	printList(head);

	insert(&head, 40, 42);  printList(head);
	
	// 없는 데이터 수정, 추가
	modify(&head, 200, 33);
	insert(&head, 120, 400);
	printList(head);



	clear(&head);
}
