#include <iostream>
#include <cmath>
using namespace std;
int giaiphuongtrinhbac4(float a, float b, float c, float& t1, float& t2)
{
    int sn = -1;
    if (a == 0)
    {
        if (b == 0)
        {
            if (c == 0)
                sn = -1;
            else
                sn = 0;
        }
        else
        {
            t1 = -c / b;
            if (t1 >= 0)
                sn = 2;
            else
                sn = 0;
        }
    }
    else
    {
        float denta = pow(b, 2) - 4 * a * c;
        if (denta < 0)
            sn = 0;
        else if (denta == 0)
        {
            t1 = -b / (2 * a);
            if (t1 >= 0)
                sn = 2;
            else
                sn = 0;
        }
        else
        {
            float dentasqrt = sqrt(denta);
            t1 = (-b + dentasqrt) / (2 * a);
            t2 = (-b - dentasqrt) / (2 * a);
            if (t1 >= 0 && t2 >= 0)
                sn = 4;
            else if (t1 >= 0 || t2 >= 0)
                sn = 2;
            else
                sn = 0;
        }
    }
    return sn;
}

int main() {
    float a, b, c;
    float t1, t2;
    cout << "Nhap a,b,c ";
    cin >> a >> b >> c;
    int sn = giaiphuongtrinhbac4(a, b, c, t1, t2);
    if (sn == -1)
        cout << "phuong trinh co vo so nghiem";
    else if (sn == 0)
        cout << "phuong trinh vo nghiem";
    else if (sn == 2)
    {
        cout << "phuong trinh co 2 nghiem ";
        if (t1 >= 0)
            cout << -sqrt(t1) << " " << sqrt(t1) << endl;
        else
            cout << "phuong trinh vo nghiem" << endl;
    }
    else if (sn == 4)
    {
        cout << "phuong trinh co 4 nghiem ";
        if (t1 >= 0)
            cout << -sqrt(t1) << " " << sqrt(t1) << endl;
        if (t2 >= 0)
            cout << -sqrt(t2) << " " << sqrt(t2) << endl;
    }

    return 0;
}
