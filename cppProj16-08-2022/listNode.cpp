#include<iostream>
using namespace std;


class listNode{
    int data;
    listNode *next;

    public:    
    listNode(){ //unparameterised constructor
        data = 0;
        next = nullptr;
<<<<<<< HEAD
        cout << "Constructor 0-param: Default data " << data << endl;
=======
        cout << "Constructor 0param: Default data " << data << endl;
>>>>>>> 645a4859a03730492de7d40b5c50da6ad927f396
    }

    listNode(int num){ //int linked list
        data = num;
        next = nullptr;
<<<<<<< HEAD
        cout << "Constructor 1-param: Data " << data << " NextPtr: " << next << endl;
=======
        cout << "Constructor 1param: Data " << data << " NextPtr: " << next << endl;
>>>>>>> 645a4859a03730492de7d40b5c50da6ad927f396
    }

    listNode(int num, listNode *nextPtr){ //int linked list
        data = num;
        next = nextPtr;
<<<<<<< HEAD
        cout << "Constructor 2-param: Data " << data << " NextPtr: " << next << endl;
=======
        cout << "Constructor 2param: Data " << data << " NextPtr: " << next << endl;
>>>>>>> 645a4859a03730492de7d40b5c50da6ad927f396
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