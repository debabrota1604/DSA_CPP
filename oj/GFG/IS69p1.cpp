#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> solveQueries(int N, int num, vector<int> &A, vector<vector<int>> &Q) {
        vector<int> res; int count=0, c2=0;
        for(auto query:Q){
            c2=0;
            for(int ind=query[0]; ind<=query[1]; ind++){
                count =0;
                for(int it=ind; it<N; it++){
                    if(A[it] == A[ind]) count++;
                }
                if(count == query[2]) c2++;
            }
            res.emplace_back(c2);
        }
        return res;
    }
};



int main(){



    return 0;
}