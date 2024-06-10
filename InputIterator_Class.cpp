#include <iostream>

template <typename T> 
class InputIterator {
    public:
        InputIterator(T *ptr = nullptr) : _current(ptr) {}

        T& operator*() {
            return *_current;
        }

        T& operator->() {
            return _current;
        }

        InputIterator& operator++() {
            ++_current;
            return *this;
        }

        InputIterator& operator++(int) {
            InputIterator temp = *this;
            ++(*this);
            return temp;
        }

        bool operator==(const InputIterator &other) const {
            return (_current == other._current);
        }

        bool operator!=(const InputIterator &other) const {
            return (_current != other._current);
        }

    private:
        T *_current;
};

int main() {

    int arr[] = {1, 2, 3, 4, 5};

    InputIterator<int> begin(arr);
    InputIterator<int> end(arr + 5);

    std::cout << "Elements in the array: ";
    for(InputIterator<int> it = begin; it != end; ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    return 0;
}