#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>

void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif // _WIN32
}

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

std::vector<int> getInputDataFromUser() {
    std::string input = "";
    std::vector<int> arr;

    while (true) {
        clearScreen();
        std::cout << "Введите входные данные: ";
        std::getline(std::cin, input);

        if (input.find(' ') == std::string::npos)
        {
            std::cout << "Не вверный ввод. Введите численные значения через пробел.";
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            arr.erase(arr.begin(), arr.end());
        }
        else {
            std::string sub_str = "";

            for (char ch : input)
            {
                if (ch != ' ') {
                    sub_str += ch;
                }
                else {
                    if (!isNumber(input))
                    {
                        std::cout << "Не вверный ввод. Введите численные значения.";
                        std::cin.clear();
                        std::cin.ignore(1000, '\n');
                        arr.erase(arr.begin(), arr.end());
                        sub_str = "";
                        break;
                    };
                    arr.push_back(std::stoi(sub_str));
                    sub_str = "";
                }
            }
            if (sub_str != "")
            {
                arr.push_back(std::stoi(sub_str));
            }
            try {
                if (arr.at(0) != arr.size() - 1)
                {
                    std::cout << "Не вверный ввод. Первым числом вводится количество элементов, далее сами значения.";
                    std::cin.clear();
                    std::cin.ignore(1000, '\n');
                    arr.erase(arr.begin(), arr.end());
                }
                else {
                    break;
                }
            }
            catch (std::exception e)
            {
                std::cout << e.what();
            }

        }
    }
    return arr;
};

int main()
{
    setlocale(LC_ALL, "Rus");
    std::vector<int> arr = getInputDataFromUser();

    std::set<int> my_set;

    std::cout << "[IN]: \n";

    for (int i = 0; i <= arr[0]; ++i) {
    
        std::cout << arr[i] << "\n";
        if (i != 0) 
        {
            my_set.insert(arr[i]);
        }
    }

    std::cout << "[OUT]: \n";
    std::for_each(my_set.rbegin(), my_set.rend(), [](const auto& el)
        {
            std::cout << el << "\n";
        });
    return 0;
}