#include<stdio.h>
#include<stdlib.h>
#include <malloc.h>
#define MAX 20000
typedef struct queue
{
	int head;
	int tail;
	int data[MAX];
}Queue;
Queue *create()
{
	Queue *Q;
	if (Q = (Queue*)malloc(sizeof(struct queue)))
	{
		Q->head = 0;
		Q->tail = 0;
		return Q;
	}
	else
	{
		return NULL;
	}
}
int isempty(Queue*Q)
{
	int tmp;
	tmp = Q->head == Q->tail;
	return(tmp);
}
void outqueue(Queue* Q)
{
	if (isempty(Q))
	{
		printf("invalid\n");
	}
	else {
		
		printf("%d\n", Q->data[Q->head++]);
	}

}
void inqueue(Queue*Q, int element)
{
	if (Q->tail == MAX)
	{
		return;
	}
	Q->data[Q->tail++] = element;
}
int main()
{
	Queue* Q = create();
	int number, flag, element;
	scanf("%d", &number);
	for (int i = 0; i < number; i++) {
		scanf("%d", &flag);
		if (flag == 1)
		{
			scanf("%d", &element);
			inqueue(Q, element);
		}
		else {
			outqueue(Q);
		}
	}
	return 0;
}
