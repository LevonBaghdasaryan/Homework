#include <iostream>

template <typename T>
struct TreeNode {
    T value;
    TreeNode* parent;
    TreeNode* leftChild;
    TreeNode* rightChild;
    bool color;  // 0 for red, 1 for black

    TreeNode(const T& val, TreeNode* p = nullptr)
        : value(val), parent(p), leftChild(nullptr), rightChild(nullptr), color(0) {}
};

template <typename T>
class Set {
public:
    Set();
    ~Set();
    void insert(const T& value);
    bool contains(const T& value) const;
    void print() const;

private:
    TreeNode<T>* root;
    TreeNode<T>* nullNode;

    void destroyHelper(TreeNode<T>* node);
    void printInOrder(TreeNode<T>* node) const;
    void leftRotate(TreeNode<T>* node);
    void rightRotate(TreeNode<T>* node);
    void balanceAfterInsert(TreeNode<T>* node);
};

template <typename T>
Set<T>::Set() {
    nullNode = new TreeNode<T>(T());
    nullNode->color = 1;  // Black
    root = nullNode;
}

template <typename T>
Set<T>::~Set() {
    destroyHelper(root);
    delete nullNode;
}

template <typename T>
void Set<T>::destroyHelper(TreeNode<T>* node) {
    if (node != nullNode) {
        destroyHelper(node->leftChild);
        destroyHelper(node->rightChild);
        delete node;
    }
}

template <typename T>
void Set<T>::print() const {
    printInOrder(root);
    std::cout << std::endl;
}

template <typename T>
void Set<T>::printInOrder(TreeNode<T>* node) const {
    if (node != nullNode) {
        printInOrder(node->leftChild);
        std::cout << node->value << " ";
        printInOrder(node->rightChild);
    }
}

template <typename T>
void Set<T>::leftRotate(TreeNode<T>* node) {
    TreeNode<T>* rightChild = node->rightChild;
    node->rightChild = rightChild->leftChild;
    if (rightChild->leftChild != nullNode) {
        rightChild->leftChild->parent = node;
    }
    rightChild->parent = node->parent;
    if (node->parent == nullptr) {
        root = rightChild;
    } else if (node == node->parent->leftChild) {
        node->parent->leftChild = rightChild;
    } else {
        node->parent->rightChild = rightChild;
    }
    rightChild->leftChild = node;
    node->parent = rightChild;
}

template <typename T>
void Set<T>::rightRotate(TreeNode<T>* node) {
    TreeNode<T>* leftChild = node->leftChild;
    node->leftChild = leftChild->rightChild;
    if (leftChild->rightChild != nullNode) {
        leftChild->rightChild->parent = node;
    }
    leftChild->parent = node->parent;
    if (node->parent == nullptr) {
        root = leftChild;
    } else if (node == node->parent->rightChild) {
        node->parent->rightChild = leftChild;
    } else {
        node->parent->leftChild = leftChild;
    }
    leftChild->rightChild = node;
    node->parent = leftChild;
}

template <typename T>
void Set<T>::balanceAfterInsert(TreeNode<T>* node) {
    TreeNode<T>* uncle;
    while (node->parent && node->parent->color == 0) {
        if (node->parent == node->parent->parent->leftChild) {
            uncle = node->parent->parent->rightChild;
            if (uncle->color == 0) {
                node->parent->color = 1;
                uncle->color = 1;
                node->parent->parent->color = 0;
                node = node->parent->parent;
            } else {
                if (node == node->parent->rightChild) {
                    node = node->parent;
                    leftRotate(node);
                }
                node->parent->color = 1;
                node->parent->parent->color = 0;
                rightRotate(node->parent->parent);
            }
        } else {
            uncle = node->parent->parent->leftChild;
            if (uncle->color == 0) {
                node->parent->color = 1;
                uncle->color = 1;
                node->parent->parent->color = 0;
                node = node->parent->parent;
            } else {
                if (node == node->parent->leftChild) {
                    node = node->parent;
                    rightRotate(node);
                }
                node->parent->color = 1;
                node->parent->parent->color = 0;
                leftRotate(node->parent->parent);
            }
        }
        if (node == root) {
            break;
        }
    }
    root->color = 1;
}

template <typename T>
void Set<T>::insert(const T& value) {
    TreeNode<T>* newNode = new TreeNode<T>(value, nullptr);
    TreeNode<T>* parentNode = nullptr;
    TreeNode<T>* currentNode = root;

    while (currentNode != nullNode) {
        parentNode = currentNode;
        if (newNode->value < currentNode->value) {
            currentNode = currentNode->leftChild;
        } else if (newNode->value > currentNode->value) {
            currentNode = currentNode->rightChild;
        } else {
            delete newNode;  // Duplicate value
            return;
        }
    }
    newNode->parent = parentNode;
    if (parentNode == nullptr) {
        root = newNode;
    } else if (newNode->value < parentNode->value) {
        parentNode->leftChild = newNode;
    } else {
        parentNode->rightChild = newNode;
    }

    newNode->leftChild = nullNode;
    newNode->rightChild = nullNode;
    newNode->color = 0;

    balanceAfterInsert(newNode);
}

template <typename T>
bool Set<T>::contains(const T& value) const {
    TreeNode<T>* currentNode = root;
    while (currentNode != nullNode) {
        if (value == currentNode->value) {
            return true;
        } else if (value < currentNode->value) {
            currentNode = currentNode->leftChild;
        } else {
            currentNode = currentNode->rightChild;
        }
    }
    return false;
}

int main() {
    
    Set<int> mySet;

    mySet.insert(1);
    mySet.insert(2);
    mySet.insert(3);
    mySet.insert(4);

    mySet.print();

    std::cout << "Contains 3: " << (mySet.contains(3) ? "Yes" : "No") << std::endl;
    std::cout << "Contains 5: " << (mySet.contains(5) ? "Yes" : "No") << std::endl;

    return 0;
}
