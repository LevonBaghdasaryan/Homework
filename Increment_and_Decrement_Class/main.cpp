#include "incrementDecrement.hpp"

int main() {

    Point p(5,15);

    std::cout << "Initial value of p: (" << p.getX() << ", " << p.getY() << ")" << std::endl;

    // Increment operator (++)
    ++p;
    std::cout << "After prefix increment:" << std::endl;
    std::cout << "p: (" << p.getX() << ", " << p.getY() << ")" << std::endl;

    p++;
    std::cout << "After postfix increment:" << std::endl;
    std::cout << "p: (" << p.getX() << ", " << p.getY() << ")" << std::endl;

    // Decrement operator (--)
    --p;
    std::cout << "After prefix decrement:" << std::endl;
    std::cout << "p: (" << p.getX() << ", " << p.getY() << ")" << std::endl;

    p--;
    std::cout << "After postfix decrement:" << std::endl;
    std::cout << "p: (" << p.getX() << ", " << p.getY() << ")" << std::endl;

    return 0;
}