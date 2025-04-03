#include <iostream>
#include <cmath> 
using namespace std;
// Hàm kiểm tra số chính phương
void KiemTraChinhPhuong(int* n)
{
    int x = static_cast<int>(sqrt(*n)); // Tính căn bậc hai của n và chuyển đổi sang kiểu int
    if (x * x == *n)
        cout << "So " << *n << " la so chinh phuong." << endl;
    else
        cout << "So " << *n << " khong phai la so chinh phuong." << endl;
}
int main()
{
    int n;
    cout << "Moi ban nhap so nguyen n: ";
    cin >> n;

    KiemTraChinhPhuong(&n);
    return 0;
}