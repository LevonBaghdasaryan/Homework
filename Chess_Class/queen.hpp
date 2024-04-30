#ifndef __QUEEN__
#define __QUEEN__

#include "chess.hpp"

class Queen : public Chess {
    public:
        Queen(str color) : Chess(color, "Queen") {}
        void displayInformation() override;
};

#endif // __QUEEN__