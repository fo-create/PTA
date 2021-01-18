#include<stdio.h>
#include<cstdlib>
typedef struct node {
	char data;
	struct node*left;
	struct node*right;
}Node, *Tree;
Tree insert();
void inorder(Node* node);
int dingyi(char x);
int main()
{
	Tree root;
	root = insert();
	inorder(root);
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
void inorder(Node* node) {
	int result;
	if (node) {
		if (node->left != NULL) {
			/*result = bijiao(node->data, node->left->data);*/
			bool flag = dingyi(node->data) > dingyi(node->left->data);
			if (flag)
				printf("(");
			inorder(node->left);
			if (flag)
				printf(")");
		}
		printf("%c", node->data);
		if (node->right != NULL)
		{
			/*result = bijiao(node->data, node->right->data);*/
			bool flag = dingyi(node->data) >= dingyi(node->right->data);
			if (flag)
				printf("(");
			inorder(node->right);
			if (flag )
				printf(")");
		}
			
	}
}
//int bijiao(char x, char y)
//{
//	switch (x) {
//	case '+':case '-':
//		if (y == '+' || y == '-')
//		{
//			return 0;
//		}
//		else
//		{
//			return -1;
//		}
//		break;
//	case '*':
//		if ((x == '*') && (y == '-' || y == '+'))
//			return 1;
//		else
//			return 0;
//	case '/':
//		/*if ((x == '*' || x == '/')&&(y=='+'||y=='-'||y=='*'||y=='/'))*/
//		if (( x == '/') && (y == '+' || y == '-' || y == '*' || y == '/'))
//		{
//			return 1;
//		}
//		else
//		{
//			return 0;
//		}
//		break;
//	}
//}
//*c##/a##*d##e##
int dingyi(char x)
{
	if (x == '+' || x == '-')
		return 1;
	if (x == '*' || x == '/')
		return 2;
	if (x >= 'a'&&x <= 'z')
		return 3;
}