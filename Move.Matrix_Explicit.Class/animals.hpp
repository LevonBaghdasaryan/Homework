#ifndef __ANIMALS_HPP__
#define __ANIMALS_HPP__

#include <iostream>
#include <string>

class Animals {
    public:
        explicit Animals(const std::string &name, const int &age, const double &weight) : _name(name), _age(age), _weight(weight) {}
        Animals(Animals&& other) noexcept;
        Animals& operator=(Animals&& other) noexcept;

        bool operator<(const Animals& other) const;
        bool operator>(const Animals& other) const;
        bool operator==(const Animals& other) const;

        virtual void displayInformation() = 0;
        virtual ~Animals() {}

    protected:
        std::string _name;
        int _age;
        double _weight;
        static int _count; 
};

#endif // __ANIMALS_HPP__