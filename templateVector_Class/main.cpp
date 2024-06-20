#include <iostream>
#include "vectorClass.hpp"

int main() {

    size_t size = 5;

    // Integer Vector
    Vector<int> intVector(size);

    std::cout << "Enter " << size << " integers: " << std::endl;
    intVector.inputVector();
    std::cout << "Int Vector: ";
    intVector.printVector();

    intVector.push_front(100);
    std::cout << "After push_front(100): ";
    intVector.printVector();

    intVector.pop_back();
    std::cout << "After pop_back(): ";
    intVector.printVector();

    intVector.pop_front();
    std::cout << "After pop_front(): ";
    intVector.printVector();

    intVector.insert(2, 200);
    std::cout << "After insert(2, 200): ";
    intVector.printVector();

    intVector.resize(3);
    std::cout << "After resize(3): ";
    intVector.printVector();

    intVector.reserve(10);
    std::cout << "After reserve(10): ";
    intVector.printVector();

    std::cout << std::endl;

    return 0;
}