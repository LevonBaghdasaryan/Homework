#include "matrix.hpp"

int main() {

    Matrix matrix(3,3);

    matrix.inputMatrix();
    std::cout << "Original Matrix: " << std::endl; 
    matrix.printMatrix();

    Matrix matrix2(std::move(matrix));
    matrix2.printMatrix();

    Matrix matrix3;
    matrix3 = std::move(matrix2);
    matrix3.printMatrix();

    return 0;
}