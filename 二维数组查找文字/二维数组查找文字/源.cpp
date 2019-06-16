#include<iostream>
using namespace std;
int main()
{
	int m, n;
	cin >> m >> n;
	int**p = new int*[m];
	int x;
	bool a=0;
	cin >> x;
	for (int i = 0; i < m; i++)
		p[i] = new int[n];
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			cin >> p[i][j];
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			if (p[i][j] == x)
			{
				a = 1;
				break;
			}
	if (a)
		cout << "Yes";
	else
		cout << "No";
	system("pause");
	return 0;
}