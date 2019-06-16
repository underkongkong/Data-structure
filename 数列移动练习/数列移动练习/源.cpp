#include<iostream>
using namespace std;

bool judge(unsigned short int a, unsigned short int b)
{
	unsigned short int x = 0;
	int i=16;
	while(i>0)
	{
		x = a >> (16 - i) | a << i;
		if (x == b)
			return 1;
		i--;
	}
	if (i == 0)
		return 0;
}
int main()
{
	int num;
	cin >> num;
	while (num > 0)
	{
		unsigned short int m, n;
		cin >> m >> n;
		if (judge(m, n))
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
		num--;
	}
	system("pause");
	return 0;
}