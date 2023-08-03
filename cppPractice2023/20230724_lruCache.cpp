#include<bits/stdc++.h>
using namespace std;

template<typename T>
struct Node{
    T key,value;
    Node *prev, *next;  
    Node(T Key, T Value): key(Key), value(Value){}
};

template<typename T>
class LruCache{
    Node *head, *tail;
    unordered_map<T, Node *> cache;
    int cacheSize;

    void moveToTail(Node *keyNode){
        // Step1: Adjust remaining list
        if(keyNode == head){
            head = head->next;
        }
        else if(keyNode == tail) return;
        else{ // intermediate node
            keyNode->next->prev = keyNode->prev;
            keyNode->prev->next = keyNode->next;
        }

        // link the keynode with tailNode
        tail->next = keyNode;
        keyNode->prev = tail;
        tail = keyNode;
    }
    public:
    LruCache(): cacheSize(0), head(nullptr), tail(nullptr){}
    T get(T key){
        //Key not found
        if(cache.find(key) == cache.end()) return -1;

        //Key is present. Get value and push the node to tail
        Node* keyNode = cache[key];
        moveToTail(keyNode);
        return keyNode->value;
    }
    void put(T key, T value){
        if(cache.find(key)!=cache.end()){ //Key already exists in the LRU, update with latest value
            Node *keyNode = cache[key];
            keyNode->value = value;
            moveToTail(cache[key]);
            return;
        }
        else{ // Create a node, link it and delete the LRU node.
            Node *keyNode = new Node(key, value);
            cache[key] = keyNode;

            // add keyNode to the list
            tail->next = keyNode;
            keyNode->prev = tail;
            tail = keyNode;

            // delete lru node from the list
            Node *temp = head;
            head = head->next;
            head->next->prev = nullptr;
            delete temp;
        }
    }
};