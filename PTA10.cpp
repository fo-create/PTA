#include<stdio.h>
void out(int data[], int begin, int end);
int MID(int data[], int begin, int end);
int qsort(int data[], int begin, int end);
void change(int *a, int *b);
int data[50001];
int main()
{
	int n,i;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &data[i]);
	}
	out(data, 0, n - 1);
	for (int i = 0; i < n; i++)
	{
		printf("%d ", data[i]);
	}
	return 0;
}
int MID(int data[], int begin, int end)
{
	int l, r,mid;
	l = begin;
	r = end;
	mid = begin + ((end - begin) / 2);
	if (data[l] < data[mid])
	{
		if (data[r] > data[mid])
			return mid;
		if (data[l] < data[r])
			return r;
		else
			return l;
	}
	else
	{
		if (data[r] < data[mid])
			return mid;
		if (data[r] > data[l])
			return l;
		else
			return r;
	}
}
int qsort(int data[], int begin, int end)
{
	int l, r,mid,temp;
	l = begin;
	r = end;
	mid = MID(data, begin, end);
	change(&data[mid], &data[end]);
	temp = data[end];
	while (l < r)
	{
		while (l < r&&data[l] <= temp)
		{
			l++;
		}
		while (l < r&&data[r] >= temp)
		{
			r--;
		}
		if (data[l] > data[r])
		{
			change(&data[l], &data[r]);
		}
	}
	change(&data[l], &data[end]);
	return l;
}
void change(int *a, int *b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}
void out(int data[], int begin, int end)
{
	if (begin < end)
	{
		int temp = qsort(data, begin, end);
		out(data, begin, temp - 1);
		out(data, temp + 1, end);
	}
}