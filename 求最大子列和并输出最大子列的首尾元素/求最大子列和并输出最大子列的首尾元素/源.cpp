#include<iostream>
using namespace std;
void maxSum(int *p, int n)
{
	int sum = 0;
	int maxsum = 0;
	int longest = 0;
	int j, i, length,firstnum,lastnum;
	for (i = 0; i < n; i++)
	{
		int sum = 0;
		for (j = i; j < n; j++)
		{
			sum += p[j];
			length = j - i;
			if ((sum > maxsum)&&(length >= longest))
			{
				maxsum = sum;
				longest =length;
				firstnum = p[i];
				lastnum = p[i + length];
			}	
		}
	}
	cout << maxsum <<" "<< firstnum <<" "<< lastnum << endl;
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
		cout << 0 <<" "<< p[0]<<" " << p[a - 1] << endl;
		system("pause");
		return 0;
	}
	maxSum(p, a);
	delete[]p;
	system("pause");
	return 0;
}