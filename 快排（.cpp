//#include<stdio.h>
//int data[1010];
//int n;
//int p(int a[], int l, int h);
//void quicksort(int a[], int s, int t);
//void change(int*a, int *b);
//int main()
//{
//
//	scanf("%d", &n);
//	for (int i = 1; i <= n; i++)
//		scanf("%d", &data[i]);
//	p(data, 1, n);
//	quicksort(data, 0, n);
//	return 0;
//}
//int p(int a[], int m, int n)
//{
//	int  i = m, j = n+1, x = a[i]; a[0] = a[i];
//	while (i < j)
//	{
//		while (i < j&&a[j] >= x)//从后往前找小于基准的值//
//		{
//			j--;
//		}
//		a[i] = a[j];
//		while (i < j&&a[i] <= x)//从前往后找大于等于基准的值//
//		{
//			i++;
//		}
//		a[j] = a[i];
//	}
//	a[i] = a[0];
//	
//	return i;
//}
//void change(int*a, int *b)
//{
//	int temp;
//	temp = *a;
//	*a = *b;
//	*b = temp;
//}
//void quicksort(int a[], int s, int t)
//{
//	if (s < t)
//	{
//		int k = p(a, s, t);
//		quicksort(a, s, k - 1);
//		quicksort(a, k + 1, t);
//	}
//}