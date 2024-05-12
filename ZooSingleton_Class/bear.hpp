#ifndef __BEAR_HPP__
#define __BEAR_HPP__

#include "animals.hpp"

class Bear : public Animals {
    public:
        Bear(const int &age) : Animals(age) {}
        std::string getSpecies() const override;
        int getAge() const override;
};

#endif // __BEAR_HPP__