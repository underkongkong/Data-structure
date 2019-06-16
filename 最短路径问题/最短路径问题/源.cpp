#include<iostream>
using namespace std;
int MAX = 1000000;
void floyd(int **& distmap,//�ɱ����µ��ڽӾ��󣬸��º���ȷ��ԭ�б�
	int ** &costs,int n)//·���ϵ���õ����ת��
						
{
	int NODE = n;//���ڽӾ���Ĵ�С���ݶ�����������ٲ�������
	for (int k = 0; k < NODE; k++)//����ÿһ����ת��
		for (int i = 0; i < NODE; i++)//ö��Դ��
			for (int j = 0; j < NODE; j++){//ö���յ�
				int select = (distmap[i][k] == MAX || distmap[k][j] == MAX) ? MAX : (distmap[i][k] + distmap[k][j]); {
					if (distmap[i][j] > select) {//���������ǲ���ʽ
						distmap[i][j] = distmap[i][k] + distmap[k][j];//����
						costs[i][j] = costs[i][k] + costs[k][j];
					}
					if ((distmap[i][j] == distmap[i][k] + distmap[k][j]) && (costs[i][j] > costs[i][k] + costs[k][j])) {
						costs[i][j] = costs[i][k] + costs[k][j];
					}
				}
			}
}

int main()
{
	int n_num, e_num, beg, end;//�������
	cin >> n_num >> e_num;
	int **distmap = new int*[n_num];
	int **costs = new int*[n_num];
	for (int i = 0; i < n_num; i++) {
		distmap[i] = new int[n_num];
		costs[i] = new int[n_num];
	}
	//Ĭ�ϳ�ʼ���ڽӾ���
	for(int i=0;i<n_num;i++)
		for (int j = 0; j < n_num; j++) {
			if (i != j) {
				distmap[i][j] = MAX;
				costs[i][j] = MAX;
			}
			else
				distmap[i][j] = 0;
				costs[i][j] = 0;
		}
	for (int i = 0, p, q; i <e_num; i++){
		cin >> p >> q;
		cin >> distmap[p-1][q-1];
		cin >> costs[p-1][q-1];
		distmap[q - 1][p - 1] = distmap[p - 1][q - 1];
		costs[q - 1][p - 1] = costs[p - 1][q - 1];
	}
	/*for (int i = 0; i < n_num; i++) {
		for (int j = 0; j < n_num; j++)
			cout << distmap[i][j] << " ";
		cout << endl;
	}*/
	floyd(distmap, costs ,n_num);
	cin >> beg >> end;
	cout << distmap[beg-1][end-1] << " ";
	cout << costs[beg-1][end-1];
	for (int i = 0; i < n_num; i++) {
		delete[]distmap[i];
		delete[]costs[i];
	}
	delete[]distmap;
	delete[]costs;
	system("pause");
	return 0;
}