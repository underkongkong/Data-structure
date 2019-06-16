#include<iostream>
using namespace std;
bool canjump(int n, int p[])
{
	if (n-1 == 0)
		return false;
	int i = 0;
	//判断有没有0，没有0的肯定能达到
	while (i < n) {
		if (p[i] == 0) {
			break;
		}
		i++;
	}
	//没有0，肯定能达到
	if (i == n) {
		return true;
	}
	i = 0;
	while (i < n) {
		if (i + p[i] >= n-1)
			return true;
		if (p[i] == 0)
			return false;
		int max = 0;
		int index = 0;
		//下一步能前进最大的步骤
		for (int j = i + 1; j - i <= p[i]; j++) {
			if (max < j - i + p[j]) {
				max = j - i + p[j];
				index = j;
			}
		}//走到下一步的索引
		i = index;
	}
	return true;
}
int main()
{
	int n;
	int price[100];
	int amount = 0;
	while (cin>>n)
	{
		price[amount] = n;
		amount++;
	}
	if (canjump(amount, price))
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
