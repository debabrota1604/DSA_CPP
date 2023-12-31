#include<bits/stdc++.h>
using namespace std;

// Problem: Given an m x n matrix matrix and an integer k, return the max sum of a rectangle in the matrix such that its sum is no larger than k.
// It is guaranteed that there will be a rectangle with a sum no larger than k.

// Algorithm: DP with memoization
// 1. five local variables: sti,stj,edi,edj,localSum. One map of four ints mapping to one int.
// 2. Two functions. RecMaxSum(si,sj,ei,ej) to compute the rectangle size and store its sum to the map. 
//     ComputeSum(si,sj,ei,ej) computes sum of rectangle starting from (si,sj) to (ei,ej) and returns.
//     If map already has an entry for the index touple then return.
// 3. start this recursize function with si=0,sj=0,ei=si,ej=sj. then go to (si,sj,ei.size(),ej.size()) for all values of ei,ej.
// 4. return when any sum is found to be k. else return localSum at the end.
 

class Solution {
    unordered_map<string,int> m;
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {

        //initializations of local var
        int si=0,sj=0,ei=0,ej=0,localSum=INT_MIN, localMax=INT_MIN; 
        int rowSize=matrix.size(), colSize = matrix[0].size(); 

        for(si=0;si<rowSize;si++){
            for(sj=0;sj<colSize;sj++){
                for(ei=si;ei<rowSize;ei++){
                    for(ej=sj;ej<colSize;ej++){
                        localSum = computeSum(matrix,k,si,sj,ei,ej);
                        if(localSum <=k){
                            if (localSum ==k) return localSum;
                            if (localSum>localMax) localMax = localSum;
                        }                        
                    }
                }
            }
        }
        return localMax;
    }
    int computeSum(const vector<vector<int>>& matrix, int k, int si, int sj, int ei, int ej){

        //create map strings
        string mapIndex = "[" + to_string(si) + "," + to_string(sj) + "][" + to_string(ei) + "," + to_string(ej) + "]";
        string mapIndex_lr = "[" + to_string(si) + "," + to_string(sj) + "][" + to_string(ei-1) + "," + to_string(ej) + "]";
        string mapIndex_lc = "[" + to_string(si) + "," + to_string(sj) + "][" + to_string(ei) + "," + to_string(ej-1) + "]";

        //check for map entry
        if (si == ei && sj ==ej ){//sum of a single cell
            m[mapIndex] = matrix[si][sj]; 
            return m[mapIndex];  
        }
        else if (m.find(mapIndex) !=m.end()){  // if value already exists
            return m[mapIndex]; 
        }
        else if (si==ei && m.find(mapIndex_lc) !=m.end()){ // adding a new cell in column
            m[mapIndex] = m[mapIndex_lc] + matrix[ei][ej]; 
            return m[mapIndex]; 
        } 
        else if (sj==ej && m.find(mapIndex_lr) !=m.end()){ // adding a new cell in row
            m[mapIndex] = m[mapIndex_lr] + matrix[ei][ej]; 
            return m[mapIndex]; 
        }

        //if no entry exists, compute the sum of the last row
        int sum=0;
        for(int j=sj;j<=ej;j++){
            sum +=matrix[ei][j];
        }            
        m[mapIndex] = sum + m[mapIndex_lr]; //map gives sum till last row-1. then then add the last row sum.        
        return m[mapIndex];
    }
};



