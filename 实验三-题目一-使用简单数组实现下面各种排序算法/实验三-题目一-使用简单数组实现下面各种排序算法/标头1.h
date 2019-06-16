#include<iostream>
#include <math.h>  
#include <windows.h>
#include<ctime>
using namespace std;
//1�����������
//2��ϣ�������
//3��ð�������
//4�����������
//5����ѡ�������
//6��������ѡ������
//7���鲢����ѡ������
//8����������ѡ����

//1
int x[7] = { 0 };
int x2[7] = { 0 };
void InsertSort(int r[], int n)
{
	for (int i = 2; i <= n; i++)
	{
		x2[0]++;
		if (r[i] < r[i - 1])
		{
			r[0] = r[i];
			int j = i - 1;
			x2[0]++;
			for (; r[0] < r[j]; j--)
			{
				x2[0]++;
				r[j + 1] = r[j];
				x[0]++;
			}
			r[j + 1] = r[0];
			x[0]+=2;
		}
	}
}
Node<int>* LinkInsertSort(Node<int> *head)
{	//�������Ϊ�գ�����ֻ��һ��Ԫ�أ�ֱ�ӷ��ؼ���  
	if (head == NULL || head->next == NULL)
		return head;
	//������ĵڶ���Ԫ�ؿ�ʼ����  
	Node<int> *p = head->next;
	while (p)
	{
		//�����ǰ������Ԫ��С���Ѿ��ź���Ԫ�ص���СԪ�أ�����headָ��  
		if (p->data < head->data)
		{
			Node<int> *tmp1 = head;
			while (tmp1->next != p)
			{
				tmp1 = tmp1->next;
			}
			Node<int> *tmp = p;
			p = p->next;
			tmp1->next = p;
			tmp->next = head;
			head = tmp;
			continue;
		}
		//ָ��Ҫ����λ�õ�ǰһ��ָ��  
		Node<int> *q = head;
		while (q->next != p)
		{
			if (q->next->data< p->data)
				q = q->next;
			else
				break;
		}
		//��ǰԪ�����ڲ����λ�ã�ֱ���ƶ�p����  
		if (q->next == p)
		{
			p = p->next;
		}
		else
		{
			//���뵱ǰԪ��  
			Node<int> *tmp1 = q;
			while (tmp1->next != p)
			{
				tmp1 = tmp1->next;
			}
			Node<int> *tmp = p;
			p = p->next;
			tmp1->next = p;
			tmp->next = q->next;
			q->next = tmp;
		}
	}
	return head;
}
//�����������  
void show(Node<int> *pHead)
{
	while (pHead)
	{
		cout << pHead->data << " ";
		pHead = pHead->next;
	}
	cout << endl;
}

void ShellInsert(int r[], int n)
{
	for (int d = n / 2; d >= 1; d = d / 2)
	{
		for (int i = d + 1; i <= n; i++)
		{
			x2[1]++;
			if (r[i] < r[i - d])
			{
				r[0] = r[i];
				int j = i - d;
				for (; j > 0 && r[0] < r[j]; j = j - d)
				{
					r[j + d] = r[j];
					x[1]++;
				}
				r[j + d] = r[0];
				x[1] += 2;
			}
		}
	}
}

void BubbleSort(int r[], int n)
{
	for (int i = 1; i < n + 1; i++)
	{
		for (int j = 1; j < n - i + 1; j++)
		{
			if (r[j] > r[j + 1])
			{
				r[0] = r[j];
				r[j] = r[j + 1];
				r[j + 1] = r[0];
				x[2] += 3;
			}
		}
	}
}
int Partion(int r[], int first, int end)
{
	int i = first;
	int j = end;
	int pivot = r[i];
	while (i < j)
	{
		while ((i < j) && (r[j] >= pivot))
			j--;
		r[i] = r[j];
		x[3]++;
		while ((i < j) && (r[j] <= pivot))
			i++;
		r[j] = r[i];
		x[3]++;
	}
	r[i] = pivot;
	return i;
}
void Qsort(int r[], int i, int j)
{
	if (i < j)
	{
		int pivotloc = Partion(r, i, j);
		Qsort(r, i, pivotloc - 1);
		Qsort(r, pivotloc + 1, j);
	}
}


