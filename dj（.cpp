#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
#define max 20000
#define INF 99999
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
int str[2001];
int count1 = 0;
int locate(GraphAdjList *G, int v);
void CreateALGraph(GraphAdjList *G);
void dijkstra(GraphAdjList *G, int v);
void Dispath(GraphAdjList* g, int dist[], int path[], int S[], int v);
int main()
{
	GraphAdjList *G = new GraphAdjList;
	CreateALGraph(G);
	dijkstra(G, 0);
	return 0;
}
int locate(GraphAdjList *G, int v)//查找顶点在顺序表中位置//
{
	for (int i = 0; i < G->numVertexes; i++)
	{
		if (G->adjList[i].adjvex == v)
			return i;
	}
	return 0;
}
void CreateALGraph(GraphAdjList *G)
{
	int i, j, k, weight;
	int x, y;//弧头，弧尾顶点//
	edgeNode *e;
	scanf("%d%d", &G->numVertexes, &G->numEdges);//输入顶点数和边数//
	for (i = 0; i < G->numVertexes; i++)
	{
		G->adjList[i].adjvex = i;
		G->adjList[i].next = NULL;//边表置为空表//
		G->adjList[i].count = INF;
	}
	for (k = 0; k < G->numEdges; k++)
	{
		scanf("%d%d%d", &i, &j, &weight);//输入边上的顶点序号//
		str[count1++] = i;
		str[count1++] = j;
		x = locate(G, i);
		y = locate(G, j);
		e = (edgeNode*)malloc(sizeof(edgeNode));
		e->weight = weight;
		e->adjvex = y;
		e->next = G->adjList[x].next;
		G->adjList[x].next = e;
	}
}
void dijkstra(GraphAdjList *G, int v)
{
	int dist[max], s[max];
	int path[max];
	int i, j, u, k, min, x, y;
	for (i = 0; i < G->numVertexes; i++)
	{
		dist[i] = INF;
		s[i] = 0;
		path[i] = -1;
	}
	dist[v] = 0;
	s[v] = 1;
	G->adjList[v].count = 0;
	edgeNode *p;
	p = (edgeNode*)malloc(sizeof(edgeNode));
	p = G->adjList[v].next;
	u = v;
	for (j = 0; j < G->numVertexes; j++)
	{
		while (p != NULL)
		{
			k = p->adjvex;
			if (s[k] != 1 && dist[u] + p->weight <= dist[k])
			{
				if (dist[u] + p->weight < dist[k]) {
					dist[k] = dist[u] + p->weight;
					G->adjList[k].count = G->adjList[u].count + 1;
					path[k] = u;
				}
				if (dist[u] + p->weight == dist[k])
				{
					dist[k] = dist[u] + p->weight;
					if (G->adjList[k].count > G->adjList[u].count + 1)
						path[k] = u;
				}
			}
			p = p->next;
		}
		min = INF;
		for (i = 0; i < count1; i++)
			if (dist[str[i]] < min&&s[str[i]] == 0)
			{
				min = dist[str[i]];
				u = str[i];
			}
		s[u] = 1;
		p = G->adjList[u].next;
	}
	Dispath(G, dist, path, s, v);
}
void Dispath(GraphAdjList* g, int dist[], int path[], int S[], int v)
{
	int i, j, k;
	int apath[max], d;//存放一条最短路径（逆向）及其顶点个数//
	for (i = 0; i < g->numVertexes; i++)//循环输出v到i的路径//
		if (S[i] == 1 && i != v)
		{
			d = 0; apath[d] = i;
			k = path[i];
			if (k == -1)
				return;
			else
			{
				while (k != v)
				{
					d++;
					apath[d] = k;
					k = path[k];
				}
				d++;
				apath[d] = v;
				printf("%d->", apath[d]);
				for (j = d - 1; j > 0; j--)
					printf("%d->", apath[j]);
				printf("%d", apath[0]);
				printf("\n");
			}
		}
}