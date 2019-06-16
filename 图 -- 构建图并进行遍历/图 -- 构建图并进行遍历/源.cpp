#include<iostream>
using namespace std;
const int MAXSIZE = 10;
bool visited1[MAXSIZE] = { false };
bool visited2[MAXSIZE] = { false };
int x = 0;
void DFS(int **a,int *a1,int v,int n)
{
	x++;
	if (x < n)
		cout << a1[v] << " ";
	else
		cout << a1[v];
	visited1[v] = true;
	for (int j = 0; j < n; j++)
		if (a[v][j] != 0 && !visited1[j])
			DFS(a,a1,j,n);
}
void BFS(int **a, int *a1, int v, int n)
{
	int queue[MAXSIZE];
	int f = 0, r = 0;
	cout << a1[v]<<" ";
	visited2[v] = true;
	queue[++r] = v;
	while (f != r)
	{
		v = queue[++f];
		for (int j = 0; j < n; j++)
		{
			if (a[v][j] != 0 && !visited2[j])
			{
				if (j == n-1)
					cout << a1[j];
				else
					cout<<a1[j]<< " ";
				visited2[j] = true;
				queue[++r] = j;
			}
		}
	}
}
int main()
{
	int n;
	cin >> n;
	int *pn = new int [n];
	int **p = new int*[n];
	for (int i = 0; i < n; i++)
		p[i] = new int[n];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> p[i][j];
		}
		pn[i] = i;
	}
	DFS(p, pn, 0, n);
	cout << endl;
	BFS(p, pn, 0, n);
	delete[]pn;
	for (int i = 0; i < n; i++)
		delete[] p[i];
	system("pause");
	return 0;

}