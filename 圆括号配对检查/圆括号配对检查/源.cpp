#include<iostream>
using namespace std;
int main()
{
	char a[200];
	int judgenum = 0;
	cin >> a;
	int length = 0;
	int i = 0;
	while (a[i])
	{
		length++;
		i++;
	}
	for (int i=0; i < length; i++)
	{
		if (a[i] == '(')
			judgenum++;
		else if (a[i] == ')')
			judgenum--;
		if (judgenum < 0)
		{
			cout << "Error" << endl;
			system("pause");
			return 0;
		}
	}
	if (judgenum < 0 || judgenum>=1)
		{
			cout << "Error" << endl;
			system("pause");
			return 0;
		}
	else cout << "OK" << endl;
	system("pause");
	return 0;
}