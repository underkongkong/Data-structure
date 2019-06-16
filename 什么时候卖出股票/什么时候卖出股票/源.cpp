/********************************************************************************************************************
题目描述

假设有一组数，其中第 i 个元素表示 第 i 天的给定股票的价格，如果您只允许完成至多 2 笔交易，请设计一个算法以实现最大的利润。
注意：您不得同时进行多笔交易（即您必须在再次购买之前出售股票）

输入
股票在一段时间内的价格，即一组小于100 的数

输出
能够得到的最大利润(>=0)

样例输入
7 1 3 6 4 5
样例输出
6

提示
样例表示 以1 买入，以6卖出，再以4 买入，以5卖出 获得利润最大。

************************************************************************************************************************/



#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

bool judgeguaidian(int i, vector<int> a)
{
	if (i == 0 && a[i] < a[1])
		return 1;
	else if ((a[i] < a[i - 1] && a[i + 1] > a[i]))
		return 1;
	else
		return 0;
}
int main()
{
	int result;
	int n;
	vector<int>price;
	while (cin >> n)
	{
		price.push_back(n);
	}
	int amount = price.size();
	int guaidian = 0;

	for (int i = 0; i < amount-1; i++)
	{
		if (judgeguaidian(i, price))
			guaidian++;
	}
	if (guaidian > 1)
	{
		int * pg = new int[guaidian];
		int k = 0;
		for (int i = 0; i < amount-1; i++)
		{
			if (judgeguaidian(i, price))
			{
				pg[k] = i;
				k++;
			}
		}
		int * re = new int[guaidian];
		for (int i = 0; i < guaidian; i++)
		{
			re[i] = 0;
			if (i < guaidian - 1)
			{
				for (int k = pg[i]; k < pg[i + 1]; k++)
				{
					if (price[k] < price[k + 1])
						re[i] += price[k + 1] - price[k];
				}
			}
			else if (i == guaidian - 1)
			{
				for(int k=pg[i];k<amount-1;k++)
				{
					if (price[k] < price[k + 1])
						re[i] += price[k + 1] - price[k];
				}
			}
		}
		for (int i = 0; i < guaidian-1; i++)
			if (re[i] < re[i + 1])
			{
				int temp = re[i + 1];
				re[i + 1] = re[i];
				re[i] = temp;
			}
		cout << re[0] + re[1];
		delete[]pg;
		delete[]re;
		system("pause");
		return 0;
	}
	if (guaidian == 1)
	{
		for (int i = 0; i < amount-1; i++)
		{
			if (judgeguaidian(i, price))
			{
				result = price[amount - 1] - price[i];
				break;
			}
		}
		cout << result;
		system("pause");
		return 0;
	}
	if (guaidian == 0)
	{
		cout << 0;
		system("pause");
		return 0;
	}
}











/*int max1=0;
	int s = 0;
	int x = 0;
	for (int k = 1; k < i; k++)
		if ((price[k + 1] > price[k] && price[k] < price[k - 1])||(k=1&&price[k]>price[0]))
			x++;
	int*data = new int[x];
	for (int k = 0; k < i; k++)
	{
		if ((price[k + 1] > price[k] && price[k] < price[k - 1]) || (k = 1 && price[k]>price[0]))
		{
			while (price[k + 1] > price[k])
			{
				max1 = max1 + price[k + 1] - price[k];
				k++;
			}
			data[s] = max1;
			s++;
		}
	}
	vector<int> a(x,0);
	for (int i = 0; i < x; i++)
		a.push_back(data[i]);
	sort(a.begin(), a.end());
	cout << a. + a[1] << endl;
	delete[]data;*/