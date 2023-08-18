#include<bits/stdc++.h>
using namespace std;

// Problem: You are given an n x n 2D matrix representing an image, rotate the image by 90 degrees (clockwise).
// You have to rotate the image in-place, which means you have to modify the input 2D matrix directly. DO NOT allocate another 2D matrix and do the rotation.

// Algorithm:
// 1. Rotate one element from each side to 90 degree. The element in arr[r][c] position will go to arr[c][n-r]. 
//     DO this four times for all sides. This will make 00 -> 03, 03 -> 33, 33 -> 30, 30->03 for a 3x3 matrix.
// 2. Then move to next element in the row. that is start with 01 now. the movement will be is outer for loop for n-1 items.
//     The step for second element will make 01->13, 13->32, 32->20, 20->01.
// 3. After repeating 2nd step for (n-1) times, increment step 1's start to 11 and try repeating Step 1 and Step 2.

class Solution {
public:
    void displayMatrix(vector<vector<int>>& matrix){
        for(int i=0;i<matrix.size();i++){
            for (int j=0;j<matrix[0].size();j++){
                cout << matrix[i][j] << "\t";
            }
            cout << endl;
        }

    }
    void rotate(vector<vector<int>>& matrix) {
        int maxSize=matrix.size()-1, maxDepth = matrix.size()/2; //for 3x3, size will be 1, so replacements will be done on single outer layer. for 4x4, two layers will be replaced.
        
        int tempVar, tempVar2,rowBeg=0,colBeg=0,row, col;
        for(int iter1=0; iter1<maxDepth; iter1++){  //Runs for depth. 3x3 = 1, 4x4 = 2
            cout << "Iter1: " << iter1 << endl; 
            row = rowBeg; col = colBeg;

            for(int iter2=0; iter2<matrix.size()-1; iter2++){ // Runs for start element, 00, 01, 02, .., 0(n-2)
                cout << "Iter2: " << iter2 << endl;

                for(int iter3=0; iter3<4; iter3++){ //Runs for swapping elements on each side: 00 -> 03, 03 -> 33, 33 -> 30, 30->03 for a 3x3 matrix
                    cout << "Iter3: " << iter3 << endl;

                    if(iter3 ==0){ //temp doesn't contain valid value
                        tempVar = matrix[col][maxSize-row-iter1];
                        matrix[col][maxSize-row-iter1] = matrix[row][col];
                        int temp = row; row = col; col = maxSize-temp-iter1;
                    }
                    else{
                        cout << "Exchanging [" << row << "," << col << "] to [" ;

                        tempVar2 = matrix[col][maxSize-row-iter1];
                        matrix[col][maxSize-row-iter1] = tempVar;
                        int temp = row; row = col; col = maxSize-temp-iter1; tempVar = tempVar2;

                        cout << row << "," << col << "]: " << tempVar << endl; 
                    }    
                    displayMatrix(matrix);  getchar();
 
                }
                col++;  
            }
            cout << "After iter1 end: " << row << "," <<col << endl;
            rowBeg++; colBeg++; // element exchange updated from 00 to 11.
        }
        
    }
};

int main(){

    vector<vector<int>> m3x3 {{1,2,3}, {4,5,6},{7,8,9}}, m4x4 { {1,2,3,4}, {5,6,7,8}, {9,10,11,12}, {13, 14, 15, 16}};
    Solution s;
    cout << "Initial Matrix:" << endl; s.displayMatrix(m4x4);
    s.rotate(m4x4);


    return 0;
}