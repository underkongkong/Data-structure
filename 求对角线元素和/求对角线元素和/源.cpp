#include<iostream>
using namespace std;
int main() 
{
	int matrix[3][3];
	for (int i = 0; i < 3; i++)
		for(int j=0;j<3;j++)
		cin >> matrix[i][j];
	int sum1 = matrix[0][0] + matrix[1][1] + matrix[2][2];
	int sum2 = matrix[0][2] + matrix[1][1] + matrix[2][0];
	cout << sum1 << " " << sum2 << endl;
	return 0;
}