#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool equalFrequency(string word) {
        cout << "Word: " << word << endl;
        map<int,int> mp;
        for(char ch:word){
            mp[ch-'a']++; cout << "Update: " << ch-'a' << " " << mp[ch-'a'] << endl;
        }
        bool res=0; vector<int> v;
        for(auto i:mp){ v.emplace_back(i.first);}

        for(int i=1;i<mp.size(); i++){
            cout << "\t\t" << abs(mp[v[i]] - mp[v[i-1]]) << endl;
            if(abs(mp[v[i]] - mp[v[i-1]]) ==1){
                if(~res) res=1;
                else return 0;
            }
            else if(abs(mp[v[i]] - mp[v[i-1]]) >1) return 0;
        }
        if(!res && v[0]==1) return 1;
        return 0;
    }
};

int main(){
    Solution s;
    cout << s.equalFrequency("abcc") << endl;
    cout << s.equalFrequency("aacc") << endl;
    cout << s.equalFrequency("aazz") << endl;

    cout << s.equalFrequency("bca") << endl;

    cout << s.equalFrequency("aca") << endl;
    cout << s.equalFrequency("cac") << endl;
    cout << s.equalFrequency("cbc") << endl;
    

}