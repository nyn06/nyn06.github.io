#include <iostream>
#include <fstream>
#include <unordered_set>
#include <vector>
using namespace std;
int main()
{
    // Mở file để đọc dữ liệu
    ifstream inputFile("CapSo.INP");
    ofstream outputFile("CapSo.OUT");
    if (!inputFile)
    {
        cout << "Cannot open input file!" << endl;
        return 1;
    }

    int n, k;
    inputFile >> n >> k;  // Đọc số n và k
    vector<int> numbers(n);
    for (int i = 0; i < n; ++i)
    {
        inputFile >> numbers[i];  // Đọc dãy số
    }
    unordered_set<int> seen;  // Hash table để lưu trữ các số đã gặp
    vector<pair<int, int>> result;
    // Tìm các cặp (ai, aj) sao cho ai + aj = k
    for (int i = 0; i < n; ++i)
    {
        int complement = k - numbers[i];
        if (seen.find(complement) != seen.end())
        {
            result.push_back({ complement, numbers[i] });
        }
        seen.insert(numbers[i]);  // Thêm số hiện tại vào bảng băm
    }

    // Ghi kết quả ra file
    if (result.empty())
    {
        outputFile << 0 << endl;
    }
    else
    {
        outputFile << result.size() << endl;
        for (const auto& pair : result)
        {
            outputFile << pair.first << " " << pair.second << endl;
        }
    }

    inputFile.close();
    outputFile.close();

    return 0;
}