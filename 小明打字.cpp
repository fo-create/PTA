#include<stdio.h>
#include<stdlib.h>
#define MAX 50000
typedef struct node {
	char data;
	struct node* left;
	struct node* right;
}list, *linklist;
linklist init();
linklist creat(linklist &head, char data[]);
void out(linklist head);
void rightmove(linklist head, linklist &p);
void Backspace(linklist head, linklist &p);
void leftmove(linklist head, linklist &p);
void End(linklist head, linklist &p);
void Home(linklist head, linklist &p);
int main()
{
	linklist head;
	char data[MAX],ch;
	int i = 0;
	head = init();
	ch = getchar();
	while (ch != '\n')
	{
		data[i++] = ch;
		ch = getchar();
	}
	data[i] = '\0';
		head = creat(head, data);
	out(head);
	return 0;
}
linklist init()
{
	linklist head;
	head = (linklist)malloc(sizeof(list));
	head->left = NULL;
	head->right = NULL;
	return head;
}
linklist creat(linklist &head,char data[])
{
	bool flag = 0;
	linklist m, n;
	int i = 0;
	m = head;
	for (;data[i]!='\0';i++)   //遍历字符数组，根据对应符号进行相应操作//
	{
		if (data[i] == '[')
		{
			Home(head, m);
			continue;
		}
		if (data[i] == ']')
		{
			End(head, m);
			continue;
		}
		if (data[i] == '{')
		{
			leftmove(head, m);
			continue;
		}
		if (data[i] == '}')
		{
			rightmove(head, m);
			continue;
		}
		if (data[i] == '=')
		{
			Backspace(head, m);
			continue;
		}
		if (data[i] == '-')
		{
			if (flag == 0)
				flag = 1;
			else
				flag = 0;
			continue;
		}
		
		if (flag == 0)//插入//
		{
			n = (linklist)malloc(sizeof(list));
			/*n->left = NULL;
			n->right = NULL;*/
			n->right = m->right;
			n->left = m;
			if(n->right!=NULL)
			{
				n->right->left = n;
			}
			m->right = n;
			n->data = data[i];
			m = m->right;
		}
		if (flag == 1)//替换//
		{
			m->right->data = data[i];
			m = m->right;
		
		}
	}	
	return head;
}
void out(linklist head)
{
	linklist p = head->right;
	while (p != NULL)
	{
		printf("%c", p->data);
		p = p->right;
	}
}
void Home(linklist head,linklist &p)
{
	if (p != head)
	{
		p = head;
	}
}
void End(linklist head, linklist &p)
{
	while (p->right != NULL)
	{
		p = p->right;
	}
}
void leftmove(linklist head,linklist &p)
{
	if (p != head)
		p = p->left;
}
void rightmove(linklist head, linklist &p)
{
	if (p->right != NULL)
		p = p->right;
}
void Backspace(linklist head, linklist &p)
{
		p->left->right = p->right;
		if(p->right!=NULL)
		p->right->left = p->left;
		linklist val;
		val = p;
		p = p->left;
		free(val);
}
