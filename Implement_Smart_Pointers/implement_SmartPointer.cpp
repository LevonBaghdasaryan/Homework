#include <iostream>

template <typename T>
class SmartPointer {
    public:
        explicit SmartPointer(T* p = nullptr) : _ptr(p) {}
        ~SmartPointer() {
            delete _ptr;
        }

        SmartPointer(const SmartPointer&) = delete;
        SmartPointer& operator=(const SmartPointer&) = delete;

        SmartPointer(SmartPointer&& other) noexcept : _ptr(other._ptr) {
            other._ptr = nullptr;
        }

        SmartPointer& operator=(SmartPointer&& other) noexcept {
            if (this != &other) {
                delete _ptr;
                _ptr = other._ptr;
                other._ptr = nullptr;
            }
            return *this;
        }

        T* get() const {
            return _ptr;
        }

        T& operator*() const {
            return *_ptr;
        }

        T* operator->() const {
            return _ptr;
        }

        bool operator==(std::nullptr_t) const {
            return _ptr == nullptr;
        }

    private:
        T* _ptr;
};

int main() {

    SmartPointer<int> obj(new int(10));
    std::cout << "Value: " << *obj << std::endl;

    SmartPointer<int> obj2 = std::move(obj);
    
    if (obj == nullptr) {
        std::cout << "Obj is now null." << std::endl;
    }

    if (obj2.get()) {
        std::cout << "Value obj2: " << *obj2 << std::endl;
    }

    return 0;
}
