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

	else if ((*root)->data < num)
		insert(&(*root)->right, num);

	else if ((*root)->data > num) 
		insert(&(*root)->left, num);
}

void preOrder(Tree** root) {	
	if (*root == NULL) return;

	// 전위 순회 : root -> left -> right
	printf("%d ", (*root)->data);							// root
	
	if ((*root)->left != NULL)	preOrder(&(*root)->left);	// left

	if ((*root)->right != NULL)	preOrder(&(*root)->right);	// right
}

void inOrder(Tree** root) {
	if (*root == NULL) return;

	// 중위 순회 : left -> root -> right
	if ((*root)->left != NULL)	inOrder(&(*root)->left);	// left
	printf("%d ", (*root)->data);							// root
	if ((*root)->right != NULL)	inOrder(&(*root)->right);	// right
}

void postOrder(Tree** root) {
	if (*root == NULL) return;

	// 후위 순회 : left -> right -> root
	if ((*root)->left != NULL)	postOrder(&(*root)->left);	// left
	if ((*root)->right != NULL)	postOrder(&(*root)->right);	// right
	printf("%d ", (*root)->data);							// root
}

int count = 0;

void showTree(Tree** root) {
	if (*root == NULL) return;
	
	for (int i = 2; i <= count; i++) {
		printf("   ");
	}

	if (count != 0)	printf("└─ ");
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
	if ((*root)->right != NULL)	clear(&(*root)->right);
	
	free(*root); 
	*root = NULL;	// 지운 위치의 주소를 NULL로 해주지 않으면
					// 다음 insert에서 주소가 NULL이 아니여서 추가가 안됨
}

int main() {
	Tree* root = NULL;

	insert(&root, 45);
	insert(&root, 27);	insert(&root, 62);
	insert(&root, 17);	insert(&root, 57);	insert(&root, 73);
	insert(&root, 52);	insert(&root, 65);	insert(&root, 76);
	insert(&root, 63);	insert(&root, 69);
	insert(&root, 64);	insert(&root, 71);


	printf("전위 순회 : ");
	preOrder(&root);
	printf("\n");

	printf("중위 순회 : ");
	inOrder(&root);
	printf("\n");

	printf("후위 순회 : ");
	postOrder(&root);
	printf("\n");


	printf("\n트리 구조 출력~\n\n");
	showTree(&root);


	clear(&root);		// 후위순회 방식을 사용하자

	insert(&root, 20);

	printf("전위 순회 : ");
	preOrder(&root);
	printf("\n");
}