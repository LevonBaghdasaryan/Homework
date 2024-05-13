#ifndef __OPERATOR_OVERLOADING__
#define __OPERATOR_OVERLOADING__

#include <iostream>

class Point {
    public:
        Point(const int &x, const int &y) : _x(x), _y(y) {}
        
        Point& operator++();
        Point operator++(int);

        Point& operator--();
        Point operator--(int);

        int getX() const;
        int getY() const;

    private:
        int _x;
        int _y;
};

#endif // __OPERATOR_OVERLOADING__