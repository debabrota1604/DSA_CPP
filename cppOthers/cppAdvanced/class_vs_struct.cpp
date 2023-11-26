#include<bits/stdc++.h>
using namespace std;

class A{
    int id;
    char ch;
    public:
    A(int inp1, char inp2):id(inp1), ch(inp2){}
};

struct B{
    int id;
    char ch;
    public:
    B(int inp1, char inp2):id(inp1), ch(inp2){}
};


int main(){
    A obj(5, 'a');
    B *b = reinterpret_cast<B*> (&obj);
    
    cout << "private members of A:" << endl;
    // cout << "A.id: " << obj.id << endl;
    // cout << "A.ch: " << obj.ch << endl;
    cout << "A.id: " << (*b).id << endl;
    cout << "A.ch: " << (*b).ch << endl;
}