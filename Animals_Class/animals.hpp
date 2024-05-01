#ifndef __ANIMALS__
#define __ANIMALS__

#include <iostream>
#include <string>

class Animals {
    public:
        Animals(const std::string &name, const int &age, const double &weight) : _name(name), _age(age), _weight(weight) {}
        virtual void displayInformation();
        virtual void animalInformation() = 0;
        virtual ~Animals() {}

    protected:
        std::string _name;
        int _age;
        double _weight;    
};

#endif // __ANIMALS__