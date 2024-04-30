#include "chess.hpp"

#include "king.hpp"
#include "queen.hpp"
#include "boat.hpp"
#include "horse.hpp"
#include "elephant.hpp"
#include "soldier.hpp"

int main() {

    King king("White");
    Queen queen("Black");
    Boat boat("Black");
    Horse horse("white");
    Elephant elephant("Black");
    Soldier soldier("White");

    std::cout << "Chess pieces:\n" << std::endl;

    king.displayInformation();
    queen.displayInformation();
    boat.displayInformation();
    horse.displayInformation();
    elephant.displayInformation();
    soldier.displayInformation();

    return 0;
}