// Preorder Traversal
// Root -> Left -> Right

#include <iostream>

template <typename T>
struct Node {
    T _data;
    Node *_right;
    Node *_left;

    Node(const T& data) : _data(data), _right(nullptr), _left(nullptr) {}
};

template <typename T>
void printPreorderTraversal(Node<T> *root) {
    if(root == nullptr) {
        return;
    }
    std::cout << root->_data << " ";

    printPreorderTraversal(root->_left);
    
    printPreorderTraversal(root->_right);
}

int main() {

    Node<int> *root = new Node<int>(1);
    root->_left = new Node<int>(2);
    root->_right = new Node<int>(3);
    root->_left->_left = new Node<int>(4);
    root->_left->_right = new Node<int>(5);
    root->_right->_right = new Node<int>(6);

    // Preorder Traversal of Binary tree
    //           1
    //      2        3 
    //  4       5         6
    // Preorder Traversal: 1 -> 2 -> 4 -> 5 -> 3 -> 6

    std::cout << "Preorder Traversal: ";
    printPreorderTraversal(root);
    std::cout << std::endl;

    delete root->_right->_right;
    delete root->_left->_right;
    delete root->_left->_left; 
    delete root->_right;
    delete root->_left; 
    delete root;
    
    return 0;
}