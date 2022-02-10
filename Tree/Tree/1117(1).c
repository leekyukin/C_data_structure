#include <stdio.h>
#include <stdlib.h>

typedef struct treeNode {
	char data;
	struct treeNode* left;
	struct treeNode* right;
}treeNode;

treeNode* makeRootNode(char data, treeNode* leftNode, treeNode* rightNode) {
	treeNode* root = (treeNode*)malloc(sizeof(treeNode));

	root->left = leftNode;
	root->right = rightNode;
	root->data = data;
	return root;
}

void preorder(treeNode* root) {
	if (root == NULL)
		return;
	printf("%c ", root->data);
	preorder(root->left);
	preorder(root->right);

}
void inorder(treeNode* root) {
	if (root == NULL)
		return;
	inorder(root->left);
	printf("%c ", root->data);
	inorder(root->right);
}
void postorder(treeNode* root) {
	if (root == NULL)
		return;
	postorder(root->left);
	postorder(root->right);
	printf("%c ", root->data);
}

int main(void) {

	treeNode* H = makeRootNode('H', NULL, NULL);
	treeNode* G = makeRootNode('G', NULL, NULL);
	treeNode* F = makeRootNode('F', NULL, NULL);
	treeNode* E = makeRootNode('E', NULL, NULL);
	treeNode* D = makeRootNode('D', H, NULL);
	treeNode* C = makeRootNode('C', F, G);
	treeNode* B = ('B', D, E);
	treeNode* A = makeRootNode('A', B, C);

	printf("<< preorder >>\n");
	preorder(A);
	printf("\n");
	printf("<< inorder >>\n");
	inorder(A);
	printf("\n");
	printf("<< postorder >>\n");
	postorder(A);

}

