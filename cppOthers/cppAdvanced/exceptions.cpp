#include<iostream>
using namespace std;

class A{
    int i,j;
    public:
    A():i(0), j(1){}
    double exception01_basic(){
        double res=0;
        try{
            cout << i << ":" << j << endl;
            if(i==0) throw i;
            res = j/i;
        }
        catch(...){
            cout << "Basic Error: Div by zero!!!" << endl;
        }
        return res;
    }

    void runtimeErr()  noexcept
    {
        throw runtime_error("Generic Error");
    }

    void exception02_generic(){
        try{
            runtimeErr();
        }
        catch(const exception& e){
            cout << e.what() << endl;
        }
    }
};


int main(){
    A a;
    a.exception01_basic();
    a.exception02_generic();

    return 0;
}