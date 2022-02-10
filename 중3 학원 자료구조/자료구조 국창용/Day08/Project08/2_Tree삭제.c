#include<stdio.h>
#include<stdlib.h>

typedef struct tree {
	int data;
	struct tree* left, * right;
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
	}

	else if ((*root)->data < num)	insert(&(*root)->right, num);
	else if ((*root)->data > num)	insert(&(*root)->left, num);
}

void inOrder(Tree** root) {
	if (*root == NULL)	return;

	if ((*root)->left != NULL)		inOrder(&(*root)->left);
	printf("%d ", (*root)->data);
	if ((*root)->right != NULL)		inOrder(&(*root)->right);
}

void preOrder(Tree** root) {
	if (*root == NULL)	return;

	printf("%d ", (*root)->data);
	if ((*root)->left != NULL)		preOrder(&(*root)->left);
	if ((*root)->right != NULL)		preOrder(&(*root)->right);
}

void clear(Tree** root) {
	if (*root == NULL)	return;

	if ((*root)->left != NULL)		clear(&(*root)->left);
	if ((*root)->right != NULL)		clear(&(*root)->right);

	free(*root);	
	*root = NULL;
}

Tree* minNode(Tree** root) {
	if ((*root)->left != NULL) 
		return minNode(&(*root)->left);
	
	else 
		return *root;
}

void del(Tree** root, int num) {
	if (*root == NULL) {
		printf("%d(은)는 없는 데이터!!!\n", num);
		return;
	}

	// 1. 매개변수로 받은 num 값을 찾는다
	if ((*root)->data > num)		del(&(*root)->left, num);

	else if ((*root)->data < num)	del(&(*root)->right, num);

	else {
		// 2. 찾은 후 해당 데이터의 노드를 제거한다
		Tree* tmp = *root;


		if ((*root)->left == NULL && (*root)->right == NULL) {
			// 단말
			*root = NULL;
			free(tmp);
		}

		else if ((*root)->right == NULL) {
			// 왼쪽을 가진 노드
			*root = (*root)->left;
			free(tmp);
		}

		else if ((*root)->left == NULL) {
			// 오른쪽을 가진 노드
			*root = (*root)->right;
			free(tmp);
		}

		else {
			// 양쪽을 가진 노드
			// 단순히 노드를 제거하면 안된다
			// 대체 값을 찾아서 값을 바꿔줘야 한다

			// 대체값 알고리즘
			// 1. 현재의 오른쪽에서 가장 왼쪽 노드의 데이터를 가져온다
			// (= 나보다 크지만 그 중 가장 작은 데이터)

			// 2. 현재의 왼쪽에서 가장 오른쪽 노드의 데이터를 가져온다
			// (= 나보다 작지만 그 중 가장 큰 데이터)

			Tree* min = minNode(&(*root)->right);	// 1번 알고리즘

			(*root)->data = min->data;
			del(&(*root)->right, min->data);
		}
	}
}

int main() {
	Tree* root = NULL;

	insert(&root, 45);
	insert(&root, 27);	insert(&root, 62);
	insert(&root, 17);	insert(&root, 57);	insert(&root, 73);
	insert(&root, 52);	insert(&root, 65);	insert(&root, 76);
	insert(&root, 63);	insert(&root, 69);
	insert(&root, 64);	insert(&root, 71);

	printf("중위 순회 : ");	 inOrder(&root);	printf("\n");

	del(&root, 17);		// 단말 노드 제거
	printf("중위 순회 : ");	 inOrder(&root);	printf("\n");

	del(&root, 57);		// 왼쪽을 가진 노드 제거
	printf("중위 순회 : ");	 inOrder(&root);	printf("\n");

	del(&root, 63);		// 오른쪽을 가진 노드 제거
	printf("중위 순회 : ");	 inOrder(&root);	printf("\n\n");


	printf("전위 순회 : ");	 preOrder(&root);	printf("\n");

	del(&root, 45);		// 양쪽을 가진 노드 제거
	printf("전위 순회 : ");	 preOrder(&root);	printf("\n");

	clear(&root);
}