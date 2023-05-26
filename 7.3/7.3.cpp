#include <iostream>
#include <exception>

template<class T> class vector
{
public:
    vector() {
        arr_ = new T[capacity_]();
    }
    ~vector() {
        delete[] arr_;
        arr_ = nullptr;
    }

    vector(const vector& arr)
    {
        if (this != &arr) {
            int arr_size = arr.size();
            
            if (arr_size > 0) 
            {
                arr_ = new T[arr_size]();
                for (int i = 0; i < arr_size; ++i) 
                {
                    arr_[i] = arr.at(i);
                }
                size_ = arr.size();
                capacity_ = arr.capacity();
            }
            else {
                arr_ = new T[capacity_]();
            }
        }
    }

    vector& operator= (const vector& rhl) 
    {
        if (this != &rhl) {
            int arr_size = rhl.getSize();

            if (arr_size > 0)
            {
                arr_ = new T[arr_size]();
                for (int i = 0; i < arr_size; ++i)
                {
                    arr_[i] = rhl[i];
                }
                size_ = rhl.size();
                capacity_ = rhl.capacity();
            }
            else {
                arr_ = new T[capacity_]();
            }
        }
        return *this;
    }

    void push_back(const T& new_value)
    {
        if (size_ + 1 > capacity_) {
            T* tmp_arr = new T[2 * capacity_];

            for (int i = 0; i < size_; ++i) {
                tmp_arr[i] = arr_[i];
            }
            delete[] arr_;
            arr_ = tmp_arr;
            capacity_ *= 2;
        }
        arr_[size_++] = new_value;
    }
    const int size () const
    {
        return size_;
    }

    const int capacity () const
    {
        return capacity_;
    }

    T& at(int index) const
    {
        if (index >= 0 && index <= capacity_)
        {
            return arr_[index];
        }
        else {
            throw std::logic_error("\nПопытка доступа за пределы массива.");
        }
    }

private:
    T* arr_ = nullptr;
    int size_ = 0;
    int capacity_ = 1;
};

int main()
{
    setlocale(LC_ALL , "Rus");

    vector<int> arr;
    std::cout << "Размер: " << arr.size() << "\n";
    std::cout << "Всего ячеек: " << arr.capacity() << "\n";
    arr.push_back(55);
    std::cout << "\nElement 55 add\n";
    std::cout << "Размер: " << arr.size() << "\n";
    std::cout << "Всего ячеек: " << arr.capacity() << "\n";
    arr.push_back(2);
    std::cout << "\nElement 2 add\n";
    std::cout << "Размер: " << arr.size() << "\n";
    std::cout << "Всего ячеек: " << arr.capacity() << "\n";
    arr.push_back(17);
    std::cout << "\nElement 17 add\n";
    std::cout << "Размер: " << arr.size() << "\n";
    std::cout << "Всего ячеек: " << arr.capacity() << "\n";
    std::cout << "\n-----------------------------\n";
    //std::cout << arr[0]; оператора индексирования не требуется по заданию
    vector<int> arr2 = arr;
    vector<int> arr3(arr2);
    try {
        std::cout << "\nЭлемент в массиве 2 с idx[0]: " << arr2.at(0);
        std::cout << "\nЭлемент в массиве 2 с idx[1]: " << arr2.at(1);
        std::cout << "\nЭлемент в массиве 3 с idx[2]: " << arr3.at(2);
        std::cout << "\nЭлемент в массиве 3 с idx[3]: " << arr3.at(3);
        std::cout << "\nЭлемент в массиве 3 с idx[4]: " << arr3.at(4);
        std::cout << "\nЭлемент в массиве 3 с idx[5]: " << arr3.at(5);
    }
    catch (std::exception e) {
        std::cout << e.what();
    }
    return 0;
}