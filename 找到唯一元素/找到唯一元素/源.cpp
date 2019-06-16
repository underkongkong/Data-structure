#include<iostream>
using namespace std;
int Onlyone(int A[], int n)
{
	if (n == 1)
		return A[0];
	int result = A[0];
	for (int i = 1; i < n; i++)
	{
		result ^= A[i];//异或运算的可交换性  
	}
	return result;
}
int main() 
{
	int n;
	cin >> n;
	int *p = new int[n];
	for(int i=0;i<n;i++)
	{
		cin >> p[i];
	}
	cout << Onlyone(p, n) << endl;
	delete[]p;
	return 0;
}