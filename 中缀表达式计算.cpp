#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAXSIZE 1000	
int calculate(char x, int y, int z);
bool flag = 0;
int main()
{
	char data[MAXSIZE];//����׺���ʽ���ַ�������//
	//����ջ���Ͳ�ͬ��Ϊ��﷽�㣬�ʲ���ʾ����ջ//
	int str1[MAXSIZE], y, z;//������ֵ�ջ���Լ��������ֵ�������//
	char str2[MAXSIZE],x;//����ַ���ջ�������ַ��ı���//
	int top1 = 0, top2 = 0;//ջ����־//
	int number;//������ֵ//
	scanf("%s", data);
	int length = strlen(data);
	for (int i = 0; i < length; i++)
	{
		if (data[i] >= '0'&&data[i] <= '9')
		{
			number = data[i] - '0';
			while (data[i + 1] != '\0')
			{
				if (data[i + 1] >= '0'&&data[i + 1] <= '9')
				{
					number = 10 * number + data[i + 1] - '0';
					i++;
				}
				else
					break;
			}
			str1[++top1] = number;
		}
		//�����������Ƕ�λ�������������������ջstr1//
		else if (data[i] == '+' || data[i] == '-')//���ȼ����//
		{
			if (top2 == 0)
			{
				str2[++top2] = data[i];
			}
			else
			{
				while (str2[top2] == '+' || str2[top2] == '-' || str2[top2] == '*' || str2[top2] == '/')
				{
					x = str2[top2--];
					y = str1[top1--];
					z = str1[top1--];
					str1[++top1] = calculate(x, y, z);
				}//��ʱ���ȼ���ͣ�һֱ��������//
				str2[++top2] = data[i];//�����꽫���ַ���ջstr2//
			}
		}
		else if (data[i] == '*' || data[i] == '/')
		{
			if (top2 == 0)
			{
				str2[++top2] = data[i];
			}
			else
			{
				while (str2[top2] == '*' || str2[top2] == '/')
				{
					x = str2[top2--];
					y = str1[top1--];
					z = str1[top1--];
					str1[++top1] = calculate(x, y, z);
				}
				str2[++top2] = data[i];
			}
		}
		else if (data[i] == '(')
		{
			str2[++top2] = data[i];//������ֱ����ջstr2//
		}
		else if (data[i] == ')')
		{
			while (str2[top2] != '(')
			{
				x = str2[top2--];
				y = str1[top1--];
				z = str1[top1--];
				str1[++top1] = calculate(x, y, z);
			}
			str2[top2--];//�����ŵ���//
			/*if (str1[top1] == 0 && str2[top2] == '/')
			{
				printf("ILLEGAL");
				break;
			}*/
		}
	}
	while (top2 != 0)
	{
		x = str2[top2--];
		y = str1[top1--];
		z = str1[top1--];
		str1[++top1] = calculate(x, y, z);
	}
	if (!flag)
	{
		printf("%d", str1[top1]);
	}
	return 0;
}
int calculate(char x, int y, int z)//���㺯��//
{
	switch (x)
	{
	case '+':
		return y + z;
		break;
	case '-':	
		return z-y;
			break;
	case '*':
		return y * z;
		break;
	case '/':
		if (y == 0)
		{
			flag = 1;
			printf("ILLEGAL");
			break;
		}
		
		return z / y;
		
			break;
	}
}