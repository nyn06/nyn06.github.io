#include <iostream>
#include <cstring>   
using namespace std;
int main()
{
    char s[1001];
    int k;         // Vị trí cần chèn
    char c;        // Ký tự cần chèn
    // Nhập chuỗi từ người dùng
    cout << "Moi ban nhap chuoi s: ";
    cin.getline(s, 1001);  // Đọc chuỗi nhập vào

    // Nhập vị trí cần chèn
    cout << "Moi ban nhap vi tri can chen: ";
    cin >> k;
    // Nhập ký tự cần chèn
    cout << "Moi ban nhap ky tu chen: ";
    cin >> c;
    // Kiểm tra điều kiện vị trí hợp lệ (0 <= k < length của chuỗi)
    int len = strlen(s);
    if (k < 0 || k > len)
    {
        cout << "Vi tri khong hop le!" << endl;
        return 0;
    }
    // Dịch các ký tự từ vị trí k đến cuối chuỗi lên một vị trí tiếp theo
    for (int i = len; i >= k; i--)
    {
        s[i + 1] = s[i];  // Dịch ký tự
    }
    // Chèn ký tự c vào vị trí k
    s[k] = c;
    cout << "Chuoi \"" << s << "\" sau khi them ky tu \"" << c << "\" vao vi tri " << k << ": " << s << endl;
    return 0;
}