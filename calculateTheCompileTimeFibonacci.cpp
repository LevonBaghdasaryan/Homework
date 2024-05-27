#include <iostream>

template <unsigned int T>
struct Fibonacci {
    static const unsigned int value = Fibonacci<T - 1>::value + Fibonacci<T - 2>::value;
};

template<>
struct Fibonacci<0> {
    static const unsigned int value = 0;
};

template<>
struct Fibonacci<1> {
    static const unsigned int value = 1;
};

int main () {
    constexpr int n = 10;
    std::cout << "Fibonacci of " << n << " is: " << Fibonacci<n>::value << std::endl;
    return 0;
}