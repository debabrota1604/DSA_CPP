#include<iostream>
using namespace std;

/*
You are given a binary string s that contains at least one '1'.

You have to rearrange the bits in such a way that the resulting binary number is the maximum odd binary number that can be created from this combination.

Return a string representing the maximum odd binary number that can be created from the given combination.

Note that the resulting string can have leading zeros.

 

Example 1:

Input: s = "010"
Output: "001"
Explanation: Because there is just one '1', it must be in the last position. So the answer is "001".
Example 2:

Input: s = "0101"
Output: "1001"
Explanation: One of the '1's must be in the last position. The maximum number that can be made with the remaining digits is "100".
*/

//Code was accepted

class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int zero,one;
        zero=one=0;

        // Count zero and one bits
        for(auto ch:s){
            if(ch=='0') zero++;
            if(ch=='1') one++;
        }
        
        string res="";

        // Add n-1 set bits to the MSB
        while(one>1){
            res += '1';
            one--;
        }

        // Add all zero bits in the middle
        while(zero>0){
            res += '0';
            zero--;
        }

        // Add the last set bit to the LSB
        res +='1';
        return res;
        
    }
};
