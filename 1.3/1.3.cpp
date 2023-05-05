#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <cmath>

constexpr auto PI = 3.14159265;

void printOutputData(std::vector<double> angles, std::vector<std::function<void(double)>> functions) {
    for (const auto& angle : angles) {
        std::cout << angle << ": ";
        for (const auto& function : functions)
            function(angle);
        std::cout << std::endl;
    }
}

void printSin(double angle) {
    std::cout << "sin: " << sin(angle) << " ";
}

void printCos(double angle) {
    std::cout << "cos: " << cos(angle) << " ";
}

void printTan(double angle) {
    std::cout << "tan: " << tan(angle) << " ";
}

int main()
{
    setlocale(LC_ALL, "Rus");

    std::vector<double> angles = { 30, 60, 90 };

    std::vector<std::function<void(double)>> functions = { printSin, printCos/*, printTan*/};
    
    std::cout << "[Входные данные]: ";
    double last = angles.back();

    std::for_each(angles.begin(), angles.end(), [&last](double& n) {
        std::cout << n << " * " << PI << " / 180";
        if (n != last) {
            std::cout << ", ";
        }
        n = n * PI / 180;
    });

    std::cout << "\n[Выходные данные]: \n";

    printOutputData(angles, functions);

    return 0;
}