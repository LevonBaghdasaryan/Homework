#include <iostream>
#include <vector>
#include <list>
#include <utility>

template <typename Key, typename Value>
class Unordered_Map {
    public:
        Unordered_Map(std::size_t bucketCount = 16) : _numBuckets(bucketCount), _numElements(0) {
            _table.resize(_numBuckets);
        }

        void insert(const Key& key, const Value& value) {
            std::size_t index = hashFunction(key);
            for (auto& node : _table[index]) {
                if (node._key == key) {
                    node._value = value;
                    return;
                }
            }
            _table[index].emplace_back(key, value);
            ++_numElements;
        }

        bool find(const Key& key, Value& value) const {
            std::size_t index = hashFunction(key);
            for (const auto& node : _table[index]) {
                if (node._key == key) {
                    value = node._value;
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
            Value _value;
            Node(const Key& k, const Value& v) : _key(k), _value(v) {}
        };

        std::vector<std::list<Node>> _table;
        std::size_t _numBuckets;
        std::size_t _numElements;

        std::size_t hashFunction(const Key& key) const {
            return std::hash<Key>{}(key) % _numBuckets;
        }
};

int main() {

    Unordered_Map<std::string, int> myMap;

    myMap.insert("BMW", 1);
    myMap.insert("Mersedes", 2);
    myMap.insert("Tesla", 3);

    int value = 0;

    if (myMap.find("BMW", value)) {
        std::cout << "BMW: " << value << std::endl;
    } else {
        std::cout << "BMW not found" << std::endl;
    }

    myMap.remove("Mersedes");

    if (myMap.find("Mersedes", value)) {
        std::cout << "Mersedes: " << value << std::endl;
    } else {
        std::cout << "Mersedes not found" << std::endl;
    }

    std::cout << "Map size: " << myMap.size() << std::endl;

    return 0;
}
