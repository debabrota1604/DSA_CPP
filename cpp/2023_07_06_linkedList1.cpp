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


    void insertAt(int pos, int data){
        if(pos==0){
            Node *temp = new Node(data);
            temp->next = head;
            head = temp;
        }
        else if(pos == -1){ //insert at end
            pos=0;
            Node *temp = head;
            while(temp != nullptr){
                temp = temp->next;
                pos++;
            }
            insertAt(pos, data);
        }
        else{ //insert at middle or end
            int count = 1;
            Node *iter = head;
            Node *temp = new Node(data);
            while(iter->next != nullptr && count !=pos){
                iter = iter->next;
                count++;
            }
            if(count >pos){
                cout << "Error: Delete index is larger than list size!" << endl;
                return;
            }
            temp->next = iter->next;
            iter->next = temp;
        }
    }

    void deleteFrom(int pos){
        Node *temp = head;
        if(pos == 0){
            head = head->next;
            delete(temp);
            return;
        }
        else if(pos == -1){
            pos=0;
            while(temp->next != nullptr){
                temp = temp->next;
                pos++;
            }
            return deleteFrom(pos);
        }
        else{
            while(pos >1){
                temp = temp->next;
                pos--;
                if(temp= nullptr){
                    cout << "Delete Error: position outside list size" << endl;
                    return;
                }
            }
            Node *temp2 = temp->next;
            if(temp2->next == nullptr){
                temp->next = nullptr;
            }
            else{
                temp->next = temp->next->next;
            }
            delete(temp2);
        }
    }
};


int main(){
    cout << "Hello world from Ubuntu Studio\n";
    LinkedList l;
    l.disp();
    l.insertAt(0,1);
    l.disp();
    l.insertAt(-1,3);
    l.disp();
    l.insertAt(0,0);
    l.disp();
    l.insertAt(2,2);
    l.disp();
    l.insertAt(-1,4);
    l.disp();
    l.insertAt(10,10);
    l.disp();



    l.deleteFrom(0);
    l.disp();
    l.deleteFrom(1);
    l.disp();
    l.deleteFrom(-1);
    l.disp();

    return 0;
}
