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

	// ������ ��������					   �������� ����
	else if ((*root)->data > num) 	insert(&(*root)->left, num);
	
	// ������ ū����						   ���������� ����
	else if ((*root)->data < num) 	insert(&(*root)->right, num);
	
}

int main() {
	Tree* root = NULL;		// ����� ���� �ֻ��� ��ġ�� ����

	insert(&root, 10);
	insert(&root, 20);
	insert(&root, 5);
	insert(&root, 7);

	printf("root = %d\n", root->data);			// 10
	printf("left = %d\n", root->left->data);	// 5
	printf("right = %d\n", root->right->data);	// 20
	printf("left->right = %d\n", root->left->right->data);
}