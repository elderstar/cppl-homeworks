#include <iostream>
#include <vector>
#include <algorithm>

//[IN]: 1 1 2 5 6 1 2 4
//[OUT] : 1 2 4 5 6
int main()
{
    std::vector<int> cont =  { 1, 1, 2, 5, 6, 1, 2, 4 };

    std::cout << "[IN] ";
    for (const int& el : cont) {
        std::cout << el << " ";
    };
    
    std::cout << std::endl;

    std::sort(cont.begin(), cont.end());
    auto last_itr = std::unique(cont.begin(), cont.end());

    cont.erase(last_itr, cont.end());

    std::cout << "[OUT] ";
    for (const int& el : cont) {
        std::cout << el << " ";
    };
}