#include<bits/stdc++.h>
using namespace std;

vector<int> computeLPS(string pattern){
    int len=0; vector<int> lppsArr (pattern.size(), 0);
    int iter = 1; //lppsArr[0] is always zero
    while(iter <pattern.size()){
        if(pattern[iter] == pattern[len]){ len++; lppsArr[iter]=len; iter++; }
        else{
            if(len !=0) len = lppsArr[len-1]; //Example: AAACAAAA and iter= 7
            else {lppsArr[iter] = 0; iter++;}
        }
    }
    return lppsArr;
}

vector<int> computeLPPS(string pattern){
    int len=0; vector<int> lppsArr (pattern.size(), 0);
    int iter = 1; //lppsArr[0] is always zero
    while(iter <pattern.size()){
        if(pattern[iter] == pattern[len]){ len++; lppsArr[iter]=len; iter++; }
        else{
            if(len !=0) len = lppsArr[len-1]; //Example: AAACAAAA and iter= 7
            else {lppsArr[iter] = 0; iter++;}
        }
    }
    return lppsArr;
}


int main(){
    string s; cin>>s;
    cout << "The array for <longest Proper Prefix which is also a suffix> is: "; 
    auto res = computeLPPS(s); for(int i=0; i<s.size(); i++){ cout << res[i] << " "; }
    cout << "\n";
}