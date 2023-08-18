#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<int> v = {1,2,3,4,5};
    for(auto i:v){  cout << i << " "; } cout << endl;
    auto vec = v; vec.erase(vec.begin());
    for(auto i:vec){  cout << i << " "; } cout << endl;
    for(auto i:v){  cout << i << " "; } cout << endl;
}