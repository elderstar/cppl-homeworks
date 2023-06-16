#include <iostream>
#include <exception>
#include <vector>
#include <algorithm>
#include <string>

class big_integer {
public:
    big_integer(std::string str)
    {
        if (str == "" || str == " " || !fillVector(str)) {
            throw std::logic_error("В исходных данных недопустимые символы.");
        }
    };

    big_integer(const std::vector<int>& int_val) : long_ {int_val}{}

    big_integer(const big_integer& other) = delete;


    big_integer(big_integer&& rvalue) noexcept 
        : long_{ std::move( rvalue.long_ ) } {}

    ~big_integer() {};

    big_integer& operator= (const big_integer& other) = delete;

    big_integer& operator= (big_integer&& rvalue) noexcept
    {
        std::vector<int> tmp = std::move(long_);
        long_ = std::move(rvalue.long_);
        rvalue.long_ = std::move(tmp);

        return *this;
    }

    big_integer operator+ (const big_integer& other) 
    {
        std::vector<int> sum{};

        if (long_.size() < other.getValue().size())
        {
            sum = calculateSum(long_, other.getValue());
        }
        else {
            sum = calculateSum(other.getValue(), long_);
        }
        
        return big_integer(sum);
    }

    std::vector<int> calculateSum(std::vector<int> short_v, std::vector<int> long_v) {
        std::vector<int> sum = {};
        int sum_rest = 0;
        int a = 0;
        int b = 0;
        int sub_sum = 0;
        while (short_v.size() > 0) {
            
            b = short_v.back();
            short_v.pop_back();
            a = long_v.back();
            long_v.pop_back();
            sub_sum = sum_rest + a + b;
            sum.insert(sum.begin(),(sub_sum) % 10);
            sum_rest = sub_sum / 10;
        }

        if (sum_rest != 0 && long_v.size() == 0) {
            
            sum.insert(sum.begin(), sum_rest);
        }
        else {
            std::for_each(long_v.rbegin(), long_v.rend(), [&sum, &sum_rest](const int& el) {
                sum.insert(sum.begin(), el + sum_rest);
                sum_rest = 0;
                });
        }
        
        return sum;
    }

    bool fillVector(std:: string& str) {
        for (const char& ch : str) {
            if (isdigit(ch) == 0)
            {
                long_ = std::vector<int>{}; // очищаем память на случай если были записаны какие-то символы в вектор
                return false;
            }else{
                long_.push_back(ch - '0');
            }
        }
        return true;
    }

    std::vector<int> getValue() const
    {
        return long_;
    }

    friend std::ostream& operator<< (std::ostream& stream, big_integer& right)
    {
        for (const int& i : right.getValue())
        {
            std::cout << i;
        }
        return stream;
    };
    
private:
    std::vector<int> long_;
};

big_integer operator* (big_integer& long_v, int multiplier)
{
    std::vector<int> sum = long_v.getValue();

    while (multiplier > 1) {
        sum = long_v.calculateSum(long_v.getValue(), sum);
        --multiplier;
    }

    return big_integer(sum);
}

int main()
{
    setlocale(LC_ALL, "Rus");
    try
    {
        auto number1 = big_integer("114575");
        auto number2 = big_integer("78524");
        auto result_plus = number1 + number2;
        auto result_mult = number1 * 18;
        number1 = std::move(number2);

        const std::vector<int> CONST_VALUES = { 1,2,3 };

        big_integer num(CONST_VALUES);

        for (const int& i : num.getValue()) {
            std::cout << i;
        }
        std::cout << std::endl;

        for (const int& i : number1.getValue()) {
            std::cout << i;
        }
        std::cout << std::endl;

        for (const int& i : number2.getValue()) {
            std::cout << i;
        }

        std::cout << "\nresult(+): " << result_plus; // 193099
        std::cout << "\nresult(*): " << result_mult; // 2062350
    }
    catch (const std::exception& e)
    {
        std::cout << e.what();
    }
    return 0;
}