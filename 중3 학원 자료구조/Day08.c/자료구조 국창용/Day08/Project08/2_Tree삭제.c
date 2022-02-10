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
		printf("%d(��)�� ���� ������!!!\n", num);
		return;
	}

	// 1. �Ű������� ���� num ���� ã�´�
	if ((*root)->data > num)		del(&(*root)->left, num);

	else if ((*root)->data < num)	del(&(*root)->right, num);

	else {
		// 2. ã�� �� �ش� �������� ��带 �����Ѵ�
		Tree* tmp = *root;


		if ((*root)->left == NULL && (*root)->right == NULL) {
			// �ܸ�
			*root = NULL;
			free(tmp);
		}

		else if ((*root)->right == NULL) {
			// ������ ���� ���
			*root = (*root)->left;
			free(tmp);
		}

		else if ((*root)->left == NULL) {
			// �������� ���� ���
			*root = (*root)->right;
			free(tmp);
		}

		else {
			// ������ ���� ���
			// �ܼ��� ��带 �����ϸ� �ȵȴ�
			// ��ü ���� ã�Ƽ� ���� �ٲ���� �Ѵ�

			// ��ü�� �˰���
			// 1. ������ �����ʿ��� ���� ���� ����� �����͸� �����´�
			// (= ������ ũ���� �� �� ���� ���� ������)

			// 2. ������ ���ʿ��� ���� ������ ����� �����͸� �����´�
			// (= ������ ������ �� �� ���� ū ������)

			Tree* min = minNode(&(*root)->right);	// 1�� �˰���

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

	printf("���� ��ȸ : ");	 inOrder(&root);	printf("\n");

	del(&root, 17);		// �ܸ� ��� ����
	printf("���� ��ȸ : ");	 inOrder(&root);	printf("\n");

	del(&root, 57);		// ������ ���� ��� ����
	printf("���� ��ȸ : ");	 inOrder(&root);	printf("\n");

	del(&root, 63);		// �������� ���� ��� ����
	printf("���� ��ȸ : ");	 inOrder(&root);	printf("\n\n");


	printf("���� ��ȸ : ");	 preOrder(&root);	printf("\n");

	del(&root, 45);		// ������ ���� ��� ����
	printf("���� ��ȸ : ");	 preOrder(&root);	printf("\n");

	clear(&root);
}