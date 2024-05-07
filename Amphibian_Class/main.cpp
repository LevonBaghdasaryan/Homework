#include <iostream>
#include "amphibian.hpp"
#include "frog.hpp"

int main() {

    Frog frog("Frog", "Pond");

    std::cout << "Display info for frog:" << std::endl;
    frog.additionalInfo();

    return 0;
}