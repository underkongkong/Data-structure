#include<iostream>
using namespace std;
template<class T>
struct Node
{
	T data;
	struct Node<T>* next;
};
template<class T>
class LinkStack
{
public:
	LinkStack() { top = NULL; }
	~LinkStack();
	void Push(T x);
	T Pop();
	T GetTop();
	bool Empty() { return NULL == top; }
private:
	struct Node<T>*top;
};
template<class T>
void LinkStack<T>::Push(T x)
{
	Node<T>* p = new Node<T>;
	p->data = x;
	p->next = top;
	top = p;
}
template<class T>
T LinkStack<T>::Pop()
{
	if (Empty())
		throw"downflow";
	T x = top->data;
	Node<T>*p = top;
	top = top->next;
	delete p;
	return x;
}
template<class T>
T LinkStack<T>::GetTop()
{
	return top->data;
}
template<class T>
LinkStack<T>::~LinkStack()
{
	while (top)
	{
		Node<T>*p = top;
		top = top->next;
		delete p;
	}
}