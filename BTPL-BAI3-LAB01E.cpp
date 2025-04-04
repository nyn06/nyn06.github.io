#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
// Kiểm tra số nguyên tố
bool isPrime(int num)
{
    if (num <= 1) return false; // Số nhỏ hơn hoặc bằng 1 không phải là số nguyên tố
    if (num == 2) return true;  // Số 2 là số nguyên tố duy nhất chẵn
    if (num % 2 == 0) return false; // Các số chẵn lớn hơn 2 không phải là số nguyên tố
    for (int i = 3; i <= sqrt(num); i += 2)
    {
        if (num % i == 0) return false;
    }
    return true;
}

int main()
{
    ifstream inputFile("NT.INP");
    ofstream outputFile("NT.OUT");

    if (!inputFile)
    {
        cout << "Cannot open input file!" << endl;
        return 1;
    }

    int n;
    inputFile >> n;

    vector<int> primes;
    int num;

    // Đọc dữ liệu và kiểm tra số nguyên tố
    for (int i = 0; i < n; ++i)
    {
        inputFile >> num;
        if (isPrime(num))
        {
            primes.push_back(num);
        }
    }

    // Sắp xếp các số nguyên tố theo thứ tự tăng dần
    sort(primes.begin(), primes.end());

    // Ghi kết quả vào file NT.OUT
    outputFile << primes.size() << endl;
    for (int i = 0; i < primes.size(); ++i)
    {
        outputFile << primes[i] << " ";
    }
    outputFile << endl;

    inputFile.close();
    outputFile.close();

    return 0;
}