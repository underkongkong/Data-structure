#include<iostream>
#include "string"
#include "stack" 
#include "algorithm"
#include <cmath> 
using namespace std;
int main() 
{
	string str;
	while (getline(cin, str))
	{
		reverse(str.begin(), str.end());
		int nbegin = 0; int nend = 0;
		int pos = 0;
		int length = str.length();
		while(true)
		{
			if (pos == 0)
				nbegin = pos;
			else
				nbegin = pos + 1;
			pos = str.find(' ', pos + 1);
			if (pos == std::string::npos) {
				reverse(str.begin() + nbegin, str.end());
				break;
			}
			nend = pos;
			reverse(str.begin() + nbegin, str.begin() + nend);
		}
		cout << str << endl;
	}
	return 0;
}