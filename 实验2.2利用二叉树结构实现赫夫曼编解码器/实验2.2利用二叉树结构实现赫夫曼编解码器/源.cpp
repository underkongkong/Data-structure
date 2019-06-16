#include<iostream>
#include<iomanip>
using namespace std;
#define N 10
void reverse(char x[],int n)
{
	for (int i = 0; i < n / 2; i++)
	{
		char temp = x[i];
		x[i] = x[n - i - 1];
		x[n - i - 1] = temp;
	}
}

//哈夫曼树的节点结构
struct HNode    
{
	int weight;  //权值
	int parent;  //双亲指针
	int LChild;  //左孩子指针
	int RChild;  //右孩子指针
};

//编码表结点结构
struct HCode
{
	char data;
	char code[100];
};

//哈夫曼结构
class Huffman
{
private:
	HNode*HTree;                  //哈夫曼树
	HCode*HCodeTable;             //哈夫曼编码表
	char str[1024];               //输入的原始字符串
	char leaf[256];				  //叶子结点对应的字符
	int a[256];					  //记录每个出现的字符的个数
	
public:
	int n;                        //叶子结点个数
	void init();                  //初始化
	void CreateHTree();           //创建哈夫曼树
	void CreateCodeTable();               //创建编码表
	void SelectMin(int &x, int&y, int s, int e);   
	void Encode(char*d);                        //编码
	void Decode(char*s, char*d, int n);                        //解码
	void print1(int i, int m);                         //打印哈夫曼树
	void print2(int i, int m);
	//int count(int R);                     //求哈夫曼树的深度
	~Huffman();          
};


void Huffman::init()
{
	int nNum[256] = { 0 };
	int ch = cin.get();
	int i = 0;
	while ((ch != '\r') && (ch != '\n'))
	{
		nNum[ch]++;
		str[i++] = ch;
		ch = cin.get();
	}
	str[i] = '\0';
	n = 0;
	for (i = 0; i < 256; i++)
	{
		if (nNum[i] > 0)
		{
			leaf[n] = (char)i;
			a[n] = nNum[i];
			n++;
		}
	}

}


void Huffman::SelectMin(int &x, int&y, int s, int e)
{
	int i;
	for (i = s; i <= e; i++)
		if (HTree[i].parent == -1)
		{
			x = y = i; break;
		}
	for(;i<e;i++)
		if (HTree[i].parent == -1)
		{
			if (HTree[i].weight < HTree[x].weight)
			{
				y = x; x = i;
			}
			else if ((x == y) || (HTree[i].weight < HTree[y].weight))
				y = i;
		}
}

//创建哈夫曼树
void Huffman::CreateHTree()              //a[0..n-1]是权重数组
{
	HTree = new HNode[2 * n - 1];
	for (int i = 0; i < n; i++)
	{
		HTree[i].weight = a[i];
		HTree[i].LChild = HTree[i].RChild = HTree[i].parent = -1;
	}
	int x, y;
	for (int i = n; i < 2 * n - 1; i++)
	{
		SelectMin(x, y, 0, i);
		HTree[x].parent = HTree[y].parent = i;
		HTree[i].weight = HTree[x].weight + HTree[y].weight;
		HTree[i].LChild = x;
		HTree[i].RChild = y;
		HTree[i].parent = -1;
	}
}
//打印哈夫曼树
void Huffman::print1(int i, int m)
{
	if (HTree[i].LChild == -1)
		cout << setfill(' ') << setw(m + 1) << leaf[i] << setfill('-') << setw(N - m) << '\n';
	else 
	{
		cout << setfill(' ') << setw(m + 1) <<HTree[i].weight<< setfill('-') << setw(N - m) << '\n';
		print1(HTree[i].LChild, m + 1);
		print1(HTree[i].RChild, m + 1);
	}
}

//第二类打印法
void Huffman::print2(int i, int m) 
{

}

