#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int hardestWorker(int n, vector<vector<int>>& logs) {
        int resID=0, resDur=0, lastFinish=0, thisDur;
        for(auto i:logs){
            thisDur = i[1] - lastFinish ;
            cout << "Check: " << i[0] << " timeTaken: " << thisDur << endl;
            if(thisDur > resDur){
                resDur=thisDur;
                resID = i[0];
                cout << "Update: " << resDur << " " << resID << endl;
            }
            if(thisDur == resDur && i[0] < resID){
                resDur=thisDur;
                resID = i[0];
                cout << "Update: " << resDur << " " << resID << endl;
            }
            lastFinish = i[1];
        }
        return resID;
    }
};



int main(){

    Solution s;
    vector<vector<int>> v {{36,3},{1,5},{12,8},{25,9},{53,11},{29,12},{52,14}};
    cout << s.hardestWorker(0, v) << endl;

    vector<vector<int>> v2 {{0,10}, {1,20}};
    cout << s.hardestWorker(0, v2) << endl;



    return 0;
}