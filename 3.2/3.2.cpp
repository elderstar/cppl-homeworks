#include <iostream>
#include <string>

class SmartArray {
public:

	SmartArray(size_t size) {
			actual_size_ = size;
			arr_ = new double[actual_size_]();
	}

	~SmartArray() {
			std::cout << "\nMem free of arr with " << arr_[0] << " first el";
			
			delete[] arr_;
			arr_ = nullptr;
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

	double getElement(int index) const {
		if (index >= logical_size_ || index < 0) {
			throw std::invalid_argument("\nerror: " + std::to_string(index) + " is wrong index. Valid index in range [0," + std::to_string(logical_size_ - 1) + "]");
		}
		return arr_[index];
	}

	size_t getSize() const {
		return logical_size_;
	}

	size_t getActualSize() const {
		return actual_size_;
	};

	SmartArray(const SmartArray& rhl) {

		if (this != &rhl)
		{
			size_t r_size = rhl.getSize();

			if (r_size > 0) {
				arr_ = new double[r_size]();
				for (int i = 0; i < r_size; ++i) {

					arr_[i] = rhl.getElement(i);
				}
			}
			else {
				arr_ = new double[actual_size_]();
			}
			
			actual_size_ = rhl.getActualSize();
			logical_size_ = rhl.getSize();
		}
	}

	SmartArray& operator= (const SmartArray& rhl) {
		
		if (this != &rhl){
			new (this) SmartArray(rhl);

			std::cout << "\narr copied";
		}
		else {
			std::cout << "присвоение самому себе";
		}
		return *this;
	}

private:
	size_t actual_size_ = 1;
	size_t logical_size_ = 0;
	double* arr_ = nullptr;
};

void printArr(SmartArray& arr) {

	size_t count = arr.getSize();
	for (int i = 0; i < count; ++i) {

		std::cout << arr.getElement(i) << " ";
	}
}

int main()
{
	setlocale(LC_ALL , "Rus");
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
		std::cout << std::endl;

		SmartArray arr1(3);
		SmartArray arr2(arr1);
		SmartArray x1(5);
		x1.addElement(1);

		SmartArray x2(5);
		x1 = x1;
		x2 = x1;
	}
	catch (const std::exception& ex) {
		std::cout << ex.what() << std::endl;
	}

}