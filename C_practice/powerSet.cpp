#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> powerSet;
vector<int> buffer;

 void generatePowerSet(int index, int maxSize){
    if (index==maxSize){
        //comptute set
        powerSet.push_back(buffer);
    }
    else{   //recursion calls

        //one call with element
        buffer.push_back(index);
        generatePowerSet(index+1,maxSize);

        //one call without element
        buffer.pop_back();
        generatePowerSet(index+1,maxSize);
    }
}

void displayPowerSet(vector<vector<int>> ps){
    for(auto vec:ps){
        cout << "[";
        for(auto num:vec){
            cout << num << ",";
        }
        cout << "], ";
    }
    cout << endl;
}


int main(){
    int numEl;
    cout << "Number pf elements for the set: "; cin >> numEl;

    generatePowerSet(0,numEl);

    displayPowerSet(powerSet);




    return 0;
}