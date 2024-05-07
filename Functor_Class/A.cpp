#include "A.hpp"

void A::operator()() {
    std::cout << "Functor for class A: " << std::endl;
}

double A::operator()(const int& a, const int& b) const {
    return (a + b) / 2.0;
}

double A::f(const A& functor) {
    return functor(15, 30);
}