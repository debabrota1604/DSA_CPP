#include <iostream>
#include <utility> // for std::pair

template <typename Key, typename Value>
class MyMap {
private:
    enum Color { RED, BLACK };

    struct Node {
        Key key;
        Value value;
        Node* left;
        Node* right;
        Color color;

        Node(const Key& k, const Value& v) : key(k), value(v), left(nullptr), right(nullptr), color(RED) {}
    };

    Node* root;

    // Helper function for insertion (red-black tree balancing)
    Node* insert(Node* node, const Key& key, const Value& value) {
        if (node == nullptr)
            return new Node(key, value);

        if (key < node->key)
            node->left = insert(node->left, key, value);
        else if (key > node->key)
            node->right = insert(node->right, key, value);
        else
            node->value = value; // Update existing key

        // Red-black tree balancing rules
        // (You can implement these rules here)

        return node;
    }

    // Helper function for searching
    Node* search(Node* node, const Key& key) {
        if (node == nullptr || node->key == key)
            return node;

        if (key < node->key)
            return search(node->left, key);
        else
            return search(node->right, key);
    }

    // Helper function for deletion
    Node* deleteKey(Node* node, const Key& key) {
        if (node == nullptr)
            return nullptr;

        if (key < node->key)
            node->left = deleteKey(node->left, key);
        else if (key > node->key)
            node->right = deleteKey(node->right, key);
        else {
            // Node to be deleted found
            if (node->left == nullptr || node->right == nullptr) {
                Node* temp = (node->left) ? node->left : node->right;
                delete node;
                return temp;
            }

            // Node has two children, find in-order successor
            Node* temp = minValueNode(node->right);
            node->key = temp->key;
            node->value = temp->value;
            node->right = deleteKey(node->right, temp->key);
        }

        // Red-black tree balancing rules
        // (You can implement these rules here)

        return node;
    }

    // Helper function to find minimum value node
    Node* minValueNode(Node* node) {
        while (node->left != nullptr)
            node = node->left;
        return node;
    }

    // Helper function for inorder traversal
    void inorderTraversal(Node* node) {
        if (node == nullptr)
            return;

        inorderTraversal(node->left);
        std::cout << node->key << ": " << node->value << std::endl;
        inorderTraversal(node->right);
    }

public:
    MyMap() : root(nullptr) {}

    void insert(const Key& key, const Value& value) {
        root = insert(root, key, value);
        root->color = BLACK; // Root is always black
    }

    Value search(const Key& key) {
        Node* result = search(root, key);
        return (result != nullptr) ? result->value : Value{}; // Return default-constructed value if not found
    }

    void deleteKey(const Key& key) {
        root = deleteKey(root, key);
        if (root != nullptr)
            root->color = BLACK; // Root is always black
    }

    void inorderTraversal() {
        inorderTraversal(root);
    }
};

int main() {
    MyMap<int, std::string> myMap;
    myMap.insert(1, "apple");
    myMap.insert(2, "banana");
    myMap.insert(3, "cherry");

    std::cout << "Value at key 2: " << myMap.search(2) << std::endl;

    myMap.deleteKey(2);
    std::cout << "After deletion:" << std::endl;
    myMap.inorderTraversal();

    return 0;
}
