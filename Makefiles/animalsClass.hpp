#ifndef __ANIMALSCLASS__
#define __ANIMALSCLASS__

#include <string>

class Animals {
public:
    std::string _name;

    virtual void speak();
    virtual void voice() = 0;
    virtual ~Animals();
};

class Lion : public Animals {
public:
    void voice() override;
};

class Tiger : public Animals {
public:
    void voice() override;
};

class Bear : public Animals {
public:
    void voice() override;
};

class Wolf : public Animals {
public:
    void voice() override;
};

class Elephant : public Animals {
public:
    void voice() override;
};

#endif // __ANIMALSCLASS__