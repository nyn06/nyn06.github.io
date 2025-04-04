#include <iostream>
#include <fstream>  // Thư viện để làm việc với file
using namespace std;
#define MAX 100  // Giới hạn số lượng phần tử tối đa của mảng
// Hàm đọc file và xuất kết quả ra màn hình
void DocCacSoNguyen(int a[], int& n)
{
    ifstream fi("DaySoNguyen.inp");  // Mở file DaySoNguyen.inp để đọc
    if (!fi)  // Kiểm tra nếu không thể mở file
    {
        cout << "Khong the mo file!" << endl;
        return;
    }
    fi >> n;  // Đọc số lượng phần tử n từ file
    for (int i = 0; i < n; ++i)
    {
        fi >> a[i];  // Đọc từng số nguyên vào mảng a[]
    }
    fi.close();  // Đóng file sau khi đọc xong
}
// Hàm xuất mảng ra màn hình
void XuatMang(int a[], int n)
{
    for (int i = 0; i < n; ++i)
    {
        cout << a[i] << " ";  // In từng phần tử của mảng
    }
    cout << endl;
}

int main()
{
    int a[MAX];  // Khai báo mảng chứa các số nguyên
    int n;  // Biến lưu số lượng phần tử
    DocCacSoNguyen(a, n);  // Đọc các số nguyên từ file
    cout << "Danh sach so nguyen trong file:" << endl;
    XuatMang(a, n);
    return 0;
}