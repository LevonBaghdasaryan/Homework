#ifndef __SOLDIER__
#define __SOLDIER__

#include "chess.hpp"

class Soldier : public Chess {
    public:
        Soldier(str color) : Chess(color, "Soldier") {}
        void displayInformation() override;
};

#endif // __SOLDIER__