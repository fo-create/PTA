#include<iostream>
#include<cstdlib>
#include<cstring>
using namespace std;
#define max 210
#define INF 0x3f3f3f3f
typedef struct EdgeNode {
	int adjvex;//顶点i相邻的顶点编号//
	struct EdgeNode *next;//下一个边结点指针域//
	int weight;//权值//
	int count;
}edgeNode, AdjList[max];//边结点类型//
typedef struct {
	AdjList adjList;//邻接表//
	int numVertexes, numEdges;//顶点数，边数//
}GraphAdjList;
typedef struct
{
	int x;
	int y;
}num;
//int cmp(const void *a, const void *b) {
//	if ((*(num *)a).i != (*(num *)b).i)
//		return (*(num *)a).i - (*(num*)b).i;
//	else
//		return (*(num *)a).j - (*(num *)b).j;
//}
num str[max];
int cnt = 0;
int sum = 0;
int flag=0;
int dta[max];
int add = 1;
num temp;
void CreateALGraph(GraphAdjList *G);
void topo(GraphAdjList *G);
void CriticalPath(GraphAdjList *G);
//bool has(GraphAdjList *G);
void out(GraphAdjList *G);
void quicksort(num a[], int m, int n);
int main()
{
	GraphAdjList *G = new GraphAdjList;
	while (scanf("%d%d", &G->numVertexes, &G->numEdges) != EOF)
	{
		CreateALGraph(G);
		topo(G);
		if (flag)
		{
			printf("unworkable project\n");
			
		}
		else {
			CriticalPath(G);
			out(G);
			 
		}
		flag = 0;
		cnt = 0;
		sum = 0;
		add = 1;
		memset(dta, 0, sizeof(dta));
	}
	
	return 0;
}
void CreateALGraph(GraphAdjList *G)
{
	int i, j, k, weight;
	int x, y;//弧头，弧尾顶点//
	edgeNode *e;
	for (i = 1; i <= G->numVertexes; i++)
	{
		G->adjList[i].adjvex = i;
		G->adjList[i].next = NULL;//边表置为空表//
	}
	for (k = 0; k < G->numEdges; k++)
	{
		scanf("%d%d%d", &i, &j, &weight);//输入边上的顶点序号//
		e = (edgeNode*)malloc(sizeof(edgeNode));
		e->weight = weight;
		e->adjvex = j;
		e->next = G->adjList[i].next;
		G->adjList[i].next = e;
	}
}
void CriticalPath(GraphAdjList *G)
{
	int ve[max], vl[max], e, l;
	int i,j, k;
	/*int st[max], top = -1;*/
	edgeNode *p;
	for (i = 1; i <= G->numVertexes; i++)
	{
		ve[dta[i]] = 0;
		/*G->adjList[i].count = 0;*/
	}
	for (i = 1; i <= G->numVertexes; i++)//计算各事件最早发生时间//
	{
		p = G->adjList[dta[i]].next;
		while (p != NULL)
		{
			/*G->adjList[p->adjvex].count++;*/
			k = p->adjvex;
			if (ve[dta[i]] + p->weight > ve[k])
				ve[k] = ve[dta[i]] + p->weight;
			p = p->next;
		}
	}
	for (i = 1; i <= G->numVertexes; i++)
		vl[i] = ve[dta[G->numVertexes]];
	for (i = G->numVertexes; i >= 1; i--)//拓扑逆序//
	{
		p = G->adjList[dta[i]].next;
		while (p != NULL)
		{
			k = p->adjvex;
			if (vl[k] - p->weight < vl[dta[i]])
				vl[dta[i]] = vl[k] - p->weight;
			p = p->next;
		}
	}
	for (i = 1; i <= G->numVertexes; i++)
	{
		p = G->adjList[dta[i]].next;
		while (p != NULL)
		{
			k = p->adjvex;
			e= ve[dta[i]];
			l = vl[k] - p->weight;
			if (e == l)
			{
				str[cnt++] = { dta[i],k };
			}
			p = p->next;
		}
	}
	sum = ve[dta[G->numVertexes]];
}
void topo(GraphAdjList *G)
{
	int i, j,top = -1;
	int st[max];
	edgeNode *p;
	for (i = 1; i <= G->numVertexes; i++)
		G->adjList[i].count = 0;
	for (i = 1; i <= G->numVertexes; i++)//求所有顶点的入度//
	{
		p = G->adjList[i].next;
		while (p != NULL)
		{
			G->adjList[p->adjvex].count++;
			p = p->next;
		}
	}
	for (i = 1; i <= G->numVertexes; i++)
		if (G->adjList[i].count == 0)
		{
			st[++top] = i;//入度为0顶点进栈//
		}
	int number = 0;
	while (top > -1)//栈非空循环//
	{
		i = st[top--];
		dta[add++] = i;
		number++;
		p = G->adjList[i].next;
		while (p != NULL)
		{
			j = p->adjvex;
			G->adjList[j].count--;
			if (G->adjList[j].count == 0)
			{
				st[++top] = j;
			}
			p = p->next;
		}
	}
	if (number == G->numVertexes)
		flag = 0;
	else
		flag = 1;
}
void out(GraphAdjList *G)
{
	/*qsort(str, cnt, sizeof(str[0]), cmp);*/
	quicksort(str, 0, cnt - 1);
	printf("%d\n", sum);
	for (int i = 0; i < cnt; i++)
	{
		printf("%d->%d\n", str[i].x, str[i].y);
	}
}
void quicksort(num a[], int m, int n)
{
	int  i = m, j = n + 1;
	num val = a[m];
	if (m >= n)
		return;
	else
	{
		while (i < j)
		{
			i = i + 1;
			while (a[i].x < val.x|| (a[i].x == val.x&&a[i].y < val.y))
			{
				/*if(a[i].y<=val.y)*/
				i = i + 1;
				if (i == n)
					break;
			}
			j = j - 1;
			while (a[j].x > val.x || (a[j].x == val.x&&a[j].y >val.y))
			{
				/*if(a[j].y>val.y)*/
				j = j - 1;
				if (j == m)
					break;
			}
			if (i < j)
			{

				temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}

		}
		temp = a[j];
		a[j] = a[m];
		a[m] = temp;
		quicksort(a, m, j - 1);
		quicksort(a, j + 1, n);
	}
}
//7 8
//1 2 6
//1 3 4
//1 4 5
//2 5 1
//3 5 1
//5 7 9
//4 6 2
//6 7 4
//4 5
//1 2 6
//1 3 4
//2 4 1
//3 4 1
//4 1 3
//7 9
//1 2 6
//1 4 5
//5 4 3
//2 5 1
//3 5 1
//5 7 9
//4 6 2
//6 7 4