#include<bits/stdc++.h>
using namespace std;

//given two strings str1 and str2 anf three operations insert, delete & replace with their respective
//weights, compute the minimum weight to transform str1 into str2;


class EditDistance{
    string s1, s2;
    int costInsert, costDelete, costReplace;//0: insert, 1: delete, 2: replace

    public:
    EditDistance(string ip1, string ip2, int insW, int delW, int replaceW):s1(ip1), s2(ip2), costInsert(insW), costDelete(delW), costReplace(replaceW){}

    int solve(int pos1, int pos2){ //problem is to convert s1 into s2 with minimum cost
        if( pos1 == -1 || pos2 == -1) return 0;

        if(s1[pos1] == s2[pos2]) return solve(pos1-1, pos2-1);
        else{
            int res = INT_MAX;

            // Option 1: insert last char of s1 into s2
            res = min(res, solve(pos1, pos2-1) + costInsert);

            // Option 2: delete last char from s2 and compare next
            res = min(res, solve(pos1-1, pos2) + costDelete);

            // Option 3: replace last char of s2 with s1
            res = min(res, solve(pos1-1, pos2 -1) + costReplace);

            return res;
        }
    }
    int computeMinEditDistance(){ return solve(s1.size()-1, s2.size()-1); }
};

int main(){
    string s1 = "CAT", s2 = "CUATE";
    EditDistance ed(s1, s2, 1,1,2);
    cout << ed.computeMinEditDistance() << endl;



    return 0;
}