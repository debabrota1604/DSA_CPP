#include<iostream>
using namespace std;


class listNode{
    int data;
    listNode *next;

    public:    
    listNode(){ //unparameterised constructor
        data = 0;
        next = nullptr;

        cout << "Constructor 0-param: Default data " << data << endl;

    }

    listNode(int num){ //int linked list
        data = num;
        next = nullptr;
        cout << "Constructor 1-param: Data " << data << " NextPtr: " << next << endl;

    }

    listNode(int num, listNode *nextPtr){ //int linked list
        data = num;
        next = nextPtr;
        cout << "Constructor 2-param: Data " << data << " NextPtr: " << next << endl;

    }

    int getData(){
        return data;
    }

    void setNextptr(listNode *newPtr){
        next = newPtr;
    }

    bool isNextNull (){
        if (next == nullptr || next == 0 ) return true;
        return false;
    }

    listNode* getNextPtr(){
        return next;
    }
    
};