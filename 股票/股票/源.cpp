#include<iostream>
#include<algorithm>
#include<limits.h>
using namespace std;
int main()
{
	int prices[100];
	int n;
	int sum = 0;
	while (cin>>n)
	{
	 prices[sum++]=n;
	}
	if (sum == 0)
	{
		cout << 0;
		return 0;
	}
	int buy1 = INT_MIN;
	int sell1 = 0;
	int buy2 = INT_MIN;
	int sell2 = 0;
		//表示经过当前操作后的最大profit  
	for (int i = 0; i < sum; i++) {
		buy1 = max(buy1, -prices[i]);
		sell1 = max(sell1, buy1 + prices[i]);
		buy2 = max(buy2, sell1 - prices[i]);
		sell2 = max(sell2, buy2 + prices[i]);
	}
	int result=sell2;
	cout << result;
	system("pause");
	return 0;
}











/*	for (int i = 0; i < sum-1; i++)
	{
		if((i==0&&p[i]<p[i+1])||((i>0)&&(p[i] < p[i + 1])&&(p[i]<p[i-1])))
		{
			int s=0;
			p1 = i;
			int j = i;
			while (p[j] < p[j + 1])
			{
				p2 = j+1;
			}
			s = p[p1] - p[p2];
			if (s > ov[0] && s > ov[1])
			{
				ov[(jishuqi%2)] = s;
				jishuqi++;
			}
		}
	}*/