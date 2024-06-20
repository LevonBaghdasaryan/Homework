#include "vectorClass.hpp"
#include <iostream>
#include <string>

int main() {

    Vector<int> intVector(5);
    Vector<double> doubleVector({1.1, 2.2, 3.3, 4.4, 5.5});
    Vector<std::string> stringVector(3);

    // Input vectors
    std::cout << "Enter 5 integers:" << std::endl;
    intVector.inputVector();

    std::cout << "Enter 5 doubles:" << std::endl;
    doubleVector.inputVector();

    std::cout << "Enter 3 strings:" << std::endl;
    stringVector.inputVector();

    // Print vectors
    std::cout << "Integer vector: ";
    intVector.printVector();

    std::cout << "Double vector: ";
    doubleVector.printVector();

    std::cout << "String vector: ";
    stringVector.printVector();

    return 0;
}
