#include<stdio.h>
#include<cstdlib>
typedef struct node {
	int data;
	struct node*left;
	struct node*right;
}Node, *Tree;
void findfather(Tree root, Tree p,int *m);//������ֵ��Ӧ���ĸ����//
Tree insert();//�ȸ����д���������//
Node *findnode(Tree root, int data);//Ѱ�Ҷ�Ӧ���ݽ��//
int main() {
	
	Tree root,x;
	root=insert();
	int number,temp;
	scanf("%d", &number);
	for (int i = 0; i < number; i++)
	{	
		int m = 0;//����ֵ0���ݹ鲻���������������������Ҫ���0//
		scanf("%d", &temp);
		x=findnode(root, temp);
		findfather(root, x,&m);//�����ַ�����ں����иı���ֵ//
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
Node *findnode(Tree root, int data)//Ѱ�Ҷ�Ӧ���ݽ��//
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
void findfather(Tree root, Tree p,int *m)//���ڵݹ�����ֻ��һ���ط���ֵ����//
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