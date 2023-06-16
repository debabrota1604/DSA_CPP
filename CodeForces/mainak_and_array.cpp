#include<bits/stdc++.h>
using namespace std;


int main(){
    int tc, sz, data; vector<int> inp;

    cin >> tc;
    while(tc--){
        cin >> sz;
        for(auto iter=0; iter<sz; iter++){
            cin >> data;
            inp.push_back(data);
        }
        cout << *max_element(inp.begin(), inp.end()) - *min_element(inp.begin(), inp.end()) << endl;
        inp.clear();
    }

    return 0;
}