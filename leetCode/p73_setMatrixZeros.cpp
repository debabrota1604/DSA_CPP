#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void disp2Dmat(vector<vector<int>>& matrix){
        for(int r=0; r<matrix.size(); r++){
            for (int c=0; c< matrix[0].size(); c++){
                cout << matrix[r][c] << " ";
            }
            cout << endl;
        }
    }
    
    void setZeroes_OMplusN(vector<vector<int>>& matrix) {
        //Use two flag array of row & col size.
        vector<bool> row (matrix.size(), false), col(matrix[0].size(), false);

        //Traverse the array and update the flag array
        for(int i=0; i<matrix.size(); i++){
            for(int j=0; j<matrix[0].size(); j++){
                if(matrix[i][j] ==0){ row[i] = true; col[j]=true;}
            }
        }
        
        //Check the row flag array and update all the rows 
        for(int i=0; i<matrix.size(); i++){
            if(row[i]){
                for(int j=0; j<matrix[0].size(); j++){
                    matrix[i][j] = 0;
                }
            }
        }
        //Check the col flag array and update all the columns 
        for(int i=0; i<matrix[0].size(); i++){
            if(col[i]){
                for(int j=0; j<matrix.size(); j++){
                    matrix[j][i] = 0;
                }
            }
        }
    }

    void setZeros_O1(vector<vector<int>>& matrix){
        //Use the first row and column as flag array and use two variables as flag for first row and col;
        bool r1=false, c1=false;
        for(int r=0; r< matrix.size(); r++){
            for (int c=0; c< matrix[0].size(); c++){
                if (matrix[r][c]==0){
                    matrix[0][c] = 0; matrix[r][0] = 0;

                    //update flags if first row & first col has zeros..
                    if (r==0) r1 =true;
                    if (c==0) c1 =true;
                }
            }
        }

        for(int r=1; r< matrix.size(); r++){
            for(int c=1; c< matrix[0].size(); c++){
                if(matrix[r][0] ==0 || matrix[0][c]==0) matrix[r][c] = 0;
            }
        }

        //update the first row based on flags.
        if(r1) for(int c=0; c<matrix[0].size(); c++) matrix[0][c] = 0;
        if(c1) for(int r=0; r<matrix.size(); r++) matrix[r][0] = 0;
    }
};

int main(){

    Solution s; bool f=false;
    vector<vector<int>> v1 ={{1,1,1}, {1,0,1}, {1,1,1}};
    vector<vector<int>> v2 ={{0,1,2,0}, {3,4,5,2}, {1,3,1,5}};

    cout << "First Matrix" << endl;
    s.disp2Dmat(v1);
    if(f){
        cout << "Solving using O(M+N) space: "<< endl;
        s.setZeroes_OMplusN(v1); s.disp2Dmat(v1);
    }
    else{
        cout << "Solving using O(1) space: "<< endl;
        s.setZeros_O1(v1); s.disp2Dmat(v1);
    }

   

    cout << "Second Matrix" << endl;
    s.disp2Dmat(v2);

    if(f){
        cout << "Solving using O(M+N) space: "<< endl;
        s.setZeroes_OMplusN(v2); s.disp2Dmat(v2);
    }
    else{
        cout << "Solving using O(1) space: "<< endl;
        s.setZeros_O1(v2); s.disp2Dmat(v2);
    }





    return 0;

}