#include "incrementDecrement.hpp"

Point& Point::operator++() {
    _x++;
    _y++;
    return *this;
}

Point Point::operator++(int) {
    Point temp = *this;
    ++(*this);
    return temp;
}

Point& Point::operator--() {
    _x--;
    _y--;
    return *this;
}

Point Point::operator--(int) {
    Point temp = *this;
    --(*this);
    return temp;
}

int Point::getX() const {
    return _x;
}

int Point::getY() const {
    return _y;
}