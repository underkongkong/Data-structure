#include<iostream>
using namespace std;
int n = 0;
int search(int p[],int x, int k)
{
	int low = 0;
	int high = x-1;
	while (low <= high)
	{
		int mid = (low + high) / 2;
		if (p[mid] == k)
		{
			n++; return n;
		}
		else if (p[mid] > k)
		{
			n++;
			high = mid - 1;
		}
		else
		{
			n++;
			low = mid + 1;
		}
	}
	return n;
}
int main()
{
	int x;
	cin >> x;
	int *p = new int[x];
	for (int i = 0; i < x; i++)
		cin >> p[i];
	int k;
	cin >> k;
	cout<<search(p,x,k);
	delete[]p;
	system("pause");
	return 0;
}