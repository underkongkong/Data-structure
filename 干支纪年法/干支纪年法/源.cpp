#include<iostream>
using namespace std;
void output(int n,int m)
{
	switch (n)
	{
	case 0:cout << "��";
		break;
	case 1:cout << "��";
		break;
	case 2:cout << "��";
		break;
	case 3:cout << "��";
		break;
	case 4:cout << "��";
		break;
	case 5:cout << "��";
		break;
	case 6:cout << "��";
		break;
	case 7:cout << "��";
		break;
	case 8:cout << "��";
		break;
	case 9:cout << "��";
		break;
	}
	switch (m)
	{
		//�ӡ�������î�������ȡ��硢δ���ꡢ�ϡ��硢��
	case 0:cout << "��";
		break;
	case 1:cout << "��";
		break;
	case 2:cout << "��";
		break;
	case 3:cout << "î";
		break;
	case 4:cout << "��";
		break;
	case 5:cout << "��";
		break;
	case 6:cout << "��";
		break;
	case 7:cout << "δ";
		break;
	case 8:cout << "��";
		break;
	case 9:cout << "��";
		break;
	case 10:cout << "��";
		break;
	case 11:cout << "��";
		break;
	}
}
int main()
{
	int n;
	cin >> n;
	int x = n - 4;
	x = x % 60;
	int h = x % 10;
	int e = x % 12;
	output(h, e);
	system("pause");
	return 0;
}