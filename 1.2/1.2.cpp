#include <iostream>
#include <variant>
#include <vector>
#include <string>

void printArr(std::vector<int> arr) {
	for (const auto& el : arr) {
		std::cout << el << " ";
	}
}

std::variant<int, std::string, std::vector<int>> get_variant() {
	std::srand(std::time(nullptr));
	int random_variable = std::rand() % 3;

	std::variant<int, std::string, std::vector<int>> result;
	switch (random_variable)
	{
	case 0:
		result = 5;
		break;
	case 1:
		result = "string";
		break;
	case 2:
		result = std::vector<int>{ 1, 2, 3, 4, 5 };
		break;
	default:
		break;
	}
	return result;
}

int main()
{
	std::variant<int, std::string, std::vector<int>> vars = get_variant();

	const int* tmp_int = std::get_if<int>(&vars);
	const std::string* tmp_str = std::get_if<std::string>(&vars);
	const std::vector<int>* tmp_arr = std::get_if<std::vector<int>>(&vars);

	if (tmp_int != nullptr) {

		std::cout << *tmp_int * 2;
	}else if (tmp_str != nullptr) {

		std::cout << *tmp_str;
	}else if (tmp_arr != nullptr) {

		printArr(*tmp_arr);
	}

	return 0;
}