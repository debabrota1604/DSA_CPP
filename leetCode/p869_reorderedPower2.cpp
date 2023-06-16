#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void printMap(map<char, int> m){
        for(auto it:m) cout << it.first << " : " << it.second << endl;
    }
    bool reorderedPowerOf2(int n) {
        string inputAsString = to_string(n);
        map<char,int> m;
        for(auto i:inputAsString) m[i]++;

        int power_of_2 = 1;
        string powerAsString = to_string(power_of_2);

        //increment local variable until both the string sizes are equal
        while(powerAsString.size() != inputAsString.size()){
            power_of_2 *=2;
            powerAsString = to_string(power_of_2);
        }
        cout << "Reached " << power_of_2 << endl;
        cout << "Initial elements:" << endl;  printMap(m);

        while(powerAsString.size() == inputAsString.size()){//Bcoz multiple 2-power can have same length

            //remove each char from input as per local variable.
            auto tempMap = m; bool fl=0;
            for(auto i:powerAsString) tempMap[i]--;
            cout << "After substracting " << power_of_2 << endl; printMap(tempMap);

            //check if all characters are removed or not.
            for(auto i: tempMap){
                if (i.second!=0){ //this version of 2-power doesn't match with input. try next power.
                    cout << "Skipping " << power_of_2 << endl;
                    fl=1; tempMap.empty(); //discard and start afresh
                    power_of_2 *=2;
                    powerAsString = to_string(power_of_2);
                    break;
                }
                else{ fl+=0;}
            }
            if(!fl){ //all chars are matched
                return true; //Reaches only when line 35 has i.second==0 for all pairs.
            }
        }
        return false; //after the loop the local variable contains more characters than the input str.
    }
};

// Problem: You are given an integer n. We reorder the digits in any order (including the 
// original order) such that the leading digit is not zero.
// Return true if and only if we can do this so that the resulting number is a power of two.

// Algorithm: (Use map and strig length to generate the power of 2 then compare)
// 1. count the input string length and also store the frequency of each numbers
// 2. increment a local variable as power of 2 until its length equals input length.
// 3. If string length is equal, check if frequency of all numbers is same or not.
// 4. If not, increase the local variable to next power of two until the input string limit is crossed.



int main(){
    Solution s;

    cout << s.reorderedPowerOf2(512)  << endl;

    return 0;
}

