#include "vectorClass.hpp"
#include <random>

template <typename T>
Vector<T>::Vector(size_t size) : _size(size) {
}

template <typename T>
Vector<T>::Vector(std::initializer_list<T> initList) : _data(initList), _size(initList.size()) {
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

template class Vector<int>;
template class Vector<double>;
template class Vector<std::string>;