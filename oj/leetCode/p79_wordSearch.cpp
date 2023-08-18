#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool dfs(vector<vector<char>> board, string word, int row, int col, int wordIndex){
        
        // base cases
        if(wordIndex == word.size()) return true;
        if(row <0 || row == board.size() || col <0 || col == board[0].size()) return false;
        if(board[row][col] != word[wordIndex]) return false;
        
        board[row][col] = '1'; //denote checked
        
        return dfs(board, word, row-1, col, wordIndex+1) + 
                dfs(board, word, row, col-1, wordIndex+1) +
                dfs(board, word, row+1, col, wordIndex+1) +
                dfs(board, word, row, col+1, wordIndex+1);
    }
    bool exist(vector<vector<char>>& board, string word) {
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j] == word[0]){
                    if(dfs(board, word, i, j, 0)) return true;
                }
            }
        }
        return false;
    }
};