#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int nx, ny, nz;
    cin >> nx;
    int x[1000];
    for (int i = 0; i < nx; ++i)
        cin >> x[i];
    cin >> ny;
    int y[1000];
    for (int i = 0; i < ny; ++i)
        cin >> y[i];
    cin >> nz;
    int z[1000];
    for (int i = 0; i < nz; ++i)
        cin >> z[i];
    int ketqua[1000];
    int d = 0;
    for (int i = 0; i < nx; i++)
    {
        for (int j = 0; j < ny; j++)
        {
            if (x[i] == y[j])
            {
                for (int k = 0; k < nz; k++)
                {
                    if (x[i] == z[k])
                    {
                        bool vitri = false;
                        for (int l = 0; l < d; l++)
                        {
                            if (ketqua[l] == x[i]) {
                                vitri = true;
                                break;
                            }
                        }
                        if (!vitri)
                            ketqua[d++] = x[i];
                        break;
                    }
                }
                break;
            }
        }
    }
    for (int i = 0; i < d - 1; i++)
    {
        for (int j = i + 1; j < d; j++)
        {
            if (ketqua[i] > ketqua[j])
            {
                int temp = ketqua[i];
                ketqua[i] = ketqua[j];
                ketqua[j] = temp;
            }
        }
    }
    cout << d << endl;
    for (int i = 0; i < d; i++)
        cout << ketqua[i] << " ";
    return 0;
}
