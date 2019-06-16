#include<iostream>
#include<vector>
using namespace std;

int main()
{
	int n;
	vector<int>price;
	while (cin>>n)
	{
		price.push_back(n);
	}
	int amount = price.size();
	int i = 0;
	int k;
	while (true)
	{
		int x = price[i];
		i = i + x;
		if (price[i] == 0&&i!=amount-1)
		{
			k = 0; 
			break;
		}
		else if (i == amount - 1)
		{
			k = 1;
			break;
		}
		else if (i > amount - 1)
		{
			k = 0;
			break;
		}
	}
	if (k==1)
	{
		cout << "TRUE";
		system("pause");
		return 0;
	}
	else
	{
		cout << "FALSE";
		system("pause");
		return 0;
	}
}
/*bool judgement(int n, vector<int> p)
{
	int i = 0;
	while (true)
	{
		int x = p[i];
		i = i + x;
		if (i == n - 1)
		{
			return 1;
		}
		else if (i > n - 1)
			return 0;
	}
}*/