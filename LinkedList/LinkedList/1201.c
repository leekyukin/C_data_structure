#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char ELEMENT;
typedef struct listNode {
	ELEMENT data[10];
	struct listNode* link;
}listNode;
typedef struct linkedList_h {
	listNode* head;
}linkedList_h;

linkedList_h* createLinkedList_h();
void printAll(linkedList_h* L);
void freeLinkedList_h(linkedList_h* L);
void insertFirstNode(linkedList_h* L, ELEMENT* data);
void insertMiddleNode(linkedList_h* L, listNode* pre, ELEMENT* data);
void insertLastNode(linkedList_h* L, ELEMENT* data);
void searchNode(linkedList_h* L, ELEMENT* data);

int main(void) {

	linkedList_h* L = createLinkedList_h();

	printAll(L);

	insertFirstNode(L, "È­");
	printAll(L);

	insertLastNode(L, "±Ý");
	printAll(L);

	insertLastNode(L,"Åä");
	printAll(L);
	

}

linkedList_h* createLinkedList_h() {
	linkedList_h* L = (linkedList_h*)malloc(sizeof(linkedList_h));
	L->head = NULL;
}
void printAll(linkedList_h* L) {
	listNode* p = L->head;
	printf("L = (");
	while (p) {
		printf("%s", p->data);
		p = p->link;
		if (p) printf(", ");
	}
	printf(")\n");
}

void freeLinkedList_h(linkedList_h* L) {
	listNode* p;
	while (p) {
		p = L->head;
		free(p);
		L->head = L->head->link;
		p = NULL;
	}
}

void insertFirstNode(linkedList_h* L, ELEMENT* data) {
	listNode* newNode = (listNode*)malloc(sizeof(listNode));
	newNode->link = NULL;
	strcpy(newNode->data, data);
	newNode->link = L->head;
	L->head = newNode;
}

void insertMiddleNode(linkedList_h* L, listNode* pre, ELEMENT* data) {
	listNode* newNode = (listNode*)malloc(sizeof(listNode));
	newNode->link = NULL;
	strcpy(newNode->data, data);
	if (!L->head) {
		newNode->link = L->head;
		L->head = newNode;
	}
	else if (!pre) {
		newNode->link = L->head;
		L->head = newNode;
	}
	else {
		newNode->link = pre->link;
		pre->link = newNode;
	}
}

void insertLastNode(linkedList_h* L, ELEMENT* data) {
	listNode* newNode = (listNode*)malloc(sizeof(listNode));
	newNode->link = NULL;
	strcpy(newNode->data, data);
	if (!L->head) {
		newNode->link = L->head;
		L->head = newNode;
	}
	else {
		listNode* p = L->head;
		while (p->link) p->link = p->link->link;
		p->link = newNode;
	}
}