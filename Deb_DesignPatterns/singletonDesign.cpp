#include<bits/stdc++.h>
using namespace std;

class SingleInstance{
    static SingleInstance* instance;
    SingleInstance();
    SingleInstance(const SingleInstance& copyObj) =0;
    SingleInstance(SingleInstance&& copyObj) =0;
    void operator=(const SingleInstance& copyAssignObj) =0;
    void operator=(SingleInstance&& moveAssignObj) =0;

    public:
    SingleInstance* getInstance(){
        if(instance == nullptr){
            instance = new SingleInstance();
        }
        return instance;
    }
};