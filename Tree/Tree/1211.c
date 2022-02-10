#include <stdio.h>
#include <stdlib.h>

typedef int ELEMENT;
typedef struct treeNode {
	ELEMENT key;
	struct treeNode* left;
	struct treeNode* right;
}treeNode;

treeNode* searchBST(treeNode* root, ELEMENT x) {
	treeNode* p;
	p = root;
	while (p) {
		if (x < p->key) p = p->left;
		else if (x == p->key) return p;
		else p = p->right;
	}
	printf("\nNot found key!!\n\n");
	return p;
}

treeNode* insertNode(treeNode* p, ELEMENT x) {
	treeNode* newNode;
	if (p==NULL) {
		newNode = (treeNode*)malloc(sizeof(treeNode));
		newNode->key = x;
		newNode->left = NULL;
		newNode->right = NULL;
		return newNode;
	}
	
	if (p->key > x) insertNode(p->left, x);
	else if (p->key == x) printf("\n Data is already exisited!\n"); 
	else insertNode(p->right, x);
	return p;
}

int main(void) {

	treeNode* root = NULL;

	root = insertNode(root, 10);

	insertNode(root, 20);
	insertNode(root, 1);
	insertNode(root, 1);

	
	

}