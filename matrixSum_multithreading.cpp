#include <iostream>
#include <thread>
#include <random>
#include <chrono>

void inputMatrix(int** matrix, const int& rows, const int& cols) {

    for(std::size_t i = 0; i < rows; ++i) {
        for(std::size_t j = 0; j < cols; ++j) {
            matrix[i][j] = rand() % 100;
        }
    }
}

void printMatrix(int** matrix, const int& rows, const int& cols) {

    for(std::size_t i = 0; i < rows; ++i) {
        for(std::size_t j = 0; j < cols; ++j) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

void sumPart(int** matrix, int startRow, int endRow, long long int& result, const int& cols) {
    long long int sum = 0;
    for (int i = startRow; i < endRow; ++i) {
        for (int j = 0; j < cols; ++j) {
            sum += matrix[i][j];
        }
    }
    result = sum;
}

int main() {

    const int rows = 1000;
    const int cols = 1000;

    int **matrix = new int*[rows];
    for(std::size_t i = 0; i < rows; ++i) {
        matrix[i] = new int[cols];
    }

    inputMatrix(matrix, rows, cols);
    // std::cout << "Matrix:" << std::endl;
    // printMatrix(matrix, rows, cols);

    const int numThreads = 2;
    int rowsPerThread = rows / numThreads;

    long long int results[numThreads] = {0};
    std::thread threads[numThreads];

    auto start = std::chrono::high_resolution_clock::now();

    for (int i = 0; i < numThreads; ++i) {
        int startRow = i * rowsPerThread;
        int endRow = (i == numThreads - 1) ? rows : (i + 1) * rowsPerThread;
        threads[i] = std::thread(sumPart, matrix, startRow, endRow, std::ref(results[i]), cols);
    }

    for (int i = 0; i < numThreads; ++i) {
        threads[i].join();
    }

    long long int totalSum = 0;
    for (int i = 0; i < numThreads; ++i) {
        totalSum += results[i];
    }

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;

    std::cout << "Total Sum: " << totalSum << std::endl;
    std::cout << "Time taken: " << duration.count() << " seconds" << std::endl;


    for (int i = 0; i < rows; ++i) {
        delete[] matrix[i];
    }
    
    delete[] matrix;

    return 0;
}