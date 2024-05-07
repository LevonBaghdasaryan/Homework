#ifndef __AMPHIBIAN_HPP__
#define __AMPHIBIAN_HPP__

#include <iostream>
#include <string>

using str = const std::string&;

class Amphibian {
    public:
        Amphibian(str name, str habitat) : _name(name), _habitat(habitat) {}

        virtual void displayInfo() const;
        virtual void additionalInfo();

        virtual ~Amphibian() {}

    protected:
        std::string _name;
        std::string _habitat;
};

#endif // __AMPHIBIAN_HPP__