#include<stdio.h>
#include<stdlib.h>

typedef struct tree {
	int data;
	struct tree* left;
	struct tree* right;
}Tree;

Tree* getNode() {
	Tree* newnode = (Tree*)malloc(sizeof(Tree));
	newnode->left = newnode->right = NULL;
	
	return newnode;
}

void insert(Tree** root, int num) {
	if (*root == NULL) {
		*root = getNode();
		(*root)->data = num;

		// return;
	}

	// 나보다 작은값은					   왼쪽으로 진입
	else if ((*root)->data > num) 	insert(&(*root)->left, num);
	
	// 나보다 큰값은						   오른쪽으로 진입
	else if ((*root)->data < num) 	insert(&(*root)->right, num);
	
}

int main() {
	Tree* root = NULL;		// 노드의 가장 최상위 위치를 저장

	insert(&root, 10);
	insert(&root, 20);
	insert(&root, 5);
	insert(&root, 7);

	printf("root = %d\n", root->data);			// 10
	printf("left = %d\n", root->left->data);	// 5
	printf("right = %d\n", root->right->data);	// 20
	printf("left->right = %d\n", root->left->right->data);
}