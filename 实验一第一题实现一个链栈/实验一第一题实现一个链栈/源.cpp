#include<iostream>
#include"БъЭЗ.h"
using namespace std;
int main()
{
	int a[10];
	for (int i = 0; i < 10; i++)
		a[i] = i + 1;
	LinkStack<int> x;
	for (int i = 0; i < 10; i++)
		x.Push(a[i]);
	cout << x.GetTop() << endl;
	for (int i = 0; i < 10; i++)
		cout << x.Pop() << " ";
	system("pause");
	return 0;
}