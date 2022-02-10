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
// �ݺ��� �̿��� add
void add(List** head, int num) {
	
	if (*head == NULL) {
		*head = getNode();
		(*head)->data = num;
	}
	else {
		List* tmp = *head;

		while (tmp->link != NULL) {  //���������� tmp�� �̵�
			tmp=tmp->link;
		}

		tmp->link = getNode();
		tmp->link->data = num;
	}
		
}
	


int main() {
	List* head = NULL; // head : ���Ḯ��Ʈ�� ���� ù�κ��� �ǹ�

	add(&head, 10);
	add(&head, 20);
	add(&head, 30);

	printf("%d -> %d -> %d\n", head->data, head->link->data, head->link->link->data);

}