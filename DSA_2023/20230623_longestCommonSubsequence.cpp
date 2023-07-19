#include<bits/stdc++.h>
using namespace std;

// Subsequence means non-contiguous substring

class LongestCommonSubstring{
    string s1,s2;
    unordered_map<int,unordered_map<int,int>> memo;

    public:
    LongestCommonSubstring(string a, string b){
        this->s1=a;
        this->s2=b;
    }
    
    int recall(int ind1, int ind2){
        if(memo.find(ind1) != memo.end() && memo[ind1].find(ind2) != memo[ind1].end()){
            return memo[ind1][ind2];
        }
        else return -1;
    }

    void memorise(int ind1,int ind2, int val){
        memo[ind1][ind2] = val;
    }

    int lcs(int ind1,int ind2){
        if(ind1<0 || ind2<0) return 0; 

        int val = recall(ind1, ind2);
        if(val != -1) return val;


        int l1=0,l2=0,l3=0;
        l1=lcs(ind1-1,ind2  );
        l2=lcs(ind1,  ind2-1);
        if(s1[ind1-1] == s2[ind2-1]){
            l3=lcs(ind1-1,ind2-1) +1;
        }

        int res =  max(l1, max(l2, l3));
        cout << "[" << ind1 << "," << ind2 << "]: " << res << endl;
        memorise(ind1, ind2, res);
        return res;
    }
};


int main(){
    string s1 = "AGGTAB", s2="GXTXAYB";
    LongestCommonSubstring sSeq(s1, s2);

    cout << "Result is: " << sSeq.lcs(s1.size(), s2.size()) << endl;


}