#include <iostream>
using namespace std;
// Hàm kiểm tra tính đan dấu
bool KiemTraDanDau(double* a, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        if ((a[i] > 0 && a[i + 1] > 0) || (a[i] < 0 && a[i + 1] < 0))
            return false;
    }
    return true;
}

// Hàm kiểm tra tính đơn điệu
bool KiemTraDonDieu(double* a, int n)
{
    bool tang = true, giam = true;
    for (int i = 0; i < n - 1; i++)
    {
        if (a[i] >= a[i + 1]) tang = false;
        if (a[i] <= a[i + 1]) giam = false;
    }
    return tang || giam;
}

// Hàm kiểm tra tính đối xứng
bool KiemTraDoiXung(double* a, int n)
{
    for (int i = 0; i < n / 2; i++)
    {
        if (a[i] != a[n - i - 1])
            return false;
    }
    return true;
}

int main()
{
    int n;
    cout << "Moi ban nhap so luong phan tu: ";
    cin >> n;
    // Nhập dãy số thực
    double* a = new double[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Phan tu " << i << ": ";
        cin >> a[i];
    }
    // Kiểm tra các tính chất
    if (KiemTraDanDau(a, n))
        cout << "+ Day co tinh chat dan dau" << endl;
    else
        cout << "+ Day khong co tinh chat dan dau" << endl;
    if (KiemTraDonDieu(a, n))
        cout << "+ Day co tinh chat don dieu" << endl;
    else
        cout << "+ Day khong co tinh chat don dieu" << endl;
    if (KiemTraDoiXung(a, n))
        cout << "+ Day co tinh chat doi xung" << endl;
    else
        cout << "+ Day khong co tinh chat doi xung" << endl;
    // Giải phóng bộ nhớ
    delete[] a;
    return 0;
}