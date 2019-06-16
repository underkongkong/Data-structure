#include<iostream>
using namespace std;

class Node {
public:
	Node(int i):data(i),next(0){}
	int data;
	Node *next;
};
Node * creatList(int n) {
	Node *first=NULL, *p=NULL; 
	for (int i = 1; i <= n; i++)
	{
		if (i == 1) p = first = new Node(i);
		else {
			Node*q = new Node(i);
			p->next = q;
			p = p->next;
		}
	}
	p->next = first;
	return first;
}

void Josephus(Node * first, int k)
{
	Node*p = first;
	Node *q = p->next;
	int i = 1;
	while (p != q) {
		if (i != k) {
			p = q;
			q = p->next;
			i++;
		}
		else {
			cout << p->data << " ";
			p->data = q->data;
			p->next = q->next;
			delete q;
			q = p->next;
			i = 1;
		}
	}
	cout << p->data << endl;
}
int main()
{
	int n, k;
	cin >> n >> k;
	Node*first = creatList(n);
	Josephus(first, k);
	return 0;
}