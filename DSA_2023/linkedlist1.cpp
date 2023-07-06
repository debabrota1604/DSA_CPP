#include<iostream>
using namespace std;

struct Node{
    int data;
    Node *ptr;
    Node(){
        data = 0;
        ptr = nullptr;
    }
    Node(int num){
        this->data = num;
        ptr = nullptr;
    }
};


void disp(Node *head){
    Node *temp = head;
    while(temp!=nullptr){
        cout << temp->data << " ";
        temp = temp->ptr;
    }
    cout << endl;
}

void insert(Node **phead, int data, int pos){
    /*
    pos = 0 : insert at begin
    pos = -1 : insert at end
    */
    if(pos == 0){
        Node *temp = new Node(data);
        temp->ptr = *phead;
        //phead = &temp;
        *phead = temp;       
    }
}

int main(){
    Node *head = new Node();
    disp(head);
    insert(&head, 5, 0);
    disp(head);

    return 0;    
}