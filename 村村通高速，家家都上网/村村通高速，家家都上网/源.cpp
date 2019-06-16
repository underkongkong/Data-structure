#include<iostream>
using namespace std;
int result = 0;
const int MAXSIZE = 10;
class MGraph
{
public:
	MGraph(int **a,int n);
	int vertex[MAXSIZE];
	int arcs[MAXSIZE][MAXSIZE];
	int vNum, arcNum;
	int MAX=0;
};

MGraph::MGraph(int **a, int n)
{
	int i, j, k;
	vNum = n;
	for (k = 0; k < n; k++)  vertex[k] = k+1;
	for (k = 0; k < n; k++)
		for (j = 0; j < n; j++)	arcs[k][j] = 0;
	for (i = 0; i< n; i++)
		for(j=0;j<n;j++)
		{
			if (a[i][j] >= MAX)
				MAX = a[i][j];
			arcs[i][j] = a[i][j];
		}
}


int adjvex[MAXSIZE];
int lowcost[MAXSIZE];
int mininum(MGraph G, int lowcost[],int MAX)
{
	int min = MAX;
	int k = 0;
	for (int i = 1; i < G.vNum; i++)
	{
		if (lowcost[i] != 0 && lowcost[i] < min)
		{
			min = lowcost[i];
			k = i;
		}
	}
	return k;
}
void Prim(MGraph G)
{
	for (int i = 0; i < G.vNum; i++)
	{
		adjvex[i] = 0; lowcost[i] = G.arcs[0][i];
	}
	lowcost[0] = 0;
	for (int i = 1; i < G.vNum; i++)
	{
		int k = mininum(G, lowcost,G.MAX);
		//cout<<'V'<<adjvex[k]<<"->V"<<k<<endl;
		result += lowcost[k];
		lowcost[k] = 0;
		for (int j = 0; j < G.vNum; j++)
		{
			if (lowcost[j] != 0 && G.arcs[k][j] < lowcost[j])
			{
				lowcost[j] = G.arcs[k][j];
				adjvex[j] = k;
			}
		}
	}
	cout << result;
}
int main()
{
	int n;
	cin >> n;
	int **p = new int*[n];
	for (int i = 0; i < n; i++)
	{
		p[i] = new int[n];
	}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> p[i][j];
	MGraph xxx(p, n);
	Prim(xxx);
	for (int i = 0; i < n; i++)
		delete[]p[i];
	delete[]p;
	system("pause");
	return 0;
}