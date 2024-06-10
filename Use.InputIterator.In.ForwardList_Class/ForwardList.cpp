#include "ForwardList.hpp"

template <typename T>
Node<T>::Node(T value) : _data(value), _next(nullptr) {}

template <typename T>
ForwardList<T>::ForwardList() : _head(nullptr) {}

template <typename T>
void ForwardList<T>::push_front(T value) {
    Node<T>* newNode = new Node<T>(value);
    newNode->_next = _head;
    _head = newNode;
}

template <typename T>
Node<T>* ForwardList<T>::begin() const {
    return _head;
}

template <typename T>
Node<T>* ForwardList<T>::end() const {
    return nullptr;
}

template class ForwardList<int>;