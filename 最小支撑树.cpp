//#include<iostream>
//#include<cstdio>
//#include<cstdlib>
//using namespace std;
//#define max 200
//#define INF 32767
////int str[max] = {0};
//int cnt = 0;
////bool flag = 0;
//typedef struct
//{
//	int edges[max][max];
//	int n, e;//顶点数，边数//
//}MGraph;
//typedef struct
//{
//	int head;//边的起始顶点//
//	int tail;//边的终止顶点//
//	int weight;//权值//
//}edge;
//typedef struct
//{
//	int rank;//结点的秩//
//	int parent;//结点的双亲//
//}UFSTree;
//int cmp(const void *a, const void *b) {
//	return (*(edge *)a).weight  - (*(edge *)b).weight;
//}
//void create(MGraph *g)
//{
//	int i, j, k, weight;
//	for (i = 0; i < g->n; i++)
//	{
//		for (j = 0; j < g->n; j++)
//		{
//			if (i == j)
//				g->edges[i][j] = 0;
//			else
//				g->edges[i][j] = INF;
//		}
//	}
//	for (k = 0; k < g->e; k++)
//	{
//		scanf("%d %d %d", &i, &j, &weight);
//		g->edges[i][j] = weight;
//		/*g->edges[j][i] = weight;*/
//	}
//}
//void insert(edge a[], int N)
//{
//	for (int i = 1; i < N; i++)
//	{
//		int j = i - 1;
//		edge temp = a[i];
//		while (j >= 0 && temp.weight < a[j].weight)
//		{
//			a[j + 1] = a[j--];
//		}
//		a[j + 1] = temp;
//	}
//}
//void make_set(UFSTree t[], int n)
//{
//	int i;
//	for (i = 0; i < n; i++)//顶点编号为0到n-1//
//	{
//		t[i].rank = 0;
//		t[i].parent = i;//双亲初始化指向自己//
//	}
//}
//int find(UFSTree t[], int x)
//{
//	if (x != t[x].parent)
//		return (find(t, t[x].parent));//双亲不是自己，递归查找//
//	else
//		return x;
//}
//void Union(UFSTree t[], int x, int y)
//{
//	x = find(t, x);
//	y = find(t, y);
//	if (t[x].rank > t[y].rank)
//		t[y].parent = x;//y的秩<=x，则将y连到x上//
//	else
//	{
//		t[x].parent = y;
//		if (t[x].rank == t[y].rank)
//			t[y].rank++;
//	}
//}
//void Kruskal_2(MGraph *G)
//{
//	int i, j, u1, v1, sn1, sn2,count, k,sum=0;
//	UFSTree t[max];
//	edge E[max];//存放所有边//
//	count = 0;//E数组下标从0开始//
//	for (i = 0; i < G->n; i++)
//	{
//		for (j = 0; j < G->n; j++)
//		{
//			if (G->edges[i][j] != 0 && G->edges[i][j] != INF)
//			{
//				E[count].head = i; E[count].tail = j; E[count].weight = G->edges[i][j];
//				count++;
//			}
//		}
//	}
//	//insert(E, G->e);/*对E数组按权值递增排序*/
//	qsort(E, G->e, sizeof(E[0]), cmp);
//	make_set(t, G->n);//初始化并查集树//
//	k = 1;//k表示当前构造树的第几条边，初值1//
//	j = 0;//j表示E中边的下标，初值为0//
//	while (k < G->n)//生成边数小于n//
//	{
//		if (j >= G->e)
//			break;
//		u1 = E[j].head;//取一条边的头尾顶点//
//		v1 = E[j].tail;
//		/*if (!((u1 >= 0 && u1 <= G->n - 1) && (v1 >= 0 && v1 <= G->n - 1)))
//		{
//			flag = 1;
//			cnt = k-1;
//			break;
//		}*/
//		sn1 = find(t, u1);
//		sn2 = find(t, v1);//得到两点所属集合编号//
//		if (sn1 != sn2)//不同集合，故是一条边//
//		{
//			/*printf("(%d,%d):%d\n", u1, v1, E[j].weight);*/
//			sum += E[j].weight;
//			cnt++;
//			k++;//边数增加//
//			Union(t, u1, v1);
//		}
//		j++;//扫描下一条边// 
//	}
//	if (j == G->e)
//		printf("There is no minimum spanning tree.\n");
//	else
//	printf("%d\n", sum);
//}
////void isok(int n,int m)
////{
////	if (cnt!= n-1)
////	{
////		printf("There is no minimum spanning tree.");
////		return;
////	}
////	for (int i = 0; i < n; i++)
////	{
////		if (str[i] == 0)
////		{
////			printf("There is no minimum spanning tree.");
////			break;
////		}
////	}
////}
//int main()
//{
//	MGraph *G = new MGraph;
//	while (scanf("%d%d", &G->n, &G->e) != EOF)
//	{
//		create(G);
//		Kruskal_2(G);
//	}
//	/*isok(G->n, G->e);*/
//	return 0;
//}
////4 5
////0 1 1
////0 3 1
////1 3 5
////1 2 1
////2 3 8
////6 10
////0 1 6
////0 3 5
////0 2 1
////1 2 5
////2 3 5
////1 4 3
////4 5 6
////5 3 2
////2 4 6
////2 5 4