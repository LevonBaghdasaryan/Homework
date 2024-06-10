#include <iostream>
#include "ForwardList.hpp"
#include "InputIterator.hpp"

template <typename T>
void printMiddle(const ForwardList<T>& list) {
    InputIterator<T> slow(list.begin());
    InputIterator<T> fast(list.begin());

    while (fast != list.end() && ++fast != list.end()) {
        ++slow;
        ++fast;
    }

    std::cout << "Middle element: " << *slow << std::endl;
}

int main() {
    
    ForwardList<int> list;

    list.push_front(10);
    list.push_front(20);
    list.push_front(30);
    list.push_front(40);
    list.push_front(50);

    printMiddle(list);

    return 0;
}