#include <iostream>
#include <vector>
#include <algorithm>

template <class T>void move_vectors(std::vector<T>& two, std::vector<T>& one){

    std::vector<T> tmp = std::move(two);
    two = std::move(one);
    one = std::move(tmp);
}

void print(std::vector<std::string>& vec) {
    for (const std::string& st : vec) {
        std::cout << st << " ";
    }
    std::cout << std::endl;
}

int main()
{
    std::vector <std::string> one = { "test_string1", "test_string2" };
    std::vector <std::string> two;
    std::cout << "1: ";
    print(one);
    std::cout << "2: ";
    print(two);
    move_vectors(two, one);
    std::cout << "3: ";
    print(one);
    std::cout << "4: ";
    print(two);
}