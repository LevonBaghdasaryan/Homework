#ifndef __ARRAYCLASS_HPP__
#define __ARRAYCLASS_HPP__

#include <iostream>

class ArrayClass {
    public:
        ArrayClass(const int& size);
        friend std::istream& operator>>(std::istream& is, ArrayClass& a);
        friend std::ostream& operator<<(std::ostream& os, ArrayClass& a);
        int& operator[](int index);
        virtual ~ArrayClass();
    private:
        int *_date;
        int _size;
};

#endif // __ARRAYCLASS_HPP__