#include<iostream>
using namespace std;
void output(int n,int m)
{
	switch (n)
	{
	case 0:cout << "¼×";
		break;
	case 1:cout << "ÒÒ";
		break;
	case 2:cout << "±û";
		break;
	case 3:cout << "¶¡";
		break;
	case 4:cout << "Îì";
		break;
	case 5:cout << "¼º";
		break;
	case 6:cout << "¸ı";
		break;
	case 7:cout << "ĞÁ";
		break;
	case 8:cout << "ÈÉ";
		break;
	case 9:cout << "¹ï";
		break;
	}
	switch (m)
	{
		//×Ó¡¢³ó¡¢Òú¡¢Ã®¡¢³½¡¢ËÈ¡¢Îç¡¢Î´¡¢Éê¡¢ÓÏ¡¢Ğç¡¢º¥
	case 0:cout << "×Ó";
		break;
	case 1:cout << "³ó";
		break;
	case 2:cout << "Òú";
		break;
	case 3:cout << "Ã®";
		break;
	case 4:cout << "³½";
		break;
	case 5:cout << "ËÈ";
		break;
	case 6:cout << "Îç";
		break;
	case 7:cout << "Î´";
		break;
	case 8:cout << "Éê";
		break;
	case 9:cout << "ÓÏ";
		break;
	case 10:cout << "Ğç";
		break;
	case 11:cout << "º¥";
		break;
	}
}
int main()
{
	int n;
	cin >> n;
	int x = n - 4;
	x = x % 60;
	int h = x % 10;
	int e = x % 12;
	output(h, e);
	system("pause");
	return 0;
}