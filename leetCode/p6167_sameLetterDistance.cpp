#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkDistances(string s, vector<int>& distance) {
        map<char, int> m;
        for(int iter=0; iter<26; iter++){
            m[iter+'a'] = -1;
        }

        //insert into map the indices
        for(int iter=0; iter<s.size(); iter++){
            
            //if map doesn't contain the char at index iter, push the index for that char.
            if(m[s[iter]] ==-1){
                m[s[iter]] = iter;
            }
            //If the char is already there, store the difference between two indices.
            else{
                m[s[iter]] = iter - m[s[iter]] -1;
            }
        }

        for ( int iter=0; iter< m.size(); iter++){
            cout << m[iter + 'a'] << " ";
        }
        cout << endl;

        for ( int iter=0; iter< m.size(); iter++){
            if(m[iter + 'a'] != distance[iter] && m[iter + 'a'] != -1) return false;
        }
        return true;
    }
};

int main(){
    Solution sol;

    // string s = "abaccb";
    // vector<int> distance {1,3,0,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    // cout << sol.checkDistances(s, distance) << endl;


    string s = "aa";
    vector<int> distance {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    cout << sol.checkDistances(s, distance) << endl;




    return 0;
}