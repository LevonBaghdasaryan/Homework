#include "vectorClass.hpp"
#include <random>

template <typename T>
Vector<T>::Vector(size_t size) : _size(size), _capacity(size) {
    _data.reserve(size);
}

template <typename T>
void Vector<T>::printVector() const {
    for (const auto& elem : _data) {
        std::cout << elem << ", ";
    }
    std::cout << std::endl;
}

template <typename T>
void Vector<T>::inputVector() {
    T input;
    for (size_t i = 0; i < _size; ++i) {
        std::cout << "Enter element " << i + 1 << ": ";
        std::cin >> input;
        _data.push_back(input);
    }
    std::cout << std::endl;
}

template <typename T>
void Vector<T>::pop_back() {
    if(!_data.empty()) {
        _data.pop_back();
    }
}

template <typename T>
void Vector<T>::pop_front() {
    if(!_data.empty()) {
        _data.erase(_data.begin());
    }
}

template <typename T>
void Vector<T>::push_front(const T& value) {
    _data.insert(_data.begin(), value);
}

template <typename T>
void Vector<T>::insert(std::size_t index, const T& value) {
    if(index <= _data.size()) {
        _data.insert(_data.begin() + index, value);
    }
}

template <typename T>
void Vector<T>::resize(std::size_t newSize) {
    if (newSize <= _capacity) {
        _size = newSize;
        _data.resize(newSize);
    }
    else {
        _data.resize(newSize);
        _size = newSize;
        _capacity = newSize;
    }
}

template <typename T>
void Vector<T>::reserve(std::size_t newCapacity) {
    if (newCapacity > _capacity) {
        _data.reserve(newCapacity);
        _capacity = _data.capacity();
    }
}

template class Vector<int>;
template class Vector<double>;
template class Vector<std::string>;