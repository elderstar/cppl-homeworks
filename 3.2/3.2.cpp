#include <iostream>
#include <string>

struct SmartLinkCounter {
	size_t smart_link_counter = 0;
};

class SmartArray {
public:

	SmartArray(size_t size) {
		if (size > actual_size_)
		{
			actual_size_ = size;
			delete[] arr_;
			arr_ = new double[actual_size_]();
		}
	}

	~SmartArray() {
		if (smart_link_counter == 0) {
			std::cout << "\nMem free of arr with " << arr_[0] << " first el";
			
			delete[] arr_;
			arr_ = nullptr;
		}
	}

	void addElement(double new_value) {
		if (logical_size_ >= actual_size_) {
			double* tmp_arr = new double[2 * actual_size_]();
			for (int i = 0; i < logical_size_; ++i) {
				tmp_arr[i] = arr_[i];
			}
			delete[] arr_;
			arr_ = tmp_arr;
			actual_size_ *= 2;
		}
		arr_[logical_size_++] = new_value;
	}

	double getElement(int index) {
		if (index >= logical_size_ || index < 0) {
			throw std::invalid_argument("\nerror: " + std::to_string(index) + " is wrong index. Valid index in range [0," + std::to_string(logical_size_ - 1) + "]");
		}
		return arr_[index];
	}

	const size_t getSize() {
		return logical_size_;
	}

	SmartArray& operator= (SmartArray& rhl) {
		
		if (this != &rhl)
		{
			this->~SmartArray();
			new (this) SmartArray(rhl);
			std::cout << "\narr copied";
			++smart_link_counter;

		}
		return *this;
	}

private:
	size_t actual_size_ = 1;
	size_t logical_size_ = 0;
	double* arr_ = new double[actual_size_]();
	size_t smart_link_counter = 0;
};

void printArr(SmartArray& arr) {

	size_t count = arr.getSize();
	for (int i = 0; i < count; ++i) {

		std::cout << arr.getElement(i) << " ";
	}
}

int main()
{
	try {
		SmartArray arr(5);
		arr.addElement(1);
		arr.addElement(4);
		arr.addElement(155);

		SmartArray new_array(2);
		new_array.addElement(44);
		new_array.addElement(34);
		printArr(arr);
		std::cout << std::endl;
		printArr(new_array);
		arr = new_array;
		std::cout << std::endl;
		printArr(arr);
	}
	catch (const std::exception& ex) {
		std::cout << ex.what() << std::endl;
	}

}