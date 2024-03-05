#include <iostream>
#include <string>

// Node to store key-value pairs
struct Node {
    std::string key;
    int value;
    Node* next;

    Node(const std::string& k, int v) : key(k), value(v), next(nullptr) {}
};

class MyUnorderedMap {
private:
    static const int TABLE_SIZE = 1000;
    Node* table[TABLE_SIZE];

    // Hash function to compute the index for a given key
    int hash(const std::string& key) {
        int sum = 0;
        for (char c : key) {
            sum += static_cast<int>(c);
        }
        return sum % TABLE_SIZE;
    }

public:
    MyUnorderedMap() {
        // Initialize the hash table with nullptrs
        for (int i = 0; i < TABLE_SIZE; i++) {
            table[i] = nullptr;
        }
    }

    // Insert a key-value pair into the map
    void insert(const std::string& key, int value) {
        int index = hash(key);
        Node* newNode = new Node(key, value);
        newNode->next = table[index];
        table[index] = newNode;
    }

    // Get the value associated with a given key
    int get(const std::string& key) {
        int index = hash(key);
        Node* current = table[index];
        while (current) {
            if (current->key == key) {
                return current->value;
            }
            current = current->next;
        }
        return -1; // Key not found
    }

    // Remove a key-value pair from the map
    void remove(const std::string& key) {
        int index = hash(key);
        Node* current = table[index];
        Node* prev = nullptr;
        while (current) {
            if (current->key == key) {
                if (prev) {
                    prev->next = current->next;
                } else {
                    table[index] = current->next;
                }
                delete current;
                return;
            }
            prev = current;
            current = current->next;
        }
    }
};

int main() {
    MyUnorderedMap myMap;

    myMap.insert("apple", 10);
    myMap.insert("banana", 5);
    myMap.insert("orange", 15);

    std::cout << "Number of apples: " << myMap.get("apple") << std::endl;
    std::cout << "Number of bananas: " << myMap.get("banana") << std::endl;
    std::cout << "Number of oranges: " << myMap.get("orange") << std::endl;

    myMap.remove("banana");

    std::cout << "Number of bananas after removal: " << myMap.get("banana") << std::endl;

    return 0;
}


/*
In this implementation, we create a MyUnorderedMap class with a hash table as the underlying data structure. 
The hash function calculates the hash index for a given key, and each element is stored in a linked list at that index. 
The insert, get, and remove functions work similarly to their counterparts in the STL unordered_map.

Please note that this is a basic implementation and may not be as efficient or robust as the STL unordered_map. 
If you are not allowed to use STL data structures, consider implementing additional features like handling hash collisions, resizing the hash table, and freeing memory properly in a more complete version of the custom unordered map.
*/