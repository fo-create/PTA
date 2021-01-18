#include<stdio.h>
#include<cstdlib>
typedef struct node {
	int data;
	struct node*left;
	struct node*right;
}Node,*Tree;
void inorder(Node* node);
Tree insert();
void postorder(Node* node);
void preorder(Node* node);
int main()
{
	Tree node;
	node = insert();
	preorder(node);
	printf("\n");
	inorder(node);
	printf("\n");
	postorder(node);
	return 0;
}
Tree insert() {
	Tree node;
	int value;
	scanf("%d", &value);
	if (value == 0)
		node = NULL;
	else
	{
		node = (Node*)malloc(sizeof(Node));
		node->data = value;
		node->left=insert();
		node->right=insert();
	}
	return node;
}
void inorder(Node* node) {
		if (node) {
			inorder(node->left);
			printf("%d ", node->data);
			inorder(node->right);
		}
	}
void preorder(Node* node) {
	if (node) {
		printf("%d ", node->data);
		preorder(node->left);
		preorder(node->right);
	}
}
void postorder(Node* node) {
	if (node) {
		postorder(node->left);
		postorder(node->right);
		printf("%d ", node->data);
	}
}
