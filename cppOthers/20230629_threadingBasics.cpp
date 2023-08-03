#include<bits/stdc++.h>
using namespace std;

void fun1(int i, int j){
    while(j!=10){
        sleep(1);
        cout << "Thread " << i << ": " << ++j << endl;
    }
}

class CallableObj{
    public:
    void operator()(int i, int j){
            while(j!=10){
            sleep(1);
            cout << "Thread " << i << ": " << ++j << endl;
        }
    }
};

int main(){
    cout << "Main: Creating function threads...\n";
    thread t1(fun1,1,1);
    thread t2(fun1,2,5);

    cout << "Main: Threads created... going to wait state...\n";

    t1.join();
    t2.join();

    cout << "Main: Creating Callable Object threads...\n";
    thread t3(CallableObj(),3,1);

    cout << "Main: Threads created... going to wait state...\n";

    t3.join();
    cout<< "Main: Threads returned. Exiting..." << endl;

    
}