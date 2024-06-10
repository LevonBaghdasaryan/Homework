#ifndef __FORWARD_LIST_HPP__
#define __FORWARD_LIST_HPP__

// Node structure for the ForwardList
template <typename T>
struct Node {
    T _data;
    Node* _next;
    Node(T value);
};

// ForwardList class
template <typename T>
class ForwardList {
    public:
        ForwardList();
        void push_front(T value);
        Node<T>* begin() const;
        Node<T>* end() const;
    private:
        Node<T>* _head;
};

#endif // __FORWARD_LIST_HPP__