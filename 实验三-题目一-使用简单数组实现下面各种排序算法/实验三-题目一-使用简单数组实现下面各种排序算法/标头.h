#include<iostream>
using namespace std;

template <class T>
struct Node
{
	T data;
	struct Node<T>*next;
};
template <class T>
class LinkList
{
public:
	LinkList() { front = new Node<T>; front->next = NULL; }
	LinkList(T a[], int n);
	~LinkList();
	Node<T> * front;
};
template<class T>
LinkList<T>::LinkList(T a[], int n)
{
	front = new Node<T>;
	front->next = NULL;
	for (int i = n - 1; i >= 0; i--)
	{
		Node<T>*s = new Node<T>;
		s->data = a[i];
		s->next = front->next;
		front->next = s;
	}
}
template<class T>
LinkList<T>::~LinkList()
{
	Node<T>*p = front;
	while (p)
	{
		front = p;
		p = p->next;
		delete front;
	}
}
