#include <iostream>
#include <vector>
#include <queue>
#include <cstdlib>
#include <ctime>

template <typename T>
class TreeNode {
public:
    T _value;
    std::vector<TreeNode<T>*> _children;

    TreeNode(const T &val) : _value(val) {}
};

int getRundomNumber(int min, int max) {
    return rand() % (max - min + 1) + min;
}

template <typename T>
TreeNode<T>* creatRandomTree(int depth) {
    if (depth == 0) {
        return nullptr;
    }

    TreeNode<T>* root = new TreeNode<T>(getRundomNumber(1, 100));
    int numChildren = getRundomNumber(0, 4);

    for (std::size_t i = 0; i < numChildren; ++i) {
        TreeNode<T>* child = creatRandomTree<T>(depth - 1);
        if (child != nullptr) {
            root->_children.push_back(child);
        }
    }
    return root;
}

template <typename T>
void traverseTreeLayerByLayer(TreeNode<T>* root) {
    if (root == nullptr) {
        return;
    }

    std::queue<TreeNode<T>*> q;
    q.push(root);

    while (!q.empty()) {
        int size = q.size();
        while (size > 0) {
            TreeNode<T>* node = q.front();
            q.pop();
            std::cout << node->_value << " ";
            for (TreeNode<T>* child : node->_children) {
                q.push(child);
            }
            --size;
        }
    }
}

template <typename T>
void deleteTree(TreeNode<T>* root) {
    if (root == nullptr) {
        return;
    }

    for (TreeNode<T>* child : root->_children) {
        deleteTree(child);
    }
    delete root;
}

int main() {
    
    srand(time(0));

    int depth = getRundomNumber(0, 10);
    TreeNode<int>* root = creatRandomTree<int>(depth);

    std::cout << "Tree depth: " << depth << std::endl;
    std::cout << "Traversing the tree layer by layer:" << std::endl;
    traverseTreeLayerByLayer(root);
    std::cout << std::endl;

    deleteTree(root);

    return 0;
}