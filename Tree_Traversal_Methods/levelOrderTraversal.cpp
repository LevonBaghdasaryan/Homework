// Level-Order Traversal

#include <iostream>

template <typename T>
struct Node {
    T _data;
    Node *_right;
    Node *_left;

    Node(const T& data) : _data(data), _right(nullptr), _left(nullptr) {}
};

template <typename T>
struct QueueNode {
    Node<T> *_treeNode;
    QueueNode *_next;

    QueueNode(Node<T>* node) : _treeNode(node), _next(nullptr) {}
};

template <typename T>
class Queue {
    public:
        Queue() : _front(nullptr), _rear(nullptr) {}

        ~Queue() {
            while (!isEmpty()) {
                dequeue();
            }
        }

        bool isEmpty() {
            return _front == nullptr;
        }

        void enqueue(Node<T> *treeNode) {
            QueueNode<T> *newNode = new QueueNode<T>(treeNode);
            if (_rear) {
                _rear->_next = newNode;
            } else {
                _front = newNode;
            }
            _rear = newNode;
        }

        Node<T>* dequeue() {
            if (isEmpty()) {
                return nullptr;
            }
            QueueNode<T> *temp = _front;
            Node<T> *treeNode = temp->_treeNode;
            _front = _front->_next;
            if (!_front) {
                _rear = nullptr;
            }
            delete temp;
            return treeNode;
        }
    private:
        QueueNode<T> *_front;
        QueueNode<T> *_rear;
};

template <typename T>
void levelOrderTraversal(Node<T>* root) {
    if (root == nullptr) {
        return;
    }

    Queue<T> q;
    q.enqueue(root);

    while (!q.isEmpty()) {
        Node<T>* current = q.dequeue();
        std::cout << current->_data << " ";

        if (current->_left != nullptr) {
            q.enqueue(current->_left);
        }

        if (current->_right != nullptr) {
            q.enqueue(current->_right);
        }
    }
}

int main() {
    Node<int>* root = new Node<int>(1);
    root->_left = new Node<int>(2);
    root->_right = new Node<int>(3);
    root->_left->_left = new Node<int>(4);
    root->_left->_right = new Node<int>(5);
    root->_right->_right = new Node<int>(6);

    // Level-Order Traversal of Binary tree
    //           1
    //      2        3 
    //  4       5         6
    // Level-Order Traversal: 1-> 2 -> 3 -> 4 -> 5 -> 6

    std::cout << "Level-Order Traversal: ";
    levelOrderTraversal(root);
    std::cout << std::endl;

    delete root->_right->_right;
    delete root->_left->_right;
    delete root->_left->_left; 
    delete root->_right;
    delete root->_left; 
    delete root;
    
    return 0;
}
