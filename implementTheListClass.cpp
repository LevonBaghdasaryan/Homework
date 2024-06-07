#include <iostream>

template <typename T>
class Node {
    public:
        T _data;
        Node *_next;
        Node *_prev;
        Node(int& value) : _data(value), _next(nullptr), _prev(nullptr) {}
};

template <typename T>
class List {
    public:
        List() : _head(nullptr), _tail(nullptr), _size(0) {}
        ~List() {
            clear();
        }

        void push_back(T value) {
            Node<T> *newNode = new Node<T>(value);
            if(_tail == nullptr) {
                _head = _tail = newNode;
            }
            else {
                _tail->_next = newNode;
                newNode->_prev = _tail;
                _tail = newNode;
            }
            ++_size;
        }

        void pop_back() {
            if(_tail == nullptr) {
                return;
            }

            if(_tail == _head) {
                delete _tail;
                _tail = _head = nullptr;
            }
            else {
                Node<T> *temp = _tail->_prev;
                delete _tail;
                _tail = temp;
                _tail ->_next = nullptr;
            }
            --_size;
        }

        int getSize() const {
            return _size;
        }

        void print() {
            Node<T> *temp = _head;
            while(temp != nullptr) {
                std::cout << temp->_data << " ";
                temp = temp->_next;
            }
            std::cout << "nullptr" << std::endl;
        }

        void clear() {
            while (_head != nullptr) {
                Node<T> *temp = _head;
                _head = _head->_next;
                delete temp;
            }
            _tail = nullptr;
        }
    private:
        Node<T> *_head;
        Node<T> *_tail;
        std::size_t _size;
};

int main() {

    List<int> intList;

    intList.push_back(10);
    intList.push_back(20);
    intList.push_back(30);
    intList.push_back(40);
    intList.push_back(50);

    std::cout << "Size of List: " << intList.getSize() << std::endl;
    std::cout << "List: ";
    intList.print();

    std::cout << std::endl;

    intList.pop_back();
    std::cout << "Size of list after popping: " << intList.getSize() << std::endl;
    std::cout << "List: ";
    intList.print();

    return 0;
}