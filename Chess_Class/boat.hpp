#ifndef __BOAT__
#define __BOAT__

#include "chess.hpp"

class Boat : public Chess {
    public:
        Boat(str color) : Chess(color, "Boat") {}
        void displayInformation() override;
};

#endif // __BOAT__