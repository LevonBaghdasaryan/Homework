#include <iostream>

template <typename KeyType, typename ValueType>
struct TreeNode {
    KeyType key;
    ValueType value;
    TreeNode* parent;
    TreeNode* leftChild;
    TreeNode* rightChild;
    bool color;  // 0 for red, 1 for black

    TreeNode(const KeyType& k, const ValueType& v, TreeNode* p = nullptr)
        : key(k), value(v), parent(p), leftChild(nullptr), rightChild(nullptr), color(0) {}
};

template <typename KeyType, typename ValueType>
class Map {
public:
    Map();
    ~Map();
    void insert(const KeyType& key, const ValueType& value);
    bool search(const KeyType& key, ValueType& value) const;
    void print() const;

private:
    TreeNode<KeyType, ValueType>* root;
    TreeNode<KeyType, ValueType>* nullNode;

    void destroyHelper(TreeNode<KeyType, ValueType>* node);
    void printInOrder(TreeNode<KeyType, ValueType>* node) const;
    void leftRotate(TreeNode<KeyType, ValueType>* node);
    void rightRotate(TreeNode<KeyType, ValueType>* node);
    void balanceAfterInsert(TreeNode<KeyType, ValueType>* node);
};

template <typename KeyType, typename ValueType>
Map<KeyType, ValueType>::Map() {
    nullNode = new TreeNode<KeyType, ValueType>(KeyType(), ValueType());
    nullNode->color = 1;  // Black
    root = nullNode;
}

template <typename KeyType, typename ValueType>
Map<KeyType, ValueType>::~Map() {
    destroyHelper(root);
    delete nullNode;
}

template <typename KeyType, typename ValueType>
void Map<KeyType, ValueType>::destroyHelper(TreeNode<KeyType, ValueType>* node) {
    if (node != nullNode) {
        destroyHelper(node->leftChild);
        destroyHelper(node->rightChild);
        delete node;
    }
}

template <typename KeyType, typename ValueType>
void Map<KeyType, ValueType>::print() const {
    printInOrder(root);
    std::cout << std::endl;
}

template <typename KeyType, typename ValueType>
void Map<KeyType, ValueType>::printInOrder(TreeNode<KeyType, ValueType>* node) const {
    if (node != nullNode) {
        printInOrder(node->leftChild);
        std::cout << "(" << node->key << ": " << node->value << ") ";
        printInOrder(node->rightChild);
    }
}

template <typename KeyType, typename ValueType>
void Map<KeyType, ValueType>::leftRotate(TreeNode<KeyType, ValueType>* node) {
    TreeNode<KeyType, ValueType>* rightChild = node->rightChild;
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

template <typename KeyType, typename ValueType>
void Map<KeyType, ValueType>::rightRotate(TreeNode<KeyType, ValueType>* node) {
    TreeNode<KeyType, ValueType>* leftChild = node->leftChild;
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

template <typename KeyType, typename ValueType>
void Map<KeyType, ValueType>::balanceAfterInsert(TreeNode<KeyType, ValueType>* node) {
    TreeNode<KeyType, ValueType>* uncle;
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

template <typename KeyType, typename ValueType>
void Map<KeyType, ValueType>::insert(const KeyType& key, const ValueType& value) {
    TreeNode<KeyType, ValueType>* newNode = new TreeNode<KeyType, ValueType>(key, value, nullptr);
    TreeNode<KeyType, ValueType>* parentNode = nullptr;
    TreeNode<KeyType, ValueType>* currentNode = root;

    while (currentNode != nullNode) {
        parentNode = currentNode;
        if (newNode->key < currentNode->key) {
            currentNode = currentNode->leftChild;
        } else {
            currentNode = currentNode->rightChild;
        }
    }
    newNode->parent = parentNode;
    if (parentNode == nullptr) {
        root = newNode;
    } else if (newNode->key < parentNode->key) {
        parentNode->leftChild = newNode;
    } else {
        parentNode->rightChild = newNode;
    }

    newNode->leftChild = nullNode;
    newNode->rightChild = nullNode;
    newNode->color = 0;

    balanceAfterInsert(newNode);
}

template <typename KeyType, typename ValueType>
bool Map<KeyType, ValueType>::search(const KeyType& key, ValueType& value) const {
    TreeNode<KeyType, ValueType>* currentNode = root;
    while (currentNode != nullNode) {
        if (key == currentNode->key) {
            value = currentNode->value;
            return true;
        } else if (key < currentNode->key) {
            currentNode = currentNode->leftChild;
        } else {
            currentNode = currentNode->rightChild;
        }
    }
    return false;
}

int main() {
    
    Map<int, std::string> myMap;

    myMap.insert(1, "one");
    myMap.insert(2, "two");
    myMap.insert(3, "three");
    myMap.insert(4, "four");

    myMap.print();

    std::string value;
    if (myMap.search(3, value)) {
        std::cout << "Key 3 maps to value: " << value << std::endl;
    } else {
        std::cout << "Key 3 not found" << std::endl;
    }

    return 0;
}