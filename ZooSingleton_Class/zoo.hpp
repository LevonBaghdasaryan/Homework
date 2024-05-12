#ifndef __ZOO_HPP__
#define __ZOO_HPP__

#include "animals.hpp"

class Zoo {
    public:
        static Zoo& getInstance(const std::string &name);
        void addAnimals(Animals* a);
        void displayAnimals() const;

        Zoo(const Zoo&) = delete;
        Zoo& operator=(const Zoo&) = delete;
    private:
        std::string _name;
        static const int _size = 5;
        Animals* animals[_size];
        int _numAnimals;

        Zoo(const std::string &name) : _name(name), _numAnimals(0) {}
}; 

#endif // __ZOO_HPP__