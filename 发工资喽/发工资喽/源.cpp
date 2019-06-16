#include<iostream>
using namespace std;
int main()
{
	int n;
	while (cin >> n&&n!=0)
	{
		int x = 0;
		int *p = new int[n];
		for (int i = 0; i < n; i++)
		{
			cin >> p[i];
			if (p[i] / 100 > 0)
				x += p[i] / 100;
			if ((p[i] % 100) >= 50)
				x += ((p[i] % 100) / 50);
			if ((p[i] % 50) >=10)
				x += ((p[i] % 50) / 10);
			if ((p[i] % 10) >= 5)
				x += ((p[i] % 10) / 5);
			if ((p[i] % 5) >= 2)
				x += ((p[i] % 5) / 2);
			x += (p[i] % 2);
		}
		cout << x;
		delete[]p;
	}
	system("pause");
	return 0;
}