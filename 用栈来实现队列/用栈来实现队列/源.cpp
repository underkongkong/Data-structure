#include<iostream>
#include<string>
using namespace std;
const int StackSize = 1024;
class SeqStack
{
public:
	SeqStack() { top = -1;}
	void Push(int x);
	void Pop();
	bool Empty();
	int top1() { return data[top]; };
private:
	int data[StackSize];
	int top;
};
void SeqStack::Push(int x)
{
	if (top < StackSize - 1)
	{
		top++;
		data[top] = x;
	}
}
void SeqStack::Pop()
{
		top--;
}
bool SeqStack::Empty()
{
	if ((top == -1))
		return 1;
	else
		return 0;
}
int main()
{
	SeqStack stack1;
	SeqStack stack2;
	string str;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> str;
		if (str == "PUSH")
		{
			int temp;
			cin >> temp;
			while (!stack2.Empty())
			{
				stack1.Push(stack2.top1());
				stack2.Pop();
			}
			stack1.Push(temp);

		}
		else if (str == "POP")
		{
			while (!stack1.Empty())//出队时，要保证stack1为空
			{
				stack2.Push(stack1.top1());
				stack1.Pop();
			}
			if (stack2.Empty())
				cout << "-1";
			else
				cout <<stack2.top1() << endl;
			int temp = stack2.top1();
			stack2.Pop();
		}
	}
	system("pause");
	return 0;
}