#include<bits/stdc++.h>
using namespace std;

struct SomeStruct{
    int num;
    char ch;

    SomeStruct(int inp1, char inp2): num(inp1), ch(inp2){}
    SomeStruct(char inp2): num(0), ch(inp2){}
};

static int i; //no initialization, auto initialization to zero.


//static SomeStruct ss; // Cannot allocate without initialization as matching constructor is absent.
static SomeStruct ss2('A'); // Can allocate as constructor is present.


void demoFunction(){
    static int demoVar = 0; // Not executed or reset, once variable is declared.
    cout << "Count is " << demoVar << endl;
    demoVar++;
}

class SomeClass{
    int id;

    public:
    static int objCount;

    SomeClass(int inp=0):id(inp){ objCount = 3; }
};

int main(){

    // Shows that the default value to a static var is always zero.
    cout << i << endl;

    // Counter will not be reset in the function.
    for(int iter=0; iter<5; iter++){
        demoFunction();
    }


    // Shows static use in class
    //cout << "Object count is: " << SomeClass::objCount << endl;
    SomeClass someObj;
    //someObj.objCount = 0;

    // Both the access type should be valid. For some reason it is throwing linking error.
    // cout << "Object count is: " << someObj.objCount << endl; 
    // cout << "Object count is: " << SomeClass::objCount << endl;


    return 0;
}