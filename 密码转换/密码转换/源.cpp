#include<iostream>
#include<string>
#include<stdlib.h>
using namespace std;
int main()
{
	string letters;
	int sum = 0;
	getline(cin,letters);
	int l = letters.size();
    int x=letters[l - 1];
	x =x - 'A';
	for (int k = 0; k < l-2; k++)
	{
		if (isalpha(letters[k]))
		{
			if (letters[k] <= letters[l - 1])
				letters[k] = 'Z' - (x - letters[k] + 'A');
			else
				letters[k] = letters[k] - x - 1;
		}
	}
	for (int i = 0; i < l - 1; i++)
		cout << letters[i];
	system("pause");
	return 0;
}