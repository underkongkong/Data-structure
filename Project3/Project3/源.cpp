#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


int maxProfit(vector<int>& prices) {
	int n = prices.size();
	if (n<2) return 0;
	vector<int> maxNum(n, 0);
	maxNum[n - 1] = prices.back();
	for (int i = n - 2; i >= 0; i--) {
		maxNum[i] = max(prices[i], maxNum[i + 1]);
	}
	int minp = prices[0], profit = 0, maxprofit = 0;
	for (int i = 1; i<n; i++) {
		if (prices[i] - minp>profit) {
			profit = prices[i] - minp;
			maxprofit = max(maxprofit, profit);
		}
		else {
			maxprofit = max(maxprofit, profit + maxNum[i] - prices[i]);
		}
		if (minp>prices[i]) minp = prices[i];
	}
	return maxprofit;
}

int main()
{
	vector<int>a;
	int n;
	cin >> n;
	a.push_back(n);
	while (cin.get() != '\n')
	{
		cin >> n;
		a.push_back(n);
	}
	cout << maxProfit(a);
	system("pause");
	return 0;
}