#ifndef __ANIMALS_HPP__
#define __ANIMALS_HPP__

#include <iostream>
#include <string>

class Animals {
    public:
        Animals(const int &age) : _age(age) {}
        virtual std::string getSpecies() const;
        virtual int getAge() const = 0;
    protected:
        int _age;    
};

#endif // __ANIMALS_HPP__