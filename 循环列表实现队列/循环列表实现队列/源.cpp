#include<iostream>
using namespace std;
struct Node {
	Node(int *p, int i):data(p[i-1]), next(0) {}
	int data;
	Node * next;
};
class ListQueue
{
public:
	ListQueue(int a[], int n);
	~ListQueue();
	void POP();
	int getlength();
	int front() { return rear->next->data; }
private:
	Node * rear;
};
ListQueue::ListQueue(int a[], int n)
{
	Node*p;
	for (int i = 1; i <= n; i++)
	{
		if (i == 1)p = rear->next = new Node(a,i);
		else 
		{
			Node*q = new Node(a,i);
			p->next = q;
			p=p->next;
		}
	}
	p->next = rear->next;
}
ListQueue::~ListQueue()
{
	Node *curNode = NULL;
	while (rear != rear->next)        
	{
		curNode = rear->next;
		rear->next = curNode->next;
		delete curNode;
	}
}
void ListQueue::POP()
{
	int x = rear->next->data;
	Node*p = rear->next;
	Node*q = p->next;
	p->next = q->next;
	delete p;
	cout << x << " ";
}
int ListQueue::getlength()
{
	int count = 0;
	Node*s = rear->next->next;
	while (rear->next != s)
	{
		s = s->next;
		count++;
	}
	return count;
}
void solution(int *a, int n) {
	ListQueue x(a, n);
	cout << n << " " << x.front() << " ";
	x.POP();
	cout << x.getlength();
}
int main()
{
	int n;
	cin >> n;
	int *p = new int[n];
	for (int i = 0; i < n; i++)
		cin >> p[i];
	solution(p, n);
	system("pause");
	return 0;
}
