#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minNumberOfHours(int initialEnergy, int initialExperience, vector<int>& energy, vector<int>& experience) {
        int gEner = initialEnergy,gExp = initialExperience,tHr=0;
        for (int i=0; i<energy.size();i++){
            int lEner=0, lExp=0;
            if (! (gEner > energy[i])) {  lEner = energy[i] - gEner +1;  }
            if (! (gExp > experience[i])){ lExp = experience[i] - gExp +1; }

            tHr += lEner + lExp;
            cout << "i " << i << " : "<< lEner << " : " << lExp << endl;
            gEner = gEner + lEner - energy[i];
            gExp += experience[i];

        }
        return tHr;
    }
};


int main(){
    Solution s;
    // vector<int> engy {1, 1, 1, 1}, exp {1, 1, 1, 50};
    // cout << s.minNumberOfHours(2, 4, engy, exp) << endl;


    // vector<int> engy {1,4,3,2}, exp {2,6,3,1};
    // cout << s.minNumberOfHours(5,3, engy, exp) << endl;


    vector<int> engy {69,22,93,68,57,76,54,72,8,78,88,15,58,61,25,70,58,91,79,22,91,74,90,75,31,53,31,7,51,96,76,17,64,89,83,54,28,33,32,45,20},
     exp {51,81,46,80,56,7,46,74,64,20,84,66,13,91,49,30,75,43,74,88,82,51,72,4,80,30,10,19,40,27,21,71,24,94,79,13,40,28,63,85,70};

    cout << s.minNumberOfHours(11, 23, engy, exp) << endl;


    return 0;
}