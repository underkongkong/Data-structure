#include"标头.h"
#include"标头1.h"
int main()
{
	
	double rumTime = 0.0;
	cout << "请输入排序的数组长度：";
	int n;
	cin >> n;
	int *r = new int[n + 1];
	cout << "请输入待排序的序列：";
	for (int i = 1; i < n + 1; i++)
	{
		cin >> r[i];
	}
	int ss;
	cout << "操作：1、插入排序 2、希尔排序 3、冒泡排序 4、快速排序 5、简单选择排序 6、堆排序 7、归并排序";
	cout << endl;
	cout << "请输入你要执行的操作：";
	while (cin >> ss)
	{
		int *rrr = new int[n + 1];
		for (int i = 0; i < n + 1; i++)
			rrr[i] = r[i];
		if (ss == 1)
		{
			LARGE_INTEGER cpuFreq1;
			LARGE_INTEGER startTime1;
			LARGE_INTEGER endTime1;
			QueryPerformanceFrequency(&cpuFreq1);
			QueryPerformanceCounter(&startTime1);
			InsertSort(rrr, n);
			QueryPerformanceCounter(&endTime1);
			rumTime = (((endTime1.QuadPart - startTime1.QuadPart) * 1000.0f) / cpuFreq1.QuadPart);
			printResult(rrr, n,1);
			cout << rumTime << " ms" << endl;
		}
		else if (ss == 7)
		{
			LARGE_INTEGER cpuFreq7;
			LARGE_INTEGER startTime7;
			LARGE_INTEGER endTime7;
			int *rrrrr = new int[n];
			for (int i = 0; i < n; i++)
				rrrrr[i] = r[i + 1];
			QueryPerformanceFrequency(&cpuFreq7);
			QueryPerformanceCounter(&startTime7);
			MergeSort(rrrrr,n);
			QueryPerformanceCounter(&endTime7);
			rumTime = (((endTime7.QuadPart - startTime7.QuadPart) * 1000.0f) / cpuFreq7.QuadPart);
			for (int i = 0; i < n ; i++)
				cout << rrrrr[i] << " ";
			cout << endl;
			cout << "转换次数: " << x[6]<<endl;
			cout << rumTime << " ms" << endl;
			delete[]rrrrr;
		}
		else if (ss == 6)
		{
			LARGE_INTEGER cpuFreq6;
			LARGE_INTEGER startTime6;
			LARGE_INTEGER endTime6;
			QueryPerformanceFrequency(&cpuFreq6);
			QueryPerformanceCounter(&startTime6);
			HeapSort(rrr, n);
			QueryPerformanceCounter(&endTime6);
			rumTime = (((endTime6.QuadPart - startTime6.QuadPart) * 1000.0f) / cpuFreq6.QuadPart);
			printResult(rrr, n,6);
			cout << rumTime << " ms" << endl;
		}
		else if (ss == 5)
		{
			LARGE_INTEGER cpuFreq5;
			LARGE_INTEGER startTime5;
			LARGE_INTEGER endTime5;
			QueryPerformanceFrequency(&cpuFreq5);
			QueryPerformanceCounter(&startTime5);
			SelectSort(rrr, n);
			QueryPerformanceCounter(&endTime5);
			rumTime = (((endTime5.QuadPart - startTime5.QuadPart) * 1000.0f) / cpuFreq5.QuadPart);
			printResult(rrr, n,5);
			cout << rumTime << " ms" << endl;

		}
		else if (ss == 4)
		{
			LARGE_INTEGER cpuFreq4;
			LARGE_INTEGER startTime4;
			LARGE_INTEGER endTime4;
			QueryPerformanceFrequency(&cpuFreq4);
			QueryPerformanceCounter(&startTime4);
			Qsort(rrr, 1, n);
			QueryPerformanceCounter(&endTime4);
			rumTime = (((endTime4.QuadPart - startTime4.QuadPart) * 1000.0f) / cpuFreq4.QuadPart);
			printResult(rrr, n,4);
			cout << rumTime << " ms" << endl;
		}
		else if (ss == 3)
		{
			LARGE_INTEGER cpuFreq3;
			LARGE_INTEGER startTime3;
			LARGE_INTEGER endTime3;
			QueryPerformanceFrequency(&cpuFreq3);
			QueryPerformanceCounter(&startTime3);
			BubbleSort(rrr, n);
			QueryPerformanceCounter(&endTime3);
			rumTime = (((endTime3.QuadPart - startTime3.QuadPart) * 1000.0f) / cpuFreq3.QuadPart);
			printResult(rrr, n,3);
			cout << rumTime << " ms" << endl;
		}
		else if (ss == 2)
		{
			LARGE_INTEGER cpuFreq2;
			LARGE_INTEGER startTime2;
			LARGE_INTEGER endTime2;
			QueryPerformanceFrequency(&cpuFreq2);
			QueryPerformanceCounter(&startTime2);
			ShellInsert(rrr, n);
			QueryPerformanceCounter(&endTime2);
			rumTime = (((endTime2.QuadPart - startTime2.QuadPart) * 1000.0f) / cpuFreq2.QuadPart);
			printResult(rrr, n,2);
			cout << rumTime << " ms" << endl;
		}//else if (ss == 2)LinkList<int> rl(r, n);
		//else if (ss == 2)LinkInsertSort(rl.front->next);
		//show(rl.front);
		delete[]rrr;
		//rl.~LinkList();
	}
	delete[]r;
	system("pause");
	return 0;
}