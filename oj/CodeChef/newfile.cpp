#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int tc; cin>>tc;
	while(tc--){
	    int x,y; cin>>x>>y;
	    while(true){
	        if(x<y){
	            x *=x;
	            if(x>y){
	                cout << "NO" << endl; break;
	            }
	        }
	        else if(y<x){
	            y *=y;
	            if(y>x){
	                cout << "NO" << endl; break;
	            }
	        }
	        else{
	            cout << "YES" << endl;
	        }
	        cout << "Check " << x << " " << y << endl;
	    }
	}
	return 0;
}
