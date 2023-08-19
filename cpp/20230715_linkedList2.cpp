#include<bits/stdc++.h>
using namespace std;

class Node{
    int data;
    Node *next;

    public:
    Node(){
        data = 0;
        next = nullptr;
    }
    Node(int inp){
        data = inp;
        next = nullptr;
    }
    int getData(){
        return data;
    }
    void setData(int data){
        this->data = data;
    }
    Node* getNextPtr(){
        return next;
    }
    void setNextPtr(Node* ptr){
        next = ptr;
    }
    bool isNextNull(){
        return next == nullptr;
    }
    void operator++(){
        *this = *(this->next);
    }
};

class List{
    Node *head;
    public:
    List(){
        head = nullptr;
    }
    void insBeg(int data){
        Node *node = new Node(data);
        if(head == nullptr){
            head = node;
        }
        else{
            node->setNextPtr(head);
            head = node;
        }
    }
    void insEnd(int data){
        Node *node = new Node(data);
        
        if(head == nullptr){
            head = node;
        }
        else{
            Node *iter = head;
            while(!iter->isNextNull()) iter = iter->getNextPtr();
            iter->setNextPtr(node);
        }
    }
    void insertVectorAtEnd(vector<int> arr){
        reverse(arr.begin(), arr.end());
        for(auto item:arr){
            Node *node = new Node(item);
            if(head == nullptr){
                head = node;
            }
            else{
                node->setNextPtr(head);
                head = node;
            }
        }
    }

    void specialOperation(){
        Node *temp = head;
        while(temp->getNextPtr()){
            if(temp->getData() == temp->getNextPtr()->getData()){
                temp->setData(2*temp->getData());
                temp->getNextPtr()->setData(0);
            }
            temp = temp->getNextPtr();
        }
    }
    void specialOperation2(){
        Node *temp = head, *temp2=head;
        int count =0;
        while(temp){
            if(temp->getData() == 0){
                count++;
                temp = temp->getNextPtr();
            }
            else{
                temp2->setData(temp->getData());
                temp2 = temp2->getNextPtr();
                temp = temp->getNextPtr();
            }
        }
        while(temp2){
            temp2->setData(0);
            temp2 = temp2->getNextPtr();
        }
    }

    void disp(){
        Node *temp = head;
        cout << "Currently the list looks like: \n";
        while(temp){
            cout << temp->getData() << " ";
            temp = temp->getNextPtr();
        }
        cout << endl;
    }
};




int main(){

    List l2;
    l2.insertVectorAtEnd({2,2,0,4,0,8});
    l2.disp();
    l2.specialOperation();
    l2.disp();
    l2.specialOperation2();
    l2.disp();



    return 0;
}