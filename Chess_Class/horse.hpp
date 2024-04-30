#ifndef __HORSE__
#define __HORSE__

#include "chess.hpp"

class Horse : public Chess {
    public:
        Horse(str color) : Chess(color, "Horse") {}
        void displayInformation() override;
};

#endif // __HORSE__