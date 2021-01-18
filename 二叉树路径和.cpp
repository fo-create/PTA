#include<stdio.h>
#include<cstdlib>
typedef struct node {
	int data;
	struct node*left;
	struct node*right;
}Node, *Tree;
Tree insert();
int pathmax(Tree root);
void pathout(Tree root);
int main()
{
	Tree node;
	int max;
	node = insert();
	max=pathmax(node);
	printf("%d\n", max);
	pathout(node);
	return 0;
}
Tree insert()
{
	Tree node;
	int value;
	scanf("%d", &value);
	if (value == 0)
		node = NULL;
	else
	{
		node = (Node*)malloc(sizeof(Node));
		node->data = value;
		node->left = insert();
		node->right = insert();
	}
	return node;
}
int pathmax(Tree root)
{
	int a, b;
	if (root == NULL)
		return 0;
	else
	{
		a = root->data + pathmax(root->left);
		b = root->data + pathmax(root->right);
		return a > b ? a : b;
	}
}
void pathout(Tree root)
{
	if (root == NULL)
		return;
	else
	{
		printf("%d ", root->data);
		if (pathmax(root->left) >= pathmax(root->right))
		{
			pathout(root->left);
		}
		else
		{
			pathout(root->right);
		}
	}
}
