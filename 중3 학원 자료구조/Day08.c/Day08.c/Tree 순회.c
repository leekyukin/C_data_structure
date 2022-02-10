#include<stdio.h>
#include<Stdlib.h>

typedef struct tree {
	int data;
	struct tree* left, * right;
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
	if ((*root)->data > data) insert(&(*root)->left, data);
	if ((*root)->data < data) insert(&(*root)->right, data);
}

void preOder(Tree** root) {
	// ���� ��ȸ : root -> left -> right
	if (*root == NULL) return;

	printf("%d ", (*root)->data);	// root
	
	if ((*root)->left != NULL)	preOder(&(*root)->left);
	if ((*root)->right != NULL)	preOder(&(*root)->right);
}

void inOder(Tree** root) {
	// ���� ��ȸ : left -> root -> right
	if (*root == NULL) return;
	
	if ((*root)->left != NULL) inOder(&(*root)->left);   // left
	printf("%d ", (*root)->data);					     // root
	if ((*root)->right != NULL) inOder(&(*root)->right); // right
}

void postOder(Tree** root) {
	// ���� ��ȸ : left -> right -> root
	if (*root == NULL) return;

	if ((*root)->left != NULL)  postOder(&(*root)->left);  // left
	if ((*root)->right != NULL)	postOder(&(*root)->right); // right
	printf("%d ", (*root)->data);
}

int count = 0;

void showTree(Tree** root) {

	if (*root == NULL) return;

	for (int i = 2; i <= count; i++) {
		printf("   ");
	}

	if (count != 0)	printf("���� ");
	printf("%d\n", (*root)->data);

	if ((*root)->left != NULL) {
		count++;
		showTree(&(*root)->left);
		count--;
	}
	if ((*root)->right != NULL) {
		count++;
		showTree(&(*root)->right);
		count--;
	}

}

void clear(Tree** root) {
	if ((*root)->left != NULL)	clear(&(*root)->left);
	if ((*root)->right != NULL) clear(&(*root)->right);
	free(*root);
	*root = NULL;  // ���� ��ġ�� �ּҸ� NULL�� ������ ������
				   // ���� insert���� �ּҰ� NULL�� �ƴϿ��� �߰��� �ȵ�
	
}

int main() {
	Tree* root = NULL;
	
	
	insert(&root, 45);			
	insert(&root, 27);			insert(&root, 62);
	insert(&root, 17);			insert(&root, 57);		insert(&root, 73);
	insert(&root, 52);			insert(&root, 65);		insert(&root, 76);
	insert(&root, 63);			insert(&root, 69);
	insert(&root, 64);			insert(&root, 71);


	printf("���� ��ȸ : ");
	preOder(&root);
	printf("\n");

	printf("���� ��ȸ : ");
	inOder(&root);
	printf("\n");

	printf("���� ��ȸ : ");
	postOder(&root);
	printf("\n");

	printf("\nƮ�� ���� ���~~~\n\n");
	showTree(&root);

	clear(&root);

	insert(&root, 50);

	printf("���� ��ȸ : ");
	preOder(&root);
	printf("\n");
	
}




















}
