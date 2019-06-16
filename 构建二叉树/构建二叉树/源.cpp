#include<iostream>
#include<string>
#include<cstring>
#include<string.h>
using namespace std;
template<class T>struct BiNode
{
	T data;
	BiNode<T>*lchild;
	BiNode<T>*rchild;
};
template<class T> class BiTree
{
private:
	void Create(BiNode<T>*&R, T data[], int i, int n);
	void Release(BiNode<T>*R);
public:
	BiNode<T>* root;
	void PreOrder(BiNode<T>*R);
	void LevelOrder(BiNode<T>*R);
	BiTree(T data[], int n);
	~BiTree();
};

template<class T>
void BiTree<T>::Create(BiNode<T>*&R, T data[], int i, int n)
{
	if (i <= n&&data[i - 1])
	{
		R = new BiNode<T>;
		R->data = data[i - 1];
		Create(R->lchild, data, 2 * i, n);
		Create(R->rchild, data, 2 * i + 1, n);
	}
	else R = NULL;
}

template<class T>
BiTree<T>::BiTree(T data[], int n)
{
	Create(root, data, 1, n);
}

template<class T>
void BiTree<T>::PreOrder(BiNode<T>*R)
{
	BiNode<T>*S[100];
	int top = -1;
	while ((top != -1) || (R != NULL))
	{
		if (R != NULL)
		{
			if(R->data!='0')
				cout << R->data;
			S[++top] = R;
			R = R->lchild;
		}
		else
		{
			R = S[top--];
			R = R->rchild;
		}
	}
}

template<class T>
void BiTree<T>::LevelOrder(BiNode<T>*R)
{
	BiNode<T>*queue[100];
	int f = 0; int r = 0;
	if (R != NULL) queue[++r] = R;
	while (f != r)
	{
		BiNode<T>*p = queue[++f];
		if(p->data!='0')cout << p->data;
		if (p->lchild != NULL) queue[++r] = p->lchild;
		if (p->rchild != NULL) queue[++r] = p->rchild;
	}
}

template<class T>
void BiTree<T>::Release(BiNode<T>*R)
{
	if (R != NULL)
	{
		Release(R->lchild);
		Release(R->rchild);
		delete R;
	}
}

template<class T>BiTree<T>::~BiTree()
{
	Release(root);
}
int main()
{
	string a;
	cin >> a;
	char x[100];
	int n = a.length();
	strcpy(x, a.c_str());
	BiTree<char> TREE(x, n);
	TREE.PreOrder(TREE.root);
	cout << endl;
	TREE.LevelOrder(TREE.root);
	system("pause");
	return 0;
}