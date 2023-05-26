#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>

int main()
{
    setlocale(LC_ALL , "Rus");
    std::string input = "";
    
    std::cout << "Введите строку: ";
    std::getline(std::cin, input);

    std::map <char, int > input_map;
    std::vector<std::pair<char, int>> vec_pairs;

    for (const char&ch:input) 
    {
        ++input_map[ch];
    }
   
    for (std::pair<char, int> p:input_map) {
        vec_pairs.push_back(p);
    }

    std::sort(vec_pairs.begin(), vec_pairs.end(), [](const std::pair<char, int>& left, const std::pair<char, int>& right) {

           return left.second > right.second;
    });

    std::cout << "[IN]: " << input << "\n";
    std::cout << "[OUT]: \n";

    for (const auto &el : vec_pairs) {
        std::cout << el.first << ": " << el.second << "\n";
    }
}