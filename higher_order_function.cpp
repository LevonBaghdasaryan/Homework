#include <iostream>
#include <functional>

std::function<int(int)> mult(int x) {
    return [x](int y) -> int {
        return x * y;
    };
}

int main() {

    auto result = mult(5)(6);
    std::cout << "Result " << result << std::endl;

    return 0;
}