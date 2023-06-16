#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int tc;cin >> tc;
	while(tc--){
	    int sz; cin>>sz;
	    string ip, res; cin>>ip;
	    vector<int> nums; int plus=0,minus=0; bool op=false;
	    for(auto ch:ip){
	        if(ch=='+') plus++;
	        else if(ch=='-') minus++;
	        else nums.emplace_back(ch-'0');
	    }
	    sort(nums.rbegin(), nums.rend());
	    for(int i=0; i<sz;i++){
	        if(op && minus>0){ res+='-'; minus--; op=!op;}
	        else if(op && plus>0){ res+='+'; plus--; op=!op;}
	        else{ res+= to_string(nums.back()); nums.pop_back(); op=!op;}
	    }
        reverse(res.begin(), res.end());
        cout << res << '\n';
	}
	return 0;
}