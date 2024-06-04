#include <iostream>
#include <list>

int findLastNthElement(std::list<int> &ls, const int& n) {
    if(ls.empty() || n <= 0 || n > ls.size()) {
        std::cout << "Invalid value of n. " << std::endl;
        std::cout << "n < " << ls.size() << std::endl;
        return -1; 
    }

    auto it = ls.end();

    for(std::size_t i = 0; i < n; ++i) {
        --it;
    }
    return *it;
}

int main() {

    std::list<int> myList = {10, 20, 30, 40, 50};

    int n = 0;
    std::cout << "Enter the value of n: ";
    std::cin >> n;

    int result = findLastNthElement(myList, n);
    if(result != -1) {
        std::cout << "The last " << n << "th element is: " << result << std::endl;
    }
}