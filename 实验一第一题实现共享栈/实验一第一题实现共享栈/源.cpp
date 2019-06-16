#include<iostream>
#include"БъЭЗ.h"
using namespace std;
int main()
{
	int x[10];
	for (int i = 0; i < 10; i++)
		x[i] = i + 1;
	ShareSeqStack<int> a1;
	for (int i = 0; i < 5; i++)
		a1.PushStack1(x[i]);
	for (int i = 5; i < 10; i++)
		a1.PushStack2(x[i]);
	for (int i = 0; i < 5; i++)
		cout << a1.Pop1() << " ";
	for (int i = 0; i < 5; i++)
		cout << a1.Pop2() << " ";
	system("pause");
	return 0;
}