#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
#define max 20000
#define INF 99999
bool flag;
typedef struct EdgeNode {
	int adjvex;//����i���ڵĶ�����//
	struct EdgeNode *next;//��һ���߽��ָ����//
	int weight;//Ȩֵ//
}edgeNode, AdjList[max];//�߽������//
typedef struct {
	AdjList adjList;//�ڽӱ�//
	int numVertexes, numEdges;//������������//
}GraphAdjList;
int locate(GraphAdjList *G, int v);
void CreateALGraph(GraphAdjList *G);
void out(GraphAdjList *G);
int main()
{
	GraphAdjList *G = new GraphAdjList;
	CreateALGraph(G);
	out(G);
	return 0;
}
int locate(GraphAdjList *G, int v)//���Ҷ�����˳�����λ��//
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
	int x, y;//��ͷ����β����//
	edgeNode *e,*q,*p;
	q = (edgeNode*)malloc(sizeof(edgeNode));
	p = (edgeNode*)malloc(sizeof(edgeNode));
	scanf("%d%d", &G->numVertexes, &G->numEdges);//���붥�����ͱ���//
	for (i = 0; i < G->numVertexes; i++)
	{
		G->adjList[i].adjvex = i;
		G->adjList[i].next = NULL;//�߱���Ϊ�ձ�//
	}
	for (k = 0; k < G->numEdges; k++)
	{
		scanf("%d%d%d", &i, &j, &weight);//������ϵĶ������//
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
