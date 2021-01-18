//#include<iostream>
//#define max 300
//#define INF 9999
//using namespace std;
//int floyd(int A[max][max], int n);
//int A[max][max];
//int main()
//{
//	int n,i,j;
//	scanf("%d", &n);
//	for (i = 0; i < n; i++)
//	{
//		for (j = 0; j < n; j++)
//		{
//			scanf("%d",&A[i][j]);
//		}
//	}
//	int num=floyd(A, n);
//	printf("%d", n*(n - 1)/2 - num);
//	return 0;
//}
//int floyd(int A[max][max],int n)
//{
//	int i, j, k,cnt=0;
//	
//		for (i = 0; i < n; i++)
//		{
//			for (j = i+1; j < n; j++)
//			{
//				for(k=0;k<n;k++)
//				if ((i!=k&&j!=k)&&A[i][j] == (A[i][k] + A[k][j]))
//				{
//					cnt++;
//					break;
//				}
//			}
//		}
//	return cnt;
//}