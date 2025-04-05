/*#include<iostream>
using namespace std;
bool timx(int a[], int n, int x)
// Mảng a có n phần tử và chưa có thứ tự 
// Tìm kiếm tuần tự x trong mảng a
// Trả về kết quả tìm thấy hoặc không tìm thấy
{
	bool timkiem = false;
	int i = 0;
	while ((i < n) && (!timkiem))
	{
		if (a[i] == x)
		{
			timkiem = true;
		}
		else
			i++;
	}
	return timkiem;
}
int main()
{
	int n = 8;
	int a[] = { 6, 8, 1, 5, 6, 2, 7, 4 };
	int x = 5;
	bool kq = timx(a, n, x);
	if (kq)
		cout << "Tim thay" << endl;
	else
		cout << "Khong tim thay" << endl;

	system("pause");
	return 0;
}
#include <iostream>
using namespace std;
int timx(int a[], int n, int x)
{
// Mảng a có n phần tử và chưa có thứ tự
// Tìm kiếm tuần tự x trong mảng a
// Trả về chỉ số của phần tử tìm thấy hoặc -1
	int vitri = -1;
	bool timkiem = false;
	int i = 0;
	while ((i < n) && (!timkiem))
	{
		if (a[i] == x)
		{
			vitri = i;
			timkiem = true;
		}
		else
			i++;
	}
	return vitri;
}
int main()
{
	int n = 8;
	int a[] = { 6, 8, 1, 5, 6, 2, 7, 4 };
	int x = 5;
	int vitri = timx(a, n, x);
	if (vitri != -1)
		cout << "Tim thay phan tu co chi so " << vitri << endl;
	else
		cout << "Khong tim thay" << endl;

	system("pause");
	return 0;
}
#include <iostream>
using namespace std;
int timx(int a[], int n, int x)
{
// Mảng a có n phần tử và có thứ tự tăng dần
// Tìm kiếm tuần tự x trong mảng a
// Trả về chỉ số của phần tử tìm thấy hoặc -1
	int vitri = -1;
	bool timkiem = false;
	int i = 0;
	while ((i < n) && (!timkiem))
	{
		if (a[i] < x)
			i++;
		else if (a[i] == x)
		{
			vitri = i;
			timkiem = true;
		}
		else
			i = n; // thoát khỏi vòng lặp 
	}
	return vitri;
}
int main()
{
	int n = 8;
	int a[] = { 1,2,4,5,6,6,7,8 };
	int x = 6;
	int vitri = timx(a, n, x);
	if (vitri != -1)
		cout << "Tim thay phan tu co chi so " << vitri << endl;
	else
		cout << "Khong tim thay" << endl;

	system("pause");
	return 0;
}*/
#include <iostream>
using namespace std;
int timxchiadetri(int a[], int n, int x)
{
// Mảng a có n phần tử và có thứ tự tăng dần
// Trả về chỉ số của phần tử tìm thấy hoặc -1
	int vitri = -1;
	int i = 0;
	int j = n - 1; 
    while ((i <= j) && (vitri == -1))
    {
		int k = (i + j) / 2; // phần tử chính giữa
		if (x == a[k])
			vitri = k;
		else if (x < a[k])
			j = k - 1; // tìm trong nửa khoảng đầu
		else
			i = k + 1; // tìm trong nửa khoảng cuối
    }
	return vitri;
}
int main()
{
	int n = 8;
	int a[] = { 1,2,4,5,6,6,7,8 };
	int x = 4;
	int vitri = timxchiadetri(a, n, x);
	if (vitri != -1)
		cout << "Tim thay phan tu co chi so " << vitri << endl;
	else
		cout << "Khong tim thay" << endl;

	system("pause");
	return 0;
}