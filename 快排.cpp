//#include<stdio.h>
//int temp;
//void quicksort(int a[], int m, int n,int y);
//int main()
//{
//	int y;
//	int data[2000];
//	scanf("%d", &y);
//	for (int i = 0; i < y; i++)
//		scanf("%d", &data[i]);
//	quicksort(data, 0, y-1,y);
//	for (int m = 0; m < y; m++)
//		printf("%d ", data[m]);
//	return 0;
//}
//void quicksort(int a[], int m, int n,int y)
//{
//	int  i = m, j = n + 1, x = a[m];
//	if (m >= n)
//		return;
//	else 
//	{
//		while (i < j)
//		{
//			i = i + 1;
//			while (a[i] <= x)
//			{
//				i = i + 1;
//				if (i == n)
//					break;
//			}
//			j = j - 1;
//			while (a[j] > x)
//			{
//				j = j - 1;
//				if (j == m)
//					break;
//			}
//			if (i < j)
//			{
//				
//				temp = a[i];
//				a[i] = a[j];
//				a[j] = temp;
//			}
//
//		}
//		temp = a[j];
//		a[j] = a[m];
//		a[m] = temp;
//		for (int m = 0; m <y; m++)
//			printf("%d ", a[m]);
//		printf("\n");
//		quicksort(a, m, j - 1,y);
//		quicksort(a, j + 1, n,y);
//	}
//}