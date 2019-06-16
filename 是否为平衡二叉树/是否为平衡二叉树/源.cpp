#include<iostream>
#include<algorithm>
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
	BiTree(T data[], int n);
	bool IsBalanced(BiNode<T> *R, int&depth);
	bool IsBalanced(BiNode<T>* pRoot);
	~BiTree();
};
template<class T>
void BiTree<T>::Create(BiNode<T>*&R, T data[], int i, int n)
{
	if (i <= n&&data[i - 1]!='0')
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
bool BiTree<T>::IsBalanced(BiNode<T> *R,int &height)
{
	if (!R) 
	{
		height = 0;
		return true;
	}
	int nLeftDepth;
	int nRightDepth ;
	bool bLeft=IsBalanced(R->lchild, nLeftDepth);
	bool bRight = IsBalanced(R->rchild, nRightDepth);

	if (bLeft && bRight)
	{
		int diff = nRightDepth - nLeftDepth;
		if (diff <= 1 && diff >= -1)
		{
			height = 1 + (nLeftDepth > nRightDepth ? nLeftDepth : nRightDepth);
			return true;
		}
	}

	return false;
}
template<class T>
bool BiTree<T>::IsBalanced(BiNode<T>* pRoot)
{
	int depth = 0;
	return IsBalanced(pRoot, depth);
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
	int n = 0;
	cin >> a;
	n = a.length();
	char arr[50];
	strcpy(arr, a.c_str());
	BiTree<char> tree(arr, n);
	if (tree.IsBalanced(tree.root))
		cout << "True";
	else
		cout << "False";
	system("pause");
	return 0;
}