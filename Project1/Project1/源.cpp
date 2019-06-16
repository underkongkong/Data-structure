/*有M个小孩到公园玩，门票是1元。其中N个小孩带的钱为1元，K个小孩带的钱为2元。
售票员没有零钱，问这些小孩共有多少种排队方法，使得售票员总能找得开零钱。
注意：两个拿一元零钱的小孩，他们的位置互换，也算是一种新的排法。*/
#include<iostream>    
using namespace std;
int main() {
	int m, n, k;
	cin >> m >> n >> k;
	if (n<k)
		cout << 0 << endl; //2元小朋友比1元小朋友多   
	else {
		int s1 = 1;
		for (int i = 1; i <= k; ++i) //2元的小朋友内部全排列   
			s1 *= i;
		int s2 = 1;
		for (int i = 1; i <= n; ++i) //1元的小朋友内部全排列   
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
		} //由i个1元小朋友和j个2元小朋友组成的队伍排法   
		cout << dp[n][k] * s2*s1 << endl;
	}
	system("pause");
	return 0;
}