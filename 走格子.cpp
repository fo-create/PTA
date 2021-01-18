//#include<iostream>
//#include<cstdio>
//#include<cstdlib>
//#define max 101
//#define INF 9999
//using namespace std;
//typedef struct
//{
//	int x;
//	int y;
//}point;
//int dis[max][max], num[max][max];
//int row,line, p, q;
//int BFS(int x, int y);
//int main()
//{
//	scanf("%d%d", &row, &line);
//	for (int i = 0; i < row; i++)
//	{
//		for (int j = 0; j < line; j++)
//		{
//			dis[i][j] = INF;
//			scanf("%d", &num[i][j]);
//			if (num[i][j] == 3)
//			{
//				p = i; q = j;
//				dis[i][j] = 0;
//			}
//			
//		}
//	}
//	int result;
//	result = BFS(p, q);
//	if (result != INF)
//		printf("%d", result);
//	else
//		printf("unreachable");
//	return 0;
//}
//int BFS(int x, int y)
//{
//	point queue[101];
//	int front = 0, rear = 0;
//	int m, n;
//	rear = (rear + 1) % 101;
//	queue[rear].x = x;
//	queue[rear].y = y;
//	while (front != rear)
//	{
//		front = (front + 1) % 101;
//		point w = queue[front];
//		if (num[w.x][w.y] == 4)
//		{
//			return dis[w.x][w.y];
//		}
//		for (int i = -1; i <= 1; i++) {
//			for (int j = -1; j <= 1; j++)
//			{
//				if (i == 0 && j == 0 || i == 1 && j == 1 || i == -1 && j == 1 || i == 1 && j == -1 || i == -1 && j == -1)
//					continue;
//				m = w.x + i; n = w.y + j;
//				if (m >= 0 && m < row&&n >= 0 && n < line && num[m][n]!=1 && dis[m][n] == INF)
//				{
//					dis[m][n] = dis[w.x][w.y] + 1;
//					rear = (rear + 1) % 101;
//					queue[rear].x = m;
//					queue[rear].y = n;
//				}
//			}
//		}
//	}
//	return INF;
//}