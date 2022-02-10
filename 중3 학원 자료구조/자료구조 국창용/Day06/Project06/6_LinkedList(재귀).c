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

	// 의미 : 현재 공간을 만들지 못했으면
	// ㄴ> 다음 위치로 진입해라~
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

	del(&head, 100);	// 맨 끝값 제거
	printList(head);

	del(&head, 10);		// 맨 처음값 제거
	printList(head);

	del(&head, 50);		// 중간값 제거
	printList(head);

}