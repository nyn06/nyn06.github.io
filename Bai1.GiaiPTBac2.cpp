#include <iostream>
#include <cmath>
using namespace std;
int GiaiPTBac2(float a, float b, float c, float& x1, float& x2)
{
	int sn = -1;
	if (a == 0)
	{
		if (b == 0)
		{
			if (c == 0)
				sn = -1;
			else
				sn = 0;

		}
		else
		{
			sn = 1;
			x1 = -c / b;
		}
	}
	else
	{
		float denta = pow(b, 2) - 4 * a * c;
		if (denta < 0)
			sn = 0;
		else if (denta == 0)
		{
			sn = 1;
			x1 = -b / 2 * a;
		}
		else
		{
			sn = 2;
			x1 = (-b + sqrt(denta)) / 2 * a;
			x2 = (-b - sqrt(denta)) / 2 * a;
			if (x1 > x2)
			{
				float temp = x1;
				x1 = x2;
				x2 = temp;
			}
		}
	}
	return sn;
}
int main()
{
	float a, b, c;
	int sn;
	float x1, x2;
	cout << "Nhap a,b,c: ";
	cin >> a >> b >> c;
	sn = GiaiPTBac2(a, b, c, x1, x2);
	if (sn == -1)
		cout << "phuong trinh co vo so nghiem";
	else if (sn == 0)
		cout << "phuong trinh vo nghiem";
	else
	{
		cout << "phuong trinh co " << sn << " nghiem ";
		cout << x1 << " ";
		if (sn == 2)
			cout << x2 <<endl;
	}
	return 0;
}