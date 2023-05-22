#include <iostream>
#include <exception>
#include <string>

template <class T> class Table {
public:
    Table(int rows, int cols) : rows_{ rows }, cols_{ cols } {
        
        arr = new T*[rows_];
        for (int i = 0; i < rows_; ++i) {
            arr[i] = new T[cols_]();
        }
    };
    ~Table() {
    
        for (int i = 0; i < rows_; ++i) {
            delete[] arr[i];
        }
        delete[] arr;
    };

    auto & operator[](size_t index) {
        if (index >= rows_ || index < 0) {
            throw(std::logic_error("Нарушение прав доступа при чтении/записи"));
        }

        return arr[index];
    };

    const auto& operator[](size_t index) const {
        if (index >= rows_ || index < 0) {
            throw(std::logic_error("Нарушение прав доступа при чтении/записи"));
        }

        return arr[index];
    };

    const int Size() const {
        return rows_ * cols_;
    }
private:
    int rows_ = 0;
    int cols_ = 0;
    T** arr;
};

int main()
{
    setlocale(LC_ALL , "Rus");
    int rows_idx = 5;
    int cols_idx = 5;
    std::string input = "";

    auto test = Table<int>(rows_idx, cols_idx);
    
    std::cout << "Размер: " << test.Size() << "\n";
    try{
        test[0][0] = 4;
        test[1][2] = 12;
        std::cout << test[0][0] << "\n"; // выводит 4
        std::cout << test[1][2] << "\n"; // выводит 12
    }
    catch(const std::exception& e){
        std::cout << e.what();
    }

    return 0;
}