#ifndef __PROCESS_HPP__
#define __PROCESS_HPP__

#include <iostream>
#include <fstream>
#include "matrixClass.hpp"

template <typename T>
void inputMatrixToFile(Matrix<T> &matrix, std::ofstream &inputFile);

template <typename T>
Matrix<T> readMatrixFromFile(const std::string &filename);

template <typename T>
void writeMatrixToFile(const std::string &filename, const Matrix<T> &matrix);

#endif // __PROCESS_HPP__
