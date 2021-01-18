#include<iostream>
#include<cstdlib>
using namespace std;
#define max 10010
#define INF  0x3f3f3f3f
typedef struct EdgeNode {
	int adjvex;//����i���ڵĶ�����//
	struct EdgeNode *next;//��һ���߽��ָ����//
	int weight;//Ȩֵ//
}edgeNode, AdjList[max];//�߽������//
typedef struct {
	AdjList adjList;//�ڽӱ�//
	int numVertexes, numEdges;//������������//
}GraphAdjList;
typedef struct
{
	int sum;
	int Max;
	int pos;
}node;
node rightpath = { INF,0,0 };
int visited[10010] = { 0 };
void create(GraphAdjList *G, int numVertexes, int numEdges);
void find(GraphAdjList *G, node cur, int s, int t);
int main()
{
	GraphAdjList *G = new GraphAdjList;
	int n, s, t, m;
	scanf("%d%d%d%d", &n, &s, &t, &m);
	create(G, n, m);
	visited[s] = 1;
	find(G, { 0,0,0 }, s, t);
	printf("%d %d", rightpath.sum - rightpath.Max, rightpath.pos);
	return 0;
}
void create(GraphAdjList *G, int numVertexes, int numEdges)
{
	int i, j, k, weight;
	edgeNode *e;
	//���붥����Ϣ�����������//
	for (i = 1; i <= numVertexes; i++)
	{
		G->adjList[i].adjvex = i;
		G->adjList[i].next = NULL;//�߱���Ϊ�ձ�//
	}
	for (k = 0; k < numEdges; k++)
	{
		scanf("%d%d%d", &i, &j, &weight);//������ϵĶ������//
		e = (edgeNode*)malloc(sizeof(edgeNode));
		e->weight = weight;
		e->adjvex = j;
		e->next = G->adjList[i].next;
		G->adjList[i].next = e;
		e = (edgeNode*)malloc(sizeof(edgeNode));
		e->weight = weight;
		e->adjvex = i;
		e->next = G->adjList[j].next;
		G->adjList[j].next = e;

	}
}
void find(GraphAdjList *G, node now, int s, int t)
{
	edgeNode *p;
	p = G->adjList[s].next;
	if (s == t)
	{
		if (((now.sum - now.Max) < (rightpath.sum - rightpath.Max)) || ((now.sum - now.Max) == (rightpath.sum - rightpath.Max) && now.pos < rightpath.pos))
		{
			rightpath = { now.sum,now.Max,now.pos };
		}
	}
	else
	{
		while (p)
		{
			if (!visited[p->adjvex])
			{
				node cur;
				cur = { now.sum,now.Max,now.pos };
				visited[p->adjvex] = 1;
				if (p->weight > cur.Max)
				{
					cur.Max = p->weight;
					cur.pos = s;
				}
				else if (p->weight == cur.Max&&s < cur.pos)
				{
					cur.Max = p->weight;
					cur.pos = s;
				}
				cur.sum += p->weight;
				find(G, cur, p->adjvex, t);
				visited[p->adjvex] = 0;
			}
			p = p->next;
		}
	}
}