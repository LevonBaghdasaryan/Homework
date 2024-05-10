#include "arrayClass.hpp"

int main() {

    int size = 0;
    std::cout << "Enter the size: ";
    std::cin >> size;

    ArrayClass array(size);
    
    std::cin >> array;
    std::cout << array;

    ArrayClass array2(array);

    std::cout << "Copied array: " << std::endl;
    std::cout << array2;

    ArrayClass array3(3);
    array3 = array;

    std::cout << "Assigned array:" << std::endl;
    std::cout << array3; 

    return 0;
}