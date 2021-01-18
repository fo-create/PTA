#include<stdio.h>
#include<malloc.h>
#define MAXNUMBER 1000
typedef struct element//三元组元素//
{
	int row, col;//行，列序号//
	int val;//元素的值//
}object;
typedef struct
{
	object data[MAXNUMBER+1];
}sanyuanzu;
void input(sanyuanzu *p, int number);
void jian(sanyuanzu A, sanyuanzu B, sanyuanzu*C);
int m, n;
int main()
{
	scanf("%d %d", &m, &n);
	sanyuanzu A, B, *C;
	C = (sanyuanzu*)malloc(sizeof(sanyuanzu));
	input(&A, m);
	input(&B, n);
	jian(A, B, C);
	return 0;
}
void input(sanyuanzu *p,int number)
{
	for (int i = 1; i <=number; i++)
	{
		scanf("%d%d%d", &p->data[i].row, &p->data[i].col, &p->data[i].val);
	}
}
void jian(sanyuanzu A,sanyuanzu B,sanyuanzu*C)
{
	int x, y, z = 1;
	for (x = 1; x <= m; x++) {
		for (y = 1; y <= n; y++) {
			if (B.data[y].row == A.data[x].row&&B.data[y].col == A.data[x].col) {
				C->data[z].val = A.data[x].val - B.data[y].val;
				if (C->data[z].val == 0)
					continue;
				C->data[z].row = B.data[y].row;
				C->data[z].col = B.data[y].col;
				
				z++;
			}
		}
	}
	for (x = 1; x <= m; x++) {
		for (y = 1; y <= n  ; y++) {
			if (B.data[y].row == A.data[x].row&&B.data[y].col == A.data[x].col) {
				break;
			}
		}
		if (y - 1 == n) {
			C->data[z].row = A.data[y].row;
			C->data[z].col = A.data[y].col;
			C->data[z].val = A.data[y].val;
			z++;
		}
	}
	for (y = 1; y <= n; y++) {
		for (x = 1; x <= m; x++) {
			if (A.data[y].row == B.data[x].row&&A.data[y].col == B.data[x].col) {
				break;
			}
		}
		if (x - 1 == m) {
			C->data[z].row = B.data[y].row;
			C->data[z].col = B.data[y].col;
			C->data[z].val = -B.data[y].val;
			z++;
		}
	}

	for (int i = 1; i <= z - 1; i++)
	{
		printf("%d %d %d\n", C->data[i].row, C->data[i].col, C->data[i].val);
	}
}
