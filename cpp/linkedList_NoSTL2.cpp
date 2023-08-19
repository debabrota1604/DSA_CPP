#include<iostream>
using namespace std;

struct list{
    int val;
    list* next;
};

class MyList{
    list &l;
    public:
    MyList(){
        list t = new list();
        this.l = &t;
    }
    MyList(int i){
        l = new list();
        l.val = i;
        l.next = nullptr;
    }
};

int main(){
    list l;   

}