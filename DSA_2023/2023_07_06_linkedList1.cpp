#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node* next;

    Node(){
        this->data = 0;
        this->next = nullptr;
    }

    Node(int data){
        this->data = data;
        this->next = nullptr;
    }
};

class LinkedList{
    Node *head;
    
    public:
    // This works in two steps, without "new" operator
    // LinkedList(){
    //     Node temp;
    //     this->head = &temp;
    // }
    LinkedList(){
        this->head = nullptr;
    }
    LinkedList(int data){
        Node temp(data);
        this->head = &temp;
    }

    void disp(){
        Node *temp = head;
        while(temp != nullptr){
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    int size(){
        int len=0;
        Node *temp=head;
        while(temp != nullptr){
            temp = temp->next;
            len++;
        }
        return len;
    }


    void insert_at_pos(int data, int pos){
        if(pos > this->size()){
            cout << "Error: Size is lesser [" << this->size() << "] than given position " << pos << endl;
            return;
        }
        if(pos==0){
            Node *temp = new Node(data);
            temp->next = head;
            head = temp;
        }
        else if(pos == -1){ //insert at end
            insert_at_pos(data, this->size());
        }
        else{ //insert at middle or end
            int count = 0;
            Node *iter = head;
            Node *temp = new Node(data);
            while(iter->next != nullptr && count !=pos-1){
                iter = iter->next;
                count++;
            }
            temp->next = iter->next;
            iter->next = temp;
        }
    }
};


int main(){
    cout << "Hello world from Ubuntu Studio\n";
    LinkedList l;
    l.disp();
    cout << "List size: " << l.size() << endl;
    l.insert_at_pos(1,0);
    l.disp();
    cout << "List size: " << l.size() << endl;
    l.insert_at_pos(3,-1);
    l.disp();
    cout << "List size: " << l.size() << endl;
    l.insert_at_pos(0,0);
    l.disp();
    cout << "List size: " << l.size() << endl;
    l.insert_at_pos(2,2);
    l.disp();
    cout << "List size: " << l.size() << endl;
    l.insert_at_pos(4,-1);
    l.disp();
    cout << "List size: " << l.size() << endl;
    l.insert_at_pos(10,10);
    l.disp();
    cout << "List size: " << l.size() << endl;

    return 0;
}