//创建编码表
void Huffman::CreateCodeTable()
{
	HCodeTable = new HCode[n];                         //生成编码表
	cout << "编码表为：" << endl;
	for (int i = 0; i < n; i++)
	{
		HCodeTable[i].data = leaf[i];
		int child = i;                                 //孩子结点编号
		int parent = HTree[i].parent;                  //父节点编号
		int k = 0;
		while (parent != -1)
		{
			if (child == HTree[parent].LChild)
				HCodeTable[i].code[k] = '0';
			else
				HCodeTable[i].code[k] = '1';
			k++;
			child = parent;
			parent = HTree[child].parent;
		}
		HCodeTable[i].code[k] = '\0';
		reverse(HCodeTable[i].code,k);
		cout <<" "<< HCodeTable[i].data<<":      ";
		for (int j = 0; j < k; j++)
			cout << HCodeTable[i].code[j];
		cout << endl;
	}
}
void Huffman::Encode(char*d)
{
	char*s = str;
	while (*s != '\0')
	{
		for (int j = 0; j < n; j++)
			if (*s == HCodeTable[j].data)
			{
				strcat(d, HCodeTable[j].code);
				break;
			}
		s++;
	}
}
void Huffman::Decode(char*s,char*d,int n)
{
	while (*s != '\0')
	{
		int parent = 2 * n - 2;
		while (HTree[parent].LChild != -1)
		{
			if (*s == '0')
				parent = HTree[parent].LChild;
			else
				parent = HTree[parent].RChild;
			s++;
		}
		*d = HCodeTable[parent].data;
		d++;
	}
}


Huffman::~Huffman()
{
	delete[]HTree;
	delete[]HCodeTable;
}
int main()
{
	Huffman ht1;
	cout << "                                          ****************************" << endl;
	cout << "                                          ***请输入你要编码的字符串***" << endl;
	cout << "                                          ****************************" << endl;
	ht1.init();
	cout << endl;
	cout << "                                             请输入你要进行的操作： " << endl;
	cout << "                       **********************************************************************" << endl;
	cout << "                       " << "*" << "     " << "1.创建哈夫曼树" << "                *              " << "2.创建编码表" << "     " << "*" << endl;
	cout << "                       " << "*" << "     " << "3.输出编码    " << "                *              " << "4.解码      " << "     " << "*" << endl;
	cout << "                       **********************************************************************" << endl;
	int x;
	int kb = 0;
	char c[1024] = { 0 };
	char d[1024] = { 0 };
	while (cin >> x)
	{
		if (x == 1)
		{
			cout << "                                             ****************************" << endl;
			cout << "                                             ********创建哈夫曼树********" << endl;
			cout << "                                             ****************************" << endl;
			ht1.CreateHTree();
			ht1.print1(2 * ht1.n - 2, 1);
			cout << endl;
			kb++;
		}
		else if (x == 2)
		{
			if (kb == 0)
				cout << "请先创建哈夫曼树";
			else 
			{
				cout << "                                             ****************************" << endl;
				cout << "                                             ******创建哈夫曼编码表******" << endl;
				cout << "                                             ****************************" << endl;
				ht1.CreateCodeTable();
				kb++;
			}
		}
		
		
		if (x == 3)
		{
			if (kb == 0)
				cout << "请先创建哈夫曼树";
			else if (kb == 1)
				cout << "请先创建哈夫曼编码表";
			else 
			{
				ht1.Encode(d);
				kb++;
				cout << "                                             ****************************" << endl;
				cout << "                                             ***********编码为***********" << endl;
				cout << "                                             ****************************" << endl;
				cout << d << endl;
			}
		}
		else if (x == 4)
		{
			if (kb == 0)
				cout << "请先创建哈夫曼树";
			else if (kb == 1)
				cout << "请先创建编码表";
			else if (kb == 2)
				cout << "请先编码";
			else
			{
				ht1.Decode(d, c, ht1.n);
				cout << "                                             ****************************" << endl;
				cout << "                                             ***********解码为***********" << endl;
				cout << "                                             ****************************" << endl;
				cout <<c<< endl;
			}
		}
		cout << endl;
		cout << "                                             请输入你要进行的操作： " << endl;
		cout << "                       **********************************************************************" << endl;
		cout << "                       " << "*" << "     " << "1.创建哈夫曼树" << "                *              " << "2.创建编码表" << "     " << "*" << endl;
		cout << "                       " << "*" << "     " << "3.输出编码    " << "                *              " << "4.解码      " << "     " << "*" << endl;
		cout << "                       **********************************************************************" << endl;
	}
	system("pause");
	return 0;
}