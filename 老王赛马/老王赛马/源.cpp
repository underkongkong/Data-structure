#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main() 
{
	int n=1;
	while (n != 0)
	{
		bool result = 0;
		cin >> n;
		if (n == 0)
		{
			system("pause");
			return 0;
		}
		vector<int> pmh;
		vector<int> peh;
		int winnum = 0;
		int losenum = 0;
		//int*pmh=new int[n];
		//int*peh=new int[n];
		for (int i = 0; i < n; i++)
		{
			int data;
			cin >> data;
			pmh.push_back(data);
		}
		for (int i = 0; i < n; i++)
		{
			int data;
			cin >> data;
			peh.push_back(data);
		}
		sort(pmh.begin(), pmh.end());
		sort(peh.begin(), peh.end());
		/*for (int i = 0; i < n; i++)
			cout << pmh[i] << " ";
		for (int i = 0; i < n; i++)
			cout << peh[i] << " ";*/
		for (int i = 0; i < n; i++)
		{
			int j = i;
			for (int x = 0; x < i; x++)
			{
				if (pmh[x] > peh[n - x - 1])
					winnum++;
				else
					losenum++;

			}
			for (; j < n; j++)
			{
				if (pmh[j] > peh[j - i])
					winnum++;
				else
					losenum++;
			}
			if (winnum > losenum)
			{
				result = 1;
				break;
			}
		}
		if (result)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	system("pause");
	return 0;

}