int main(){
    Solution s;

    //vector<vector<int>> v {{1,0,1},{0,-2,3}}; int k=2;
    //vector<vector<int>> v {{2,2,-1}}; int k=3;
    //vector<vector<int>> v {{28,4,-19,18,-7,-10,27,19,1,16,0,10,-17,11,11,27,-1,10,12,-1},{-2,-19,17,4,25,-20,4,3,4,28,-10,7,16,-14,-3,-19,6,17,-4,-7},{2,8,18,-17,-2,10,-6,-5,11,10,22,-6,19,-16,6,-4,18,5,22,-17},{-14,-7,-20,13,-19,-20,-15,21,-11,-10,-8,-9,10,13,6,-10,15,9,-15,-2},{-18,26,12,8,2,16,-17,12,0,-5,9,-3,-12,-11,3,-6,-18,16,-7,-14},{5,29,25,22,11,-3,-2,-15,4,13,-17,-2,0,-2,20,10,-18,6,25,-20},{5,-7,8,5,15,22,8,-5,22,-18,-5,-14,23,2,-8,12,-16,-18,12,-12},{27,18,4,11,-3,12,-4,-8,-3,25,-9,24,-14,5,11,-9,-17,0,25,-15},{26,-7,18,4,4,18,-17,9,-19,-9,-19,-8,-4,-13,10,-11,6,-16,-12,12},{28,22,7,11,-6,13,8,22,7,-14,17,14,10,29,16,9,-3,18,-9,10},{27,19,-10,-9,1,3,14,1,7,3,-3,16,-2,9,14,-7,-19,-5,23,19},{-17,7,-20,8,-5,-6,-2,25,29,16,23,4,4,27,16,17,9,20,-6,22},{2,9,-13,1,-18,25,4,7,25,26,-4,8,-19,18,6,-7,-5,7,21,-8},{-2,11,1,29,6,-16,-8,3,7,11,10,-2,-1,-20,20,4,19,5,29,-7},{29,-12,-3,17,6,19,23,12,-19,13,19,5,27,22,-17,27,10,-12,12,23},{24,16,4,25,15,13,24,-19,1,-7,-19,13,-13,14,13,26,9,18,-9,-18},{-17,4,-18,-18,-19,3,-13,12,23,-17,-10,-20,14,2,18,21,-12,27,-3,4},{27,13,12,14,16,-9,-2,-15,-20,8,-2,24,18,15,26,21,27,17,-15,-3},{25,-8,17,-10,-16,13,26,-11,-15,6,-5,-13,23,2,24,-4,5,8,-15,-1},{15,-12,18,5,-3,7,5,11,-4,-13,28,20,0,-4,-13,-5,-13,-8,-16,3}}; int k=-123;
    //vector<vector<int>> v {{5,-4,-3,4},{-3,-4,4,5},{5,1,5,-4}}; int k=10;
    vector<vector<int>> v {{2,-9,2,-6,-3,-8,6,-6,3,7,-10,-2,9,1,3,-9,-3,4,0,-10,7,-9,-8,6,-10,-3,4,-5,-7,0,2,3,-1,-9,-3,5,-6,-4,1,-1,8,-4,5,-4,-1,0,-9,-1,-10,-3},{-8,7,7,-10,-7,7,0,4,1,0,1,-2,8,4,-10,-1,8,5,-8,5,6,-1,1,3,-10,2,6,1,-10,-1,5,6,8,0,2,2,3,-2,5,2,4,-1,0,8,-2,5,2,3,-6,-2},{9,7,3,-8,0,-8,5,-2,-3,-7,-4,3,1,-9,4,6,-9,-1,2,-1,9,-7,1,2,-8,9,6,5,0,7,-3,-1,0,5,-3,-2,7,0,-6,8,-4,-8,-4,-2,-2,8,-1,8,-2,-6},{1,-7,5,-10,-4,6,4,-3,1,5,7,-1,3,4,6,-7,0,-6,-6,1,-8,5,-5,7,8,1,-8,9,-2,3,0,9,-3,5,-8,9,8,-2,5,-8,-6,-3,-1,7,1,-5,-10,-10,3,0},{8,8,-4,-7,-5,-4,-6,-9,8,6,5,-1,-4,6,6,-9,-2,3,-6,4,-2,6,-5,0,0,4,-1,1,-4,-4,4,7,-3,2,-1,-1,3,5,7,-7,9,-4,-8,-9,-2,-5,-4,-6,8,2},{2,0,3,-9,6,-2,-9,0,-3,9,4,3,5,8,1,-7,-10,-4,3,-4,2,2,-9,-3,-5,8,-9,-10,3,-6,-7,-4,-4,-1,-4,-9,0,-8,3,8,-10,-3,7,-5,-1,-2,9,7,4,-1},{0,3,5,-9,-5,2,5,-7,2,-7,2,-4,-3,-8,0,-3,2,2,9,-2,9,4,4,-7,-4,1,-6,-10,-8,-1,-4,1,4,5,-2,7,-4,8,-1,-9,3,-6,-5,8,-3,-7,5,5,4,-8},{-7,-1,3,5,1,-2,0,-1,-6,7,6,-4,-7,5,6,-10,-2,7,7,5,1,1,7,8,4,9,0,9,-4,3,-10,2,-1,-8,-9,9,-2,8,-3,-6,-10,-2,-9,8,-4,8,-1,5,-3,7},{-2,3,-5,4,9,-5,-10,8,-10,-5,-10,-3,-7,-2,-3,9,1,-2,-1,-2,1,3,3,-9,4,2,5,-2,1,4,7,-6,-1,8,9,-9,9,-5,-8,-4,-1,7,-4,1,-8,-3,1,1,-9,-9},{-9,9,8,0,-2,5,-8,-6,8,6,3,-10,8,9,-3,-6,-2,-1,-1,8,-4,-6,8,9,1,-5,8,0,-8,0,7,-9,0,0,4,3,1,8,8,4,5,5,6,7,-9,-9,-3,-4,-4,4},{0,-10,4,1,4,9,-8,8,7,-6,-10,-1,0,4,0,8,3,2,4,2,-5,0,-5,-10,-3,-9,9,5,2,2,1,9,7,-3,-7,2,-8,3,0,-5,-9,-6,-6,-6,-5,5,8,4,5,-9},{-7,8,1,6,-9,-10,0,-1,-10,-9,8,3,-10,-5,-7,-7,-5,1,7,-5,2,5,-5,-10,-6,8,-1,2,4,-7,0,-3,6,-3,-6,2,9,8,-9,1,2,-8,8,-3,-10,-7,4,-10,6,9},{9,1,6,2,8,-7,8,-6,0,-5,-1,-5,6,7,-4,-9,-1,-4,5,1,3,-10,-7,4,5,-9,7,4,6,5,-10,-9,-2,9,-4,-3,1,-10,5,-9,-10,4,-1,-3,-6,7,-1,-6,-1,-7},{-1,8,-9,-6,-2,0,3,5,-1,-1,-1,-8,-6,-6,-1,-8,-1,-1,2,-1,1,4,-6,-7,-6,-9,-7,4,-5,-1,-5,-1,-10,-2,-5,-10,-10,4,-6,7,-4,7,9,0,-9,3,-1,4,-7,3},{-8,3,-8,1,3,2,-3,-5,6,6,0,2,5,3,4,7,0,-8,-6,7,7,-6,4,3,-2,-2,2,1,-2,-6,-8,6,-3,-2,-7,1,-6,3,4,-6,-3,5,-7,-2,7,2,-1,2,-3,-2},{-1,-10,9,-4,-9,-4,6,0,8,-7,9,3,-3,8,0,-8,1,0,-6,-4,-5,-1,-2,1,-4,-8,-7,-10,0,4,6,6,-4,4,4,-2,7,2,-1,4,0,-9,7,9,-8,4,-6,-7,-7,-1},{-5,-6,-3,-8,6,-10,-5,-9,5,-3,-10,-8,8,-2,4,6,-3,8,2,4,-5,1,-7,6,0,6,9,6,9,6,-6,2,9,7,-8,-3,0,4,-1,-4,-7,6,3,-5,6,-7,-10,8,7,7},{6,7,-6,-2,6,-2,1,-3,3,-9,-8,9,-5,-4,5,5,-2,-1,-7,4,3,-10,-4,-4,9,-4,-4,-5,-1,-7,2,1,-3,6,6,1,4,-3,-7,-3,-5,-5,7,-1,3,-10,2,2,4,-10},{7,4,-7,-6,-1,5,-6,8,-1,-1,-5,9,-1,4,-4,-10,-7,-7,7,-8,-8,4,1,-7,-1,1,-7,4,4,-4,-6,1,-8,5,-1,-8,5,-8,4,-9,5,3,6,2,1,-2,2,-9,2,-2},{-9,-2,-1,-3,5,2,7,9,6,-4,4,-3,-5,5,8,0,6,7,-6,9,-1,0,1,-6,7,5,0,1,-3,-8,-6,-4,-1,-4,4,4,3,-6,3,8,-10,9,-7,-1,9,9,-3,-1,2,4},{7,-8,-3,8,0,0,-8,-7,-3,4,3,-3,-8,-5,4,9,6,9,-6,-8,0,3,5,-7,7,-3,-2,-6,-3,0,-9,-2,-2,-7,-8,-10,0,5,3,7,7,-1,9,-1,-4,3,3,3,2,4},{-8,-4,5,9,-1,1,6,7,3,7,-4,6,-8,6,-6,0,2,-5,8,-10,1,2,6,2,-1,-6,-6,4,6,-1,-10,-3,-5,-9,6,-3,-9,4,-9,-4,-4,5,4,-4,-1,-5,-4,1,-3,-6},{0,9,-2,4,-1,8,5,-3,3,-9,1,4,-3,8,4,5,0,5,2,7,-3,6,8,4,7,8,6,-2,-6,-4,-3,-4,1,7,-10,5,4,7,7,-3,6,6,-6,6,7,2,-1,-3,-2,-4},{4,-7,-7,4,-7,-1,-8,5,2,-10,7,6,0,1,6,5,4,-5,-8,-6,0,5,-1,-10,-5,-9,-7,1,3,4,0,2,5,-1,-6,-5,-7,2,0,-1,3,-4,-1,-7,9,4,4,-3,-3,7},{8,-6,5,6,-1,0,-2,4,2,-6,-10,5,6,-9,-3,0,-4,-7,1,-9,2,2,1,4,-5,-10,-9,5,9,-4,-7,-5,6,5,6,4,-3,-6,-7,0,-5,-2,-2,5,1,3,-9,9,3,-9},{1,-5,-6,-10,3,9,6,-2,-5,-3,-5,7,4,-1,9,4,7,-2,1,-6,1,9,-6,-1,-8,-1,0,-10,9,-10,8,9,-3,5,-4,-1,6,0,0,-1,-3,8,2,9,-6,-1,5,3,4,-7},{-8,-6,1,7,-7,3,4,4,4,0,9,6,6,3,-8,3,9,1,2,-4,6,7,-3,9,-4,-3,-9,6,-5,-5,-4,4,9,-4,-1,3,4,-4,5,-8,-4,-3,0,-6,-3,6,-8,9,-4,-8},{3,6,-1,8,2,5,-5,1,-6,-8,-10,2,-8,3,-8,7,-3,9,-7,0,1,-6,-4,9,-2,9,-6,8,-1,8,-6,-3,-7,-3,-1,-4,-10,-4,2,8,-8,2,-2,-2,4,8,6,-5,4,4},{-10,2,6,3,8,-3,-10,8,8,3,-10,-8,-7,6,7,-6,7,6,-9,-3,2,-2,1,-4,8,-7,8,-3,-6,7,8,5,-2,6,1,-10,9,7,-2,-10,-1,5,9,4,7,-4,3,-3,-6,2},{2,0,-10,-10,5,5,-1,1,-8,2,0,5,9,3,-10,-4,-6,-8,-6,5,4,-8,8,-8,3,-7,-8,4,3,5,4,0,-5,-6,6,2,7,-2,7,-4,7,-8,0,-8,2,-9,-7,-5,-3,-8},{7,1,1,-10,-2,-9,-2,-10,2,-4,8,7,9,-8,-3,-9,-6,5,1,2,9,-4,3,-9,3,-8,9,-3,7,1,-7,-5,9,5,-4,-9,1,1,8,4,-9,2,2,-10,-6,2,2,-10,-1,-4},{-3,-2,4,-4,6,2,-8,-3,8,-4,-4,1,-8,9,3,-9,3,8,-6,-4,2,2,3,4,-8,3,-2,-2,-4,8,8,1,-4,9,-4,8,9,5,4,8,8,0,-3,0,8,-3,1,9,5,4},{0,-5,-4,9,-8,4,-4,1,6,8,-8,0,-6,1,2,4,-10,0,4,6,5,-1,1,2,-3,-8,-6,0,-8,-2,-3,-4,-1,-6,5,-3,-8,5,0,-3,-3,0,2,-9,0,8,-6,-5,0,8},{-6,3,-2,-5,-6,-2,9,-6,9,-3,-5,-3,4,-1,3,9,-9,-7,-10,-5,-7,6,-1,-2,-7,5,2,3,-10,-3,5,4,0,4,-8,-7,9,3,-5,-2,-1,1,-6,4,2,-10,9,-4,8,9},{7,-10,3,-7,-4,3,3,1,0,8,0,3,-6,-4,7,-10,9,7,8,-6,-7,5,-10,7,5,2,-2,4,4,7,5,3,-6,-2,-3,-10,5,9,-2,7,7,0,9,4,5,8,-3,8,4,-6},{-8,2,-5,9,-8,-4,9,7,-2,-6,9,-9,2,0,7,-9,9,4,5,-6,3,9,6,8,9,-7,-3,0,-6,7,-7,7,1,-8,-9,0,7,7,-7,7,8,-4,-6,-2,7,-1,-2,9,9,0},{-4,-8,-10,8,9,-1,-4,-3,2,-8,-8,-1,-3,-3,-6,0,-1,-4,7,9,-6,-9,-7,9,1,-7,7,-6,4,8,6,5,-5,5,3,3,-7,-8,-7,-3,-3,1,6,-9,7,-9,1,9,7,-5},{-2,2,-2,9,-7,6,6,4,4,-3,-8,-8,-8,0,-3,3,6,-8,-8,1,-2,0,9,-7,7,8,-9,-9,-4,8,-7,-4,-2,-7,8,6,-8,-6,0,4,-4,-3,-5,-3,3,8,2,8,-2,-9},{5,9,1,-5,6,6,4,9,-7,8,8,0,-5,6,9,7,-7,-6,-6,6,-1,3,-8,-6,7,-8,-6,-2,6,3,-4,9,9,8,-9,-2,9,-2,9,-9,-10,-2,5,9,8,-9,-3,-9,3,-10},{-10,-3,-1,-9,-4,7,-1,7,-10,-2,-10,4,4,-3,-2,-3,-8,4,5,7,9,-6,1,5,-5,-3,-7,-6,-9,2,1,8,1,8,-8,-1,-5,1,8,3,-1,-1,-2,-1,6,-3,3,-6,-9,6},{2,-1,-10,5,-1,-3,-3,6,1,-1,-10,-1,-9,2,7,3,3,-10,3,3,8,-7,5,6,-4,4,-3,-10,-3,-2,6,-1,5,0,-2,-4,-5,-6,9,8,-4,-6,8,7,-2,-2,-4,9,4,-2},{-2,-6,6,-8,8,2,-6,-9,3,-10,-5,-10,-1,-4,5,1,-2,-4,9,-8,1,0,-1,-5,-9,-10,-3,2,7,-2,5,-10,5,9,-2,3,0,-4,-9,8,6,1,5,4,-9,-3,-6,6,-10,1},{1,7,2,-6,8,-6,-8,-5,8,-8,2,8,0,6,-8,-3,8,8,-8,-5,-5,-5,-5,-1,-1,1,-10,5,-3,-9,6,-2,-8,-9,-8,5,1,-9,-9,-6,-5,-2,-5,-4,0,-10,-6,-6,1,-6},{9,4,3,0,6,-1,-2,9,7,4,4,-4,-2,-8,1,8,2,-6,-10,-10,8,-4,-9,-5,3,1,6,-2,1,3,-7,1,-9,2,6,-9,3,1,5,-3,8,-9,-6,5,9,-2,-3,-5,2,-8},{6,-4,7,1,8,-1,2,5,5,-2,-1,0,-6,-8,-6,-9,5,9,5,2,-8,-9,7,-2,-8,-6,4,1,6,2,2,8,1,-9,7,5,-8,2,8,-4,1,-2,9,-10,6,-7,-2,4,6,0},{5,2,8,4,-7,4,-4,3,3,1,-2,-5,-5,-7,3,9,1,-10,1,-4,4,7,6,-10,-5,1,8,-5,-10,-1,-9,-6,-4,-8,-8,5,-6,6,-7,-4,-10,1,9,8,9,4,-7,4,-7,7},{-2,1,0,-10,5,-6,1,9,-3,-10,4,4,0,-3,-9,1,-4,1,-6,7,7,-2,-7,-7,5,-5,-9,0,-10,-10,3,-2,-5,-7,2,0,5,7,-10,1,-9,3,2,6,7,-9,1,0,9,3},{4,0,3,-5,-1,7,4,7,7,-5,-2,-3,7,8,-7,0,-5,-6,2,-1,8,5,8,4,0,-2,-2,2,1,-6,-2,-7,2,-7,0,8,9,0,9,-1,-5,6,2,-9,-4,8,7,-6,-10,7},{1,4,-3,-6,4,6,4,4,9,8,2,2,-5,6,2,5,6,6,-5,-9,9,-7,-8,7,-4,7,-5,-2,6,-8,1,4,5,-8,-6,4,-10,-7,-3,-1,-6,-4,1,1,1,2,9,-4,-2,-1},{1,-2,3,-4,6,2,3,0,-3,-8,8,-4,-10,4,2,1,-5,-10,6,-2,6,3,-5,6,-2,-5,6,-7,-9,8,-1,-7,7,5,-1,8,-3,-6,8,0,7,7,-1,-4,-10,-4,1,5,3,0}}; int k=300;
    
    
    cout <<  s.maxSumSubmatrix(v,k)  << endl;

    return 0;
}
