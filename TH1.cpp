#include <iostream>
#include <cmath>
using namespace std;
/*int main()
{
	int n;
	int* p = NULL;
	n = 20;
	p = &n;
	cout << "n: Addr=" << &n << ", Val=" << n << endl;
	cout << "n: Addr=" << &p << ", Val=" << p << ", ValRef=" << *p<<endl;
	int* pn = NULL;
	pn = (int*)malloc(sizeof(int));
	(*pn) = 10;
	cout << "sizeof(int): " << sizeof(int)<<endl;
	cout << "pn: Addr=" << &pn << ", Val=" << pn << ", ValRef=" << *pn;
	free(pn);
	return 0;
} */
/*void Hoanvi(int a, int b)
{
	int tmp = a;
	a = b;
	b = tmp;
} 
void Hoanvi(int& a, int& b)
{
	int tmp = a;
	a = b;
	b = tmp;
} */
void HoanVi(int* a, int* b)
{
	int tmp = (*a);
	(*a) = (*b);
	(*b) = tmp;
}
int main()
{
	int x = 5;
	int y = &x;
	cout << "x: Addr= " << &x << ", Val= " << x <<endl;
	/*Hoanvi(&x, &y);*/
	cout << "x: Addr= " << &y << ", Val= " << y << endl;
	return 0;
} 
//TH1


