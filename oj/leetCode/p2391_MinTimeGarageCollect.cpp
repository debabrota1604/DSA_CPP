#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {

        //initialize counters for each truck type
        int gt=0,pt=0,mt=0,lg=0,lp=0,lm=0;

        //get last house of each garbage type
        for(int iter=0;iter<garbage.size();iter++){
            auto tempGarbage = garbage[iter]; //garbage type at house iter

            //update the last occurence pointers
            if(tempGarbage.find('G') !=string::npos) lg = iter;
            if(tempGarbage.find('P') !=string::npos) lp = iter;
            if(tempGarbage.find('M') !=string::npos) lm = iter;
        }

        travel.emplace_back(0); //garbage and travel are now equal in size

        //calculate total time to collect for each type pf garbage
        for(int iter=0;iter<garbage.size(); iter++){
            auto tempGarbage = garbage[iter]; //garbage type at house iter
            unordered_map<char, int> gmap;     //garbage counter

            //count each type of garbage
            for(auto ch: tempGarbage) gmap[ch]++;

            //Glass Truck
            if(gmap.find('G') !=gmap.end() && iter<lg){  gt += gmap['G'] + travel[iter]; }
            else if(gmap.find('G') !=gmap.end() && iter==lg){  gt += gmap['G']; } // last house does not contribute to next travel
            else if(gmap.find('G') ==gmap.end() && iter<lg){  gt += travel[iter]; } // travel time counted for future houses

            //Paper Truck
            if(gmap.find('P') !=gmap.end() && iter<lp){  pt += gmap['P'] + travel[iter]; }
            else if(gmap.find('P') !=gmap.end() && iter==lp){  pt += gmap['P']; }
            else if(gmap.find('P') ==gmap.end() && iter<lp){  pt += travel[iter]; }

            //Metal Truck
            if(gmap.find('M') !=gmap.end() && iter<lm){  mt += gmap['M'] + travel[iter]; }
            else if(gmap.find('M') !=gmap.end() && iter==lm){  mt += gmap['M']; }
            else if(gmap.find('M') ==gmap.end() && iter<lm){  mt += travel[iter]; }
        }
        return gt +pt +mt;

    }
};


int main(){
    Solution s;

    vector<string> garbage {"G","P","GP","GG"}; vector<int> travel {2,4,3};
    cout << s.garbageCollection(garbage, travel) << endl;

    // vector<string> garbage {"MMM","PGM","GP"}; vector<int> travel {3, 10};
    // cout << s.garbageCollection(garbage, travel) << endl;



    return 0;
}