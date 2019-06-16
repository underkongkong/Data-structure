#include<iostream>
using namespace std;
struct term
{
	double coef;   //系数
	int expn;    //指数
	term(double c=0,int e=0):coef(c),expn(e){}
};

class Poly
{
public:
	Poly(term a[], int n);
	void add(Poly &B);
	int n;
	term *po;
	int maxexpn;
	void print()
	{
		for (int i = 0; i < n &&po[i].coef!=0; i++)
			cout << "(" << po[i].coef << ":" << po[i].expn << ")";
		cout << endl;
	}
	~Poly();
};

Poly::Poly(term a[], int x)
{
	n = x;
	po = new term[n];
	for (int i = 0; i < n; i++)
	{
		po[i].coef = a[i].coef;
		po[i].expn = a[i].expn;
	}
}

void Poly::add(Poly &B)
{
	maxexpn = 0;
	for (int i = 0; i < n; i++)
		if (po[i].expn > maxexpn)
			maxexpn = po[i].expn;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++) {
			if (po[i].expn == B.po[j].expn)
				po[i].coef += B.po[j].coef;
		}
	}
}
Poly::~Poly()
{
	delete[]po;
}
int main() {
	term ttttt[] = { term(1,0),term(2.3,2),term(3,4) };
	term ttt[] = { term(1,1),term(-2.3,2),term(5,10) };
	Poly a(ttttt, 3), b(ttt, 4);
	a.add(b);
	a.print();
	system("pause");
	return 0;
}