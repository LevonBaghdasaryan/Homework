#ifndef __LION_HPP__
#define __LION_HPP__

#include "animals.hpp"

class Lion : public Animals {
    public:
        Lion(const int &age) : Animals(age) {};
        std::string getSpecies() const override;
        int getAge() const override;
};

#endif // __LION_HPP__