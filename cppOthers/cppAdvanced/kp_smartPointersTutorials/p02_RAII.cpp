#include<bits/stdc++.h>
using namespace std;


// RAII: Resource Acquisition in Initialization

/* Principle is to use a wrapper class whenever memory alloc/dealloc is happening */

template<typename T>
class Wrapper{
    private:
    T *safeVar;

    public:
    Wrapper(T *inp):safeVar(inp){
        cout << "Allocating Memory" << endl;
    }

    ~Wrapper(){
        cout << "Deallocating Memory\n";
        delete (safeVar);
    }
};

int main(){
    // No need to perform deallocation as whenever obj is out of scope, Wrapper destructor is called.
    Wrapper<int> obj(new int(10));

}