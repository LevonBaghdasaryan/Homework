#ifndef __KING__
#define __KING__

#include "chess.hpp"

class King : public Chess {
    public:
        King(str color) : Chess(color, "King") {}
        void displayInformation() override;
};

#endif // __KING__