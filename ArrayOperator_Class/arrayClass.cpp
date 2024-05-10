#include "arrayClass.hpp"

ArrayClass::ArrayClass(const int& size) : _size(size) {
    _data = new int[_size];
}

ArrayClass::~ArrayClass() {
    delete[] _data;
    _data = nullptr;
}

std::istream& operator>>(std::istream& is, ArrayClass& arr) {
    std::cout << "Enter the array numbers:" << std::endl;
    for(size_t i = 0; i < arr._size; ++i) {
        is >> arr._data[i];
    }

    return is;
}

std::ostream& operator<<(std::ostream& os, ArrayClass& arr) {
    os << "Array numbers: " << std::endl;
    for(size_t i = 0; i < arr._size; ++i) {
        os << arr._data[i] << " ";
    }
    os << std::endl;
    return os;
}

ArrayClass::ArrayClass(const ArrayClass& other) : _size(other._size) {
    _data = new int[_size];
    for(size_t i = 0; i < _size; ++i) {
        _data[i] = other._data[i];  
    }
}

ArrayClass& ArrayClass::operator=(const ArrayClass& other) {
    if (this != &other) {
        delete[] _data;
        _size = other._size;
        _data = new int[_size];
        for (int i = 0; i < _size; ++i) {
            _data[i] = other._data[i];
        }
    }
    return *this;
}

int& ArrayClass::operator[](int index) {
    if (index < 0 || index >= _size) {
        throw std::out_of_range("Index out of bounds!");
    }
    return _data[index];
}