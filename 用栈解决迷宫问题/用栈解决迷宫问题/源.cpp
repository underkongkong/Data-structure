#include<iostream>
#include<vector>
using namespace std;
const int StackSize = 1024;
struct place
{
	int x;
	int y;
	int d;
};
template<class T>
class SeqStack
{
public:
	SeqStack() { top1 = -1; }
	void PushStack1(T x);
	T Pop1();
	bool Empty1() { return top1 == -1; }
private:
	T data[StackSize];
	int top1;
};
template<class T>
void SeqStack<T>::PushStack1(T x)
{
	if (top1 + 1 == StackSize)
		throw"overflow";
	top1++;
	data[top1] = x;
}
template<class T>
T SeqStack<T>::Pop1()
{
	if (Empty1())
		throw"downflow";
	return data[top1--];
}

bool solution(int ** a, place begin, place end,int row,int col)
{
	SeqStack<place> n;
	n.PushStack1(begin);
	while (!n.Empty1())
	{
		place next;
		next = n.Pop1();
		//next.d++;
		if (next.d == 0)
		{
			if (next.x>0&&a[next.x-1][next.y] == 1)
			{
				next.x--;
				next.y++;
				n.PushStack1(next);
				if (next.x==end.x&&next.y == end.y)
					return true;
				else
					next.d = 0;
			}
			else next.d++;
		}
		else if (next.d == 1)
		{
			if (next.x>0&&next.y<col-1&&a[next.x-1][next.y + 1] == 1)
			{
				next.x--;
				next.y++;
				n.PushStack1(next);
				if (next.x == end.x&&next.y == end.y)
					return true;
				else
					next.d = 0;
			}
			else next.d++;
		}
		else if (next.d == 2)
		{
			if (next.y < col - 1 && a[next.x ][next.y + 1] == 1)
			{
				next.y = next.y + 1;
				n.PushStack1(next);
				if (next.x == end.x&&next.y == end.y)
					return true;
				else
					next.d = 0;
			}
			else next.d++;
		}
		else if (next.d == 3)
		{
			if (next.x < row - 1 && next.y < col - 1 && a[next.x+1 ][next.y + 1] == 1)
			{
				next.x++;
				next.y++;
				n.PushStack1(next);
				if (next.x == end.x&&next.y == end.y)
					return true;
				else
					next.d = 0;
			}
			else next.d++;
		}
		else if (next.d == 4)
		{
			if (next.x < row - 1 && a[next.x + 1][next.y] == 1)
			{
				next.x++;
				n.PushStack1(next);
				if (next.x == end.x&&next.y == end.y)
					return true;
				else
					next.d = 0;
			}
			else next.d++;
		}
		else if (next.d == 5)
		{
			if (next.x < row - 1 && next.y>0 && a[next.x - 1][next.y + 1] == 1)
			{
				next.x++;
				next.y--;
				n.PushStack1(next);
				if (next.x == end.x&&next.y == end.y)
					return true;
				else
					next.d = 0;
			}
			else next.d++;
		}
		else if (next.d == 6)
		{
			if (next.y>0 && a[next.x ][next.y --] == 1)
			{
				next.y--;
				n.PushStack1(next);
				if (next.x == end.x&&next.y == end.y)
					return true;
				else
					next.d = 0;
			}
			else next.d++;
		}
		else if ( next.d == 7)
		{
			if (next.y > 0 && next.x > 0 && a[next.x - 1][next.y - 1] == 1)
			{
				next.x--;
				next.y--;
				n.PushStack1(next);
				if (next.x == end.x&&next.y == end.y)
					return true;
				else
					next.d = 0;
			}
			else
				return false;
		}
	}
	return false;
}
int main()
{
	int x;
	int y;
	cin >> x>>y;
	int** miss=new int*[x];
	for (int i = 0; i < x; i++)
	{
		miss[i] = new int[y];
	}
	for (int i = 0; i < x; i++)
		for (int j = 0; j < y; j++)
		{
			cin >> miss[i][j];
		}
	int beginX, beginY;
	cin >> beginX >> beginY;
	int endX, endY;
	cin >> endX >> endY;
	place begin,end;
	begin.x = beginX;
	begin.y = beginY;
	begin.d = 0;
	end.x = endX;
	end.y = endY;
	bool result = solution(miss, begin, end, x, y);
	if (result)
		cout << "success";
	else
		cout << "false";
	for (int i = 0; i < x; i++)
		delete[]miss[i];
	delete[]miss;
	system("pause");
	return 0;
}