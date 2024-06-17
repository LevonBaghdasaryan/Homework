// Postorder Traversal
// Left -> Right -> Root

#include <iostream>

template <typename T>
struct Node {
    T _data;
    Node *_right;
    Node *_left;

    Node(const T& data) : _data(data), _right(nullptr), _left(nullptr) {}
};

template <typename T>
void printPostorderTraversal(Node<T> *root) {
    if(root == nullptr) {
        return;
    }
    

    printPostorderTraversal(root->_left);

    printPostorderTraversal(root->_right);
    
    std::cout << root->_data << " ";

    
}

int main() {

    Node<int> *root = new Node<int>(1);
    root->_left = new Node<int>(2);
    root->_right = new Node<int>(3);
    root->_left->_left = new Node<int>(4);
    root->_left->_right = new Node<int>(5);
    root->_right->_right = new Node<int>(6);

    // Postorder Traversal of Binary tree
    //           1
    //      2        3 
    //  4       5         6
    // Postorder Traversal: 4 -> 5 -> 2 -> 6 -> 3 -> 1

    std::cout << "Postorder Traversal: ";
    printPostorderTraversal(root);
    std::cout << std::endl;

    delete root->_right->_right;
    delete root->_left->_right;
    delete root->_left->_left; 
    delete root->_right;
    delete root->_left; 
    delete root;
    
    return 0;
}