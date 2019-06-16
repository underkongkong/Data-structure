#include<iostream>
using namespace std;
int countsum(int a) 
{
	int psum=0;
	if (a==1||a==2||a==3)
		psum = 1;
	else if (a >=4)
		psum = countsum(psum - 3) + countsum(psum - 1);
	return psum;
}
int main()
{
	int N;
	cin >> N;
	int sum=1;
	int year=1;
	if (1 <= N&&N < 4)
		sum = 0;
	else
		sum=countsum(N);
	cout << sum<< endl;
	system("pause");
	return 0;
}