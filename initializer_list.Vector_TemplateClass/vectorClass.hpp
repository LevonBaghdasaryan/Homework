#ifndef __VECTORCLASS_HPP__
#define __VECTORCLASS_HPP__

#include <iostream>
#include <string>
#include <vector>
#include <initializer_list>

template <typename T>
class Vector {
public:
    Vector(std::size_t size);
    Vector(std::initializer_list<T> initList);
    void inputVector();
    void printVector() const;
private:
    std::vector<T> _data;
    std::size_t _size;    
};

#endif // __VECTORCLASS_HPP__