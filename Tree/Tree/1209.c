#include <stdio.h>
#include <stdlib.h>


typedef struct treeNode {
	char key;
	struct treeNode* left;
	struct treeNode* right;
}treeNode;

treeNode* searchBST(treeNode* root, char x) {
	treeNode* p;
	p = root;
	while (p) {
		if (x < p->key) p = p->left;
		else if (x > p->key) p = p->right;
		else return p;
	}
	printf("\n\nNot found key!!\n\n");
	return p;
}

treeNode* insertNode(treeNode* p, char x) {
	treeNode* newNode;

	if (!p) {
		newNode = (treeNode*)malloc(sizeof(treeNode));
		newNode->key = x;
		newNode->left = NULL;
		newNode->right = NULL;
		return p;
	}
	if (x > p->key) insertNode(p->right, x);
	else if (x < p->key) insertNode(p->left, x);
	else printf("Same key is already existed\n\n");
	
	return p;
}