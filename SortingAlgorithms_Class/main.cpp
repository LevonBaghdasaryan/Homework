#include "sortingAlgorithms.hpp"

int main() {

    // Bubble Sort

    int data1[] = {3, 4, 2, 1, 5};
    unsigned int size1 = sizeof(data1) / sizeof(data1[0]);

    Array arr(data1, size1);
    std::cout << "Original Array: ";
    arr.print();

    arr.bubbleSort();
    std::cout << "Bubble Sort: ";
    arr.print();

    std::cout << std::endl;

    // Quick Sort

    int data2[] = {30, 40, 20, 10, 50};
    unsigned int size2 = sizeof(data2) / sizeof(data2[0]);

    Array arr2(data2, size2);
    std::cout << "Original Array: ";
    arr2.print();

    arr2.quickSort();
    std::cout << "Quick Sort: ";
    arr2.print();

    std::cout << std::endl;

    // Merge Sort

    int data3[] = {90, 60, 100, 70, 80};
    unsigned int size3 = sizeof(data3) / sizeof(data3[0]);

    Array arr3(data3, size3);
    std::cout << "Original Array: ";
    arr3.print();

    arr3.quickSort();
    std::cout << "Merge Sort: ";
    arr3.print();

    return 0;
}