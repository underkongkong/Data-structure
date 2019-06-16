#include<iostream>  
#include <exception> 
#include<string>
#include<cstring>
#include<string.h>
using namespace std;
struct node
{
	char value;
	node* left;
	node* right;
	node(int v) :value(v), left(NULL), right(NULL) {}
};

node* Build_Tree(char* prec, char* inorder, int len)
{
	if (!prec || !inorder || len <= 0)
	{
		cout << "error" << endl;
		system("pause");
		return 0;
	}
	//步骤1:新建根结点  
	node* root = new node(prec[0]);
	//步骤2:在中序遍历中找到根结点索引，分割左右子树  
	int SubTreeLen = 0;
	while (SubTreeLen < len && inorder[SubTreeLen] != prec[0])
		++SubTreeLen;
	if (SubTreeLen == len)//越界了，说明两个数组无法构造出二叉树  
	{
		cout << "error" << endl;
		system("pause");
		exit(1);//暴力关机  
	}
	if (SubTreeLen > 0)
	{   //步骤2:重建左子树，并且将根结点root的left指向左子树  
		root->left = Build_Tree(prec + 1, inorder, SubTreeLen);
	}
	if (len - SubTreeLen - 1 > 0)
	{   //步骤2:重建右子树，并且将根结点root的left指向右子树  
		root->right = Build_Tree(prec + 1 + SubTreeLen, inorder + 1 + SubTreeLen, len - SubTreeLen - 1);
	}
	return root;
}

void level_tree_walk(node* z)
{
	node*queue[100];
	int f = 0; int r = 0;
	if (z != NULL) queue[++r] = z;
	while (f != r)
	{
		node*p = queue[++f];
		if (p->value != '0')cout << p->value;
		if (p->left != NULL) queue[++r] = p->left;
		if (p->right != NULL) queue[++r] = p->right;
	}
}

void postorder_tree_walk(node* z)
{
	if (!z)
		return;
	postorder_tree_walk(z->left);
	postorder_tree_walk(z->right);
	cout << z->value;
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
		system("pause");
		return 0;
	}
	char p1[100];
	char p2[100];
	strcpy_s(p1, t1.c_str());
	strcpy_s(p2, t2.c_str());
	node* root = Build_Tree(p1, p2, n1);
	postorder_tree_walk(root);
	cout << endl;
	level_tree_walk(root);
	system("pause");
	return 0;
}