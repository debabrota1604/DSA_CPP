#include<bits/stdc++.h>
using namespace std;

int nPr(int N, int R){// nPr = factorial(n) / factorial (n-r)
    int nu=1,de=1,n=N,n_r;
    for(n_r=(N-R);n_r>0;n--,n_r--){
        nu*=n;
        if(nu%n_r==0){ nu /=n_r; } //if(n/(n-r) has no remainder, then store the quotient to numerator)
        else{ de *=n_r;} //if there is a remainder, store the denominator seperately.
    }
    return nu/de;
}

int nCr(int N, int R){// nCr = factorial(n) / (factorial (n-r) *factorial (r))
    int nu=1,de=1,n=N,r=(R<(N-R)?R:(N-R)),n_r; //take the min of R & (N-R) in r
    for(n_r=(n-r);r>0;n--,r--,n_r--){
        nu*=n;
        if(nu%r==0){ nu /=r; } //if(n/r has no remainder, then store the quotient to numerator)
        else{ de *=r;} //if there is a remainder, store the denominator seperately.
        if(nu%n_r==0){ nu /=n_r; } //if(n/(n-r) has no remainder, then store the quotient to numerator)
        else{ de *=n_r;} //if there is a remainder, store the denominator seperately.
        cout << n << " " << r << " " << n_r << " (n-r)" << " Nu: " << nu << " De: " << de << endl;
    }
    return nu/de;
}


int main(){
    cout << nPr(10,7) << endl;
    cout << nCr(10,7) << endl;



}