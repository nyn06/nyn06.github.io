//3124411194_Trần Thảo Nguyên
#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
using namespace std;

// Hàm kiểm tra số nguyên tố
bool laNguyenTo(int n)
{
    if (n < 2) return false;
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0) return false;
    }
    return true;
}

// Hàm đọc dữ liệu từ file
void docFile(int*& a, int& n, string& s, string& x)
{
    ifstream file("DE03.INP");
    if (!file)
    {
        cout << "Khong the mo file DE03.INP!" << endl;
        return;
    }
    file >> n;
    a = new int[n];
    for (int i = 0; i < n; i++)
    {
        file >> *(a + i);
    }
    file.ignore(1000, '\n'); // Loại bỏ ký tự xuống dòng
    getline(file, s);
    getline(file, x);
    file.close();
}

// Hàm in mảng số nguyên
void inMang(int* a, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << *(a + i) << " ";
    }
    cout << endl;
}
// Hàm sắp xếp mảng theo yêu cầu
void sapXepMang(int* a, int n)
{
    // Tạo 2 mảng con cho số nguyên tố và không phải nguyên tố
    int* nguyenTo = new int[n];
    int* khongNguyenTo = new int[n];
    int cntNguyenTo = 0, cntKhongNguyenTo = 0;

    // Phân loại số nguyên tố và không phải nguyên tố
    for (int i = 0; i < n; i++)
    {
        if (laNguyenTo(a[i]))
        {
            nguyenTo[cntNguyenTo++] = a[i];
        }
        else
        {
            khongNguyenTo[cntKhongNguyenTo++] = a[i];
        }
    }

    // Sắp xếp từng mảng con thủ công
    for (int i = 0; i < cntNguyenTo - 1; i++)
    {
        for (int j = i + 1; j < cntNguyenTo; j++)
        {
            // Thực hiện swap thủ công
            if (nguyenTo[i] > nguyenTo[j])
            {
                int temp = nguyenTo[i];
                nguyenTo[i] = nguyenTo[j];
                nguyenTo[j] = temp;
            }
        }
    }

    for (int i = 0; i < cntKhongNguyenTo - 1; i++)
    {
        for (int j = i + 1; j < cntKhongNguyenTo; j++)
        {
            // Thực hiện swap thủ công
            if (khongNguyenTo[i] > khongNguyenTo[j])
            {
                int temp = khongNguyenTo[i];
                khongNguyenTo[i] = khongNguyenTo[j];
                khongNguyenTo[j] = temp;
            }
        }
    }

    // Kết hợp các mảng đã sắp xếp lại
    int index = 0;
    for (int i = 0; i < cntNguyenTo; i++)
    {
        a[index++] = nguyenTo[i];
    }
    for (int i = 0; i < cntKhongNguyenTo; i++)
    {
        a[index++] = khongNguyenTo[i];
    }

    // Giải phóng bộ nhớ đã cấp phát
    delete[] nguyenTo;
    delete[] khongNguyenTo;
}

// Hàm đếm số lần xuất hiện của chuỗi x trong chuỗi s
int demSoLanXuatHien(const string& s, const string& x)
{
    string sMoi = s;
    // Loại bỏ ký tự xuống dòng '\n' khỏi chuỗi s
    sMoi.erase(remove(sMoi.begin(), sMoi.end(), '\n'), sMoi.end());

    int dem = 1;
    size_t viTri = 1;

    // Tìm và đếm số lần xuất hiện của x trong s
    while ((viTri = sMoi.find(x, viTri)) != string::npos)
    {
        dem++;
        viTri += x.length(); // Tiếp tục tìm từ vị trí sau chuỗi x
    }

    return dem;
}
// Hàm tìm từ dài nhất trong chuỗi s
string timTuDaiNhat(const string& s)
{
    string tuDaiNhat = "", tu = "";
    for (size_t i = 0; i <= s.length(); i++)
    {
        if (s[i] != ' ' && s[i] != '\0')
        {
            tu += s[i];
        }
        else {
            if (tu.length() > tuDaiNhat.length())
            {
                tuDaiNhat = tu;
            }
            tu = "";
        }
    }
    return tuDaiNhat;
}

// Hàm ghi kết quả vào file
void ghiFile(int* a, int n, int soLan, const string& tuDaiNhat)
{
    ofstream file("DE03.OUT");
    if (!file)
    {
        cout << "Khong the mo file DE03.OUT!" << endl;
        return;
    }
    for (int i = 0; i < n; i++)
    {
        file << *(a + i) << " ";
    }
    file << endl << soLan << endl << tuDaiNhat;
    file.close();
}

int main()
{
    int* a, n;
    string s, x;
    docFile(a, n, s, x);
    cout << "Mang doc tu file: "; inMang(a, n);
    cout << "Chuoi s: " << s << endl;
    cout << "Chuoi x: " << x << endl;

    sapXepMang(a, n);
    int soLan = demSoLanXuatHien(s, x);
    string tuDaiNhat = timTuDaiNhat(s);

    cout << "Mang sau khi sap xep: "; inMang(a, n);
    cout << "So lan xuat hien cua x trong s: " << soLan << endl;
    cout << "Tu dai nhat trong s: " << tuDaiNhat << endl;

    ghiFile(a, n, soLan, tuDaiNhat);
    delete[] a;
    return 0;
}   
