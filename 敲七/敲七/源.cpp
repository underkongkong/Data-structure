#include<iostream>
using namespace std;
int main()
{
	int m;
	cin >> m;
	int b = 0;
	if (m <= 0 || m>30000)
		return 0;
	for (int a = 1; a <= m; a++)
	{
		int x = a / 10000;
		int y = (a / 1000) % 10;
		int z = (a / 100) % 10;
		int p = (a / 10) % 10;
		int q = a % 10;
		if (a % 7 == 0 || x == 7 || y == 7 || z == 7 || p == 7 || q == 7)
			b++;
	}
	cout << b;
	system("pause");
	return 0;
}