#include<iostream>
#include<vector>
using namespace std;

//Given a string containing digits from 2 to 9 inclusive, return all possible letter combinations that the number could represent.

vector<string> numberMap {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

class Solution{
    public:
    void displayResult(vector<string> vs){
        cout << "[";
        for(string s: vs){
            cout << "\"" << s << "\" ";
        }
        cout << "]\n";
    }
    vector<string> recursiveGenerator(string& digits, int index, vector<string> tempRes){
        string tempStr, keymap;
        vector<string> newRes;
        int key = digits[index]- '0';
        keymap = numberMap[key -2];

        //Base case
        if(index == digits.size()) return tempRes;
        
        // Add characters per key for each digit
        if(index ==0){ // First key
            for(int iter=0; iter<keymap.size(); iter++){
                tempStr = string (1, keymap[iter]);
                newRes.emplace_back(tempStr);
            }
        }
        else{ //Some key already pressed
            for(int iter=0; iter<tempRes.size(); iter++){
                // Take old string and append all characters for current digit
                for(char ch: keymap){
                    tempStr = tempRes[iter] + ch;
                    newRes.emplace_back(tempStr);
                }
            }
        }

        return recursiveGenerator(digits, index+1, newRes);
    }

    vector<string> letterCombinations(string& digits){
        vector<string> res;
        return recursiveGenerator(digits, 0, res);
    }
};


int main(){
    Solution s;
    string digits = "23";
    vector<string> res = s.letterCombinations(digits);
    s.displayResult(res);

    return 0;
}

