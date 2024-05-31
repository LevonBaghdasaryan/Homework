#include <iostream>

void print() {
    std::cout << std::endl;
}

template <typename T, typename... Types>
void print(T first, Types... types) {

    std::cout << first << std::endl;
    print(types...);

}

int main() {
    print(1, 2.5, "Hello ACA");
    return 0;
}