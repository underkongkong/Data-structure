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
		adjvex[i] = 0; lowcost[i] = G.arcs[0][i];//�洢���е�v0�ı�
	}
	lowcost[0] = 0;                      //��ʼ��U={V0}
	for (int i = 1; i < G.vNum; i++)
	{
		int k = mininum(G, lowcost);     //����һ����Ȩֵ��С���ڽӵ�
		cout << 'V' << adjvex[k] << "->V" << k << endl;
		result += lowcost[k];
		lowcost[k] = 0;                  //U=U+{Vk}      
		for (int j = 0; j < G.vNum; j++) //���¸�������
		{ 
			if (lowcost[j] != 0 && G.arcs[k][j] < lowcost[j])
			{
				lowcost[j] = G.arcs[k][j];
				adjvex[j] = k;           //���Ӹ�·��
			}
		}
	}
	cout << result;                      //������·������
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
	for (i = 0; i<G.vNum; i++)                                //�Ա߽��и�ֵ
		for (j = i; j<G.vNum; j++)
			if (G.arcs[i][j] != 0&& G.arcs[i][j] != MAX){
				EdgeList[k].fromV = i;
				EdgeList[k].endV = j;
				EdgeList[k].weight = G.arcs[i][j];
				k++;
			}
	for (i = 1; i < G.arcNum ; i++) {						  //�Ա߽�������
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
				EdgeList[j + 1].weight = t.weight;				//û��д��=�������������
			}
	}
	cout << G.arcNum << endl;
}

void Kruskal( int n)
{
	int result = 0;
	int vset[MAX_VERTEX];										//Ϳɫ����
	for (int i = 0; i < n; i++) vset[i] = i;
	int k = 0, j = 0;
	while (k < n - 1)
	{
		int m = EdgeList[j].fromV, l = EdgeList[j].endV;		//��ǰ��̱ߵ������յ�
		int sn1 = vset[m];										//�����ɫ
		int sn2 = vset[l];										//�յ���ɫ
		if (sn1 != sn2)											//��ɫ����
		{
			cout << 'V' << m << "->V" << l << endl;				//��������յ�
			k++;
			result += EdgeList[j].weight;
			for (int i = 0; i < n; i++){
				if (vset[i] == sn2){							//�����к��յ���ɫһ���ĵ�ͿɫΪ�����ɫ
					vset[i] = sn1;
				}
			}
		}
		j++;
	}
	cout << result << endl;                                     //������·��
	for (int i = 0; i < 6; i++)									//���·�������Ķ���˳��
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
	cout << "����ͼ�Ľڵ���";
	while (cin >> n) {
		cout << "����ͼ���ڽӾ���" << endl;
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
		cout << "������ȱ�����";
		DFS(p, pn, 0, n);
		cout << endl;
		cout << "������ȱ�����";
		BFS(p, pn, 0, n);
		cout << endl;
		MGraph xxx(p, n);
		cout << "����ķ�㷨������С��������";
		cout << endl;
		Prim(xxx);
		cout << endl;
		GenSortEdge(xxx);
		cout << "��³˹�����㷨������С��������";
		cout << endl;
		Kruskal(n);
		cout << endl;
		cout << "�ǵݹ�������ȱ�����";
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
		cout << "�Ͻ�˹�����㷨��";
		cout << endl;
		cout << "�������·����ָ���㣺";
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
