#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAXSIZE 1000	
int calculate(char x, int y, int z);
bool flag = 0;
int main()
{
	char data[MAXSIZE];//存中缀表达式的字符型数组//
	//两个栈类型不同，为表达方便，故不显示创建栈//
	int str1[MAXSIZE], y, z;//存放数字的栈，以及接收数字的两变量//
	char str2[MAXSIZE],x;//存放字符的栈，接收字符的变量//
	int top1 = 0, top2 = 0;//栈顶标志//
	int number;//待存数值//
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
		//计算数可能是多位数，计算结果后存入数字栈str1//
		else if (data[i] == '+' || data[i] == '-')//优先级最低//
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
				}//此时优先级最低，一直进行运算//
				str2[++top2] = data[i];//运算完将此字符入栈str2//
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
			str2[++top2] = data[i];//左括号直接入栈str2//
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
			str2[top2--];//左括号弹出//
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
int calculate(char x, int y, int z)//计算函数//
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