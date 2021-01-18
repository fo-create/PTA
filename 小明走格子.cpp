////2 5 3
////15 4
//#include<stdio.h>
//int out(int number);
//int data[100];
//int main()
//{
//	int n;//操作数//
//	int number;//格子数//
//	/*scanf("%d", &n);*/
//	scanf("%d", &number);
//	data[100] = { 0 };
//	int sum=out(number);
//	printf("%d", sum);
//	return 0;
//}
//int out(int number)
//{
//	if (number == 1)
//		return 1;
//	else if (number == 2)
//		return 2;
//	else if (number == 3)
//		return 4;
//	else if (number == 4)
//		return 8;
//	else
//		data[number]= out(number - 1) + out(number - 2) + out(number - 3) + out(number - 4);
//	return data[number];
//}