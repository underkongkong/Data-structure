#include<iostream>
using namespace std;
bool canjump(int n, int p[])
{
	if (n-1 == 0)
		return false;
	int i = 0;
	//�ж���û��0��û��0�Ŀ϶��ܴﵽ
	while (i < n) {
		if (p[i] == 0) {
			break;
		}
		i++;
	}
	//û��0���϶��ܴﵽ
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
		//��һ����ǰ�����Ĳ���
		for (int j = i + 1; j - i <= p[i]; j++) {
			if (max < j - i + p[j]) {
				max = j - i + p[j];
				index = j;
			}
		}//�ߵ���һ��������
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
