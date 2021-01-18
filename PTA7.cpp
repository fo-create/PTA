#include<stdio.h>
#include<cstdlib>
#define M 5000
typedef struct node {
	int data;
	struct node*left;
	struct node*right;
}Node, *Tree;
typedef struct
{
	int top;
	Tree data[M];
}sqstack;
sqstack s;
void init()
{
	s.top = 0;
}
void push(Tree temp)
{
	s.data[s.top++] = temp;
}
Tree pop()
{
	return s.data[--s.top];
}
int isempty()
{
	return s.top = 0;
}
bool flag;
void del(Tree &b);
Tree insert();
void inorder(Tree t);
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
		node->left = insert();
		node->right = insert();
	}
	return node;
}
void findnode(Tree &root, int val)
{
	if (root == NULL)
		return;
	if (root->data == val)
	{
		flag = 1;
		del(root);
		root = NULL;
	}
	else {
		if (root->left != NULL)
		{
			findnode(root->left, val);
		}
		if (root->right != NULL)
		{
			findnode(root->right, val);
		}
	}
}
void del(Tree &treenode)
{
	if (treenode)
	{
		del(treenode->left);
		del(treenode->right);
		free(treenode);
		treenode = NULL;
	}
}
void inorder(Tree t)
{
	Tree temp = t;
	while (temp != NULL || s.top != 0)
	{
		while (temp != NULL)
		{
			push(temp);
			temp = temp->left;
		}
		if (s.top != 0)
		{
			temp = pop();
			printf("%d ", temp->data);
			temp = temp->right;
		}
	}
}
int main() {
	Tree root;
	root=insert();
	int number, temp;
	scanf("%d", &number);
	for (int i = 0; i < number; i++)
	{
		flag = 0;
		scanf("%d", &temp);
		findnode(root, temp);
		if (flag)
		{
			inorder(root);
			printf("\n");
		}
		else
			printf("0\n");
	}
}

