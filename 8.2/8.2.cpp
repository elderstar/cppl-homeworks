#include <iostream>
#include <vector>
#include <set>
#include <list>

template<class Iterator> void printContainer(Iterator begin, Iterator end) {

    while (begin != end) {

        std::cout << *begin << " ";
        begin++;
    }
    std::cout << std::endl;
}

int main()
{
    std::set<std::string> test_set = { "one", "two", "three", "four" };
    printContainer(test_set.begin(), test_set.end()); // four one three two. помните почему такой порядок? :) 
    // из-за лексико-графической сортировки set

    std::list<std::string> test_list = { "one", "two", "three", "four" };
    printContainer(test_list.begin(), test_list.end()); // one, two, three, four

    std::vector<std::string> test_vector = { "one", "two", "three", "four" };
    printContainer(test_vector.begin(), test_vector.end()); // one, two, three, four
}