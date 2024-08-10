#include <iostream>
#include <vector>
#include <list>
#include <utility>
#include <functional>

template <typename Key>
class Unordered_Set {
public:
    Unordered_Set(std::size_t bucketCount = 16) : _numBuckets(bucketCount), _numElements(0) {
        _table.resize(_numBuckets);
    }

    void insert(const Key& key) {
        std::size_t index = hashFunction(key);
        for (const auto& node : _table[index]) {
            if (node._key == key) {
                return; // Key already exists
            }
        }
        _table[index].emplace_back(key);
        ++_numElements;
    }

    bool find(const Key& key) const {
        std::size_t index = hashFunction(key);
        for (const auto& node : _table[index]) {
            if (node._key == key) {
                return true;
            }
        }
        return false;
    }

    void remove(const Key& key) {
        std::size_t index = hashFunction(key);
        auto& nodes = _table[index];
        for (auto it = nodes.begin(); it != nodes.end(); ++it) {
            if (it->_key == key) {
                nodes.erase(it);
                --_numElements;
                return;
            }
        }
    }

    std::size_t size() const {
        return _numElements;
    }

private:
    struct Node {
        Key _key;
        Node(const Key& k) : _key(k) {}
    };

    std::vector<std::list<Node>> _table;
    std::size_t _numBuckets;
    std::size_t _numElements;

    std::size_t hashFunction(const Key& key) const {
        return std::hash<Key>{}(key) % _numBuckets;
    }
};

int main() {
    Unordered_Set<std::string> mySet;

    mySet.insert("BMW");
    mySet.insert("Mersedes");
    mySet.insert("Tesla");

    if (mySet.find("BMW")) {
        std::cout << "BMW is in the set" << std::endl;
    } else {
        std::cout << "BMW not found" << std::endl;
    }

    mySet.remove("Mersedes");

    if (mySet.find("Mersedes")) {
        std::cout << "Mersedes is in the set" << std::endl;
    } else {
        std::cout << "Mersedes not found" << std::endl;
    }

    std::cout << "Set size: " << mySet.size() << std::endl;

    return 0;
}
