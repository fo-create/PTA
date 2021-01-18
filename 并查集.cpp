#include<stdio.h>
#define max 1000
void make(int father[], int n);
int find(int father[], int x);
bool judge(int father[], int x, int y);
void unit(int father[], int x, int y);
void out(int father[], int n);
bool flag;
int count = 0;
int main()
{
	int father[max];
	int n, m, q;
	int x, y;
	scanf("%d%d%d", &n, &m, &q);
	make(father, n);
	for (int i = 0; i < m; i++)
	{
		scanf("%d%d", &x, &y);
		unit(father, x, y);
	}
	for (int i = 0; i < q; i++)
	{
		scanf("%d%d", &x, &y);
		flag=judge(father, x, y);
		if (flag)
			printf("In the same gang.\n");
		else
			printf("In different gangs.\n");
	}
	out(father, n);
	return 0;
}
void make(int father[],int n)//建立集合//
{
	int i;
	for (i = 1; i <= n; i++)
		father[i] = i;
}
int find(int father[],int x)
{
	while (father[x] != x)
		x = father[x];
	return x;
}
bool judge(int father[],int x, int y)
{
	x = find(father,x);
	y = find(father,y);
	if (x == y)
		return true;
	else
		return false;
}
void unit(int father[], int x, int y)
{
	x = find(father, x);
	y = find(father, y);
	father[y] = x;
}
void out(int father[],int n)
{
	for (int i = 1; i <=n; i++)
	{
		if (father[i] == i)
			count++;
	}
	printf("%d\n", count);
}