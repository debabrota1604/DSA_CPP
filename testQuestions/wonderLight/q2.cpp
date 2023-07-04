#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<int> v = {1,2,3,4,5};
    v.reserve(10);
    v.resize(20);
    cout << sizeof(v) << endl;

    return 0;
}

/*
Output:
A. 24
B. 40
C. 80
D. 160

correct answer: A

*/