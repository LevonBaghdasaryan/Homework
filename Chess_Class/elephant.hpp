#ifndef __ELEPHANT__
#define __ELEPHANT__

#include "chess.hpp"

class Elephant : public Chess {
    public:
        Elephant(str color) : Chess(color, "Elephant") {}
        void displayInformation() override;
};

#endif // __ELEPHANT__