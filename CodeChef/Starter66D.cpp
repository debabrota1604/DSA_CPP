#include <iostream>
using namespace std;

int main() {
	// your code goes here
	long long  tc,n,m,k,x;cin>>tc;
	while(tc--){
	    cin>>n>>m>>k>>x;
        cout << n << " " << m << " " << k << " " << x << endl;
	    long long modval =(n * k) + m;x = x %modval; 
        cout << "ModVal: " << modval;
        cout << "Mod x: " << x << endl;
	    if(x!=0 && x <=(n-1)*k) cout << "NO\n";
	    else cout << "YES\n";
	}
	return 0;
}