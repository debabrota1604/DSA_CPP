#include<bits/stdc++.h>
using namespace std;


class Solution{
    public:
    int uniqueMorseRepresentations(vector<string>& words) {
        unordered_set<string> uniqueMorseCode;
        vector<string> morseCode {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        
        //for each empty string, construct the morse code string and add it to the set
        for (auto tempStr:words){
            //initialize an empty string
            string s;
            
            //find the corresponding morse code from the char to int conversion
            for (auto ch:tempStr){
                s.append(morseCode[ch-97]);
            }

            uniqueMorseCode.insert(s);
            cout << tempStr << " has morse code representation of " << s << endl;
        }


        return uniqueMorseCode.size();
    }
};

int main(){
    vector<string> words {"gin","zen","gig","msg"};

    Solution s;    cout << s.uniqueMorseRepresentations(words);

    cout << " are the unique Morse Code representations of the words. " << endl;





    return 0;

}