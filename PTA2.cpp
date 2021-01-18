#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 20000
typedef struct
{
	int top;
	int data[MAXSIZE];
}sqstack;
sqstack *create()
{
	sqstack *p;
	if (p = (sqstack*)malloc(sizeof(*p)))
	{
		p->top = 0;
		return p;
	}
	return NULL;
}
int push(sqstack *S, int num)
{
	if ((S->top + 1) > MAXSIZE)
	{
		return 0;
	}
	S->data[++(S->top)] = num;
	return 1;
}
void pop(sqstack *S)
{
	if (S->top==0)
	{
		printf("invalid\n");
	}
	else { printf("%d\n", S->data[S->top--]); }
}
int main()
{
	sqstack *S;
	S = create();
	int number, flag, element;
	scanf("%d", &number);
	for (int i = 0; i < number; i++) {
		scanf("%d", &flag);
		if (flag == 1)
		{
			scanf("%d", &element);
			push(S, element);
		}
		else if (flag == 0) { pop(S); }
	}
	return 0;

}
