#include<stdio.h> 
#include<stdlib.h> 

typedef char element;
typedef struct treeNode {
	char key;
	struct treeNode* left;
	struct treeNode* right;
} treeNode;

treeNode* searchBST(treeNode* root, char x) {
	treeNode* p;
	p = root;
	while (p) {
		if (x < p->key) p = p->left;
		else if (x == p->key) return p;
		else p = p->right;
	}
	printf("\nã�� Ű�� ����.\n");
	return p;
}

treeNode* insertNode(treeNode* p, element x) {
	treeNode* newNode;
	if(p == NULL) {
		newNode = (treeNode*)malloc(sizeof(treeNode));
		newNode->key = x;
		newNode->left = NULL;
		newNode->right = NULL;
		return newNode;
	}

	if (x < p->key) insertNode(p->left, x);
	else if (x > p->key) insertNode(p->right, x);
	else printf("\n�̹� ���� Ű�� ����\n");

	return p;
}

void deleteNode(treeNode* root, element key) {
	treeNode* parent, * p, * succ, * succ_parent;
	treeNode* child;

	parent = NULL;
	p = root;
	while ((p != NULL) && (p->key != key)) {
		parent = p;
		if (key < p->key) p = p->left;
		else p = p->right;
	}

	if (p == NULL) {
		printf("\n ã�� Ű�� ���� Ʈ���� �����ϴ�!!");
		return;
	}

	if ((p->left == NULL) && (p->right == NULL)) {
		if (parent->left == p)
			parent->left = NULL;
		else
			parent->right = NULL;
	}

	if ((p->left == NULL) || (p->right == NULL)) {
		if (parent->left == p)
			if (p->left != NULL)
				parent->left = p->left;
			else
				parent->left = p->right;
		else
			if (p->right != NULL)
				parent->right = p->right;
			else
				parent->right = p->left;
	}
	else {
		

	}
	free(p);

}
void displayInorder(treeNode* root)
{
	if (root) {
		displayInorder(root->left);
		printf("%c_", root->key);
		displayInorder(root->right);
	}
}

void menu() {
	printf("\n*-----------------------*\n");
	printf("\n\t1 : Ʈ�� ���\n");
	printf("\n\t2 : ���� ����\n");
	printf("\n\t3 : ���� ����\n");
	printf("\n\t4 : ���� �˻�\n");
	printf("\n\t5 : ����\n");
	printf("\n*-----------------------*\n");
	printf("\n�޴� �Է� >> ");

}
int main()
{
	treeNode* root = NULL;
	treeNode* foundedNode = NULL;
	char choice, key;

	root = insertNode(root, 'G');
	insertNode(root, 'I');
	insertNode(root, 'H');
	insertNode(root, 'D');
	insertNode(root, 'B');
	insertNode(root, 'M');
	insertNode(root, 'N');
	insertNode(root, 'A');
	insertNode(root, 'J');
	insertNode(root, 'E');
	insertNode(root, 'Q');

	while (1) {
		menu();
		scanf(" %c", &choice);
		switch (choice - '0') {
		case 1: printf("\t[���� Ʈ�� ���] ");
			displayInorder(root); printf("\n");
			break;
		case 2: printf("������ ���ڸ� �Է��ϼ��� : ");
			scanf(" %c", &key);
			insertNode(root, key);
			break;
		case 3: printf("������ ���ڸ� �Է��ϼ��� : ");
			scanf(" %c", &key);
			deleteNode(root, key);
			break;
		case 4: printf("ã�� ���ڸ� �Է��ϼ��� : ");
			scanf(" %c", &key);
			foundedNode = searchBST(root, key);
			if (foundedNode != NULL)
				printf("\n %c�� ã�ҽ��ϴ�! \n", foundedNode->key);
			else printf("\n ���ڸ� ã�� ���߽��ϴ�. \n");
			break;
		case 5: return 0;
		default: printf("���� �޴��Դϴ�. �޴��� �ٽ� �����ϼ���!\n");
			break;
		}
	}
}
