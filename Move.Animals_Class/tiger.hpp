#ifndef __TIGER_HPP__
#define __TIGER_HPP__

#include "animals.hpp"

class Tiger : public Animals {
    public:
        Tiger(const int &age) : Animals("Tiger", age) {}
        void displayInformation() override;
};

#endif // __TIGER_HPP__