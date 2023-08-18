#include<bits/stdc++.h>
using namespace std;

string s1, s2; 
#define INS 1
#define DEL 1
#define REP 1

int getMin(int i, int j){
    return i<j ? i:j;
}

int minEdits(int i1, int i2){
    int res=INT_MAX;
    if(i1==0 && i2==0) return 0;
    else if(i1==0) return INS * (i2+1);
    else if(i2==0) return DEL * (i1+1);
    else if(s1[i1] != s2[i2]) {
        res = getMin(res, DEL + minEdits(i1-1,i2));
        res = getMin(res, INS + minEdits(i1, i2-1));
        res = getMin(res, REP + minEdits(i1-1,i2-1));
    }
    else return minEdits(i1-1,i2-1); //skip without any operations
    return res;
}


int main(){
    s1 = "UMBRELLA", s2 = "a";
    cout << minEdits(s1.size(),s2.size()) << endl;

    return 0;
}