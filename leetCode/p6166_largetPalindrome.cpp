#include<bits/stdc++.h>
using namespace std;

/*
Return the largest palindromic integer (in the form of a string) that can be formed 
using digits taken from num. It should not contain leading zeroes.
Notes:
You do not need to use all the digits of num, but you must use at least one digit.
The digits can be reordered.

Algorithm:
    1. Frequency Count 0 to 9.
    2. construct a half palin in decreasing order of magnitude. Will add the reversed half 
        to get the full palindrome.
    3. Take the palin middle to the highest number odd available.

Code:
    string halfPalin = "", middle = "";
    freqCount = p0,...,p9
    find the largest odd pk and select the middle. pk--;
    for(p9:p0): find the max even count and add half of them to halfPalin.
    if halfPalin[0] = '0', then finalPalin = middle
    else finalPalin = halfPalin + middle + halfPalin.reverse()
*/


class Solution {
public:
    string largestPalindromic(string num) {
        string halfPalin="", mid = "";
        vector<int> freq (10,0);

        //frequency counter
        for(auto i:num){
            freq[i-'0']++;
        }

        //largest odd as mid
        for (int i=freq.size()-1; i>=0; i--){
            if (freq[i]%2==1){
                mid = i + '0'; freq[i]--; break;
            }
        }

        //construct the half-palindrome
        for( int i=freq.size()-1;i>=0; i--){
            while(freq[i]>1){
                halfPalin += i +'0';
                freq[i] -=2;
            }    
        }
        if (halfPalin[0] =='0') return mid;
        else if (halfPalin[0] =='0' && mid == "0") return "";
        else return halfPalin + mid + string(halfPalin.rbegin(), halfPalin.rend());
    }
};

int main(){
    Solution s;
    cout << s.largestPalindromic("00009") << endl;



    return 0;
}