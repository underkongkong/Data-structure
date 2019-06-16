#include<iostream>
using namespace std;

int f(int n)
{
	if (0 < n&&n < 4)
		return 1;
	else if (n >= 4)
		return f(n - 1) + f(n - 3);
}
int main()
{
	int n;
	cin >> n;
	cout << f(n);
	system("pause");
	return 0;
}