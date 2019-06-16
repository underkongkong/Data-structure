#include<iostream>
using namespace std;
int main()
{
	int money;
	int a=0;
	cin >> money;
	int m5, m2, m1;
	m5 = money / 5;
	m2 = money / 2;
	m1 = money;
	for (int i = 1; i <= m5; i++)
		for (int j = 1; j <= m2; j++)
			for (int k = 1; k <= m1; k++)
				if ((5 * i) + (2 * j) + k == money)
					a++;
	cout << a;
	return 0;
}