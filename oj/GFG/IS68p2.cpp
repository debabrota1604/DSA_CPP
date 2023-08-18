#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int finLength(int N, vector<int> color, vector<int> radius) {
        stack<int> cl,rd;
        for(int i=0; i<color.size(); i++){
            if(i==0 || cl.empty() || rd.empty()){
                cout << "Push "<< i << endl;
                cl.push(color[i]); rd.push(radius[i]);
            }
            else{
                if(color[i] ==cl.top() && radius[i] ==rd.top()){
                    cout << "Pop " << i << endl;
                    cl.pop(); rd.pop();
                }
                else{
                    cout << "Push "<< i << endl;
                    cl.push(color[i]); rd.push(radius[i]);
                }
            }
        }
        return cl.size();
    }
};


int main(){
    Solution s;

    vector<int> c2 {1,3,3,1}, r2 {2,5,5,2};
    cout << s.finLength(c2.size(), c2,r2) << endl;
    
    vector<int> c3 {1,3,3,1,2}, r3 {2,5,5,2,3};
    cout << s.finLength(c3.size(), c3,r3) << endl;

    vector<int> c {2,2,5}, r{3,3,4};
    cout << s.finLength(c.size(), c,r) << endl;

    


    return 0;
}