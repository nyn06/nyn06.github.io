#include <iostream>
#include <cstring>   // Thư viện hỗ trợ các thao tác với chuỗi
using namespace std;
int main()
{
    char s[1001];
    int k;         // Vị trí ký tự cần xóa
    // Nhập chuỗi từ người dùng
    cout << "Moi ban nhap chuoi s: ";
    cin.getline(s, 1001);  // Đọc chuỗi nhập vào
    // Nhập vị trí cần xóa
    cout << "Moi ban nhap vi tri can xoa: ";
    cin >> k;

    // Kiểm tra điều kiện vị trí xóa hợp lệ (0 <= k < length của chuỗi)
    int len = strlen(s);
    if (k < 0 || k >= len)
    {
        cout << "Vi tri khong hop le!" << endl;
        return 0;
    }
    // Xóa ký tự tại vị trí k
    for (int i = k; i < len; i++)
    {
        s[i] = s[i + 1];  // Dịch ký tự từ vị trí k+1 lên vị trí k
    }
    cout << "Chuoi \"" << s << "\" sau khi xoa ky tu tai vi tri " << k << ": " << s << endl;
    return 0;
}