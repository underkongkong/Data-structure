#include<iostream>  
#include<cmath>  
using namespace std;
int main()
{
	long long n, a;
	while (cin >> n && n != 0)
	{
		if (n == 1)
			a = 0;
		else
			a = log(n - 1) / log(3) + 1;
		cout << a << endl;
	}
	return 0;
}