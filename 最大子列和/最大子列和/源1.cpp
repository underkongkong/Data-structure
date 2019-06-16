#include<iostream>
using namespace std;
int maxSum(int *p, int n)
{
	int sum = 0;
	int maxsum = 0;
	int j, i;
	for (i = 0; i < n; i++)
	{
		int sum = 0;
		for (j = i; j < n; j++)
		{
			sum += p[j];
			if (sum > maxsum)
		    maxsum = sum;
		}
	}
	return maxsum;
}
int main()
{
	int a;
	cin >> a;
	int *p = new int[a];
	int m = 0;
	for (int i = 0; i < a; i++)
	{
		cin >> p[i];
		if (p[i] < 0)
			m++;
	}
	if (m == a)
	{
		cout << 0 << endl;
		return 0;
	}
	int result = maxSum(p, a);
	cout << result << endl;
	delete[]p;
	system("pause");
	return 0;
}