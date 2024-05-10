#ifndef __ANIMALS_HPP__
#define __ANIMALS_HPP__

#include <iostream>

class Animals {
    public:
        Animals();
        Animals(const Animals& other);
        static int getCount();
        ~Animals();
    private:
        static int _count;    
};

#endif // __ANIMALS_HPP__