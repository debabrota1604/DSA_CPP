#include<bits/stdc++.h>
using namespace std;

//Problem: Find the lexicographically smallest substring of length K in a given string of length N.

// Algorithm:
// 1. For each character in the result string (i.e. for(i=0 to k-1)), 
// 1.1 Calculate the max and min index for the search.
//     For i=0, minimum index to search is 0, max is k-1.
//     for i=1, already one character is taken, 
//     so the next char to the choosen char is the new start index. End index is k-2.
// 1.2 scan the input from right to left maxIndex to minIndex to find the lexicographically min char
// 1.3 Append the character to the result string
// 1.4 Update the max and min bound.

string findMinString(string inp, int resLen){
    if(resLen > inp.size()) return ""; //corner case

    string res=""; int minBound=0, maxBound = inp.size()-resLen+1, minIndex;

    //choose a character at each iteration
    for(int it=0; it<resLen;it++){
        minIndex=minBound;
        for(int it2=minBound+1; it2<maxBound; it2++){
            if(inp[minIndex] > inp[it2])  minIndex = it2;
        }
        res += inp[minIndex];
        minBound = minIndex+1; maxBound++;
    }
    return res;
}



int main(){
    string s; int k;
    s="abcdefghi", k=5;
    cout << "Lexicographically smallest string of length " << k << " in " << s << " is: " << findMinString(s,k) << endl;

    s="qwertyuioasdfghjk", k=5;
    cout << "Lexicographically smallest string of length " << k << " in " << s << " is: " << findMinString(s,k) << endl;

    s="zxcvbnmqwertyui", k=5;
    cout << "Lexicographically smallest string of length " << k << " in " << s << " is: " << findMinString(s,k) << endl;

    s="code", k=2;
    cout << "Lexicographically smallest string of length " << k << " in " << s << " is: " << findMinString(s,k) << endl;

    s="fooland", k=3;
    cout << "Lexicographically smallest string of length " << k << " in " << s << " is: " << findMinString(s,k) << endl;

    s="nuzwuaen", k=6;
    cout << "Lexicographically smallest string of length " << k << " in " << s << " is: " << findMinString(s,k) << endl;


    return 0;
}