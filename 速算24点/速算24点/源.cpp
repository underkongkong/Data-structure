#include<iostream>
using namespace std;
int Calculate(int x, int y, int z,int w);
int main()
{
	char a1[4];
	for (int i = 0; i < 4; i++)
		cin >> a1[i];
	int a2[4];
	for (int i = 0; i < 4; i++)
	{
		if (a1[i] == 'A')
			a2[i] = 1;
		else if (a1[i] == 'J')
			a2[i] = 11;
		else if (a1[i] == 'Q')
			a2[i] = 12;
		else if (a1[i] == 'K')
			a2[i] = 13;
		else
			a2[i] = (int)a1[i]-48;
	}
	int a = a2[0];
	int b = a2[1];
	int c = a2[2];
	int d = a2[3];
	int x = 0;
	if (Calculate(a, b, c, d) + Calculate(a, b, d, c) + Calculate(a, c, d, b) +
		Calculate(a, c, b, d) + Calculate(a, d, b, c) + Calculate(a, d, c, b) +
		Calculate(b, a, c, d) + Calculate(b, a, d, c) + Calculate(b, c, a, d) +
		Calculate(b, c, d, a) + Calculate(b, d, c, a) + Calculate(b, d, a, c) +
		Calculate(c, a, b, d) + Calculate(c, a, d, b) + Calculate(c, b, d, a) +
		Calculate(c, b, a, d) + Calculate(c, d, a, b) + Calculate(c, d, b, a) +
		Calculate(d, a, b, c) + Calculate(d, a, c, b) + Calculate(d, b, c, a) +
		Calculate(d, b, a, c) + Calculate(d, c, a, b) + Calculate(d, c, b, a) == 0)
		cout << "N";
	else
		cout << "Y";
	system("pause");
	return 0;
}

int Calculate(int x, int y, int z, int w) //运算表达式的所有情况  
{
	if (x + y + z + w == 24) return 1;//cout << x << "+" << y << "+" << z << "+" << w << "=24" << endl;
	else if (x + y + z - w == 24)  return 1;//cout << x << "+" << y << "+" << z << "-" << w << "=24" << endl;
	else if ((x + y)*(z + w) == 24)  return 1;//cout << "(" << x << "+" << y << ")*(" << z << "+" << w << ")=24" << endl;
	else if ((x - y)*(z + w) == 24)  return 1;//cout << "(" << x << "-" << y << ")*(" << z << "+" << w << ")=24" << endl;
	else if ((x - y)*(z - w) == 24)  return 1;//cout << "(" << x << "-" << y << ")*(" << z << "-" << w << ")=24" << endl;
	else if ((x + y + z)*w == 24)  return 1;//cout << "(" << x << "+" << y << "+" << z << ")*" << w << "=24" << endl;
	else if ((x - y - z)*w == 24)  return 1;//cout << "(" << x << "-" << y << "-" << z << ")*" << w << "=24" << endl;
	else if ((x + y - z)*w == 24)  return 1;//cout << "(" << x << "+" << y << "-" << z << ")*" << w << "=24" << endl;
	else if ((x*y*z) % w==0&&(x*y*z) / w == 24 )  return 1;//cout << "(" << x << "*" << y << "*" << z << ")/" << w << "=24" << endl;
	else if ((x*y)*(z + w) == 24)  return 1;//cout << "(" << x << "*" << y << ")*(" << z << "+" << w << ")=24" << endl;
	else if ((x*y)*(z - w) == 24)  return 1;//cout << "(" << x << "*" << y << ")*(" << z << "-" << w << ")=24" << endl;
	else if ((x*y)*z - w == 24)  return 1;//cout << "(" << x << "*" << y << ")*(" << z << ")-" << w << "=24" << endl;
	else if ((x*y)*z + w == 24)  return 1;//cout << "(" << x << "*" << y << ")*(" << z << ")+" << w << "=24" << endl;
	else if (x*y*z*w == 24)  return 1;//cout << x << "*" << y << "*" << z << "*" << w << "=24" << endl;
	else if ((z%w == 0) && (x + y) + (z / w) == 24)  return 1;//cout << "(" << x << "+" << y << ")+(" << z << "/" << w << ")" << "=24" << endl;
	else if ((z%w == 0) && (x + y) * (z / w) == 24)  return 1;//cout << "(" << x << "+" << y << ")*(" << z << "/" << w << ")" << "=24" << endl;
	else if ((x*y) + z + w == 24)  return 1;//cout << "(" << x << "*" << y << ")+" << z << "+" << w << "=24" << endl;
	else if ((x*y) + z - w == 24)  return 1;//cout << "(" << x << "*" << y << ")+" << z << "-" << w << "=24" << endl;
	else if ((z%w == 0) && (x*y) - (z / w) == 24)  return 1;//cout << "(" << x << "*" << y << ")-(" << z << "/" << w << ")" << "=24" << endl;
	else if ((z%w == 0) && (x*y) + (z / w) == 24)  return 1;//cout << "(" << x << "*" << y << ")-(" << z << "/" << w << ")" << "=24" << endl;
	else if ((x*y) - z - w == 24)  return 1;//cout << "(" << x << "*" << y << ")-" << z << "-" << w << "=24" << endl;
	else if ((x*y) + (z*w) == 24)  return 1;//cout << "(" << x << "*" << y << ")+(" << z << "*" << w << ")" << "=24" << endl;
	else if ((x*y) - (z*w) == 24)  return 1;//cout << "(" << x << "*" << y << ")-(" << z << "*" << w << ")" << "=24" << endl;
	else if ((x*y) % (z*w) == 0 &&(x*y) / (z*w) == 24)  return 1;//cout << "(" << x << "*" << y << ")/(" << z << "*" << w << ")" << "=24" << endl;
	else if ((z-w)!=0 && (x*y) % (z-w) == 0 && (x*y) / (z - w) == 24)  return 1;//cout << "(" << x << "*" << y << ")/(" << z << "-" << w << ")" << "=24" << endl;
	else if ((x*y) % (z+w) == 0 && (x*y) / (z + w) == 24)  return 1;//cout << "(" << x << "*" << y << ")/(" << z << "+" << w << ")" << "=24" << endl;
	else return 0;
}