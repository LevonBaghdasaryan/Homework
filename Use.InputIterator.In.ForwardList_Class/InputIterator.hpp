#ifndef __INPUT_ITERATOR_HPP__
#define __INPUT_ITERATOR_HPP__

#include "ForwardList.hpp"

template <typename T>
class InputIterator {
    public:
        InputIterator(Node<T>* ptr = nullptr);

        T& operator*();
        T* operator->();

        InputIterator& operator++();
        InputIterator operator++(int);

        bool operator==(const InputIterator& other) const;
        bool operator!=(const InputIterator& other) const;
    private:
        Node<T>* _current;
};

#endif // __INPUT_ITERATOR_HPP__