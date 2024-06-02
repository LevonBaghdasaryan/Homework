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
    private:
        std::vector<T> _data;
        size_t _size;    
};

#endif // __VECTORCLASS_HPP__