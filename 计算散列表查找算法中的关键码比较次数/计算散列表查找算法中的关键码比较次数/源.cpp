#include<iostream>
using namespace std;

int main()
{
	int n, p, m;                   //n为数字个数，p为定址数字，m为散列表长度；
	cin >> n >> p >> m;
	int k, k1;
	
	int x=1;
	int n1 = 1;
	int*pn = new int[n];
	int*ppn = new int[n];
	int*pppn = new int[n];
	int*pm = new int[m];
	for (int i = 0; i < m; i++)
		pm[i] = NULL;
	for (int i = 0; i < n; i++)
	{
		cin >> pn[i];
		ppn[i] = pn[i] % p;
		pppn[i] = 0;
	}
	cin >> k;
	k1 = k%p;
	for (int i = 0; i < n; i++)
	{
		while (pm[ppn[i]] != NULL)
		{
			ppn[i] = (ppn[i] + 1) % m;
			pppn[i]++;
			n1++;
		}
		pm[ppn[i]] = pn[i];
	}
	while (pm[k1] != k)
	{
		x++;
		k1++;
		if (x == n1)
			break;
	}
	cout << x;
	delete[]pn;
	delete[]ppn;
	delete[]pppn;
	delete[]pm;
	system("pause");
	return 0;
}
