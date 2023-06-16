#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    int totalCuts(int N,int K,vector<int> &A){
        vector<int > negA =A; for(auto i=0;i<N;i++){negA[i] *=-1;}
        for(int i=1; i<A.size(); i++){
            cout << i-1 << " " << i << "\t" << maxLeft << " " << minRight << endl;
        }

        return 0;
    }
};


int main(){

    Solution s; vector<int> v {1, 2, 0, 2, 1};

    cout << s.totalCuts(5,2,v) << endl;


}