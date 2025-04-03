#include <iostream>
#include <algorithm> // Thư viện hỗ trợ hàm sort
#include <cstring>   // Thư viện hỗ trợ chuỗi
using namespace std;
int main()
{
    char s[1001];
    cout << "Moi ban nhap chuoi s: ";
    cin.getline(s, 1001);
    // Sắp xếp chuỗi theo thứ tự tăng dần
    sort(s, s + strlen(s));  // Hàm sort() từ thư viện algorithm
    // In ra chuỗi đã sắp xếp
    cout << "Chuoi \"" << s << "\" sau khi sap xep: " << s << endl;
    return 0;
}