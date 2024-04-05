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

void insertNode(Node **phead, int data, int pos){//double pointer for head to reflect any changes done to the head node
    /*
    Two special cases:
    pos = 0 : insert at begin : Handled differently
    pos = -1 : insert at end : compute length and perform insert-at-any-position case
    */
    if(pos == 0){
        Node *temp = new Node(data);
        temp->ptr = *phead;
        //phead = &temp;
        *phead = temp;       
    }
    else if(pos == -1){
        Node *temp = *phead;
        pos = 1; // considering count from second node
        while(temp->ptr !=nullptr){ temp = temp->ptr; pos++; }

        return insertNode(phead, data, pos);
    }
    else{
        Node *iter = *phead, *temp = new Node(data);
        while(iter->ptr != nullptr && pos !=1){ 
            iter = iter->ptr; 
            pos--; 
        }
        if(pos >1){
            cout << "Error: The position is outside the list length" << endl;
            return;
        }
        if(iter->ptr != nullptr){ 
            temp->ptr = iter->ptr;
            // Else temp->ptr = nullptr, which is already there!
        }
        iter->ptr = temp;
    }   
}

void deleteNode(Node **head, int index){//double pointer for head to reflect any changes done to the head node
    if(*head == nullptr){
        cout << "Error: List is already empty!" << endl;
        return;
    }
    else if(index == 0){
        Node *temp = *head;
        *head = (*head)->ptr;
        delete(temp);
    }
    else if(index == -1){
        index=0;
        Node *temp = *head;
        while( temp->ptr != nullptr){
            temp = temp->ptr;
            index++;
        }
        return deleteNode(head, index);
    }
    else{
        int count = 1; //Stop at the previous node
        Node *temp = *head;
        while(count !=index){
            temp = temp->ptr;
            count++;
            if(temp == nullptr){
                cout << "Error: Delete index larger than the list length." << endl;
                return;
            }
        }        
        Node *delNode = temp->ptr;
        temp->ptr = delNode->ptr;
        delete(delNode);
    }
}

void searchAndDelete(Node **head, int key){
    Node *temp = *head;
    int counter = 0;
    while(temp != nullptr && temp->data !=key){
        temp = temp->ptr;
        counter++;
    }
    if(temp == nullptr){
        cout << "Error: Key not found in the list" << endl;
        return;
    }
    return deleteNode(head, counter);
}


int main(){
    Node *head = new Node();
    disp(head);
    insertNode(&head, 5, 0);
    disp(head);
    insertNode(&head, 2, -1);
    disp(head);
    insertNode(&head, 3, 1);
    disp(head);
    insertNode(&head, 4, 2);
    disp(head);
    insertNode(&head, 15, 10);
    disp(head);
    insertNode(&head, 6, -1);
    disp(head);
    insertNode(&head, 7, 6);
    disp(head);
    insertNode(&head, 9, 1);
    disp(head);

    cout << "Deleting nodes from here: " << endl;
    deleteNode(&head, 0);
    disp(head);
    deleteNode(&head, 9);
    disp(head);
    deleteNode(&head, 2);
    disp(head);
    deleteNode(&head, -1);
    disp(head);

    cout << "Deleting nodes through key:" << endl;
    searchAndDelete(&head, 6);
    disp(head);
    searchAndDelete(&head, 26);
    disp(head);


    return 0;    
}