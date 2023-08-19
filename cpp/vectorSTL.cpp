#include<iostream>
#include<vector>
using namespace std;
void disp(vector<int> v){
    // for (auto i=v.begin();i!=v.end();++i){
    //     cout << *i << " ";
    // }
    // cout <<endl;
    for(auto i:v){cout << i << " ";}
    cout <<endl;
}
int main(){
    vector<int> v={1,2,3,4,5,9,0};
    disp(v);
    cout << "Capacity of this vector: " << v.capacity() <<endl;
    cout << "Max storage of this vector: " << v.max_size() <<endl;
    v.shrink_to_fit();
    cout << "Capacity after shrinking is: " << v.capacity() <<endl;
    v.emplace_back(11);
    cout << "Inserting 11 at O(1) time..." << endl; disp(v);
    cout << "Element at index 2: " << v.at(2) << endl;

    return 0;
}