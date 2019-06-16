#include<iostream>
using namespace std;
int result = 0;
const int MAXSIZE = 10;
bool visited1[MAXSIZE] = { false };
bool visited2[MAXSIZE] = { false };
int x = 0;
const int MAX_EDGE = 20;
const int MAX = 10000;
const int MAX_VERTEX = 10;
void DFS(int **a, int *a1, int v, int n)
{
	x++;
	if (x < n)
		cout << a1[v] << " ";
	else
		cout << a1[v];
	visited1[v] = true;
	for (int j = 0; j < n; j++)
		if (a[v][j] != 0 && !visited1[j])
			DFS(a, a1, j, n);
}
void BFS(int **a, int *a1, int v, int n)
{
	int queue[MAXSIZE];
	int f = 0, r = 0;
	cout << a1[v] << " ";
	visited2[v] = true;
	queue[++r] = v;
	while (f != r)
	{
		v = queue[++f];
		for (int j = 0; j < n; j++)
		{
			if (a[v][j] != 0 && !visited2[j])
			{
				if (j == n - 1)
					cout << a1[j];
				else
					cout << a1[j] << " ";
				visited2[j] = true;
				queue[++r] = j;
			}
		}
	}
}
class MGraph
{
public:
	MGraph(int **a, int n);
	int vertex[MAXSIZE];
	int arcs[MAXSIZE][MAXSIZE];
	int vNum;
	int arcNum = 0;
	int MAX =0;
};

MGraph::MGraph(int **a, int n)
{
	int i, j, k;
	vNum = n;
	for (k = 0; k < n; k++)  vertex[k] = k + 1;
	for (k = 0; k < n; k++)
		for (j = 0; j < n; j++)	arcs[k][j] = 0;
	for (i = 0; i< n; i++)
		for (j = i; j<n; j++)
		{
			if (a[i][j] >= MAX) {
				MAX = a[i][j];
				arcNum++;
			}
			arcs[i][j] = a[i][j];
		}
}


int adjvex[MAXSIZE];
int lowcost[MAXSIZE];
int mininum(MGraph G, int lowcost[])
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
		adjvex[i] = 0; lowcost[i] = G.arcs[0][i];//存储所有到v0的边
	}
	lowcost[0] = 0;                      //初始化U={V0}
	for (int i = 1; i < G.vNum; i++)
	{
		int k = mininum(G, lowcost);     //找下一个边权值最小的邻接点
		cout << 'V' << adjvex[k] << "->V" << k << endl;
		result += lowcost[k];
		lowcost[k] = 0;                  //U=U+{Vk}      
		for (int j = 0; j < G.vNum; j++) //更新辅助数组
		{ 
			if (lowcost[j] != 0 && G.arcs[k][j] < lowcost[j])
			{
				lowcost[j] = G.arcs[k][j];
				adjvex[j] = k;           //增加该路径
			}
		}
	}
	cout << result;                      //输出最短路径长度
}


struct VEdge {
	int fromV;
	int endV;
	int weight;
};
VEdge EdgeList[MAX_EDGE];
void GenSortEdge(MGraph G)
{
	int k = 0, i, j;
	for (i = 0; i<G.vNum; i++)                                //对边进行赋值
		for (j = i; j<G.vNum; j++)
			if (G.arcs[i][j] != 0&& G.arcs[i][j] != MAX){
				EdgeList[k].fromV = i;
				EdgeList[k].endV = j;
				EdgeList[k].weight = G.arcs[i][j];
				k++;
			}
	for (i = 1; i < G.arcNum ; i++) {						  //对边进行排序
		for (j = 0; j <= G.arcNum-i+1; j++)
			if (EdgeList[j].weight > EdgeList[j+1].weight){
				VEdge t;
				t.endV= EdgeList[j].endV;
				t.fromV = EdgeList[j].fromV;
				t.weight = EdgeList[j].weight;
				EdgeList[j].endV = EdgeList[j+1].endV;
				EdgeList[j].fromV = EdgeList[j + 1].fromV;
				EdgeList[j].weight = EdgeList[j + 1].weight;
				EdgeList[j+1].endV= t.endV;
				EdgeList[j + 1].fromV = t.fromV;
				EdgeList[j + 1].weight = t.weight;				//没有写“=”的运算符重载
			}
	}
	cout << G.arcNum << endl;
}

