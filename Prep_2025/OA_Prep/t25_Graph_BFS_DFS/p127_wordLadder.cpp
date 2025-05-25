/*
https://leetcode.com/problems/word-ladder/description/

A transformation sequence from word beginWord to word endWord using a dictionary wordList is a sequence of words beginWord -> s1 -> s2 -> ... -> sk such that:

Every adjacent pair of words differs by a single letter.
Every si for 1 <= i <= k is in wordList. Note that beginWord does not need to be in wordList.
sk == endWord
Given two words, beginWord and endWord, and a dictionary wordList, return the number of words in the shortest transformation sequence from beginWord to endWord, or 0 if no such sequence exists.

 

Example 1:

Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log","cog"]
Output: 5
Explanation: One shortest transformation sequence is "hit" -> "hot" -> "dot" -> "dog" -> cog", which is 5 words long.
Example 2:

Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log"]
Output: 0
Explanation: The endWord "cog" is not in wordList, therefore there is no valid transformation sequence.
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    void addWord(string& word, unordered_set<string>& dict, queue<string>& visitq){
        for(int it=0; it<word.size(); it++){
            char bkp = word[it];
            for(int it2=0; it2<26; it2++){
                word[it] = 'a' + it2;
                
                if(dict.count(word)){
                    dict.erase(word);
                    visitq.push(word);
                }
            }
            word[it] = bkp; // Restore to same string to compare the next index
        }
    }
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        if(find(wordList.begin(), wordList.end(), endWord) == wordList.end()) return 0;

        int res=2;
        unordered_set<string> dict(wordList.begin(), wordList.end()); // handles unseen words
        queue<string> visitq; // contains words at current level

        addWord(beginWord, dict, visitq);

        while(!visitq.empty()){
            int qsize = visitq.size(); // Fix the len for inner loop (involves new inserts)
            for(int it=0; it<qsize; it++){ //Runs for a single level
                string tWord = visitq.front();
                visitq.pop();

                if(tWord == endWord) return res;

                addWord(tWord, dict, visitq);
            }
            res++; // increment level as all words in this level are processed.
        }
        return 0;
    }
};