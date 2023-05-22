#include <iostream>
#include <string>
#include <vector>

bool isNumber(std::string str) {
    if (str[0] == ' ') {
        return false; // защита если передали только пробел
    }
    for (const char& ch : str) {
        if (isdigit(ch) == 0 && ch != '.' && ch != ' ' && ch != '-') {
            return false;
        }
    }
    return true;
}

class Handler {
public:

    void operator()(std::vector<int> arr) {
        
        for(int i:arr) {
            if (i % 3 == 0) {
                ++count_;
                sum_ += i;
            }
        }
    }

    int get_count() {
        return count_;
    };

    int get_sum() {
        return sum_;
    };

private:
    int sum_ = 0;
    int count_ = 0;
};

void print(std::vector<int> arr) {

    size_t size = arr.size();
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i];
        if (i != size - 1) {
            std::cout << ", ";
        }
    }
    std::cout << std::endl;
}


int main()
{
    setlocale(LC_ALL, "Rus");
    std::string input = "";
    std::vector<int> arr;

    std::cout << "Введите входные данные: ";
    std::getline(std::cin, input);
    Handler arr_handler{};

    if (input.find(' ') == std::string::npos)
    {
        if (!isNumber(input)) {
            std::cout << "Не вверный ввод. Введите численные значения.";
            exit(0);
        };
        arr.push_back(std::stoi(input));
    }
    else {
        std::string sub_str = "";

        for (char ch : input) {
            if (ch != ' ') {
                sub_str += ch;
            }
            else {
                if (!isNumber(input)) {
                    std::cout << "Не вверный ввод. Введите численные значения.";
                    exit(0);
                };
                arr.push_back(std::stod(sub_str));
                sub_str = "";
            }
        }
        arr.push_back(std::stod(sub_str));
    }
    arr_handler(arr);
    std::cout << "[IN]: "; 
    print(arr);
    std::cout << "[OUT]: get_sum() = " << arr_handler.get_sum() << "\n";
    std::cout << "[OUT]: get_count() = " << arr_handler.get_count() << std::endl;

    return 0;
}