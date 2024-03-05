#include<iostream>
using namespace std;


// Idea is to implement a doubly linked list using a single pointer in the Node definition.
// https://www.geeksforgeeks.org/xor-linked-list-a-memory-efficient-doubly-linked-list-set-1/

struct Node{
    int data;
    Node *ptr;

    Node(int data): data(data), ptr(nullptr){}
};


class List{
    Node *head;

    public:
    List():head(nullptr){}

    List(int data){
        head = new Node(data);
    }

    void insertAtBgn(int data){
        Node *newNode = new Node(data);

        Node *Node2Ptr = reinterpret_cast<Node *> ((void *) newNode ^ (void *) head->ptr);

        newNode->ptr = head;
        head->ptr = Node2Ptr;
    }
};