#include<iostream>
#include<vector>
using namespace std;
const int &INF = 100000000;
void floyd(vector<vector<int> > &distmap,//�ɱ����µ��ڽӾ��󣬸��º���ȷ��ԭ�б�
	vector<vector<int> > &path)//·���ϵ���õ����ת��
							   //�������������û���ó�INF����κ�ȫ����������ֱ�Ӹ��ƣ�
{
	const int &NODE = distmap.size();//���ڽӾ���Ĵ�С���ݶ�����������ٲ�������
	path.assign(NODE, vector<int>(NODE, -1));//��ʼ��·������ 
	for (int k = 1; k != NODE; ++k)//����ÿһ����ת��
		for (int i = 0; i != NODE; ++i)//ö��Դ��
			for (int j = 0; j != NODE; ++j)//ö���յ�
				if (distmap[i][j]>distmap[i][k] + distmap[k][j])//���������ǲ���ʽ
				{
					distmap[i][j] = distmap[i][k] + distmap[k][j];//����
					path[i][j] = k;//��¼·��
				}
}
void print(const int &beg, const int &end,
	const vector<vector<int> > &path)//�����ã����⿽������ռ���ڴ�ռ�
									 //Ҳ������ջ�ṹ�Ƚ���������������溯���ݹ� 
{
	if (path[beg][end] >= 0)
	{
		print(beg, path[beg][end], path);
		print(path[beg][end], end, path);
	}
	else cout << "->" << end;
}
int main()
{
	int n_num, e_num, beg, end;//�������
	cout << "��������Ȩ��·�����������������";
	cin >> n_num >> e_num;
	vector<vector<int> > path,
		distmap(n_num, vector<int>(n_num, INF));//Ĭ�ϳ�ʼ���ڽӾ���
	for (int i = 0, p, q; i != e_num; ++i)
	{
		cout << "�����" << i + 1 << "���ߵ���㡢�յ㡢���ȣ�100000000��������󣬲���ͨ����";
		cin >> p >> q;
		cin >> distmap[p][q];
	}
	floyd(distmap, path);
	cout << "������ϣ����Կ�ʼ��ѯ���������������յ㣺";
	cin >> beg >> end;
	cout << "��̾���Ϊ" << distmap[beg][end] << "����ӡ·����" << beg;
	print(beg, end, path);
}