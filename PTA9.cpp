#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
#define max 20000
#define INF 99999
bool flag;
typedef struct EdgeNode {
	int adjvex;//顶点i相邻的顶点编号//
	struct EdgeNode *next;//下一个边结点指针域//
	int weight;//权值//
}edgeNode, AdjList[max];//边结点类型//
typedef struct {
	AdjList adjList;//邻接表//
	int numVertexes, numEdges;//顶点数，边数//
}GraphAdjList;
void CreateALGraph(GraphAdjList *G);
void out(GraphAdjList *G);
void del(GraphAdjList *G, int x, int y);
int main()
{
	GraphAdjList *G = new GraphAdjList;
	CreateALGraph(G);
	int number, i, x, y;
	scanf("%d", &number);
	for (i = 0; i < number; i++)
	{
		scanf("%d%d", &x, &y);
		del(G, x, y);
	}
	out(G);
	return 0;
}
void CreateALGraph(GraphAdjList *G)
{
	int i, j, k, weight;
	int x, y;//弧头，弧尾顶点//
	edgeNode *e, *q, *p;
	q = (edgeNode*)malloc(sizeof(edgeNode));
	p = (edgeNode*)malloc(sizeof(edgeNode));
	scanf("%d%d", &G->numVertexes, &G->numEdges);//输入顶点数和边数//
	for (i = 0; i < G->numVertexes; i++)
	{
		G->adjList[i].adjvex = i;
		G->adjList[i].next = NULL;//边表置为空表//
	}
	for (k = 0; k < G->numEdges; k++)
	{
		scanf("%d%d%d", &i, &j, &weight);//输入边上的顶点序号//
		x = i;
		y = j;
		e = (edgeNode*)malloc(sizeof(edgeNode));
		e->weight = weight;
		e->adjvex = y;
		if (G->adjList[x].next != NULL)
		{
			q = G->adjList[x].next;
			if (q->adjvex < e->adjvex) {
				while (q->next != NULL)
				{
					if (q->next->adjvex > e->adjvex)
						break;
					q = q->next;
				}
				e->next = q->next;
				q->next = e;
			}
			else {
				e->next = G->adjList[x].next;
				G->adjList[x].next = e;
			}
		}
		else {
			e->next = G->adjList[x].next;
			G->adjList[x].next = e;
		}
	}
}
void out(GraphAdjList *G)
{
	int i, j;
	edgeNode* p;
	for (i = 0; i < G->numVertexes; i++)
	{
		p = G->adjList[i].next;
		if (p == NULL)
			continue;
			printf("%d:", i);
		while (p != NULL) {
			printf("(%d,%d,%d)", i, p->adjvex, p->weight);
			p = p->next;
		}
		printf("\n");
	}
}
void del(GraphAdjList *G,int x,int y)
{
	edgeNode *p,*q;
	p = G->adjList[x].next;
	if (p->next == NULL && p->adjvex == y)
	{
		G->adjList[x].next = NULL;
		return;
	}
	if (p->adjvex == y) {
		G->adjList[x].next = p->next;
		return;
	}
	while (p!= NULL)
	{
		q = p;
		p = p->next;
		if (p->adjvex == y)
		{
			q->next = p->next;
			return;
		}
	}
}
