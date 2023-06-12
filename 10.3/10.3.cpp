#include <iostream>
#include <memory>

class Obj {

public:
    Obj(int val) : val_{val}{};
    ~Obj() {
        std::cout << "\nObj deleted\n";
    }
    int getVal() {
        return val_;
    }
private:
    int val_;
};

template<class T> class unique_ptr{
public:
    unique_ptr(T* in_obj_ptr) : ptr{ in_obj_ptr } {}
    unique_ptr(const unique_ptr& in_obj) = delete;
    ~unique_ptr() {
        delete ptr;
    }
    unique_ptr& operator=(const unique_ptr& in_obj) = delete;

    T* operator->() {
        return ptr;
    }
    T operator*() const {
        return *ptr;
    }

    T* release() {
        return std::exchange(ptr, nullptr);
    }

private:
    T* ptr = nullptr;
};

int main()
{
    {
        Obj* obj_ptr = new Obj(2);
        unique_ptr<Obj> o_ptr(obj_ptr);
        unique_ptr<int> i_ptr(new int[1] {8});

        std::cout << o_ptr->getVal();
        std::cout << "\n";
        std::cout << *i_ptr;
        std::cout << "\n";
        std::cout << &o_ptr;
        std::cout << "\n";
        Obj* new_ptr =  o_ptr.release(); // но тогда объект не удаляется
        new_ptr->~Obj();                //  если не удалить вручную
        std::cout << "\n";
    }
    return 0;
}