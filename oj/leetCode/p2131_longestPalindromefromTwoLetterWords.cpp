#include<bits/stdc++.h>
using namespace std;

// You are given an array of strings words. Each element of words consists of two lowercase English letters.
// Create the longest possible palindrome by selecting some elements from words and concatenating them in any order. Each element can be selected at most once.
// Return the length of the longest palindrome that you can create. If it is impossible to create any palindrome, return 0.
// A palindrome is a string that reads the same forward and backward.


class Solution {
public:
    bool isPalin(string word){ if(word[0]==word[1]) return true; else return false;}

    int longestPalindrome(vector<string>& words){
        //get distinct occurences and its count
        //if word is of type xy, check for yx and its count. Take min of both occurences
            //take largest even number in min and add to result as 4*evenMin.
        //if word is of type xx with occurence 2n+1, add 4n to res. 
        //if minflag is false take one odd palin of xx type and add 2 to res.

        //get distinct words and its count
        map<string,int> wordCount;
        for(auto iter:words) wordCount[iter]++;

        //revisit the wordCount and determine length
        int resLen=0; bool midPalin=false;
        for(auto iter = wordCount.begin(); iter!=wordCount.end(); iter++){
            cout << "Processing " << iter->first << " count: " << iter->second <<" len: " << resLen << endl;
            if(iter->second ==0) continue;
            string word = iter->first, wordRev= word;
            reverse(wordRev.begin(), wordRev.end());

            if(isPalin(iter->first)){//Palindromic word
                if(1 & (iter->second) && !midPalin){//odd and midPalin is false
                    resLen += 2* (iter->second);
                    midPalin = true;
                    cout << "Result +=" << 2* (iter->second) << endl;
                }
                else {resLen += 2* (iter->second -1); cout << "Result +=" << 2* (iter->second) <<" Result: " << resLen << endl;}
            }
            else{
                if(wordCount.find(wordRev) != wordCount.end()){
                    //add 4 times min of two occurences to sum.
                    cout << "Match: " << iter->first << ":" << iter->second << " with " << wordRev << ":" <<  wordCount[wordRev] <<" : ";
                    resLen+= (4* min(iter->second, wordCount[wordRev]));
                    cout << "Result increased by: " << (4* min(iter->second, wordCount[wordRev])) << endl;
                    wordCount[wordRev]=0; wordCount[word] = 0;
                }
            }
        }
        cout << resLen << endl;
        return resLen;
    }
};


int  main(){
    vector<string> words; Solution s;

    words = {"lc", "cl", "gg"}; cout << s.longestPalindrome(words) << endl;
    words = {"ab","ty","yt","lc","cl","ab"}; cout << s.longestPalindrome(words) << endl;
    words = {"cc","ll","xx"}; cout << s.longestPalindrome(words) << endl;
    words = {"ll","lb","bb","bx","xx","lx","xx","lx","ll","xb","bx","lb","bb","lb","bl","bb","bx","xl","lb","xx"}; cout << s.longestPalindrome(words) << endl;




    return 0;
}