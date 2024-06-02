#include <iostream>
#include "vectorClass.hpp"

int main() {

    size_t size = 5;


    // Integer
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


    // Double
    // Vector<double> doubleVector(size);

    // std::cout << "Enter " << size << " doubles: " << std::endl;
    // doubleVector.inputVector();

    // std::cout << "Double Vector: ";
    // doubleVector.printVector();


    // String
    // Vector<std::string> doubleVector(size);

    // std::cout << "Enter " << size << " string: " << std::endl;
    // doubleVector.inputVector();

    // std::cout << "String Vector: ";
    // doubleVector.printVector();

    return 0;
}