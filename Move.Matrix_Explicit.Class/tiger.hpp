#ifndef __TIGER_HPP__
#define __TIGER_HPP__

#include "animals.hpp"

class Tiger : public Animals {
    public:
        explicit Tiger(const int &age, const double &weight) : Animals("Tiger", age, weight) {}
        void displayInformation() override;
};

#endif // __TIGER_HPP__