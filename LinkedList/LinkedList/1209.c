#include <stdio.h>
#include <stdlib.h>
typedef int ELEMENT;
typedef struct listNode {
	ELEMENT data;
	struct listNode* link;
}listNode;
typedef struct linkedList_h {
	listNode* head;
}linkedList_h;

linkedList_h* createLinkedList_h();
void printAll(linkedList_h* L);
void freeLinkedList_h(linkedList_h* L);
void insertFirstNode(linkedList_h* L, ELEMENT data);
void insertMiddleNode(linkedList_h* L, listNode* pre, ELEMENT data);
void insertLastNode(linkedList_h* L, ELEMENT data);
listNode* search(linkedList_h* L, ELEMENT key);

int main(void) {

	linkedList_h* L;
	ELEMENT data;
	int menu, key;
	listNode* pre;
	L = createLinkedList_h();
	
	
	while (1) {
		printf("1.insert firstNode 2.insert middleNode 3.insertLastNode 4.print all 5.search : ");
		scanf_s("%d", &menu);
		switch (menu) {
		case 1:
			printf("data : ");
			scanf_s("%d", &data);
			insertFirstNode(L, data);
			break;
		case 2:
			printf("data : ");
			scanf_s("%d", &data);
			printf("position(behind key) : ");
			scanf_s("%d", &key);
			pre = search(L, key);
			insertMiddleNode(L, pre, data);
			break;
		case 3:
			printf("data : ");
			scanf_s("%d", &data);
			insertLastNode(L, data);
			break;
		case 4:
			printAll(L);
			break;
		case 5:
			printf("key : ");
			scanf_s("%d", &key);
			pre = search(L, key);
			if (pre) printf("exitst!!\n");
			else printf("NONONONO!!\n");
			break;
		default:
			printf("Try again!!\n");
			break;
		}
	}
	


}




linkedList_h* createLinkedList_h() {
	linkedList_h* L = (linkedList_h*)malloc(sizeof(linkedList_h));
	L->head = NULL;
	return L;
}
void printAll(linkedList_h* L) {
	listNode* temp = L->head;
	printf("L-(");
	while (temp) {
		printf("%d", temp->data);
		temp = temp->link;
		if (temp) printf("->");
	}
	printf(")\n");
}
void freeLinkedList_h(linkedList_h* L) {
	listNode* temp = L->head;
	while (temp) {
		temp = L->head;
		L->head = L->head->link;
		free(temp);
		temp = NULL;
	}
}
void insertFirstNode(linkedList_h* L, ELEMENT data) {
	listNode* newNode = (listNode*)malloc(sizeof(listNode));
	newNode->link = NULL;
	newNode->link = L->head;
	newNode->data = data;
	L->head = newNode;
}
void insertMiddleNode(linkedList_h* L, listNode* pre, ELEMENT data) {
	listNode* newNode = (listNode*)malloc(sizeof(listNode));
	newNode->data = data;
	newNode->link = NULL;
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
void insertLastNode(linkedList_h* L, ELEMENT data) {
	listNode* p;
	listNode* newNode = (listNode*)malloc(sizeof(listNode));
	newNode->data = data;
	newNode->link = NULL;
	if (!L->head) L->head = newNode;
	else {
		p = L->head;
		while (p->link) p->link = p->link->link;
		p->link = newNode;
	}
}
listNode* search(linkedList_h* L, ELEMENT key) {
	listNode* p = L->head;
	while (p) {
		if (p->data == key) return p;
		p = p->link;
	}
	return 0;
}