void SelectSort(int r[], int n)
{
	for (int i = 1; i < n; i++)
	{
		int index = i;
		for (int j = i + 1; j <= n; j++)
			if (r[j] < r[index])
				index = j;
		if (index != 1)
		{
			r[0] = r[i];
			r[i] = r[index];
			r[index] = r[0];
			x[4]+=3;
		}
	}
}

void Sift(int r[], int k, int m)
{
	int i = k, j = 2 * i;
	while (j <= m)
	{
		if (j < m&&r[j] < r[j + 1])j++;
		if (r[i] >= r[j])break;
		else {
			r[0] = r[i];
			r[i] = r[j];
			r[j] = r[0];
			x[5] += 3;
		}
		i = j;
		j = 2 * i;
	}
}

void HeapSort(int r[], int n)
{
	for (int i = n / 2; i >= 1; i--)
		Sift(r, i, n);
	for (int i = n; i > 1; i--)
	{
		r[0] = r[1]; r[1] = r[i]; r[i] = r[0];
		x[5] += 3;
		Sift(r, 1, i - 1);
	}
}
void Merge(int* data, int a, int b, int length, int n) {
	int right;
	if (b + length - 1 >= n - 1) right = n - b;
	else right = length;
	int* temp = new int[length + right];
	int i = 0, j = 0;
	while (i <= length - 1 && j <= right - 1) {
		if (data[a + i] <= data[b + j]) {
			temp[i + j] = data[a + i]; i++;
			x[6]++;
		}
		else {
			temp[i + j] = data[b + j];
			x[6]++;
			j++;
		}
	}
	if (j == right) {//a�л���Ԫ�أ���ȫ����b�еĴ�,a[i]��δʹ��
		memcpy(temp + i + j, data + a + i, (length - i) * sizeof(int));
	}
	else if (i == length) {
		memcpy(temp + i + j, data + b + j, (right - j) * sizeof(int));
	}
	memcpy(data + a, temp, (right + length) * sizeof(int));
	delete[] temp;
}
void MergeSort(int* data, int n) {
	int step = 1;
	while (step < n) {
		for (int i = 0; i <= n - step - 1; i += 2 * step)
			Merge(data, i, i + step, step, n);
		//��i��i+step�������������н��кϲ�
		//���г���Ϊstep
		//��i�Ժ�ĳ���С�ڻ��ߵ���stepʱ���˳�
		step *= 2;//�ڰ�ĳһ�����鲢����֮�󣬲����ӱ�
	}
}
/*
void Merge(int r[], int r1[], int s, int m, int t)
{
int i = s;
int j = m + 1;
int k = s;
while (i <= m&&j <= t)
{
if (r[i] <= r[j])
r1[k] = r[i++];
else
r1[k] = r[j++];
}
while (i <= m) r1[k++] = r[i++];
while (j <= t) r1[k++] = r[j++];
}
void MergePass(int r[], int r1[], int n, int h)
{
int i = 1;
while (i <= n - 2 * h + 1)
{
Merge(r, r1, i, i + h - 1, i + 2 * h - 1);
i += 2*h;
}
if (i < n - h + 1)
Merge(r, r1, i, i + h - 1, n);
else
for (; i <= n; i++)
r1[i] = r[i];
}
void MergeSort(int r[], int r1[], int n)
{
int h = 1;
while (h < n)
{
MergePass(r, r1, n, h);
h = 2 * h;
MergePass(r1, r, n, h);
h = 2 * h;
}
}
*/
void printResult(int r[], int n,int a)
{
	for (int i = 1; i < n + 1; i++)
		cout << r[i] << " ";
	cout << "ת������:" << x[a - 1];
	cout << endl;
}
