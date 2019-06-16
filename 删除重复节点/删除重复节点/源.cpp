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
private:
	Node<T> *front;    //ͷָ��
	
};
template<class T>
LinkList<T>::LinkList(T a[], int n)
{
	length = n;
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
	int n;
	cin >> n;//1�ĳ���
	int*a = new int[n];//����1
	int*b = new int[n];
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	if (n == 0)
		cout << "empty";
	else
	{
		int j = 0, i = 0, k;
		while (i < n - 1)
		{
			if (a[i] != a[i + 1])
			{
				b[j++] = a[i];
				i++;
			}
			else
			{
				for (k = i + 1; k < n; k++)
				{
					if (a[k] != a[i]) break;
				}
				i = k;
			}
		}
		if (a[n - 2] != a[n - 1])
			b[j++] = a[n - 1];
		if (j != 0)
		{
			for (int i = 0; i < j - 1; i++)
				cout << b[i] << " ";
			cout << b[j - 1];
		}
		else
			cout << "empty";
	}
	system("pause");
	return 0;
}