//#include<stdio.h>
//typedef struct node{
//	int data[100] = {0};
//};
//struct node number[1000];
//bool flag;
//int main()
//{
//	int count = 1;
//	int n, m, q,a,b,c,d;
//	
//	scanf("%d %d %d", &n, &m, &q);
//	scanf("%d %d", &a, &b);
//	number[count].data[b] = b;
//	number[count].data[a] = a;//先存入第一组//
//	for (int i = 1; i < m; i++)
//	{
//		scanf("%d %d", &a, &b);
//		if (number[count].data[a] != 0 && number[count].data[b] == 0)
//		{
//			number[count].data[b] = b;
//		}
//		if (number[count].data[a] == 0 && number[count].data[b] != 0)
//		{
//			number[count].data[a] = a;
//		}
//		if (number[count].data[a] == 0 && number[count].data[b] == 0)
//		{
//			count++;
//			number[count].data[b] = b;
//			number[count].data[a] = a;
//		}
//	}
//	for (int i = 1; i <=q; i++)
//	{
//		scanf("%d %d", &c, &d);
//		for (int j = 1; j <= count; j++) {
//			if (number[j].data[c] != 0 && number[j].data[d] != 0)
//			{
//				flag = 1;
//				break;
//			}
//			else
//			{
//				flag = 0;
//				continue;
//			}
//		}
//		if (flag)
//			printf("In the same gang.\n");
//		else
//			printf("In different gangs.\n");
//	}
//	printf("%d", count);
//	return 0;
//}
