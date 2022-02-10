#include <stdio.h>
#include <stdlib.h>
#define _CRT_SECURE_NO_WARNINGS
typedef int ELEMENT;
typedef struct listNode {
	ELEMENT data;
	int i;
	struct listNode* link;
}listNode;
typedef struct linkedList_h {
	listNode* head;
}linkedList_h;

linkedList_h* createLinkedList_h();
void insertFirstNode(linkedList_h* L, ELEMENT data);
void insertMiddleNode(linkedList_h* L, listNode* pre, ELEMENT data);
void insertLastNode(linkedList_h* L, ELEMENT data);
void printList(linkedList_h* L, int count);
void freeLinkedList_h(linkedList_h* L);
ELEMENT getD(linkedList_h* L, int index);
listNode* search(linkedList_h* L, ELEMENT data);
int countNode(linkedList_h * L);
int partition(linkedList_h* L, int left, int right);
void swapNodes(listNode* x, listNode* y);
void quickSort(linkedList_h* L, int left, int right);

int main(void) {
	linkedList_h* L = createLinkedList_h();
	ELEMENT data;
	listNode* p;
	int count;

	count = countNode(L);
	insertFirstNode(L, 1);
	printList(L,count);
	
	count = countNode(L);
	insertFirstNode(L, 10);
	printList(L,count);
	
	printf("스왑 전 : ");
	count = countNode(L);
	insertLastNode(L, 12);
	printList(L,count);

	printf("10과 12 스왑 후 :");
	swapNodes(search(L, 12), search(L, 10));
	printList(L, count);

	p = search(L, 10);
	insertMiddleNode(L, p, 20);
	count = countNode(L);
	printList(L,count);
	
	insertFirstNode(L, 9);
	count = countNode(L);
	printList(L,count);

	insertLastNode(L, 100);
	count = countNode(L);
	printList(L,count);

	printf("\n\n 정렬 후 : \n");
	quickSort(L, 0, count-1);
	printList(L, count);
	printf("\n\n");

	freeLinkedList_h(L);
	printList(L,count);
}
linkedList_h* createLinkedList_h() {
	linkedList_h* L = (linkedList_h*)malloc(sizeof(linkedList_h));
	L->head = NULL;
	return L;
}
void printList(linkedList_h* L, int count) {
	listNode* p;
	printf("랜덤 수 -> ");
	p = L->head;
	while (p) {
		printf("%d번째.%d", p->i, p->data);
		p = p->link;
		if (p) printf(", ");
	}
	printf("\n");
	printf("노드 갯수 : %d\n", count);
}
void insertFirstNode(linkedList_h* L, ELEMENT data) {
	listNode* newNode = (listNode*)malloc(sizeof(listNode));
	newNode->data = data;
	if (L->head) {
		listNode* p = L->head;
		while (p) {
			p->i++;
			p = p->link;
		}
	}
	newNode->link = L->head;
	newNode->i = 0;
	L->head = newNode;
}
void insertMiddleNode(linkedList_h* L, listNode* pre, ELEMENT data) {
	listNode* newNode = (listNode*)malloc(sizeof(listNode));
	newNode->data = data;
	if (!L->head)
		insertFirstNode(L, data);
	else if (!pre)
		insertFirstNode(L, data);
	else {
		newNode->link = pre->link;
		pre->link = newNode;
		newNode->i = (pre->i)+1;
		listNode* p = newNode->link;
		while (p) {
			(p->i)++;
			p = p->link;
		}
	}
}
void insertLastNode(linkedList_h* L, ELEMENT data) {
	listNode* newNode = (listNode*)malloc(sizeof(listNode));
	newNode->data = data;
	newNode->link = NULL;
	if (!L->head) {
		L->head = newNode;
		return;
	}
	listNode* p = L->head;
	while (p->link) p = p->link;
	newNode->i = (p->i) + 1;
	p->link = newNode;
}
void freeLinkedList_h(linkedList_h* L) {
	listNode* p;
	while (L->head) {
		p = L->head;
		L->head = L->head->link;
		free(p);
		p = NULL;
	}
}
ELEMENT getD(linkedList_h* L, ELEMENT index) {
	listNode* p = L->head;
	while (p) {
		if (p->i == index) return p->data;
		p = p->link;
	}
}
listNode* search(linkedList_h* L, ELEMENT data) {
	listNode* p = L->head;
	while (p) {
		if (p->data == data) return p;
		else p = p->link;
	}
}
int countNode(linkedList_h* L) {
	listNode* p = L->head;
	int count = 0;
	while (p) {
		count++;
		p = p->link;
	}
	return count;
}
void swapNodes(listNode* x, listNode* y) {
	ELEMENT tmp = x->data;
	x->data = y->data;
	y->data = tmp;
}
int partition(linkedList_h* L, int left, int right) {
	int pivot, tmp, low, high;
	low = left;
	high = right + 1;
	pivot = getD(L, left);
	printf("\nPivot = %d\n\n", pivot);
	do {
		do {
			low++;
		} while (getD(L, low) < pivot);
		do {
			high--;
		} while (getD(L, high) > pivot);
		if (low < high) 
			swapNodes(search(L, getD(L, low)), search(L, getD(L, high)));
	} while (low < high);
	swapNodes(search(L, getD(L, left)), search(L, getD(L, high)));
	return high;
}
void quickSort(linkedList_h* L, int left, int right) {
	if (left < right) {
		int q = partition(L, left, right);
		quickSort(L, left, q - 1);
		quickSort(L, q + 1, right);
	}
}