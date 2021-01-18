#include<iostream>
#include<cstdio>
#include<string.h>
using namespace std;
typedef struct node
{
	char data;
	struct node *lchild;
	struct node *rchild;
}tree ,*Tree;
Tree init(char ch);
void preout(Tree root);
Tree creat(char *in, char *post, int length);
int height(Tree root);
void clear(Tree root);
void isok(char *in, char *post, int length);
bool flag=0;
int main()
{
	char in[26], post[26];
	scanf("%s", post);
	scanf("%s", in);
	int length = strlen(in);
	Tree root = creat(in, post, length);
	if (!flag) {
		printf("%d\n", height(root) - 1);
		preout(root);
		clear(root);
	}
		return 0;
}
Tree init(char ch)
{
	Tree root;
	root = new tree;
	root->data = ch;
	root->lchild = root->rchild = NULL;
	return root;
}
Tree creat(char *in, char *post, int length)
{
	if (length == 0)
		return NULL;
	int count = 0;//计数标志量//
	for (count = 0; count < length; count++)
	{
		if (in[count] == post[length - 1])
			break;//找到在中序遍历中根结点的位置//
	}
	isok(in, post, length);
	if (flag == 1)
	{
		printf("INVALID");
		return NULL;
	}
	if (flag == 0) {
		Tree root;
		root = init(post[length - 1]);
		root->lchild = creat(in, post, count);
		root->rchild = creat(in + count + 1, post + count, length - count - 1);
		return root;
	}
	
}
void preout(Tree root)
{
	if (root == NULL)
		return;
	printf("%c", root->data);
	preout(root->lchild);
	preout(root->rchild);
}
void clear(Tree root)
{
	if (root)
	{
		clear(root->lchild);
		clear(root->rchild);
		free(root);
		root = NULL;
	}
}
int height(Tree root)
{
	if (root == NULL)
		return 0;
	else
	{
		int lheight = height(root->lchild);
		int rheight = height(root->rchild);
		return (lheight > rheight) ? (lheight + 1) : (rheight + 1);
	}
}
void isok(char *in, char *post, int length)
{
	char str1[26], str2[26];
	if (length == 0)
		return;
	int count = 0;//计数标志量//
	for (count = 0; count < length; count++)
	{
		if (in[count] == post[length - 1])
			break;//找到在中序遍历中根结点的位置//
	}
	int sum1=0, sum2=1,sum3=0,sum4=1;
	for (int i = 0; i <count; i++)
	{
		sum1 += (int)(in[i] - 'A'+1);
		sum2 *= (int)(in[i] - 'A' + 1);
		sum3 += (int)(post[i] - 'A' + 1);
		sum4 *= (int)(post[i] - 'A' + 1);
	}
	if (sum1 != sum3 && sum2 != sum4)
	{
		flag = 1;
		return;
	}
		isok(in, post, count);
		isok(in + count + 1, post + count, length - count - 1);
}