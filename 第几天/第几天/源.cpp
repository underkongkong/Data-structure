#include<iostream>
using namespace std;
int judgeloopyear(int a) {
	if ((a % 4 == 0 && a % 100 != 0) || (a % 400 == 0))
		return 1;
	else
		return 0;
}
class getindex {
public:
	getindex(int a, int b, int c) { year = a; month = b; day = c; }
	int whatday() 
	{
		int months[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
		int index = 0;
		if (judgeloopyear(year))
			months[1] += 1;
		for (int i = 0; i < month-1; i++)
			index += months[i];
		index += day;
		return index;
	};
private:
	int year;
	int month;
	int day;
};
int main() 
{
	int a, b, c;
	char e, f;
	while (cin >> a >> e >> b >> f >> c)
	{
		getindex day(a, b, c);
		cout << day.whatday() << endl;
	}
	return 0;
}