#include "matrix.hpp"

int main() {

    Matrix matrix(2,3);

    matrix.inputMatrix();
    std::cout << "Original Matrix: " << std::endl; 
    matrix.printMatrix();

    ++matrix;
    std::cout << "Prefix increment by 3: " << std::endl;
    matrix.printMatrix();

    matrix++;
    std::cout << "Postfix increment by 3: " << std::endl;
    matrix.printMatrix();

    return 0;
}