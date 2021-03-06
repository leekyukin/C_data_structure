#include<stdio.h>
#include<stdlib.h>
#include<time.h>

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
	if (*root == NULL)	return;
	
	// root -> left -> right
	printf("%d ", (*root)->data);
	
	if ((*root)->left != NULL)
		preOrder(&(*root)->left);

	if ((*root)->right != NULL)
		preOrder(&(*root)->right);
}

void inOrder(Tree** root) {
	if (*root == NULL)	return;

	// left -> root -> right
	if ((*root)->left != NULL)
		inOrder(&(*root)->left);

	printf("%d ", (*root)->data);

	if ((*root)->right != NULL)
		inOrder(&(*root)->right);
}

void postOrder(Tree** root) {
	if (*root == NULL)	return;

	// left -> right -> root
	if ((*root)->left != NULL)
		postOrder(&(*root)->left);

	if ((*root)->right != NULL)
		postOrder(&(*root)->right);

	printf("%d ", (*root)->data);
}

void clear(Tree** root) {
	if (*root == NULL)	return;

	// left -> right -> root
	if ((*root)->left != NULL)
		clear(&(*root)->left);

	if ((*root)->right != NULL)
		clear(&(*root)->right);

	free(*root);	*root = NULL;
}

int count = 0;

void showTree(Tree** root) {
	if (*root == NULL)	return;

	for (int i = 2; i <= count; i++) {
		printf("   ");
	}

	if(count != 0) printf("???? ");
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

Tree* minNode(Tree** root) {
	if ((*root)->left != NULL)
		return minNode(&(*root)->left);

	else
		return *root;
}

Tree* maxNode(Tree** root) {
	if ((*root)->right != NULL)
		return maxNode(&(*root)->right);

	else
		return *root;
}

void del(Tree** root, int num) {
	// 1. ?˻?
	if ((*root)->data > num)
		del(&(*root)->left, num);

	else if ((*root)->data < num)
		del(&(*root)->right, num);

	else {	// ?????? ã??
		// 2. ????
		Tree* tmp = *root;

		// ?񱳿????? ?????? ?̸? ?????صθ? 
		int left = (*root)->right == NULL;
		int right = (*root)->left == NULL;
		int none = left && right;

		if (none) {	// ??????? ?????ϰ? ???? ????
			*root = NULL;
			free(tmp);
		}

		else if (left) {
			*root = (*root)->left;
			free(tmp);
		}

		else if (right) {
			*root = (*root)->right;
			free(tmp);
		}

		else {
			Tree* min = minNode(&(*root)->right);
			Tree* max = maxNode(&(*root)->left);

			int resultMin = (*root)->data - min->data;
			int resultMax = (*root)->data - max->data;

			if (resultMin < 0)	resultMin = -resultMin;
			if (resultMax < 0)	resultMax = -resultMax;

			if (resultMin < resultMax) {
				(*root)->data = min->data;
				del(&(*root)->right, min->data);
			}

			else {
				(*root)->data = max->data;
				del(&(*root)->left, max->data);
			}
		}
	}
}

int main() {
	Tree* root = NULL;
	int menu;

	do {
		system("pause");
		system("cls");

		showTree(&root);

		printf("=========== ?޴? ===========\n");
		printf("\t1. insert\n");
		printf("\t2. preOrder\n");
		printf("\t3. inOrder\n");
		printf("\t4. postOrder\n");
		printf("\t5. delete\n");
		printf("\t6. random(10)\n");

		printf("\n?Է?(0 : ????) : ");
		scanf_s("%d", &menu);

		int num;
		srand(time(NULL));

		switch (menu) {
		case 1:
			printf("???? ?Է? : ");
			scanf_s("%d", &num);
			
			insert(&root, num);
			break;
		case 2:
			printf("???? ??ȸ : ");
			preOrder(&root);
			printf("\n");
			break;
		case 3:
			printf("???? ??ȸ : ");
			inOrder(&root);
			printf("\n");
			break;
		case 4:
			printf("???? ??ȸ : ");
			postOrder(&root);
			printf("\n");
			break;
		case 5:
			printf("?????? ?????? : ");
			scanf_s("%d", &num);

			del(&root, num);

			break;
		case 6:
			for (int i = 0; i < 10; i++) {
				int num = rand() % 100 + 1;

				insert(&root, num);
			}

			printf("\n???? 10?? ?߰?!!!\n\n");

			break;
		case 100:
			insert(&root, 45);
			insert(&root, 27);	insert(&root, 62);
			insert(&root, 17);	insert(&root, 57);	insert(&root, 73);
			insert(&root, 52);	insert(&root, 65);	insert(&root, 76);
			insert(&root, 63);	insert(&root, 69);
			insert(&root, 64);	insert(&root, 71);
			break;
		case 0:
			printf("???α׷? ????~~\n\n");
			clear(&root);
			break;
		default :
			printf("???? ?޴? ??ȣ!!!\n");
		}

	} while (menu != 0);
}