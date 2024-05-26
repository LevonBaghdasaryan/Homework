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


    // Double

    Vector<double> doubleVector(size);

    std::cout << "Enter " << size << " doubles: " << std::endl;
    doubleVector.inputVector();

    std::cout << "Double Vector: ";
    doubleVector.printVector();


    // String

    Vector<std::string> doubleVector(size);

    std::cout << "Enter " << size << " string: " << std::endl;
    doubleVector.inputVector();

    std::cout << "String Vector: ";
    doubleVector.printVector();

    return 0;
}