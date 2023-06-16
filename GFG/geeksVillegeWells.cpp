#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    int calcDist(int si, int sj, int di, int dj){
        int res=0;




        return res;
    }
    vector<vector<int>> chefAndWells(int n,int m,vector<vector<char>> &c){
        // Code here
        vector<vector<int> > res(n, vector<int>(m, INT_MAX));
        for(int i=0;i<n; i++){
            for(int j=0; j<m;j++){
                if(c[i][j]=='W'){
                    for(int k=0; k<n; k++){
                        for(int l=0;l<m;l++){
                            int dist = calcDist(i,j,k,l);
                            res[k][l] = (res[k][l] > dist ? dist: res[k][l]);
                        }
                    }
                } 
            }
        }
    }
};

int main(){



}