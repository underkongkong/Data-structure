#include<iostream>
using namespace std;
int x = 0;
class solution
{
private:
	int i;
	int j;
	int k;
public:
	int n;
	solution(int k)
	{
		n = k;
	}
	void printsolution();
};
void solution::printsolution()
{
	for(i=0;i<100;i++)
		for(j=0;j<100;j++)
			for (k = 0; k < 100; k++)
			{
				if (k%3==0&&5 * i + 3 * j + k / 3 == n&&i+j+k==100)
				{
					x++;
					cout << "cock:" << i << " hen:" << j << " chick:" << k << endl;
				}
			}
	if (x == 0) cout << "No Solution";
}
int main()
{
	int n;
	cin >> n;
	solution abc(n);
	abc.printsolution();
	system("pause");
	return 0;
}