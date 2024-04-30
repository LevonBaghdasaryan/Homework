#ifndef __CHESS__
#define __CHESS__

#include <iostream>
#include <string>

using str = const std::string &;

class Chess {
    public:
        Chess(str color, const std::string &name) : _color(color), _name(name) {}
        virtual void displayInformation() = 0;
        virtual ~Chess() {}
    protected:
        std::string _color;
        std::string _name;    
};

#endif // __CHESS__