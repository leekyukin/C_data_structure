#include<stdio.h>
#include<stdlib.h>


List* getNode() {
	List* newnode = (List*)malloc(sizeof(List));

}

voidadd(List** head, int num) {
	if (*head == NULL) {
		*head = getNode();
		(*head)->data = num;
		return;
	}
	add(&(*head)->link, num);

}





int main() {


	List* head = NULL;

	for (int i = 10; i <= 50; i += 10) {
		add(&head, i);
	}
}