void Kruskal( int n)
{
	int result = 0;
	int vset[MAX_VERTEX];										//涂色数组
	for (int i = 0; i < n; i++) vset[i] = i;
	int k = 0, j = 0;
	while (k < n - 1)
	{
		int m = EdgeList[j].fromV, l = EdgeList[j].endV;		//当前最短边的起点和终点
		int sn1 = vset[m];										//起点颜色
		int sn2 = vset[l];										//终点颜色
		if (sn1 != sn2)											//颜色不等
		{
			cout << 'V' << m << "->V" << l << endl;				//输出起点和终点
			k++;
			result += EdgeList[j].weight;
			for (int i = 0; i < n; i++){
				if (vset[i] == sn2){							//给所有和终点颜色一样的点涂色为起点颜色
					vset[i] = sn1;
				}
			}
		}
		j++;
	}
	cout << result << endl;                                     //输出最短路径
	for (int i = 0; i < 6; i++)									//输出路径经过的顶点顺序
		cout << EdgeList[i].weight<<" " ;
}


bool bVisited[MAXSIZE] = { false };
void DFS222(int **a, int *a1, int v, int n) {
	int stack[MAXSIZE];
	int top = -1, i = 0;
	cout <<a1[v] << " ";
	bVisited[v] = true;
	top++;
	stack[top] = v;
	while (top != -1) {
		v = stack[top];
		for (i = 0; i < n; i++) 
			if(a[v][i]!=0&&!bVisited[i]){
			cout << a1[i] << " ";
			bVisited[i] = true;
			stack[++top] = i;
			break;
		}
		if (i == n)top--;
	}
}


int FindMin(int Disk[], bool S[], int n) {
	int k = 0, min = MAX;
	for (int i = 0; i < n; i++) {
		if (!S[i] && min > Disk[i]) {
			min = Disk[i]; k = i;
		}
	}
	if (min == MAX) return -1;
	return k;
}
void Print(int D[], int p[], int n) {
	for (int i = 0; i < n; i++) {
		cout << 'V' << i << ":" << D[i] << "\t{V" << i;
		int pre = p[i];
		while (pre != -1) {
			cout << 'V' << pre; pre = p[pre];
		}
		cout << "}" << endl;
	}
}

void ShortPath(MGraph G, int v, int Disk[], int path[],int n) {
	bool S[MAX_VERTEX] = { false };
	for (int i = 0; i < n; i++) {
		Disk[i] = G.arcs[v][i];
		if (Disk[i] != MAX&&Disk[i]!=0) path[i] = v;
		else path[i] = -1;
	}
	S[v] = true;
	Disk[v] = 0;
	for (int i = 0; i < n; i++) {
		v = FindMin(Disk, S, n);
		if ((v = FindMin(Disk, S, n)) == -1)
			break;
		S[v] = true;
		for(int j=0;j<n;j++)
			if (!S[j] && (Disk[j] > G.arcs[v][j] + Disk[v])) {
				Disk[j] = G.arcs[v][j] + Disk[v];
				path[j] = v;
			}
	}
	Print(Disk, path, n);
}



int main()
{
	int n;
	cout << "输入图的节点数";
	while (cin >> n) {
		cout << "输入图的邻接矩阵：" << endl;
		int *pn = new int[n];
		int **p = new int*[n];
		bool *S = new bool[n];
		int *Disk = new int[n];
		int *path = new int[n];
		for (int i = 0; i < n; i++)
		{
			p[i] = new int[n];
		}
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
				cin >> p[i][j];
			pn[i] = i;
		}
		cout << "深度优先遍历：";
		DFS(p, pn, 0, n);
		cout << endl;
		cout << "广度优先遍历：";
		BFS(p, pn, 0, n);
		cout << endl;
		MGraph xxx(p, n);
		cout << "普里姆算法生成最小生成树：";
		cout << endl;
		Prim(xxx);
		cout << endl;
		GenSortEdge(xxx);
		cout << "克鲁斯卡尔算法生成最小生成树：";
		cout << endl;
		Kruskal(n);
		cout << endl;
		cout << "非递归深度优先遍历：";
		cout << endl;
		DFS222(p, pn, 0, n);
		cout << endl;
		for (int i = 0; i<n; i++)
			for (int j = 0; j < n; j++) {
				if (i != j&&p[i][j]==0) {
					p[i][j] = MAX;
				}
				else
					p[i][j] = 0;
			}
		cout << "迪杰斯特拉算法：";
		cout << endl;
		cout << "输入最短路径的指定点：";
		int v;
		cin >> v;
		ShortPath(xxx, v, Disk, path,n);
		delete[]pn;
		for (int i = 0; i < n; i++)
			delete[]p[i];
		delete[]p;
	}
	system("pause");
	return 0;
}
