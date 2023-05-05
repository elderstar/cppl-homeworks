#include <iostream>
#include <vector>
#include <algorithm>

void printArr(std::vector<int> &arr) {
    for (const auto& el : arr) {
        std::cout << el << " ";
    }
}

int main()
{
    setlocale(LC_ALL, "Rus");

    std::vector<int> arr = { 4, 7, 9, 14, 12 };

    std::cout << "Входные данные: ";
    printArr(arr);

    std::cout << "\nВыходные данные: ";
    std::for_each(arr.begin(), arr.end(), [](int& n) {
        if (n % 2 != 0) {
            n *= 3;
        }
    });
    printArr(arr);
    return 0;
}