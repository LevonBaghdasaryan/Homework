// Inorder Traversal
// Left -> Root -> Right

#include <iostream>

template <typename T>
struct Node {
    T _data;
    Node *_right;
    Node *_left;

    Node(const T& data) : _data(data), _right(nullptr), _left(nullptr) {}
};

template <typename T>
void printInorderTraversal(Node<T> *root) {
    if(root == nullptr) {
        return;
    }

    printInorderTraversal(root->_left);

    std::cout << root->_data << " ";
    
    printInorderTraversal(root->_right);
}

int main() {

    Node<int> *root = new Node<int>(1);
    root->_left = new Node<int>(2);
    root->_right = new Node<int>(3);
    root->_left->_left = new Node<int>(4);
    root->_left->_right = new Node<int>(5);
    root->_right->_right = new Node<int>(6);

    // Inorder Traversal of Binary tree
    //           1
    //      2        3 
    //  4       5         6
    // Inorder Traversal: 4 -> 2 -> 5 -> 1 -> 3 -> 6

    std::cout << "Inorder Traversal: ";
    printInorderTraversal(root);
    std::cout << std::endl;

    delete root->_right->_right;
    delete root->_left->_right;
    delete root->_left->_left; 
    delete root->_right;
    delete root->_left; 
    delete root;
    
    return 0;
}