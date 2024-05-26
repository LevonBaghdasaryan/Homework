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
    private:
        std::vector<T> _data;
        size_t _size;    
};

#endif // __VECTORCLASS_HPP__