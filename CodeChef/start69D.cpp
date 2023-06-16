#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int tc,n;cin>>tc;
	while(tc--){
	    cin>>n; vector<int> a (n,1); bool flag=0; int res=0,num=n;
        // Get the vector
 
        // Print the vector
        cout << "Vector: ";
        for (int i = 0; i < a.size(); i++)
            cout << a[i] << " ";
        cout << endl; 

	    for(int i=0; i<n; i++)cin>>a[i];
	    sort(a.begin(), a.end(),  greater<int>());
        // Print the reversed vector
        cout << "Sorted Vector in descending order:\n";
        for (int i = 0; i < a.size(); i++)
            cout << a[i] << " ";
        cout << endl;
	    for(int i=0;i<n; i++){
	        cout << "Checking " << a[i] << " with " << num << endl;
	        if(a[i]>num--) flag=1;
	        res+=a[i];
	    }
	    if(flag) cout << "-1\n";
	    else cout << (n*(n+1))/2-res << endl;
	}
	return 0;
}