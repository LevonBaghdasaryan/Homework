#include "arrayClass.hpp"

ArrayClass::ArrayClass(const int& size) : _size(size) {
    _date = new int[_size];
}

ArrayClass::~ArrayClass() {
    delete[] _date;
    _date = nullptr;
}

std::istream& operator>>(std::istream& is, ArrayClass& arr) {
    std::cout << "Enter the array numbers:" << std::endl;
    for(size_t i = 0; i < arr._size; ++i) {
        is >> arr._date[i];
    }

    return is;
}

std::ostream& operator<<(std::ostream& os, ArrayClass& arr) {
    os << "Array numbers: " << std::endl;
    for(size_t i = 0; i < arr._size; ++i) {
        os << arr._date[i] << " ";
    }
    os << std::endl;
    return os;
}

int& ArrayClass::operator[](int index) {
    if( index < 0 || index >= _size) {
        throw std::out_of_range("Index out of bounds!");
    }
    return _date[index];
}