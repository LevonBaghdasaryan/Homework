#include "A.hpp"

int main() {

    A a;

    a.operator()();
    std::cout << "The arithmetic mean of two numbers: " << std::endl;
    std::cout << "Result: " << a.operator()(5,6) << std::endl;
    std::cout << "Using f() function: " << a.f(a) << std::endl; // Numbers is 15, 30

    return 0;
}