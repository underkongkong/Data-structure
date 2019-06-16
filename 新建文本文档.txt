#include<iostream>
using namespace std;
int main() {
	int s, n;     //s为背包容量，n为物品数量
	int a=0;        //a为解的数量
	int mn=1;
	int nm=0;
	cin >> s >> n;
	int *p = new int[n];
	int *q = new int[n];
	for (int i = 0; i < n; i++)
	{
		cin >> p[i];
		q[i] = 0;
		mn *= 2;
	}
	while (p)
	{
		for (int i = 0; i < n; i++)
			if (q[i] == 0)
			{
				q[i] = 1;
				continue;
			}
			else
			{
				q[i] = 0;
				break;
			}
		int sum = 0;
		for (int i = 0; i < n; i++)
		{
			if (q[i] == 1)
				sum += p[i];
		}
		if (sum == s)
			a++;
		nm++;
		if (nm == mn)
			break;
	}
	cout << a;
	system("pause");
	delete[]p;
	delete[]q;
	return 0;
}