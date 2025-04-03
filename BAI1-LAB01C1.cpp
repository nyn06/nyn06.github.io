#include <iostream>
#include <cmath>
using namespace std;
/* Khai báo cấu trúc PhanSo */
struct PhanSo
{
    int tuSo;
    int mauSo;
};

/* Nhập phân số */
void NhapPhanSo(const char* info, PhanSo& ps)
{
    cout << info;
    cin >> ps.tuSo >> ps.mauSo;
}
/* Xuất phân số */
void XuatPhanSo(PhanSo ps)
{
    cout << "[" << ps.tuSo << "/" << ps.mauSo << "]";
}
/* Tìm ước chung lớn nhất */
int UCLN(int a, int b)
{
    while (b != 0)
    {
        int tmp = a;
        a = b;
        b = tmp % a;
    }
    return a;
}
/* Rút gọn phân số */
void RutGonPhanSo(PhanSo& ps)
{
    int ucln = UCLN(abs(ps.tuSo), abs(ps.mauSo));
    ps.tuSo /= ucln;
    ps.mauSo /= ucln;
}
/* So sánh hai phân số */
int SoSanhPhanSo(PhanSo p1, PhanSo p2)
{
    // Quy đồng mẫu số
    p1.tuSo = p1.tuSo * p2.mauSo;
    p2.tuSo = p2.tuSo * p1.mauSo;
    p1.mauSo = p2.mauSo = p1.mauSo * p2.mauSo;
    if (p1.tuSo > p2.tuSo) return 1;
    else if (p1.tuSo < p2.tuSo) return -1;
    return 0;
}
/* Cộng hai phân số */
void CongPhanSo(PhanSo p1, PhanSo p2, PhanSo& pret)
{
    pret.tuSo = p1.tuSo * p2.mauSo + p1.mauSo * p2.tuSo;
    pret.mauSo = p1.mauSo * p2.mauSo;
    RutGonPhanSo(pret);  // Rút gọn kết quả
}

int main()
{
    PhanSo p1, p2;
    // Nhập hai phân số
    NhapPhanSo("Moi ban nhap phan so 1: ", p1);
    NhapPhanSo("Moi ban nhap phan so 2: ", p2);
    // Rút gọn phân số
    RutGonPhanSo(p1);
    RutGonPhanSo(p2);
    // Xuất phân số sau khi rút gọn
    cout << "+ Rut gon: ";
    XuatPhanSo(p1);
    cout << " ";
    XuatPhanSo(p2);
    cout << endl;
    // So sánh hai phân số
    char aDau[3] = { '<', '=', '>' };
    int ret = SoSanhPhanSo(p1, p2);
    cout << "+ So sanh: ";
    XuatPhanSo(p1);
    cout << aDau[ret + 1];
    XuatPhanSo(p2);
    cout << endl;

    // Cộng hai phân số
    PhanSo pret;
    CongPhanSo(p1, p2, pret);
    cout << "+ Cong: ";
    XuatPhanSo(p1);
    cout << "+";
    XuatPhanSo(p2);
    cout << "=";
    XuatPhanSo(pret);
    cout << endl;

    return 0;
}