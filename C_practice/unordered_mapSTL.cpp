#include<iostream>
#include<unordered_map>
using namespace std;

int main(){
    unordered_map<int, int> um;


    //Insert
    um[3] = 234;
    um[5] = 123;
    um.insert(make_pair(4,2345));


    //Display
    cout << "The hash is:" << endl;
    for(auto i=um.begin();i!=um.end();++i){
        cout << "\t" << i->first << " : " << i->second << endl;
    }


    //Check for key
    cout << "Checking if key 9 is present: " << um.count(9) << endl;
    cout << "Checking if key 5 is present: " << um.count(5) << endl;

    //find the key
    cout << "Find the key 5: " << (um.find(5))->second << endl;
    cout << "Find the key 9: " << (um.find(9))->second << endl;
    


    /*
class Solution {
public:
vector twoSum(vector& nums, int target) {
unordered_map<int, int> numToIndex;

for (int i = 0; i < nums.size(); ++i) {
  if (numToIndex.count(target - nums[i]))
    return {numToIndex[target - nums[i]], i};
  numToIndex[nums[i]] = i;
}

throw;
}
};

    */









    return 0;
}