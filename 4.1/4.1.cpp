#include <iostream>
#include "list_class.h"

int fun() {
    return 1;
}

int main() {

	List list;
	list.PushBack(1);
	list.PushBack(55);
	std::cout << list.Size() << "\n";
	std::cout << list.PopBack() << "\n";
    if (fun() == 2) {
        std::cout << "true" << " ";
    }
    else {
        std::cout << "false";
    }

    return 0;
}