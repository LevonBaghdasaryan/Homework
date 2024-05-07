#ifndef A_HPP
#define A_HPP

#include <iostream>

class A {
    public:
        void operator()();
        double operator()(const int& a, const int& b) const;
        double f(const A& functor);
};

#endif // A_HPP