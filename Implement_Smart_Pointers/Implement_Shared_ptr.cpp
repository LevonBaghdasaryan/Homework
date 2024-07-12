#include <iostream>

template <typename T>
class Shared_Ptr {
    public:
        // Default Constructor
        Shared_Ptr() : _ptr(nullptr), _count(new unsigned(0)) {}

        explicit Shared_Ptr(T* p = nullptr) : _ptr(p), _count(new unsigned(1)) {}
        ~Shared_Ptr() {
            release();
        }

        // Copy constructor
        Shared_Ptr(const Shared_Ptr<T>& other) : _ptr(other._ptr), _count(other._count) {
            ++(*_count);
        }

        // Copy assignment operator
        Shared_Ptr<T>& operator=(const Shared_Ptr<T>& other) {
            if(this != &other) {
                release();
                _ptr = other._ptr;
                _count = other._count;
                ++(*_count);
            }
            return *this;
        }

        // Move constructor
        Shared_Ptr(Shared_Ptr<T>&& other) noexcept : _ptr(other._ptr), _count(other._count) {
            other._ptr = nullptr;
            other._count = nullptr;
        }

        // Move assignment operator
        Shared_Ptr<T>& operator=(Shared_Ptr<T>&& other) noexcept {
            if(this != &other) {
                release();
                _ptr = other._ptr;
                _count = other._count;
                other._ptr = nullptr;
                other._count = nullptr;
            }
            return *this;
        }

        T& operator*() const {
            return *_ptr;
        }

        T* operator->() const {
            return _ptr;
        }

        T* get() const {
            return _ptr;
        }

        unsigned useCount() const {
            return *_count;
        }

    private:
        T* _ptr;
        unsigned* _count;

        void release() {
            if(_ptr) {
                if(--(*_count) == 0) {
                    delete _ptr;
                    delete _count;
                }
            }
        }
};

struct Test {
    int _data;
    Test(const int& val) : _data(val) {}
    void show() const {
        std::cout << "Data: " << _data << std::endl;
    }
};

int main() {

    Shared_Ptr<Test> obj1(new Test(5)); {
        Shared_Ptr<Test> obj2 = obj1;
        std::cout << "Obj2 use count: " << obj2.useCount() << std::endl;
        obj2->show();
    }

    std::cout << "Obj1 use count: " << obj1.useCount() << std::endl;
    obj1->show();

    return 0;
}