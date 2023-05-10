#include <iostream>
#include "list_class.h"

int main() {

	List list;
	list.PushBack(1);
	list.PushBack(55);
	list.PushFront(23);
	std::cout << list.Size() << "\n";
	std::cout << list.PopBack() << "\n";

    return 0;
}