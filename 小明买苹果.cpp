#include <iostream>
#include<cstring>
#include<cstdlib>
using namespace std;
void out(char str[], int start, int end, int *flags);
int n,k=0;
char OUT[100000][16];
int cmp(const void*a, const void *b)
{
	return strcmp((char*)a, (char*)b);
}
int main()
{
	char str[16];
	int count = 0;
	scanf("%d", &n);
	for (char i = 'a'; i < 'a' + n; i++)
	{
		str[count++] = i;
	}
	str[count] = '\0';
	int flags[15] = { 0 };
	printf("{}\n");
	out(str, 0, n, flags);
	qsort(OUT,k,sizeof(OUT[0]), cmp);
	for (int i = 0; i < k-1; i++)
	{
		/*int l = 0;
		printf("{");
		while (OUT[i][l] != '\0') {
			printf("%c,", OUT[i][l]);
			l++;
		}
		printf("}\n");*/
		int length = strlen(OUT[i]);
		printf("{");
		for (int l = 0; l < length - 1; l++)
		{
			printf("%c,",OUT[i][l]);
		}
		printf("%c}\n", OUT[i][length - 1]);
	}
	int l_ength = strlen(OUT[k - 1]);
	printf("{");
	for (int l = 0; l < l_ength - 1; l++)
	{
		printf("%c,", OUT[k-1][l]);
	}
	printf("%c}", OUT[k-1][l_ength - 1]);
	return 0;
}
void out(char str[], int start, int end, int *flags)
{
	char x[16] = { 0 };
	int count = 0;
	if (start == end)
	{
		int i = 0;
		for (; i < end; i++)
		{
			if (flags[i])
			{
				int m = 0;
				for (int p = 0; p < n; p++)
				{
					if (flags[p] == 1)
						m++;
				}

				x[count++] = str[i];
				if (count == m)
				{
					x[count] = '\0';
					strcpy(OUT[k++], x);
				}
				
			}
			
		}
		return;
	}
	else
	{
		flags[start] = 0;
		out(str, start + 1, end, flags);
		flags[start] = 1;
		out(str, start + 1, end, flags);

	}
}