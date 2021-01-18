#include<stdio.h>
#define MAX 100000
int main()
{
	char data[MAX],ch;
	int i=0;
	while ((ch = getchar()) != '\n')
	{
		data[i++] = ch;
	}
	data[i] = '\0';
	int res = 0,num=0;//num����������//
	for (int j = 0; j < i; j++)
	{
		if (data[j] == '(') {
			num++;
		}//���������ž�����1//
		else {
			if (num > 0)
				num--;//��ʱ���������ţ����֮ǰ�������ţ�num�����㣩����֮ƥ��,num����//
			else
				res++;//��¼�����������//
		}
	}
	if (num ==0&&res == 0)
		printf("Match");
	else
	{
		printf("%d\n", num + res);
		if (res)
		{
			for (int m = 0; m < res; m++)
				printf("(");
		}
		printf("%s", data);
		if (num)
		{
			for (int m = 0; m < num; m++)
				printf(")");
		}
	}
	return 0;
}
#include<stdio.h>
#include<malloc.h>
#define MAX 100000
typedef struct
{
	char data[MAX];
	int top;
}stack;
int isempty(stack *s)
{
	return (s->top == 0);
}
void push(stack *s, int val)
{
	if ((s->top + 1) > MAX)
		return;
	s->data[++s->top] = val;
}
void pop(stack *s)
{
	if (s->top == 0)
		return;
	s->top--;
}
int main()
{
	stack *p;
	p = (stack*)malloc(sizeof(stack));
	p->top = 0;
	char data[MAX], ch;
	int i=0,num=0,res=0;
		while ((ch = getchar()) != '\n')
		{
			data[i++] = ch;
		}
		data[i] = '\0';
		for (int j = 0; j < i; j++)
		{
			if (data[j] == '(')
			{
				push(p, data[j]);
			}
			else {
				if (!isempty(p))
					pop(p);
				else
					res++;
			}
		}
		if (p->top == 0 && res == 0)
			printf("Match");
		else
				{
					printf("%d\n", p->top+ res);
					if (res)
					{
						for (int m = 0; m < res; m++)
							printf("(");
					}
					printf("%s", data);
					if (!isempty(p))
					{
						for (int m = 0; m < p->top; m++)
							printf(")");
					}
				}
	return 0;
}
