#include <iostream>

template <typename T>
struct Node {
    T _data;
    Node *_next;
};

template <typename T>
class SinglyLinkedList {
    public:
        SinglyLinkedList() : _head(nullptr) {}

        ~SinglyLinkedList() {
            while (_head != nullptr) {
                Node<T> *temp = _head;
                _head = _head->_next;
                delete temp;
            }
        }

        void insert(T value) {
            Node<T> *newNode = new Node<T>();
            newNode->_data = value;
            newNode->_next = nullptr;

            if (_head == nullptr) {
                _head = newNode;
            }
            else {
                Node<T> *temp = _head;
                while (temp->_next != nullptr) {
                    temp = temp->_next;
                }
                temp->_next = newNode;
            }
        }

        void printList() {
            Node<T> *temp = _head;
            while (temp != nullptr) {
                std::cout << temp->_data << " -> ";
                temp = temp->_next;
            }
            std::cout << "nullptr" << std::endl;
        }

        T findLastNthElement(const int &index) {
            if (index <= 0) {
                std::cout << "Invalid value of n. Must be a positive integer." << std::endl;
                return T();
            }

            int length = 0;
            Node<T> *temp = _head;

            while (temp != nullptr) {
                temp = temp->_next;
                ++length;
            }

            if (index > length) {
                std::cout << "Index is greater than the length of the list." << std::endl;
                return T();
            }

            temp = _head;
            int count = length - index;
            for (int i = 0; i < count; ++i) {
                temp = temp->_next;
            }

            return temp->_data;
        }

    private:
        Node<T> *_head;
};

int main() {

    SinglyLinkedList<int> intList;

    intList.insert(10);
    intList.insert(20);
    intList.insert(30);
    intList.insert(40);
    intList.insert(50);

    std::cout << "Integer list: ";
    intList.printList();

    int index = 0;
    std::cout << "Enter the last nth index: ";
    std::cin >> index;

    int result = intList.findLastNthElement(index);
    if (result != 0) {
        std::cout << index << "th last element is " << result << std::endl;
    } else {
        std::cout << "Element not found or an error occurred." << std::endl;
    }

    return 0;
}
