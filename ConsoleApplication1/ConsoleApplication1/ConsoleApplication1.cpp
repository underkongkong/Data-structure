#include<iostream>
using namespace std;
void reverse(char a[])
{
	int n = 0;
	while (a[n])
		n++;
	for (int i = 0; i < n / 2; i++)
	{
		char temp = a[i];
		a[i] = a[n - i - 1];
		a[n - i - 1] = temp;
	}
}
int main()
{
	char a[8] = { 'a','b','c','d','e','f','g','h' };
	reverse(a);
	cout << a;
	system("pause");    return 0;
}

