#include<iostream>
using namespace std;
int node0 = 0;
int node1 = 0;
int node2 = 0;
template<class T> class BiNode
{
public:
	T data;
	BiNode<T>   *lch;
	BiNode<T>   *rch;
	BiNode():lch(NULL), rch(NULL) {};
};

template<class T> class BST
{
public:
	BST(T r[],int n);
	void Realease(BiNode<T>*R);
	~BST();
	//BiNode<T>*Search(BiNode<T>*R, T key);
	void InsertBST(BiNode<T>*&R, BiNode<T>*s);
	//void Delete(BiNode<T>*&R);
	//bool DeleteBST(BiNode<T>*&R, T key);
	void count(BiNode<T>*R);
	BiNode<T>*Root;
};

template<class T>
void BST<T>::InsertBST(BiNode<T>*&R, BiNode<T>*s)
//R为二叉排序根节点，s为待插入的新节点
{
	if (R == NULL)
		R = s;
	else if (s->data < R->data)
		InsertBST(R->lch, s);
	else
		InsertBST(R->rch, s);
}
template<class T>
BST<T>::BST(T r[], int n)
{
	Root = NULL;
	for (int i = 0; i < n; i++)
	{
		BiNode<T>*s = new BiNode<T>;
		s->data = r[i];
		s->lch = s->rch = NULL;
		InsertBST(Root, s);
	}
}
template<class T>
void BST<T>::Realease(BiNode<T>*R)
{
	if (R != NULL)
	{
		Realease(R->lch);
		Realease(R->rch);
		delete R;
	}
}

template<class T>
BST<T>::~BST()
{
	Realease(Root);
}
template<class T>
void BST<T>::count(BiNode<T>*R)
{
	if (R != NULL)
	{
		count(R->lch);
		count(R->rch);
		if (R->lch&&R->rch)
		{
			node2++;
		}
		else if (R->lch || R->rch)
		{
			node1++;
		}
		else
		{
			node0++;
		}
	}
}
int main()
{
	int n;
	cin >> n;
	int *p = new int[n];
	for (int i = 0; i < n; i++)
		cin >> p[i];
	BST<int> a(p,n);
	a.count(a.Root);
	cout << node0 << " " << node1 << " " << node2;
	system("pause");
	return 0;
}