#include<bits/stdc++.h>
using namespace std;



int main(){

    string s; cin >> s; int i=0,j=0,k=0,sum;
    for(auto ch:s){
        if(ch=='1') i++;
        else if(ch=='2') j++;
        else if(ch=='3') k++;
    }
    sum = i+j+k;
    for(int it=1; it<sum; it++){
        if (i>0){ cout << '1' << '+'; i--;}
        else if (j>0){ cout << '2' << '+'; j--;}
        else if (k>0){ cout << '3' << '+'; k--;}
    }

        if (i>0){ cout << '1' << endl;}
        else if (j>0){ cout << '2' << endl;}
        else if (k>0){ cout << '3' << endl;}




    return 0;
}