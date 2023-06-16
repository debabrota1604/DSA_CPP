#include<iostream>
#include<vector>
using namespace std;

int main(){
    cout << "This function takes two inputs n & k and returns a string of lowercase characters whose numeric sum is k and is alphabetically smallest with n characters. " << endl;
    cout << "Input n & k: ";
    int n,k; cin >> n; cin >> k;

    vector<int> v; v= {1,n};
    for(int i=0;i<n;i++) cout << v[i] << endl;

    
    return 0;
}