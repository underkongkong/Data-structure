#include<iostream>
#include<math.h>
using namespace std;
int weiz(int n, int m)
{
	int t, k;
	if (n<m)
	{
		t = n;
		n = m;
		m = t;
	}
	k = n - m;
	n = (int)(k*(1 + sqrt(5.0)) / 2.0);//核心公式，计算当前必败局  
	if (n == m)
		return 0;
	else
		return 1;
}
int main()
{
	int a, b;
	while (cin >> a >> b)
	{
		cout << weiz(a, b)<<endl;
	}
	return 0;

}