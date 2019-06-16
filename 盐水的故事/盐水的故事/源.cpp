#include<iostream>
using namespace std;
int main() 
{
	double VUL, D;
	cin >> VUL >> D;
	int time = 0;
	for(int a=1;VUL>0;a++)
	{
		if (VUL -( a * D )<= 0)
		{
			while (VUL > 0.000001)
			{
				VUL -= D;
				time++;
			}
			break;
		}
		VUL -= a * D;
		time += a;
		time++;
	}
	cout << time << endl;
	system("pause");
	return 0;
}