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

void insert(Tree** root, int data) {
	if (*root == NULL) {
		*root = getNode();
		(*root)->data = data;
	}
	else if ((*root)->data > data)  insert(&(*root)->left,data);
	else if ((*root)->data < data)  insert(&(*root)->right,data);
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

void preOrder(Tree** root) {
	if (*root == NULL) return;
	printf("%d ", (*root)->data);
	if ((*root)->left != NULL)   preOrder(&(*root)->left);
	if ((*root)->right != NULL)  preOrder(&(*root)->left);
}

void inOrder(Tree** root) {
	if (*root == NULL) return;
	if ((*root)->left != NULL)  inOrder(&(*root)->left);
	printf("%d ", (*root)->data);
	if ((*root)->right != NULL) inOrder(&(*root)->right);
}

void postOrder(Tree** root) {
	if (*root == NULL) return;
	if ((*root)->left != NULL)  postOrder(&(*root)->left);
	if ((*root)->right != NULL) postOrder(&(*root)->right);
	printf("%d ", (*root)->data);
	
}

void clear(Tree** root) {
	if (*root == NULL) return;
	if ((*root)->left != NULL)  postOrder(&(*root)->left);
	if ((*root)->right != NULL) postOrder(&(*root)->right);
	free(*root); *root = NULL;
}

Tree* minNode(Tree** root) {
	if ((*root)->right != NULL)
		return minNode(&(*root)->left);
	else  return *root;
}

Tree* maxNode(Tree** root) {
	if ((*root)->left != NULL)
		return maxNode(&(*root)->right);
	else  return *root;
}

void del(Tree** root, int data){
	if (*root == NULL) {
		printf("������ ���� ���ٶ�!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
		return;
	}
	else if ((*root)->data < data)  del(&(*root)->right,data);
	else if ((*root)->data > data)  del(&(*root)->left, data);
	
	else {
		Tree* tmp = *root;



		if ((*root)->left == NULL && (*root)->right == NULL) {
			*root = NULL;
			free(tmp);
		}

		else if ((*root)->right == NULL) {
			*root = (*root)->left;
			free(tmp);
		}

		else if ((*root)->left == NULL) {
			*root = (*root)->right;
			free(tmp);
		}

		else {
			Tree* min = minNode(&(*root)->right);
			Tree* max = maxNode(&(*root)->left);

			int resultmin = (*root)->data - min->data;
			int resultmax = (*root)->data - max->data;

			if (resultmin < 0)	resultmin = -resultmin;
			if (resultmax < 0)	resultmax = -resultmax;

			if (resultmin < resultmax) {
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

		printf("============�޴�============\n");
		printf("\t1. insert\n");
		printf("\t2. preOrder\n");
		printf("\t3. inOrder\n");
		printf("\t4. postOrder\n");
		printf("\t5. delete\n");
		printf("\t6. random\n");

		printf("�Է�(0 : ����) : ");
		scanf_s("%d", &menu);

		int num;
		srand(time(NULL));

		switch (menu) {
		case 1:
			printf("������ �� : "); 
			scanf_s("%d", &num);
			insert(&root, num);
			break;
		case 2:
			printf("���� ��ȸ : ");
			preOrder(&root);
			break;
		case 3:
			printf("���� ��ȸ : ");
			inOrder(&root);
			break;
		case 4:
			printf("���� ��ȸ : ");
			postOrder(&root);
			break;
		case 5:
			printf("������ ������ : ");
			scanf_s("%d", &num);
			del(&root, num);
			break;
		case 6:
			for (int i = 0; i < 10; i++) {
				int num = rand() % 100 + 1;
				
				insert(&root, num);
			}

			printf("\n���� 10�� �߰�!!!\n\n");

			break;
		case 0:
			printf("���α׷� ����!!\n");
			return;
		default :
			printf("���� �޴� ��ȣ!!!\n");
		}

	


	} while (menu != 0);
}

