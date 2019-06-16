#include<iostream>
using namespace std;
int jiecheng(int k) {
	int jiecheng = 1;
	for (int i = k; i > 0; i--) {
		jiecheng *= i;
	}
	return jiecheng;
}
int pailie(int m, int n)
{
	int pailie = 1;
	pailie = jiecheng(m) / jiecheng(m - n);
	return pailie;
}
int zuhe(int m, int n)
{
	int zuhe = jiecheng(m) / jiecheng(n);
	zuhe = zuhe / jiecheng(m - n);
	return zuhe;
}
int main() {
	int	M, N, K;
	int sum=1;
	cin >> M >> N >> K;
	if (K>N||K<=0||M<=0||K<=0)
	{
		sum = 0;
		cout << sum;
	}
	else if (K == 0)
	{
		for (int i = 0; i < N; i++)
		{
			sum *= (i + 1);
		}
		cout << sum;
	}
	else if(N==K)
	{
		int sum = N;
		for (int i = 0; i < N; i++)
		{
			sum *= i + 1;
		}
		for (int i = 0; i < K; i++)
		{
			sum *= i + 1;
		}
		cout << sum;
	}
	else if (N > K)
	{
		int sum = zuhe(N-K+1,K);
	    int akk = jiecheng(K);
		for (int i = 1; K - i > 0; i++) { sum = sum + zuhe(N - K+1,K-i)*zuhe(K - 1, i); }
		sum = sum*jiecheng(N)*jiecheng(K);
		cout << sum;
	}
	system("pause");
	return 0;
}