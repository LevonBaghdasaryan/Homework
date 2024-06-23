#include <iostream>
#include <vector>
#include <list>
#include <string>

template <typename K, typename V>
class HashEntry {
    public:
        HashEntry(const K &key, const V &value) : _key(key), _value(value) {}

        const K& getKey() const {
            return _key;
        }

        const V& getValue() const {
            return _value;
        }
    private:
        K _key;
        V _value;        
};

template <typename K, typename V>
class HashMap {
    public:
        HashMap(const std::size_t capacity) : _capacity(capacity), _size(0) {
            _table.resize(_capacity);
        }

        bool insert(const K &key, const V &value) {
            int index = hashFunction(key);

            for(auto& entry : _table[index]) {
                if(entry.getKey() == key) {
                    return false; // Key already exists
                }
            }
            _table[index].emplace_back(key, value);
            ++_size;
            return true;
        }

        bool get(const K &key, V &value) const {
            int index = hashFunction(key);
            for (const auto& entry : _table[index]) {
                if (entry.getKey() == key) {
                    value = entry.getValue();
                    return true; // Key found, return value
                }
            }
            return false; // Key not found
        }

        bool remove(const K &key) {
            int index = hashFunction(key);
            auto& list = _table[index];
            for (auto it = list.begin(); it != list.end(); ++it) {
                if (it->getKey() == key) {
                    list.erase(it);
                    --_size;
                    return true; // Key found and removed
                }
            }
            return false; // Key not found
        }

        std::size_t size() const {
            return _size;
        }

        bool empty() const {
            return _size == 0;
        }
    private:
        std::vector<std::list<HashEntry<K, V>>> _table;
        std::size_t _capacity;
        std::size_t _size;

        int hashFunction(const K &key) const {
            return std::hash<K>()(key) % _capacity;
        }
};

int main() {

    HashMap<int, std::string> hashTable(10);

    hashTable.insert(1, "One");
    hashTable.insert(2, "Two");
    hashTable.insert(11, "Eleven");

    std::string value;
    if (hashTable.get(1, value)) {
        std::cout << "Value for key 1: " << value << std::endl;
    }

    if (hashTable.remove(1)) {
        std::cout << "Key 1 removed successfully." << std::endl;
    }

    std::cout << "Current size: " << hashTable.size() << std::endl;

    if (!hashTable.get(1, value)) {
        std::cout << "Key 1 not found." << std::endl;
    }

    return 0;
}