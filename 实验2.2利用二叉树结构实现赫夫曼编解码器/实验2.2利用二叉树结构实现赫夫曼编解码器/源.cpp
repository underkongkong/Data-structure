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

//���������Ľڵ�ṹ
struct HNode    
{
	int weight;  //Ȩֵ
	int parent;  //˫��ָ��
	int LChild;  //����ָ��
	int RChild;  //�Һ���ָ��
};

//�������ṹ
struct HCode
{
	char data;
	char code[100];
};

//�������ṹ
class Huffman
{
private:
	HNode*HTree;                  //��������
	HCode*HCodeTable;             //�����������
	char str[1024];               //�����ԭʼ�ַ���
	char leaf[256];				  //Ҷ�ӽ���Ӧ���ַ�
	int a[256];					  //��¼ÿ�����ֵ��ַ��ĸ���
	
public:
	int n;                        //Ҷ�ӽ�����
	void init();                  //��ʼ��
	void CreateHTree();           //������������
	void CreateCodeTable();               //���������
	void SelectMin(int &x, int&y, int s, int e);   
	void Encode(char*d);                        //����
	void Decode(char*s, char*d, int n);                        //����
	void print1(int i, int m);                         //��ӡ��������
	void print2(int i, int m);
	//int count(int R);                     //��������������
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

//������������
void Huffman::CreateHTree()              //a[0..n-1]��Ȩ������
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
//��ӡ��������
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

//�ڶ����ӡ��
void Huffman::print2(int i, int m) 
{

}

//���������
void Huffman::CreateCodeTable()
{
	HCodeTable = new HCode[n];                         //���ɱ����
	cout << "�����Ϊ��" << endl;
	for (int i = 0; i < n; i++)
	{
		HCodeTable[i].data = leaf[i];
		int child = i;                                 //���ӽ����
		int parent = HTree[i].parent;                  //���ڵ���
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
	cout << "                                          ***��������Ҫ������ַ���***" << endl;
	cout << "                                          ****************************" << endl;
	ht1.init();
	cout << endl;
	cout << "                                             ��������Ҫ���еĲ����� " << endl;
	cout << "                       **********************************************************************" << endl;
	cout << "                       " << "*" << "     " << "1.������������" << "                *              " << "2.���������" << "     " << "*" << endl;
	cout << "                       " << "*" << "     " << "3.�������    " << "                *              " << "4.����      " << "     " << "*" << endl;
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
			cout << "                                             ********������������********" << endl;
			cout << "                                             ****************************" << endl;
			ht1.CreateHTree();
			ht1.print1(2 * ht1.n - 2, 1);
			cout << endl;
			kb++;
		}
		else if (x == 2)
		{
			if (kb == 0)
				cout << "���ȴ�����������";
			else 
			{
				cout << "                                             ****************************" << endl;
				cout << "                                             ******���������������******" << endl;
				cout << "                                             ****************************" << endl;
				ht1.CreateCodeTable();
				kb++;
			}
		}
		
		
		if (x == 3)
		{
			if (kb == 0)
				cout << "���ȴ�����������";
			else if (kb == 1)
				cout << "���ȴ��������������";
			else 
			{
				ht1.Encode(d);
				kb++;
				cout << "                                             ****************************" << endl;
				cout << "                                             ***********����Ϊ***********" << endl;
				cout << "                                             ****************************" << endl;
				cout << d << endl;
			}
		}
		else if (x == 4)
		{
			if (kb == 0)
				cout << "���ȴ�����������";
			else if (kb == 1)
				cout << "���ȴ��������";
			else if (kb == 2)
				cout << "���ȱ���";
			else
			{
				ht1.Decode(d, c, ht1.n);
				cout << "                                             ****************************" << endl;
				cout << "                                             ***********����Ϊ***********" << endl;
				cout << "                                             ****************************" << endl;
				cout <<c<< endl;
			}
		}
		cout << endl;
		cout << "                                             ��������Ҫ���еĲ����� " << endl;
		cout << "                       **********************************************************************" << endl;
		cout << "                       " << "*" << "     " << "1.������������" << "                *              " << "2.���������" << "     " << "*" << endl;
		cout << "                       " << "*" << "     " << "3.�������    " << "                *              " << "4.����      " << "     " << "*" << endl;
		cout << "                       **********************************************************************" << endl;
	}
	system("pause");
	return 0;
}