#include <iostream>
#include <list>
#include <vector>

template <typename T>
class StackList {
    public:
        void push_back(const T &value) {
            _stackList.push_back(value);
        }

        void pop_back() {
            if(!_stackList.empty()) {
                _stackList.pop_back();
            }
            else {
                std::cerr << "Stack underflow!" << std::endl;
            }
        }

        T top() const {
            if(!_stackList.empty()) {
                return _stackList.back();
            }
            else {
                std::cerr << "Stack is empty!" << std::endl;
                return T();
            }
        }

        bool empty() const {
            return _stackList.empty();
        }

        std::size_t size() const {
            return _stackList.size();
        }

    private:
        std::list<T> _stackList;
};

template <typename T>
class StackVector {
    public:
        void push_back(const T &value) {
            _stackVector.push_back(value);
        }

        void pop_back() {
            if(!_stackVector.empty()) {
                _stackVector.pop_back();
            }
            else {
                std::cerr << "Stack underflow!" << std::endl;
            }
        }

        T top() const {
            if(!_stackVector.empty()) {
                return _stackVector.back();
            }
            else {
                std::cerr << "Stack is empty!" << std::endl;
                return T();
            }
        }

        bool empty() const {
            return _stackVector.empty();
        }

        std::size_t size() const {
            return _stackVector.size();
        }

    private:
        std::vector<T> _stackVector;
};

int main() {

    // List

    std::cout << "Using StackList with int:" << std::endl;

    StackList<int> stackList;
    stackList.push_back(10);
    stackList.push_back(20);
    stackList.push_back(30);

    std::cout << "Top element: " << stackList.top() << std::endl;

    stackList.pop_back();
    std::cout << "Top element after pop is: " << stackList.top() << std::endl;
    std::cout << std::endl;


    // Vector

    std::cout << "Using StackVector with int:" << std::endl;

    StackVector<int> stackVector;
    stackVector.push_back(50);
    stackVector.push_back(60);
    stackVector.push_back(70);

    std::cout << "Top element is: " << stackVector.top() << std::endl;

    stackVector.pop_back();
    std::cout << "Top element after pop is: " << stackVector.top() << std::endl;

    return 0;
}