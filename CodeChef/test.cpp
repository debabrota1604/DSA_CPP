#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int tc;cin>>tc;
	while(tc--){
	    string ip; int res=0;
	    cin>>ip;
	    if(ip.size()<=1){cout<< "0\n";continue;}
	    for(int i=1;i<ip.size();i++){
	        if(ip[i]==ip[i-1]) res++;
	    }
	    cout << res << endl;
	}
	return 0;
}
