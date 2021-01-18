#include<iostream>
#define max 100
#define INF 9999
using namespace std;
typedef struct
{
	int edges[max][max];
	int n, e;//¶¥µãÊý£¬±ßÊý//
}MGraph;
int A[max][max];
void Floyd(MGraph *g, int number);
void Dispath(int i, int j);
int main()
{
	MGraph *g = new MGraph;
	int  number, x, y, k, i, j, weight;
	while (scanf("%d%d%d", &g->n, &g->e, &number) != EOF)
	{
		for (i = 0; i < g->n; i++)
		{
			for (j = 0; j < g->n; j++)
			{
				if (i == j)
					g->edges[i][j] = 0;
				else
					g->edges[i][j] = INF;
			}
		}
		for (k = 0; k < g->e; k++)
		{
			scanf("%d %d %d", &i, &j, &weight);
			g->edges[i][j] = weight;
		}
		Floyd(g, number);
	}
	return 0;
}
void Floyd(MGraph *g, int number)
{
	int flag = 0;
	int i, j, k, x, y;
	for (i = 0; i < g->n; i++)
		for (j = 0; j < g->n; j++)
		{
			A[i][j] = g->edges[i][j];
		}
	for (k = 0; k < g->n; k++)
	{
		for (i = 0; i < g->n; i++)
		{
			for (j = 0; j < g->n; j++)
				if (A[i][j] > (A[i][k] + A[k][j]))
				{
					A[i][j] = A[i][k] + A[k][j];
				}
		}
	}
	for (k = 0; k < g->n; k++)
	{
		if (A[k][k] < 0)
		{
			flag = 1;
			break;
		}
	}
	if (flag)
	{
		for (int m = 0; m < number; m++)
		{
			scanf("%d%d", &x, &y);
		}
		printf("negative circle\n");
	}
	else {
		for (int m = 0; m < number; m++)
		{
			scanf("%d%d", &x, &y);
			Dispath(x, y);
		}
	}
	return;
}
void Dispath(int i, int j)
{
	if (A[i][j] == INF)
		printf("none\n");
	else
		printf("%d\n", A[i][j]);

}