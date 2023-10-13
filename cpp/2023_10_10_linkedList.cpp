#include<iostream>
using namespace std;


struct Node{
    int data;
    Node *next;
    
    Node(int data):data(data), next(nullptr){}
    Node(int data, Node* ptr):data(data), next(ptr){}
};

class LinkedList{
    Node *head;
    public:
    LinkedList():head(nullptr){}
    LinkedList(int data){
        Node *temp = new Node(data);
        head = temp;
    }

    void insert(int pos, int data){
        if(pos == 1){
            if(!head){
                head = new Node(data);
            }
            
        }
        if(pos ==2){
            if(!head->next){
                //only one node is present
                head->next = new Node(data);
            }
        }
    }
};
