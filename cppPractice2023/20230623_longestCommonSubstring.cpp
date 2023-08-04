#include<bits/stdc++.h>
using namespace std;

class Solve{
    string s1, s2;
    unordered_map<int, unordered_map<int, int>> memory;
    public:
    Solve(string s1, string s2):s1(s1), s2(s2){}

    int findLongestCommonSubstring(int index1, int index2, int currLen){
        // Base case: When one string is empty, the common subsequence would be zero.
        if(index1<0 || index2<0) return currLen;

        // Recursion1: When both strings are equal by their last index, increase current length by 1 and call subproblem
        if(s1[index1] == s2[index2]){
            return findLongestCommonSubstring(index1-1, index2-1 , currLen+1);
        }
        else{
            // Recursion2: When last character is not equal, return max of two recursive calls.
            return max(currLen,
            max(findLongestCommonSubstring(index1-1, index2,0), findLongestCommonSubstring(index1, index2-1,0)));
        }
    }

    int findLongestCommonSubstringMemoization(int index1, int index2, int currLen){
        //Base Case
        if(index1<0 || index2<0) return currLen;
        // Return from stored result.
        if(memory.find(index1) != memory.end() && memory[index1].find(index2) != memory[index1].end()) return memory[index1][index2];

        // When both last indices are equal, reduce both indices and increase common substring count by 1
        if(s1[index1] == s2[index2]){
            memory[index1][index2] = findLongestCommonSubstring(index1-1, index2-1 , currLen+1);
        }
        else{
            // Otherwise restart common substring count from 0 to denote new substring start
            memory[index1][index2] = max(currLen,
            max(findLongestCommonSubstring(index1-1, index2,0), findLongestCommonSubstring(index1, index2-1,0)));
        }
        // Return from saved result.
        return memory[index1][index2];
    }

    int findLCS_Iterative(){
        //initialize memory
        int l1 = s1.size(), l2 = s2.size(), memory[l1+1][l2+1];
        for(int iter=0; iter<=l1; iter++){
            for(int iter2=0; iter2<=l2; iter2++){
                memory[iter][iter2] = 0;
            }
        }
        
        // Compute LCS
        int maxRes=0;
        for(int iter=1; iter<=l1; iter++){
            for(int iter2=1; iter2<=l2; iter2++){
                int res = 0;
                if(s1[iter -1] == s2[iter2 -1]) res = memory[iter -1][iter2-1] +1;
                else res = 0;
                memory[iter][iter2] = res;
                if(maxRes <res) maxRes = res;
            }
        }
        return maxRes;
    }

    int findLCS_IterativeOptimized(){
        //initialize memory: Only two 1D array is required
        int l1 = s1.size(), l2 = s2.size(), memory[2][l2+1];
        memory[0][0] = 0;
        memory[1][0] = 0;
        
        // Compute LCS
        int maxRes=0;
        for(int iter=1; iter<=l1; iter++){
            for(int iter2=1; iter2<=l2; iter2++){
                int res = 0;
                if(s1[iter -1] == s2[iter2 -1]) res = memory[(iter -1)%2][iter2-1] +1;
                else res = 0;

                // store and update result
                memory[iter%2][iter2] = res;
                if(maxRes <res) maxRes = res;
            }
        }
        return maxRes;
    }

    int lcs(){
        //return findLongestCommonSubstring(s1.size()-1, s2.size()-1, 0);
        //return findLongestCommonSubstringMemoization(s1.size()-1, s2.size()-1, 0);
        //return findLCS_Iterative();
        return findLCS_IterativeOptimized();
    }

};

int main(){
    //Solve s("sDeb", "Desb");
    Solve s("sDebabrota", "Debashri");
    cout << s.lcs() << endl;

    return 0;
}