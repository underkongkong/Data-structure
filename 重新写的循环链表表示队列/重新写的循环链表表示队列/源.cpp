#include<iostream>
using namespace std;
int main()
{
	int n;
	cin >> n;
	int *p = new int[n];
	for (int i = 0; i < n; i++)
		cin >> p[i];
	cout << n << " " << p[0] << " " << p[0] << " " << n - 1;
	system("pause");
	return 0;
}