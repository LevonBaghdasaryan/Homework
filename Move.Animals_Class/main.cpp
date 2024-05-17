#include "animals.hpp"
#include "tiger.hpp"
#include "panda.hpp"

int main() {

    std::cout << "Animals: " << std::endl;

    // Tiger
   
    Tiger tiger1(8);
    tiger1.displayInformation();

    Tiger tiger2(5);
    tiger2.displayInformation();

    Tiger tiger3(std::move(tiger1));
    tiger3.displayInformation();

    tiger2 = std::move(tiger3);
    tiger2.displayInformation();

    // Panda
    std::cout << "\nPanda: " << std::endl;

    Panda panda(18);
    panda.displayInformation();

    Panda panda2(std::move(panda));
    panda2.displayInformation();

    return 0;
}
