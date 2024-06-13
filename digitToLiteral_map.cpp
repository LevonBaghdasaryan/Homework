#include <iostream>
#include <string>
#include <map>

const std::map<int, std::string> digits = {
    {0, "Zero"},
    {1, "One"},
    {2, "Two"},
    {3, "Three"},
    {4, "Four"},
    {5, "Five"},
    {6, "Six"},
    {7, "Seven"},
    {8, "Eight"},
    {9, "Nine"},
    {10, "Ten"}
};

std::string print(const int& n) {

    auto it = digits.find(n);
    if (it != digits.end()) {
        return it->second;
    }
    return "That number is not contained in our std::map.";
}

int main() {

    int digit = 0;
    std::cout << "Enter the number(0 - 10): ";
    std::cin >> digit;

    std::cout << digit << " - " << print(digit) << std::endl;

    return 0;
}