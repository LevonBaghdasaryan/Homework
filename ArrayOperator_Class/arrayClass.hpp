#ifndef __ARRAYCLASS_HPP__
#define __ARRAYCLASS_HPP__

#include <iostream>

class ArrayClass {
    public:
        ArrayClass(const int& size);
        ArrayClass(const ArrayClass& other);
        ArrayClass& operator=(const ArrayClass& other);
        int& operator[](int index);

        friend std::istream& operator>>(std::istream& is, ArrayClass& a);
        friend std::ostream& operator<<(std::ostream& os, ArrayClass& a);

        virtual ~ArrayClass();
    private:
        int *_data;
        int _size;
};

#endif // __ARRAYCLASS_HPP__