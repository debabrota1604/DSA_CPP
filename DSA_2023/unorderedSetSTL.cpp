#include<iostream>
#include<unordered_set>
#include<set>
using namespace std;

int main(){
    unordered_set<char> s = {'c', 'b','a','c','d','c','b','c'};//{'b','c','a','b','c'};
    set<char> s2={s.begin(),s.end()};

    for (auto i:s){ cout << i << " "; }; cout << endl;
    for (auto i:s2){ cout << i << " "; }; cout << endl;



    return 0;
}