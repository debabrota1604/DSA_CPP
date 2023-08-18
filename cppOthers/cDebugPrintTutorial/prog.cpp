#include<iostream>

using namespace std;

#ifdef debugEnable
    #define debug(arg) (arg)
#else
    #define debug(arg) ((void)0)
#endif

int main(){
    debug(cout<< "This is a debug print" << endl);
    cout << "This is a normal print, which will appear always" << endl;    
}
