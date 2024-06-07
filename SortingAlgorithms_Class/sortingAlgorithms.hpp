#ifndef __SORTING_ALGORITHMS_HPP__
#define __SORTING_ALGORITHMS_HPP__

#include <iostream>

class Array {
    public:
        Array(int *arr, const unsigned int &size);
        Array(const Array &other);
        Array& operator=(const Array &other);
        ~Array();

        void bubbleSort();
        void quickSort();
        void mergeSort();

        void print() const; 
    private:
        int *_arr;
        unsigned int _size;

        // Quick Sort funtions
        void quickSortHelper(int low, int high);
        int partition(int low, int high);

        // Merge Sort functions
        void mergeSortHelper(int *arr, int left, int right);
        void merge(int *arr, int left, int mid, int right);
};

#endif // __SORTING_ALGORITHMS_HPP__