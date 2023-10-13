#include<iostream>
#include<vector>
using namespace std;

/*
This program generates all permutations of a given string.
*/

void solve(string& sample, string& tempStr, int index, vector<string>& res){
    //Base case
    if(index == sample.size()){
        res.emplace_back(tempStr);
        return;
    }

    // Recursion Step
    for(int iter=0; iter<sample.size(); iter++){

        // Skip interation if character already present
        if(tempStr.find(sample[iter]) >=0) continue;
        
        // Add the new char and call recursively.
        tempStr += sample[iter];
        solve(sample, tempStr, index+1, res);
        tempStr.pop_back();
    }
}

int main(){
    string sample = "abc", tempStr="";
    vector<string> res;
    solve(sample, tempStr, 0, res);

    for(auto s:res){
        cout << s << " ";
    }
    cout << endl;

    return 0;
}