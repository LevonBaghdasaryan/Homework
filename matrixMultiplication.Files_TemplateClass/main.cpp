#include "matrixClass.hpp"
#include "process.hpp"

int main() {
    
    // Matrix 1
    const unsigned int rows1 = 4;
    const unsigned int cols1 = 3;

    Matrix<int> matrix1(rows1, cols1);
    std::ofstream inputFile1("matrix1.dat");

    inputMatrixToFile(matrix1, inputFile1);

    // Matrix 2
    const unsigned int rows2 = 3;
    const unsigned int cols2 = 4;

    Matrix<int> matrix2(rows2, cols2);
    std::ofstream inputFile2("matrix2.dat");

    inputMatrixToFile(matrix2, inputFile2);

    try {
        matrix1 = readMatrixFromFile<int>("matrix1.dat");
        matrix2 = readMatrixFromFile<int>("matrix2.dat");

        Matrix<int> resultMatrix = matrix1 * matrix2;

        writeMatrixToFile("resultMatrix.dat", resultMatrix);

        std::cout << "Multiplication completed and result written to resultMatrix.dat" << std::endl;
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }

    return 0;
}
