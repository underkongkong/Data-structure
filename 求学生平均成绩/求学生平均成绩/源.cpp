#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
	int n, m;
	cin >> n >> m;
	int**p = new int*[n];
	double *paverage = new double[n];
	double *caverage = new double[m];
	for (int i = 0; i < n; i++)
		p[i] = new int[m];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> p[i][j];
	for (int i = 0; i < n; i++)
	{
		paverage[i] = 0;
		for (int j = 0; j < m; j++)
			paverage[i] += p[i][j];
		paverage[i] = paverage[i] / m;
	}
	for (int i = 0; i < m; i++)
	{
		caverage[i] = 0;
		for (int j = 0; j < n; j++)
			caverage[i] += (float)p[j][i];
		caverage[i] = caverage[i] / n;
	}
	int elite = 0;
	for (int i = 0; i < n; i++)
	{
		int count = 0;
		for (int j = 0; j < m; j++)
			if (p[i][j] >= caverage[j])
				count++;
		if (count == m)
			elite++;
	}
	for (int i = 0; i < n - 1; i++)
		cout << setiosflags(ios::fixed) << setprecision(2)<< paverage[i] << " ";
	cout << setiosflags(ios::fixed) << setprecision(2)<< paverage[n - 1]<<endl;
	for (int i = 0; i < m - 1; i++)
		cout << setiosflags(ios::fixed) << setprecision(2) << caverage[i] << " ";
	cout << setiosflags(ios::fixed) << setprecision(2) << caverage[m-1]<<endl;
	cout << elite;
	for (int i = 0; i < n; i++)
		delete[]p[i];
	delete[]p;
	system("pause");
	return 0;

}