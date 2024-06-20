#ifndef __VECTORCLASS_HPP__
#define __VECTORCLASS_HPP__

#include <iostream>
#include <string>
#include <vector>

template <typename T>
class Vector {
    public:
        Vector(std::size_t size);

        void inputVector();
        void printVector() const;

        void pop_back();
        void pop_front();
        void push_front(const T& value);
        void insert(std::size_t index, const T& value);
        void resize(std::size_t newSize);
        void reserve(std::size_t newCapacity);
    private:
        std::vector<T> _data;
        std::size_t _size;
        std::size_t _capacity;
};

#endif // __VECTORCLASS_HPP__