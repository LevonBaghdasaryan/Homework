#include "sortingAlgorithms.hpp"

Array::Array(int *arr, const unsigned int &size) : _arr(arr), _size(size) {
    _arr = new int[_size];
    for(std::size_t i = 0; i < _size; ++i) {
        _arr[i] = arr[i];
    }
}

Array::Array(const Array &other) : _size(other._size) {
    _arr = new int[_size];
    for (unsigned int i = 0; i < _size; ++i) {
        _arr[i] = other._arr[i];
    }
}

Array& Array::operator=(const Array &other) {
     if(this != &other) {
        return *this;
    }

    delete[] _arr;

    _size = other._size;
    _arr = new int[_size];
    for(std::size_t i = 0; i < _size; ++i) {
        _arr[i] = other._arr[i];
    }
    return *this;
}

Array::~Array() {
    delete[] _arr;
}


// Bubble Sort

void Array::bubbleSort() {
    for(std::size_t i = 0; i < _size; ++i) {
        for(std::size_t j = 0; j < _size - 1 - i; ++j) {
            if(_arr[j] > _arr[j + 1]) {
                std::swap(_arr[j], _arr[j + 1]);
            }
        }
    }
}

// Quick Sort

void Array::quickSort() {
    quickSortHelper(0, _size - 1);
}

void Array::quickSortHelper(int low, int high) {
    if (low < high) {
        int pivotIndex = partition(low, high);
        quickSortHelper(low, pivotIndex - 1);
        quickSortHelper(pivotIndex + 1, high);
    }
}

int Array::partition(int low, int high) {
    int privot = _arr[high];
    int i = low - 1;

    for(std::size_t j = low; j < high; ++j) {
        if(_arr[j] < privot) {
            ++i;
            std::swap(_arr[i], _arr[j]);
        }
    }
    std::swap(_arr[i + 1], _arr[high]);
    return i + 1;
}

// Merge Sort

void Array::mergeSort() {
    mergeSortHelper(_arr, 0, _size - 1);
}

void Array::mergeSortHelper(int *arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSortHelper(arr, left, mid);
        mergeSortHelper(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

void Array::merge(int *arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int *L = new int[n1];
    int *R = new int[n2];

    for (std::size_t i = 0; i < n1; ++i)
        L[i] = arr[left + i];
    for (std::size_t j = 0; j < n2; ++j)
        R[j] = arr[mid + 1 + j];

    int i = 0;
    int j = 0;
    int k = left;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            ++i;
        } else {
            arr[k] = R[j];
            ++j;
        }
        ++k;
    }

    while (i < n1) {
        arr[k] = L[i];
        ++i;
        ++k;
    }

    while (j < n2) {
        arr[k] = R[j];
        ++j;
        ++k;
    }

    delete[] L;
    delete[] R;
}

void Array::print() const {
    for(std::size_t i = 0; i < _size; ++i) {
        std::cout << _arr[i] << " ";
    }
    std::cout << std::endl;
}