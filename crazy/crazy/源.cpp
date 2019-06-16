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
	~LinkList();    //析构
private:
	Node<T>*front;
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
int main()
{
	int n1, n2;
	cin >> n1;//1的长度
	int*a1 = new int[n1];//链表1
	for (int i = 0; i < n1; i++)
	{
		cin >> a1[i];
	}
	cin >> n2;//2的长度
	int*a2 = new int[n2];//链表2
	for (int i = 0; i < n2; i++)
	{
		cin >> a2[i];
	}
	int*a3 = new int[n1 + n2];//存放了1，2所有元素的链表三
	for (int i = 0; i < n1; i++)
	{
		a3[i] = a1[i];
	}
	for (int i = 0; i < n2; i++)
	{
		a3[n1 + i] = a2[i];
	}
	LinkList<int>L1(a1, n1);
	LinkList<int>L2(a2, n2);//初始化结束
	for (int i = 0; i < n1 + n2; i++)
	{
		for (int j = 0; j< n1 + n2 - i - 1; j++)
			if (a3[j] >= a3[j + 1])
			{
				int temp = a3[j];
				a3[j] = a3[j + 1];
				a3[j + 1] = temp;
			}
	}
	LinkList<int>L3(a3, n1 + n2);
	for (int i = 0; i < n1 + n2; i++)
	{
		cout << a3[i] << " ";
	}
	return 0;
}