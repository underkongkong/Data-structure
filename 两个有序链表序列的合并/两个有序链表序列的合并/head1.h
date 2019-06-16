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