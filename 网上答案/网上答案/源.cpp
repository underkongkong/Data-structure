#include <stdio.h>
#include <stdlib.h>
#include<iostream>
using namespace std;
typedef struct node {
	int data;
	struct node *next;
}LinkList;

/* 建立链表 */

LinkList *create_link(int m)
{
	LinkList *head, *s, *p;
	int i;
	head = (LinkList *)malloc(sizeof(LinkList));
	head->next = NULL;
	p = head;
	for (i = 0; i<m; i++) {
		s = (LinkList *)malloc(sizeof(LinkList));
		if (s == NULL) {
			printf("failed.\n");
			exit(0);
		}
		cin>>s->data;
		s->next = NULL;
		p->next = s;
		p = s;

	}

	return head;
}

/* 2个非递减的链表合并一一个非递增的链表 */

LinkList *add_link(LinkList *head1, LinkList *head2, LinkList *head)
{
	LinkList *p1, *p2, *q;
	p1 = head1->next;
	p2 = head2->next;
	head = q = head1;
	q->next = NULL;
	while (p1&&p2) {
		if (p1->data <= p2->data) {
			q = p1;
			p1 = p1->next;
		}
		else {
			q = p2;
			p2 = p2->next;
		}
		q->next = head1->next;
		head1->next = q;
	}
	while (p1)
	{
		q = p1;
		p1 = p1->next;
		q->next = head1->next;
		head1->next = q;
	}
	while (p2)
	{
		q = p2;
		p2 = p2->next;
		q->next = head1->next;
		head1->next = q;
	}

	return head;

}

/* 打印链表 */

void print_link(LinkList *head)
{
	LinkList *p;

	p = head->next;
	if (!p) {
		printf("Link is NULL.\n");
		exit(0);
	}

	while (p) {
		printf("%d ", p->data);
		p = p->next;
	}

}

int main(void)
{
	LinkList *head, *head1, *head2;

	int m, n;
	cin>>m;
	head = create_link(m);
	cin>>n;
	head1 = create_link(n);
	head2 = add_link(head, head1, head2);
	print_link(head2);
	getchar();
	getchar();
	return 0;
}