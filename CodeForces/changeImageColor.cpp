#include<iostream>
#include<unordered_map>
using namespace std;


int main(){
    int numInp; cin >> numInp; char a,b,c,d;
    while(numInp-->0){
        unordered_map<char, int> m;
        cin >> a >> b >> c >> d;
        m[a]++; m[b]++; m[c]++; m[d]++;
        cout << m.size()-1 << endl;
    }
}
