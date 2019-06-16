#include<iostream>
using namespace std;
template<class T>
struct Node
{
	T data;
	struct Node<T>*next;
};

template <class T>
class LinkList {
public:
	LinkList() { front = new Node<T>; front->next = NULL; }
};
