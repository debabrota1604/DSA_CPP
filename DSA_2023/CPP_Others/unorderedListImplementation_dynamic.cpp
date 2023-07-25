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
    static const int INITIAL_TABLE_SIZE = 10000;
    int tableSize;
    int elementCount;
    Node** table;

    // Hash function to compute the index for a given key
    int hash(const std::string& key) {
        int sum = 0;
        for (char c : key) {
            sum += static_cast<int>(c);
        }
        return sum % tableSize;
    }

    // Helper function to resize the hash table when it becomes too full
    void resize() {
        int newTableSize = tableSize * 2;
        Node** newTable = new Node*[newTableSize];
        for (int i = 0; i < newTableSize; i++) {
            newTable[i] = nullptr;
        }

        for (int i = 0; i < tableSize; i++) {
            Node* current = table[i];
            while (current) {
                int newIndex = hash(current->key) % newTableSize;
                Node* newNode = new Node(current->key, current->value);
                newNode->next = newTable[newIndex];
                newTable[newIndex] = newNode;
                current = current->next;
            }
        }

        // Delete the old table and update the class members
        delete[] table;
        table = newTable;
        tableSize = newTableSize;
    }

public:
    MyUnorderedMap() {
        // Initialize the hash table with nullptrs
        tableSize = INITIAL_TABLE_SIZE;
        table = new Node*[tableSize];
        for (int i = 0; i < tableSize; i++) {
            table[i] = nullptr;
        }
        elementCount = 0;
    }

    ~MyUnorderedMap() {
        // Clean up the dynamically allocated memory
        for (int i = 0; i < tableSize; i++) {
            Node* current = table[i];
            while (current) {
                Node* next = current->next;
                delete current;
                current = next;
            }
        }
        delete[] table;
    }

    // Insert a key-value pair into the map
    void insert(const std::string& key, int value) {
        if (elementCount >= tableSize) {
            resize();
        }

        int index = hash(key);
        Node* newNode = new Node(key, value);
        newNode->next = table[index];
        table[index] = newNode;
        elementCount++;
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
                elementCount--;
                return;
            }
            prev = current;
            current = current->next;
        }
    }
};

int main() {
    MyUnorderedMap myMap;

    for (int i = 0; i < 20000; i++) {
        std::string key = "key_" + std::to_string(i);
        myMap.insert(key, i);
    }

    // Access and print values for keys
    for (int i = 0; i < 20000; i += 5000) {
        std::string key = "key_" + std::to_string(i);
        std::cout << key << ": " << myMap.get(key) << std::endl;
    }

    return 0;
}
/*
In this updated implementation, we added a resize function to handle resizing the hash table when the number of elements exceeds the current table size. The resize function creates a new hash table with twice the size and rehashes all existing elements to their new positions.

The elementCount member keeps track of the number of elements in the hash table to determine when a resize is needed. When elementCount exceeds the tableSize, we call the resize function.

The program now inserts and retrieves 20000 key-value pairs into the custom unordered map. By resizing the hash table as needed, it can handle more than 10000 keys efficiently.
*/