#include <iostream>
using namespace std;
// Hàm hoán đổi hai số sử dụng con trỏ
void HoanVi(int* a, int* b)
{
    int tmp = *a;  // Đổi giá trị của a vào biến tạm
    *a = *b;       // Đặt giá trị b vào a
    *b = tmp;      // Đặt giá trị tạm vào b
}

int main()
{
    int x, y;
    cout << "Moi ban nhap so a: ";
    cin >> x;
    cout << "Moi ban nhap so b: ";
    cin >> y;
    // Hiển thị trước khi hoán vi
    cout << "Truoc khi hoan vi, a = " << x << " va b = " << y << "." << endl;

    // Hoán đổi giá trị của x và y
    HoanVi(&x, &y);
    // Hiển thị sau khi hoán vi
    cout << "Sau khi hoan vi, a = " << x << " va b = " << y << "." << endl;
    return 0;
}