#include "process.hpp"

template <typename T>
void inputMatrixToFile(Matrix<T> &matrix, std::ofstream &inputFile) {
    if (inputFile.is_open()) {
        inputFile << matrix.getRows() << " " << matrix.getCols() << std::endl;
        matrix.inputMatrix();
        matrix.printMatrix(inputFile);
        inputFile.close();
    } else {
        std::cerr << "Error: Could not open file for writing." << std::endl;
    }
}

template <typename T>
Matrix<T> readMatrixFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        throw std::runtime_error("Unable to open file: " + filename);
    }

    int numRows, numCols;
    file >> numRows >> numCols;

    Matrix<T> matrix(numRows, numCols);

    for (int i = 0; i < numRows; ++i) {
        for (int j = 0; j < numCols; ++j) {
            T value;
            file >> value;
            matrix.setValue(i, j, value);
        }
    }

    file.close();
    return matrix;
}

template <typename T>
void writeMatrixToFile(const std::string &filename, const Matrix<T> &matrix) {
    std::ofstream file(filename);
    if (!file.is_open()) {
        throw std::runtime_error("Unable to open file: " + filename);
    }

    file << matrix.getRows() << " " << matrix.getCols() << std::endl;
    for (int i = 0; i < matrix.getRows(); ++i) {
        for (int j = 0; j < matrix.getCols(); ++j) {
            file << matrix.getValue(i, j) << " ";
        }
        file << std::endl;
    }

    file.close();
}

// Explicit instantiation of template functions
template void inputMatrixToFile<int>(Matrix<int> &matrix, std::ofstream &inputFile);
template Matrix<int> readMatrixFromFile<int>(const std::string& filename);
template void writeMatrixToFile<int>(const std::string& filename, const Matrix<int>& matrix);

template void inputMatrixToFile<double>(Matrix<double> &matrix, std::ofstream &inputFile);
template Matrix<double> readMatrixFromFile<double>(const std::string& filename);
template void writeMatrixToFile<double>(const std::string& filename, const Matrix<double>& matrix);
