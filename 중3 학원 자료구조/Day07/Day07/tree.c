#include<stdio.h>
#include<stlib.h>

typedef struct tree {
	int data;
	struct tree* left, *right;
}Tree;

Tree* getNode() {
	Tree* newnode = (Tree*)malloc(sizeof(Tree));
	newnode->left = newnode->right = NULL;

	return newnode;
}

void insert(Tree** root, int data) {
	if (*root == NULL) {
		*root = getNode();
		(*root)->data = data;
		return;
	}
	// 나보다 작은 값은                       왼쪽으로 진입
	if ((*root)->data > data) 	insert(&(*root)->left, data);
	// 나보다 큰 값은                         오른쪽으로 진입
	if ((*root)->data < data)	insert(&(*root)->right, data);
	
	
}

int main() {
	Tree* root = NULL;     // 노드의 가장 최상위 위치 저장

	insert(&root, 10);
	insert(&root, 20);
	insert(&root, 5);
	insert(&root, 7);

	printf("root = %d\n", root->data);			// 10
	printf("left = %d\n", root->left->data);	// 5
	printf("right = %d\n", root->right->data);  // 20
	printf("lett->right = %d\n", root->left->right->data);
}