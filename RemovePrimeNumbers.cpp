#include <iostream>
#include <vector>
#include <algorithm>

int main() {

    std::vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    std::for_each(v.begin(), v.end(), [](int n) -> void {std::cout << n << " ";});
    std::cout << "\n";

    v.erase(std::remove_if(v.begin(), v.end(), [](int n) -> bool {
        if (n <= 0) return true;
        for (int i = 2; i * i <= n; ++i) {
            if (n % i == 0) return true;
        }
        return false;
    }), v.end());

    std::for_each(v.begin(), v.end(), [](int n) -> void {std::cout << n << " ";});
    std::cout << "\n";

    return 0;
}