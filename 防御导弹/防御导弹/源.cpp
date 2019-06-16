#include<iostream>  
#include<algorithm>
using namespace std;
int a[100] = { 0 }, down[100] = { 0 }, up[100] = { 0 };
using namespace std;
int main()
{
	int n = 1, i, j, ans1 = 0, ans2 = 0;
	while (cin>>a[n])n++;
	n = n - 1;
	for (i = 1; i <= n; i++)
	{
		up[i] = down[i] = 1;
		for (j = 1; j<i; j++)
		{
			if (a[i] <= a[j])     /* 最长不升子序列 */
				down[i] = max(down[i], down[j] + 1);
			else              /* 最长上升子序列*/
				up[i] = max(up[i], up[j] + 1);
		}
		ans1 = max(ans1, down[i]);
	}
	cout << ans1;
	system("pause");
	return 0;
}