#include<bits/stdc++.h>
using namespace std;

string s1, s2; 

int getMax(int i, int j){
    return i>j ? i:j;
}

int maxCommon(int i, int j){
    int res=0;
    if(i==0 || j==0) return 0;
    else if(s1[i] == s2[j]) return maxCommon(i-1, j-1) +1;//check next char if same
    else{
        res = getMax(res, maxCommon(i-1, j));//delete
        res = getMax(res, maxCommon(i, j-1));//insert
        res = getMax(res, maxCommon(i-1, j-1));//replace
    }
    return res;
}


int main(){
    s1 = "UMBRELLA", s2 = "AUMRA";
    cout << maxCommon(s1.size(), s2.size()) << endl;
    return 0;
}