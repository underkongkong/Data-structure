#include<iostream>
using namespace std;

template<class T>
struct Node
{
	T data;
	struct Node<T>* next;
};

template <class T>
class LinkList
{
public:
	LinkList() { front = new Node<T>; front->next = NULL; }//无参构造函数
	LinkList(T a[], int n); //有参构造函数，使用含有n个元素的数组a初始化单链表
	~LinkList();	//析构
	void PrintList();    //打印
	int GetLength() { return length; }     //获取长度
	void Merge(LinkList <T> &L);     //合并
	Node<T> *front;    //头指针
private:
	int length;
};