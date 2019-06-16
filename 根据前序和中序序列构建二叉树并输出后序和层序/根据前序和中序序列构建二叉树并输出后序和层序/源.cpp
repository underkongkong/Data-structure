#include<iostream>
#include<string>
#include<cstring>
#include<string.h>
#include<vector>
using namespace std;
template<class T>
struct BiNode {
	char data;
	BiNode<T>*lchild;
	BiNode<T>*rchild;
};
BiNode<char>* ConstructCore(char* startPerorder, char* endPreorder, char* startInorder, char* endInorder)
{
	//先序第一个为根节点  
	int rootValue = startPerorder[0];
	BiNode<char>* root = new BiNode<char>;
	root->data = rootValue;
	root->lchild= root->rchild = NULL;

	//递归退出条件  
	if (startPerorder == endPreorder)
	{
		if (startInorder == endInorder && *startPerorder == *endInorder)
			return root;
		else
			throw std::exception("error"); //异常处理  
	}

	// 在中序遍历中找到根节点的值  
	char* rootInorder = startInorder;
	while (rootInorder <= endInorder && *rootInorder != rootValue)
		++rootInorder;

	//异常处理  
	if (rootInorder == endInorder && *rootInorder != rootValue)
	{
		throw std::exception("error");
	}
	int leftLength = rootInorder - startInorder;
	char* leftPreorderEnd = startPerorder + leftLength;
	if (leftLength > 0)
	{
		//构建左子树  
		root->lchild = ConstructCore(startPerorder + 1, leftPreorderEnd, startInorder, rootInorder - 1);
	}
	if (leftLength < endPreorder - startPerorder)
	{
		//构建右子树  
		root->rchild = ConstructCore(leftPreorderEnd + 1, endPreorder, rootInorder + 1, endInorder);
	}

	return root;
}
BiNode<char>*place(char*p1,char*p2,int n)
{
	if (p1 == NULL || p2 == NULL || n <= 0)
		return NULL;

	return ConstructCore(p1, p1 + n - 1, p2, p2 + n - 1);
}
template<class T>
void PostOrder(BiNode<T>*R)
{
	if (R != NULL)
	{
		PostOrder(R->lchild);
		PostOrder(R->rchild);
		cout << R->data;
	}
}
template<class T>
void LevelOrder(BiNode<T>*R)
{
	BiNode<T>*queue[100];
	int f = 0; int r = 0;
	if (R != NULL) queue[++r] = R;
	while (f != r)
	{
		BiNode<T>*p = queue[++f];
		if (p->data != '0')cout << p->data;
		if (p->lchild != NULL) queue[++r] = p->lchild;
		if (p->rchild != NULL) queue[++r] = p->rchild;
	}
}
template<class T>
void Release(BiNode<T>*R)
{
	if (R != NULL)
	{
		Release(R->lchild);
		Release(R->rchild);
		delete R;
	}
}


int main()
{
	string t1;
	string t2;
	cin >> t1 >> t2;
	int n1 = t1.length();
	int n2 = t2.length();
	if (n1 != n2)
	{
		cout << "error";
		return 0;
	}
	char p1[100];
	char p2[100];
	strcpy_s(p1, t1.c_str());
	strcpy_s(p2, t2.c_str());
	BiNode<char>* pRoot = place(p1, p2, n1);
	PostOrder<char>(pRoot);
	cout << endl;
	LevelOrder<char>(pRoot);
	Release(pRoot);
	system("pause");
	return 0;
}