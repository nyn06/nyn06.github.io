#include <iostream>
using namespace std;
void Insertionsort(int a[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int j = i - 1;
        int x = a[i];
        bool cont = true;
        while (j >= 0 && cont)
            if (a[j] > x)
            {
                a[j + 1] = a[j];
                j--;
            }
            else
                cont = false;
        a[j + 1] = x;
    }
}
void Selectionsort(int a[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int minval = a[i];
        int kmin = i;
        for (int j = i + 1; j < n; j++)
            if (minval > a[j])
            {
                minval = a[j];
                kmin = j;
            }
        swap(a[i], a[kmin]);
    }
}
void swap(int& x, int& y)
{
    int temp = x;
    x = y;
    y = temp;
}
void Heapsort(int a[], int n)
{
    // Giai đoạn 1: tạo heap ban đầu
    int k = n / 2 - 1;
    for (int i = k; i >= 0; i--)
        Sift(a, i, n - 1);
    // Giai đoạn 2: tạo mảng có thứ tự
    for (int i = n - 1; i > 0; i--)
    {
        swap(a[0], a[i]); // Đưa max (root) về cuối
        Sift(a, 0, i - 1);  // Khôi phục Heap cho phần còn lại
    }
}
void Sift(int a[], int p, int q) {
    int x = a[p];    // Lưu lại giá trị node cha
    int i = p;
    int j = 2 * i + 1;   // Vị trí con trái
    bool cont = true;

    while ((j <= q) && cont) 
    {
        if (j < q && a[j] < a[j + 1]) // Nếu có con phải lớn hơn con trái
            j = j + 1; // Chọn con lớn hơn

        if (x < a[j]) 
        { 
            // Nếu cha nhỏ hơn con lớn hơn, thì đổi chỗ
            a[i] = a[j];
            i = j;
            j = 2 * j + 1; // Đi xuống tiếp
        }
        else cont = false;
    }
    a[i] = x; // Gán giá trị của cha vào vị trí cuối cùng sau khi sift
}

int main()
{
    int a[100];
    int n;
    cout << "Nhap phan tu n: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << "Phan tu thu a[" << i << "] la: ";
        cin >> a[i];
    }
    cout << "Mang Insertionsort sau khi sap xep la: ";
    Insertionsort(a, n);
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
    cout << "Mang Selectionsort sau khi sap xep la: ";
    Selectionsort(a, n);
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << "Mang Heapsort sau khi sap xep la: ";
    Heapsort(a, n);
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    return 0;
} 








