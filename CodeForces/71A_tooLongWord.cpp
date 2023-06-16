#include<bits/stdc++.h>
using namespace std;



int main(){

    int sz; cin >> sz;
    while(sz--){
        string s;
        cin >> s; 
        if(s.size() >10) cout << s.front()-2 << s.size() << s.back() << endl;
        else cout << s << endl;
    }




    return 0;
}