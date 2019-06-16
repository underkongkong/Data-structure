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
	LinkList() { front = new Node<T>; front->next = NULL; }//�޲ι��캯��
	LinkList(T a[], int n); //�вι��캯����ʹ�ú���n��Ԫ�ص�����a��ʼ��������
	~LinkList();	//����
	void PrintList();    //��ӡ
	int GetLength() { return length; }     //��ȡ����
	void Merge(LinkList <T> &L);     //�ϲ�
	Node<T> *front;    //ͷָ��
private:
	int length;
};

template<class T>
LinkList<T>::LinkList(T a[], int n)
{
	length = n;
	front = new Node<T>;
	last = new Node<T>;
	Node<T>*r = front;
	for (int i = 0; i < n; i++)
	{
		r->next = new Node<T>;
		r = r->next;
		r->data = a[i];
		last = r->next;//last û��node
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

template<class T>
void LinkList<T>::PrintList()
{
	Node<T>*r = front;
	while (r->next != 0)
	{
		cout << r->data << " ";
		r = r->next;
	}
}
template<class T>
void LinkList<T>::Merge(LinkList<T>&L)
{
	int m, n, sumlength;
	m = GetLength();
	n = L.GetLength();
	sumlength = m + n;
	int * p = new int[sumlength];
	Node<T>*s = front->next;
	for (int i = 0; i < m; i++)
	{
		p[i] = s->data;
		s = s->next;
	}
	Node<T>*s1 = L.front->next;
	for (int i = 0; i < n; i++)
	{
		p[i + m] = s1->data;
		s = s->next;
	}
	for (int i = 0; i < sumlength; i++)
		cout << p[i];

}