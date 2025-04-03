#include <iostream>
using namespace std;
void NhapMang(int** a, int* n)
{
    cout << "Moi ban nhap so luong phan tu: ";
    cin >> *n;
    while (*n <= 0 || *n > 100)
    {  // Kiểm tra số lượng phần tử hợp lệ
        cout << "Nhap sai. Hay nhap lai: ";
        cin >> *n;
    }
    *a = new int[*n];  // Cấp phát mảng động
    for (int i = 0; i < *n; i++)
    {  // Nhập từng phần tử của mảng
        cout << "Phan tu " << i << ": ";
        cin >> (*a)[i];
    }
}
void XuatMang(int* a, int n)
{
    cout << "Day so co " << n << " phan tu: ";
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
}
// Hàm tách các số chẵn vào mảng mới
void TachChan(int* a, int n, int** b, int* m)
{
    *m = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] % 2 == 0)
            (*m)++;
    }
    *b = new int[*m];  // Cấp phát mảng b chứa các số chẵn
    int index = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] % 2 == 0)
            (*b)[index++] = a[i];
    }
}

int main()
{
    int* a = NULL, * b = NULL;
    int n, m;
    NhapMang(&a, &n);
    TachChan(a, n, &b, &m);
    cout << "Day chua cac so chan" << endl;
    XuatMang(b, m);
    // Giải phóng bộ nhớ đã cấp phát
    delete[] a;
    delete[] b;
    return 0;
}