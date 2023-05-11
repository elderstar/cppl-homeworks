#include <iostream>
#include <string>

class SmartArray {
public:

	SmartArray(size_t size) {
		actual_size_ = size;
		arr_ = new double[actual_size_]();
	}

	~SmartArray() {
		delete[] arr_;
		arr_ = nullptr;
	}

	SmartArray(const SmartArray&) = delete;
	SmartArray& operator=(const SmartArray&) = delete;

	void addElement(double new_value) {
		if (logical_size_ >= actual_size_) {
			double * tmp_arr = new double[2 * actual_size_]();
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

	size_t getSize() {
		return logical_size_;
	}

private:
	size_t actual_size_ = 1;
	size_t logical_size_ = 0;
	double* arr_;
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
		arr.addElement(3);
		arr.addElement(5);
		arr.addElement(7);
		arr.addElement(9);
		printArr(arr);
		std::cout << arr.getElement(0) << std::endl;
	}
	catch (const std::exception& ex) {
		std::cout << ex.what() << std::endl;
	}

}