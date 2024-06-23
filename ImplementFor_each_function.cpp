#include <iostream>
#include <vector>
#include <algorithm> // for std::for_each

namespace custom {
    template <typename It, typename T>
    T for_each(It begin, It end, T f) {
        while (begin != end) {
            f(*begin);
            ++begin;
        }
        return f;
    }
}

int main() {
    
    std::vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    std::cout << "Original Vector: ";
    for (auto& i : v) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    auto print = [](const int& n) { std::cout << n << " "; };

    std::cout << "Processed first 5 elements: ";
    custom::for_each(v.begin(), v.begin() + 5, print);
    std::cout << std::endl;

    return 0;
}
