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

    // Double Vector
    Vector<double> doubleVector(size);
    std::cout << "Enter " << size << " doubles: " << std::endl;
    doubleVector.inputVector();
    std::cout << "Double Vector: ";
    doubleVector.printVector();

    // String Vector
    Vector<std::string> stringVector(size);
    std::cout << "Enter " << size << " strings: " << std::endl;
    stringVector.inputVector();
    std::cout << "String Vector: ";
    stringVector.printVector();

    // Vector with initializer list
    Vector<int> intVectorInitList = {1, 2, 3, 4, 5};
    std::cout << "Int Vector (initializer list): ";
    intVectorInitList.printVector();

    return 0;
}
