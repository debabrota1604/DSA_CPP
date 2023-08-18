#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> getDiff(string word){
        vector<int> res;
        for(int i=1; i<word.size(); i++){
            res.emplace_back(word[i] - word[i-1]);
        }
        return res;
    }

    bool isEqual(vector<int> v1, vector<int> v2){
        if(v1.size() != v2.size()) return false;
        for(int i=0; i<v1.size(); i++){
            if(v1[i] != v2[i]) return false;
        }
        return true;
    }


    string oddString(vector<string>& words) {
        vector<int> t1,t2,temp; int f1=0, f2=0; string s1, s2;
        for(auto w:words){
            temp = getDiff(w);
            if(!f1 && !f2){t1=temp; f1++; s1=w;}
            
            // if(f1>1 && !isEqual(temp, t1)) return w;
            // if(f2>1 && !isEqual(temp, t2)) return w;

            if(!isEqual(t1, temp)){ t2 = temp; f2++; s2=w;}
            if(!isEqual(t2, temp)) f1++;
        }
        if(f1 >2) return s2;
        else return s1;
    }
};

int main(){
    Solution s;
    vector<string> words {"aaa","bob","ccc","ddd"}, w2 = {"ddd","poo","baa","onn"}, w3 = {"adc","wzy","abc"};
    cout << s.oddString(words) << endl;
    cout << s.oddString(w2) << endl;
    cout << s.oddString(w3) << endl;



    return 0;
}