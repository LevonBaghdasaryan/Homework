#include "animals.hpp"

// getCount is static

int main() {

    Animals a1;
    Animals a2;
    Animals a3;

    std::cout << "There are " << Animals::getCount() << " Animals type objects: " << std::endl;

    Animals a4;
    Animals a5(a4);
    Animals a6;
    Animals a7;

    std::cout << "There are " << Animals::getCount() << " Animals type objects: " << std::endl;
    
    Animals a8;
    Animals a9(a8);
    Animals a10;

    std::cout << "There are " << Animals::getCount() << " Animals type objects: " << std::endl;


    Animals a11;

    std::cout << "There are " << Animals::getCount() << " Animals type objects: " << std::endl;

    return 0;
}