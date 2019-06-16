#include<iostream>
#include <math.h>  
#include <windows.h>
#include<ctime>
using namespace std;
//1、插入排序√
//2、希尔排序√
//3、冒泡排序√
//4、快速排序√
//5、简单选择排序√
//6、堆排序（选作）√
//7、归并排序（选作）√
//8、基数排序（选作）

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
{	//如果链表为空，或者只有一个元素，直接返回即可  
	if (head == NULL || head->next == NULL)
		return head;
	//从链表的第二个元素开始遍历  
	Node<int> *p = head->next;
	while (p)
	{
		//如果当前遍历的元素小于已经排好序元素的最小元素，更新head指针  
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
		//指向要插入位置的前一个指针  
		Node<int> *q = head;
		while (q->next != p)
		{
			if (q->next->data< p->data)
				q = q->next;
			else
				break;
		}
		//当前元素已在插入的位置，直接移动p即可  
		if (q->next == p)
		{
			p = p->next;
		}
		else
		{
			//插入当前元素  
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
//正序输出链表  
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
	if (j == right) {//a中还有元素，且全都比b中的大,a[i]还未使用
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
		//将i和i+step这两个有序序列进行合并
		//序列长度为step
		//当i以后的长度小于或者等于step时，退出
		step *= 2;//在按某一步长归并序列之后，步长加倍
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
	cout << "转换次数:" << x[a - 1];
	cout << endl;
}
