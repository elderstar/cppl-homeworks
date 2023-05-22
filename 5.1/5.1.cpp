#include <iostream>
#include <string>
#include <variant>
#include <vector>

bool isNumber(std::string str) {
    if (str[0] == ' ') {
        return false; // защита если передали только пробел
    }
    for (const char& ch: str) {
        if (isdigit(ch) == 0 && ch != '.' && ch != ' ' && ch != '-') {
            return false;
        }
    }
    return true;
}

template <class T> T power(T input, int degree) {
    for (int i = 1; i < degree; ++i) {
    
        input *= input;
    }
    return input;
};

template<> std::vector<double> power(std::vector<double> input, int degree) {
    
    for (double & el:input) {
        for (int i = 1; i < degree; ++i) {

            el *= el;
        }
    }
    return input;
};

template<class T> void print(std::string prefix, T arr) {

    std::cout << prefix << ": ";
    size_t size = arr.size();
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i];
        if (i != size - 1) {
            std::cout << ", ";
        }
    }
    std::cout << std::endl;
}

template<> void print(std::string prefix, double val) {

    std::cout << prefix << ": " << val << std::endl;
}
int main()
{
    setlocale(LC_ALL , "Rus");
    std::string input = "";
    std::vector<double> arr;
    
    std::cout << "Введите входные данные для возведения в квадрат(пример: 5 или 3 4 5): ";
    std::getline(std::cin, input);

    if (input.find(' ') == std::string::npos)
    {
        if (!isNumber(input)) { 
            std::cout << "Не вверный ввод. Введите численные значения.";
            exit(0); 
        };

        double val = std::stod(input);
        print("[IN]", val);
        print("[OUT]", power(val, 2));
    }
    else {
        std::string sub_str = "";

        for (char ch : input) {
            if (ch != ' ') {
                sub_str += ch;
            }
            else{
                if (!isNumber(input)) {
                    std::cout << "Не вверный ввод. Введите численные значения.";
                    exit(0);
                };
                arr.push_back(std::stod(sub_str));
                sub_str = "";
            }
        }
        arr.push_back(std::stod(sub_str));
        print("[IN]", arr);
        print("[OUT]", power(arr, 2));
    }
    return 0;
}