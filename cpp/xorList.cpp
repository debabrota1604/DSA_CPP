#include<iostream>
using namespace std;


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