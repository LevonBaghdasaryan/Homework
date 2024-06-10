#include "InputIterator.hpp"

template <typename T>
InputIterator<T>::InputIterator(Node<T>* ptr) : _current(ptr) {}

template <typename T>
T& InputIterator<T>::operator*() {
    return _current->_data;
}

template <typename T>
T* InputIterator<T>::operator->() {
    return &(_current->_data);
}

template <typename T>
InputIterator<T>& InputIterator<T>::operator++() {
    _current = _current->_next;
    return *this;
}

template <typename T>
InputIterator<T> InputIterator<T>::operator++(int) {
    InputIterator temp = *this;
    ++(*this);
    return temp;
}

template <typename T>
bool InputIterator<T>::operator==(const InputIterator& other) const {
    return (_current == other._current);
}

template <typename T>
bool InputIterator<T>::operator!=(const InputIterator& other) const {
    return (_current != other._current);
}

template class InputIterator<int>;