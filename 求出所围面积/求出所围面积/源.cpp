#include<iostream>
using namespace std;
class box 
{
public:
	box() {};
	box(int a, int b) {
		LL = a; RL = b;
	}
	int s() { int S = a*a; return S; }
	int ll() { return LL; }
	int rl() { return RL; }
	int s1=s();
	int A() { return a; }
private:
	int LL;
	int RL;
	int a = RL > LL ? (RL - LL) : (LL - RL);
};

void checkout(box p[],box q[])
{
	if((*p->ll)<(*q->rl))
	{
		if (*p->A > *q->A)
			(p->s1) = (p->s1) - (*q->rl - *p->ll)*(*q->A);
		else
			(q->s1) = (q->s1) - (*q->rl - *p->ll)*(*p->A);
	}
	else if ((*q->ll)<(*p->rl))
	{
		if (*p->A > *q->A)
			(p->s1) = (p->s1) - (*p->rl - *q->ll)*(*q->A);
		else
			(q->s1) = (q->s1) - (*p->rl - *q->ll)*(*p->A);
	}
}
int main() 
{
	int n;
	cin >> n;
	int *p = new int[n];
	box *q = new box[n];
	for(int i=0;i<n;i++)
	{
		cin >> p[i];
		cin >> p[i + 1];
		box q[i](p[i],p[i+1]);
	}

	return 0;
}