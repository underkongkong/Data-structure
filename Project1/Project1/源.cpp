/*��M��С������԰�棬��Ʊ��1Ԫ������N��С������ǮΪ1Ԫ��K��С������ǮΪ2Ԫ��
��ƱԱû����Ǯ������ЩС�����ж������Ŷӷ�����ʹ����ƱԱ�����ҵÿ���Ǯ��
ע�⣺������һԪ��Ǯ��С�������ǵ�λ�û�����Ҳ����һ���µ��ŷ���*/
#include<iostream>    
using namespace std;
int main() {
	int m, n, k;
	cin >> m >> n >> k;
	if (n<k)
		cout << 0 << endl; //2ԪС���ѱ�1ԪС���Ѷ�   
	else {
		int s1 = 1;
		for (int i = 1; i <= k; ++i) //2Ԫ��С�����ڲ�ȫ����   
			s1 *= i;
		int s2 = 1;
		for (int i = 1; i <= n; ++i) //1Ԫ��С�����ڲ�ȫ����   
			s2 *= i;
		int dp[20][20] = { 0 };
		dp[1][0] = 1;
		dp[1][1] = 1;
		for (int i = 2; i <= n; ++i) {
			for (int j = 0; j <= i; ++j) {
				for (int g = 0; g <= j; ++g) {
					dp[i][j] += dp[i - 1][g];
				}
			}
		} //��i��1ԪС���Ѻ�j��2ԪС������ɵĶ����ŷ�   
		cout << dp[n][k] * s2*s1 << endl;
	}
	system("pause");
	return 0;
}