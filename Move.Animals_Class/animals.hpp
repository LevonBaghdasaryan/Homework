#ifndef __ANIMALS_HPP__
#define __ANIMALS_HPP__

#include <iostream>
#include <string>

class Animals {
    public:
        Animals(const std::string &name, const int &age) : _name(name), _age(age) {}
        virtual void displayInformation() = 0;
        Animals(Animals&& other) noexcept;
        Animals& operator=(Animals&& other) noexcept;
        virtual ~Animals() {}

    protected:
        std::string _name;
        int _age; 
};

#endif // __ANIMALS_HPP__