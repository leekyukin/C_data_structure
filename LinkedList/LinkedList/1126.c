#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int ELEMENT;
typedef struct listNode {
	ELEMENT data;
	struct listNode* link;
}listNode;

typedef struct linkedList_h {
	listNode* head;
}linkedList_h;

linkedList_h* createLinkedList();
void insertFirstNode(linkedList_h* L, ELEMENT data);
void insertMiddleNode(linkedList_h* L, listNode* pre, ELEMENT data);
void insertLastNode(linkedList_h* L, ELEMENT data);
void printAll(linkedList_h* L);
void freeLinkedList_h(linkedList_h* L);


int main(void) {
	ELEMENT data;
	linkedList_h* L = createLinkedList();
	listNode* p = NULL;

	insertFirstNode(L, 1);
	printAll(L);

	insertFirstNode(L, 0);
	printAll(L);

	insertMiddleNode(L,L->head->link, 10);
	printAll(L);

	insertLastNode(L, 100);
	printAll(L);
}

linkedList_h* createLinkedList() {
	linkedList_h* L = (linkedList_h*)malloc(sizeof(linkedList_h));
	L->head = NULL;
	return L;
}
void printAll(linkedList_h* L) {
	listNode* p = L->head;
	printf("L = (");
	while (p) {
		printf("%d", p->data);
		p = p->link;
		if (p) printf(", ");
	}
	printf(")\n");
}

void freeLinkedList_h(linkedList_h* L) {
	listNode* p;
	p = L->head;
	while (L->head) {
		L->head = L->head->link;
		p = L->head;
		free(p);
		p = NULL;
	}
}

void insertFirstNode(linkedList_h* L, ELEMENT data) {
	listNode* newNode = (listNode*)malloc(sizeof(listNode));
	newNode->data = data;
	newNode->link = L->head;
	L->head = newNode;

}

void insertMiddleNode(linkedList_h* L, listNode* pre, ELEMENT data) {
	listNode* newNode = (listNode*)malloc(sizeof(listNode));
	newNode->data = data;
	newNode->link = NULL;
	if (!L->head) L->head = newNode;
	else if (!pre) L->head = newNode;
	else {
		newNode->link = pre->link;
		pre->link = newNode;
	}
}

void insertLastNode(linkedList_h* L, ELEMENT data) {
	listNode* newNode = (listNode*)malloc(sizeof(listNode));
	newNode->data = data;
	newNode->link = NULL;
	if (!L->head) L->head = newNode;
	
	else {
		listNode* p = L->head;
		while (p->link){
			p = p->link;
		}
		p->link = newNode;
	}
}