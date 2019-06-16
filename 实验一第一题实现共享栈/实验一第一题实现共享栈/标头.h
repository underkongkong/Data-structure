#include<iostream>
using namespace std;
const int StackSize = 1024;
template<class T>
class ShareSeqStack
{
public:
	ShareSeqStack() { top1 = -1; top2 = StackSize; }
	void PushStack1(T x);
	void PushStack2(T x);
	T Pop1();
	T Pop2();
	bool Empty1() { return top1 == -1; }
	bool Empty2() { return top2 == StackSize; }
private:
	T data[StackSize];
	int top1;
	int top2;
};
template<class T>
void ShareSeqStack<T>::PushStack1(T x)
{
	if (top1 + 1 == top2)
		throw"overflow";
	top1++;
	data[top1] = x;
}
template<class T>
void ShareSeqStack<T>::PushStack2(T x)
{
	if (top1 + 1 == top2)
		throw"overflow";
	top2--;
	data[top2] = x;
}
template<class T>
T ShareSeqStack<T>::Pop1()
{
	if (Empty1())
		throw"downflow";
	return data[top1--];
}
template<class T>
T ShareSeqStack<T>::Pop2()
{
	if (Empty2())
		throw"downflow";
	return data[top2++];
}
