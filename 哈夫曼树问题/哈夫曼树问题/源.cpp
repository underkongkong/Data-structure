#include <iostream>
#include <stdlib.h>
using namespace std;
const int MaxValue = 10000;//初始设定的权值最大值
const int MaxBit = 4;//初始设定的最大编码位数
const int MaxN = 10;//初始设定的最大结点个数
struct HaffNode//哈夫曼树的结点结构
{
	int weight;//权值
	int flag;//标记
	int parent;//双亲结点下标
	int leftChild;//左孩子下标
	int rightChild;//右孩子下标
};
struct Code//存放哈夫曼编码的数据元素结构
{
	int bit[MaxBit];//数组
	int start;//编码的起始下标
	int weight;//字符的权值
};
void Haffman(int weight[], int n, HaffNode haffTree[])
//建立叶结点个数为n权值为weight的哈夫曼树haffTree
{
	int j, m1, m2, x1, x2;
	//哈夫曼树haffTree初始化。n个叶结点的哈夫曼树共有2n-1个结点
	for (int i = 0; i<2 * n - 1; i++)
	{
		if (i<n)
			haffTree[i].weight = weight[i];
		else
			haffTree[i].weight = 0;
		//注意这里没打else那{}，故无论是n个叶子节点还是n-1个非叶子节点都会进行下面4步的初始化
		haffTree[i].parent = 0;
		haffTree[i].flag = 0;
		haffTree[i].leftChild = -1;
		haffTree[i].rightChild = -1;
	}
	//构造哈夫曼树haffTree的n-1个非叶结点
	for (int i = 0; i<n - 1; i++)
	{
		m1 = m2 = MaxValue;//Maxvalue=10000;(就是一个相当大的数)
		x1 = x2 = 0;//x1、x2是用来保存最小的两个值在数组对应的下标

		for (j = 0; j<n + i; j++)//循环找出所有权重中，最小的二个值--morgan
		{
			if (haffTree[j].weight<m1&&haffTree[j].flag == 0)
			{
				m2 = m1;
				x2 = x1;
				m1 = haffTree[j].weight;
				x1 = j;
			}
			else if (haffTree[j].weight<m2&&haffTree[j].flag == 0)
			{
				m2 = haffTree[j].weight;
				x2 = j;
			}
		}
		//将找出的两棵权值最小的子树合并为一棵子树
		haffTree[x1].parent = n + i;
		haffTree[x2].parent = n + i;
		haffTree[x1].flag = 1;
		haffTree[x2].flag = 1;
		haffTree[n + i].weight = haffTree[x1].weight + haffTree[x2].weight;
		haffTree[n + i].leftChild = x1;
		haffTree[n + i].rightChild = x2;
	}
}
void HaffmanCode(HaffNode haffTree[], int n, Code haffCode[])
//由n个结点的哈夫曼树haffTree构造哈夫曼编码haffCode
{
	Code *cd = new Code;
	int child, parent;
	//求n个叶结点的哈夫曼编码
	for (int i = 0; i<n; i++)
	{
		//cd->start=n-1;//不等长编码的最后一位为n-1,
		cd->start = 0;//,----修改从0开始计数--morgan
		cd->weight = haffTree[i].weight;//取得编码对应权值的字符
		child = i;
		parent = haffTree[child].parent;
		//由叶结点向上直到根结点
		while (parent != 0)
		{
			if (haffTree[parent].leftChild == child)
				cd->bit[cd->start] = 0;//左孩子结点编码0
			else
				cd->bit[cd->start] = 1;//右孩子结点编码1
									   //cd->start--;
			cd->start++;//改成编码自增--morgan
			child = parent;
			parent = haffTree[child].parent;
		}
		//保存叶结点的编码和不等长编码的起始位
		//for(intj=cd->start+1;j<n;j++)
		for (int j = cd->start - 1; j >= 0; j--)//重新修改编码，从根节点开始计数--morgan
			haffCode[i].bit[cd->start - j - 1] = cd->bit[j];

		haffCode[i].start = cd->start;
		haffCode[i].weight = cd->weight;//保存编码对应的权值
	}
}
int main()
{
	int i, j, n , m = 0;
	cin >> n;
	int *weight=new int[n];
	for (int k = 0; k < n; k++)
		cin >> weight[k];
	HaffNode*myHaffTree = new HaffNode[2 * n - 1];
	Code*myHaffCode = new Code[n];
	if (n>MaxN)
	{
		cout << "定义的n越界，修改MaxN!" << endl;
		exit(0);
	}
	Haffman(weight, n, myHaffTree);
	HaffmanCode(myHaffTree, n, myHaffCode);
	//输出每个叶结点的哈夫曼编码
	for (i = 0; i<n; i++)
	{
		//cout << "Weight=" << myHaffCode[i].weight << "  Code=";
		//for(j=myHaffCode[i].start+1;j<n;j++)
		//for (j = 0; j<myHaffCode[i].start; j++)
			//cout << myHaffCode[i].bit[j];
		m = m + myHaffCode[i].weight*myHaffCode[i].start;
		//cout << endl;
	}
	//cout << "huffman's WPL is:";
	cout << m;
	cout << endl;
	system("pause");
	return 0;
}