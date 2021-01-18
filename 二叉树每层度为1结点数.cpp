#include<stdio.h>
#include<cstdlib>
#define MAX 100
typedef struct node {
	char data;
	struct node*left;
	struct node*right;
}Node, *Tree;
Tree insert();
void level(Tree root, Tree str[]);
void levcount(Tree tree, int lev, int levelnum[]);
int levelnum[100] = { 0 };
int m = 0;//����//
int n = 0;
int s[100];//��¼ÿ�������//
Tree str[100];//��¼��α����Ľ��//
int count = 0;
int main()
{
	
	Tree node;
	node = insert();//���򴴽�������//
	level(node,str);
	levcount(node, 0, levelnum);
	for (int i = 0; levelnum[i] != '\0'; i++)
	{
		s[n++] = levelnum[i];
	}
	int p=0;
	for (int i = 0; levelnum[i] != '\0'; i++)
	{
		for (int j=0; j < s[i]; j++)
		{
			if (str[p]->left == NULL && str[p]->right != NULL || str[p]->left != NULL && str[p]->right == NULL)
			{
				count++;
			}
			p++;
		}
		printf("%d\n", count);
		count = 0;
	}
	return 0;
}
Tree insert() {
	Tree node;
	char value;
	scanf("%c", &value);
	if (value == '#')
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
void levcount(Tree tree, int lev, int levelnum[])
{
	if (tree)
	{
		++levelnum[lev];
		levcount(tree->left, lev + 1, levelnum);
		levcount(tree->right, lev + 1, levelnum);
	}
	return;
}
void level(Tree root,Tree str[])
{
	Tree p;
	Tree q[MAX];
	int head = 0, tail = 0;
	if (root)
	{
		tail = (tail + 1) % MAX;
		q[tail] = root;
	}
	while (head != tail)
	{
		head = (head + 1) % MAX;
		p = q[head];
		str[m++] = p;
		if (p->left != NULL)
		{
			tail = (tail + 1) % MAX;
			q[tail] = p->left;
		}
		if (p->right != NULL)
		{
			tail = (tail + 1) % MAX;
			q[tail] = p->right;
		}
	}
}