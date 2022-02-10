#include<stdio.h>
#include<stdlib.h>
typedef struct list {
	int data;
	struct list* link;
}List;

List* getNode() {
	List* tmp = (List*)malloc(sizeof(List));
	tmp->link = NULL;
	return tmp;
}

void add(List** head, int num) {
	if (*head == NULL) {
		*head = getNode();
		(*head)->data = num;
		return;
	}

	add(&(*head)->link, num);

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

	

void printList(List* head) {
	while (head != NULL) {
		printf("%d -> ", head->data);
	}
	printf("\b\b\b  \n");
}

int main() {
	List* head = NULL;

	for (int i = 10; i <= 100; i+=10) {
		add(&head, i);
	}

	
	printList(head);
}