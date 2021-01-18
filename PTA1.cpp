#include<stdio.h>
#include<stdlib.h>
typedef struct Node
{
	int data;
	struct Node *next;
}Node, *linkedlist;
int size;
linkedlist create(linkedlist head, int count)
{
	head = (linkedlist)malloc(sizeof(Node));
	linkedlist node = NULL;
	linkedlist end = NULL;
	end = head;
	int element;
	for (int i = 0; i < count; i++) {
		node = (linkedlist)malloc(sizeof(Node));
		scanf("%d", &element);
		node->data = element;
		end->next = node;
		end = node;
	}

	end->next = NULL;
	size = count;
	return head;
}
void insert(linkedlist head, int k, int d)
{
	if (k > size) { return; }
	int j = 0;
	Node *p, *s;
	p = head;
	while (p&&j < k)
	{
		p = p->next;
		++j;
	}
	s = (linkedlist)malloc(sizeof(Node));
	s->data = d;
	s->next = p->next;
	p->next = s;
	++size;
}
void Delete(linkedlist head, int k)
{
	int j = 1;
	if (k == 0 || k > size) { return; }
	Node*p, *s, *t;
	p = head;
	while (p&&j < k)
	{
		p = p->next;
		++j;
	}
	s = p->next;
	t = s->next;
	p->next = t;
	s->next = NULL;
	free(s);
}
void output(linkedlist head) {
	linkedlist tem = head;
	while (tem->next != NULL) {
		tem = tem->next;
		printf("%d ", tem->data);
	}
}
int main()
{
	int length, number, k, d, flag;
	linkedlist head = (linkedlist)malloc(sizeof(Node));
	scanf("%d", &length);
	head = create(head, length);
	scanf("%d", &number);
	for (int i = 0; i < number; i++) {
		scanf("%d", &flag);
		if (flag == 0) {
			scanf("%d %d", &k, &d);
			insert(head, k, d);
		}
		else {
			scanf("%d", &k);
			Delete(head, k);
		}
	}
	output(head);
	return 0;
}
