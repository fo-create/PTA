#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int N;//字符数-叶子数//
int M;//总结点数//
typedef struct
{
	char ch;
	int weight;
	int parent;
	int lchild;
	int rchild;
}hufmtree;//哈夫曼树的结构体//
typedef struct
{
	char str[26];
	int start;
	char ch;
}Code;//计算编码//
void huffmancode(Code code[], hufmtree tree[]);
void create(hufmtree tree[], int quanzhi[], char data[]);
void yima(hufmtree tree[], char b[]);
//void select(hufmtree tree[], struct node number[]);
void bubble(hufmtree tree[], struct node number[]);
char data[5001];//输入的字符串//
char str[26];//存放译码字符//
int count1 = 0;//str的计数变量//
int count = 0;//字符数组计数//
int count2 = 0;
bool flag=0;//输出标志量//
char b[2][100];//待译码的01序列//
int quanzhi[27] = { 0 };//权值表//
struct node {
	char val;
	int weg;
	char out[100];
};
int main()
{
	struct node number[26];
	hufmtree tree[100];//哈夫曼树//
	Code code[26];
	scanf("%s", data);
	for (int a = 0; a < 2; a++)
	{
		scanf("%s", b[a]);
	}
	int i, j;
		int sum=0;
	int length = strlen(data);//未压缩前长度//
	//计算权值，并去除重复元素//
	for (int i = 0; i < length; i++)
	{
		if (quanzhi[data[i] - 'a'] == 0)
			data[count++] = data[i];
		quanzhi[data[i]-'a']++;//遍历一遍输入字符串，计算各个字符的权值//	
	}
	data[count] = '\0';
	N = count;
	M = 2 * N - 1;//全局变量赋值//
	create(tree, quanzhi, data);
	huffmancode(code, tree);
	printf("%d ", length);
	for (i = 0; i < N; i++)
	{
		sum +=(N-code[i].start)*tree[i].weight;

	}
	if (sum % 8 == 0)
	{
		printf("%d\n", sum / 8);
	}
	else
		printf("%d\n", sum / 8 + 1);
	for ( i = 0; i < N; i++)
	{
		/*printf("%c: ", code[i].ch);*/
		number[i].val = code[i].ch;
		number[i].weg = tree[i].weight;
		for (j = code[i].start; j < N; j++)
			/*printf("%c", code[i].str[j]);*/
		{
			number[i].out[count2++] = code[i].str[j];
		}
		number[i].out[count2] = '\0';
		count2 = 0;
		/*printf("\n");*/
	}
	bubble(tree, number);
	for (i = 0; i < N; i++)
	{
		printf("%c:%s\n", number[i].val,number[i].out);

	}
	for (int a = 0; a < 2; a++)
	{
		yima(tree, b[a]);
		if (!flag) {
			printf("%s\n", str);
			count1 = 0;
		}
		else
		{
			printf("INVALID\n");
			count1 = 0;
		}
	}
	return 0;
}
void create(hufmtree tree[],int quanzhi[],char data[])
{
	int i, j, p1, p2, x, y;//p1,p2分别记住每次合并时权值最小和次小的两个根结点的下标//
	for (i = 0; i < M; i++)
	{
		tree[i].parent = 0;
		tree[i].lchild = -1;
		tree[i].rchild = -1;
		tree[i].weight = 0;
	}//初始化//
	for (i = 0; i < N; i++)//读入结点的字符及权值//
	{
		tree[i].ch = data[i];
		tree[i].weight = quanzhi[data[i]-'a'];
	}	
	for (i = N; i < M; i++)//开始合并结点//
	{
		x= 5000; 
		y = 5000;
		p1 = 0; p2 = 0;
		for (j = 0; j < i; j++)
			if(tree[j].parent==0)
				if (tree[j].weight < x)
				{
					y= x;
					x = tree[j].weight;
					p2 = p1;
					p1 = j;
				}
				else if (tree[j].weight < y)
					{
						y = tree[j].weight;
						p2 = j;
					}
		tree[p1].parent = i;
		tree[p2].parent = i;
		tree[i].lchild = p1;
		tree[i].rchild = p2;
		tree[i].weight = tree[p1].weight + tree[p2].weight;
	}
}
void huffmancode(Code code[], hufmtree tree[])
{
	int i, c, p;
	Code cd;
	for (i = 0; i < N; i++)
	{
		cd.start = N;
		cd.ch = tree[i].ch;
		c = i;
		p = tree[i].parent;

		while (p != 0)
		{
			cd.start--;
			if (tree[p].lchild == c)
				cd.str[cd.start] = '0';
			else
				cd.str[cd.start] = '1';
			c = p;
			p = tree[p].parent;
		}
		//cd.start++;//指向最开始字符//
		code[i] = cd;
	}
}
void yima(hufmtree tree[],char b[])
{
	int i, j = 0;
	i = M - 1;
	while (b[j] != '\0')
	{
		if (b[j] == '0')
			i = tree[i].lchild;
		else
			i = tree[i].rchild;
		if (tree[i].lchild == -1)
		{
			str[count1++] = tree[i].ch;
			str[count1] = '\0';
			if (b[j+1] == '\0')
				break;
			i = M - 1;
		}
		j++;
	}
	if (tree[i].lchild != -1 && b[j] == '\0')
	{
		flag = 1;
	}
}
void bubble(hufmtree tree[], struct node number[])//冒泡排序//
{
	int i, j,flag;
	struct node temp;
	for (i = 0; i < N-1; i++)
	{
		flag = 1;//定义标记量，满足条件则跳出循环//
		for (j = 0; j < N - 1; j++)
		{
			if (number[j].weg >number[j+1].weg)
			{
				temp = number[j];
				number[j] = number[j + 1];
				number[j + 1] = temp;
				flag = 0;
			}
		}
		if (flag)
			break;
	}
}
