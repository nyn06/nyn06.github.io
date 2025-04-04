#include <iostream>
#include <fstream>  // Thư viện để làm việc với file
using namespace std;
#define MAX 100  
// Hàm đọc mảng 2 chiều từ file và xuất kết quả ra màn hình
void DocMang2CSoNguyen(int a[MAX][MAX], int& n, int& m)
{
    ifstream fi("MangSo.inp");  // Mở file MangSo.inp để đọc
    if (!fi)  // Kiểm tra nếu không thể mở file
    {
        cout << "Khong the mo file!" << endl;
        return;
    }
    // Đọc số lượng dòng n và số lượng cột m
    fi >> n >> m;
    // Đọc các phần tử của mảng 2 chiều từ file
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            fi >> a[i][j];
        }
    }
    fi.close();  // Đóng file sau khi đọc xong
}
// Hàm xuất mảng 2 chiều ra màn hình
void XuatMang2C(int a[MAX][MAX], int n, int m)
{
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cout << a[i][j] << " ";  // In các phần tử trong hàng
        }
        cout << endl;  // Xuống dòng sau khi in xong một hàng
    }
}
int main()
{
    int a[MAX][MAX];
    int n, m;
    DocMang2CSoNguyen(a, n, m);
    cout << "Mang 2 chieu doc duoc tu file:" << endl;
    XuatMang2C(a, n, m);
    return 0;
}