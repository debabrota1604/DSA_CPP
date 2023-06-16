#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    vector<vector<string>> mostPopularCreator(vector<string>& creators, vector<string>& ids, vector<int>& views) {
        vector<vector<string>> maxID; map<string, pair<string, int>> maxViewID; map<string, int> totalViews; int maxView=0;

        //populate DS
        for(auto it=0; it<ids.size(); it++){
            string name = creators[it];
            if(maxViewID.find(name) ==maxViewID.end()){
                maxViewID[name] = make_pair(ids[it], views[it]); 
                totalViews[name] += views[it];
            } 
            else{
                totalViews[name] +=views[it];
                auto pr = maxViewID[name];
                if(views[it] > pr.second){
                    maxViewID[name] = make_pair(ids[it], views[it]); 
                }
                else if(views[it] == pr.second && ids[it]<pr.first){
                    maxViewID[name] = make_pair(ids[it], views[it]);
                }
            }
            for(auto it1=maxViewID.begin(); it1!=maxViewID.end(); it1++){
                cout << it1->first << " " << (it1->second).first << " " << (it1->second).second << endl;
            }
            cout << endl;
        }
        //get maxView
        for(int it=0; it<totalViews.size(); it++){
            if(totalViews[creators[it]] >maxView) maxView = totalViews[creators[it]];
        }

        //get creator with maxView
        for(auto it=maxViewID.begin(); it!=maxViewID.end(); it++){
            string name = it->first; vector<string> tempRes; 
            if(totalViews[name] ==maxView){
                tempRes.emplace_back(name);
                tempRes.emplace_back((maxViewID[name]).first);
            }
            if(tempRes.size()>0) maxID.emplace_back(tempRes);
        }
        return maxID;
    }
};





int main(){





    return 0;
}