#include<stdio.h>
#include<cstdlib>
typedef struct node {
	int data;
	struct node*left;
	struct node*right;
}Node, *Tree;
void findfather(Tree root, Tree p,int *m);//找所给值对应结点的父结点//
Tree insert();//先根序列创建二叉树//
Node *findnode(Tree root, int data);//寻找对应数据结点//
int main() {
	
	Tree root,x;
	root=insert();
	int number,temp;
	scanf("%d", &number);
	for (int i = 0; i < number; i++)
	{	
		int m = 0;//赋初值0若递归不满足题中条件则输出题中要求的0//
		scanf("%d", &temp);
		x=findnode(root, temp);
		findfather(root, x,&m);//传入地址，可在函数中改变其值//
		printf("%d\n", m);	
	}
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
		node->left = insert();
		node->right = insert();
	}
	return node;
}
Node *findnode(Tree root, int data)//寻找对应数据结点//
{
	Tree ptr;
	if (root == NULL)
	{
		return NULL;
	}
	else
	{
		if (root->data == data)
		{
			return root;
		}
		else
		{
			if (ptr = findnode(root->left, data))
			{
				return ptr;
			}
			else if (ptr = findnode(root->right, data))
			{
				return ptr;
			}
			else
			{
				return NULL;
			}
		}
	}
}
void findfather(Tree root, Tree p,int *m)//由于递归所以只在一个地方把值传出//
{

	if (root == NULL || p == NULL)
	{
		return ;

	}
	if ( root->left == p || root->right == p)
	{
		*m = root->data;
		return ;
	}
	findfather(root->left, p,m);
	findfather(root->right, p,m);
}