#include<iostream>
using namespace std;

template<typename T>
struct Node{
    T data;
    Node *next;
    Node() = delete;
    Node(T inp, Node* ptr):data(inp), next(ptr){}
};

template<typename T>
class ForwardList{
    Node<T> *head;
    public:
    ForwardList():head(nullptr){}
    ForwardList(T Data): head(new Node<T>(Data, nullptr)){}
    ForwardList(initializer_list<T> lst){
        for(auto iter = lst.size()-1; iter >=0; iter--){
            //insert lst[iter] at beginning of list
        }
    }
    bool insert(T key, int pos){
        if(pos == 0){ // insert at beginning
            Node<T> *t = new Node<T>(key, head);
            head = t;
            return true;
        }
        else{
            int count=0, len = size();
            if(len < pos) return false;
            Node<T> *iter;
            while(nullptr != iter->next && (-1 == pos || count <pos)){
                iter = iter->next;
                count++;
            }
            Node<T> *t = new Node<T>(key, iter->next);
            iter->next = t;
            return true;
        }
    }
    int size(){
        int count=0;
        Node<T>* temp = head;
        while(temp){
            temp = temp->next;
            count++;
        }
        return count;
    }

    void show(){
        if(nullptr == head) return;
        Node<T>* temp = head;
        while(nullptr != temp){
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "nullptr\n";
    }

};


int main(){
    ForwardList<int> f(5);
    f.insert(3, 0);
    f.insert(4, 1);

    f.show();
    return 0;
}