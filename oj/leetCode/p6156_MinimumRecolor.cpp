#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int Wcount=0, minW=0,srtWin, endWin;
        for (int i=0; i<k; i++){
            if (blocks[i]=='W') minW++;
        }
        Wcount = minW;
        for (int i=k; i<blocks.size(); i++){
            endWin = i; srtWin = i-k;
            if (blocks[endWin] == 'W' && blocks[srtWin]=='B'){
                Wcount++;
            }
            else if (blocks[endWin] == 'B' && blocks[srtWin]=='W'){
                Wcount--;
            }
            if (Wcount < minW){
                minW = Wcount;
                cout << minW << " Index: " << srtWin << " " << endWin << ": " << blocks.substr(srtWin,k) << endl;
            }                
        }
        return minW<0 ? 0:minW;
    }
};

int main(){
    Solution s;
    cout << s.minimumRecolors("WBBWWWWBBWWBBBBWWBBWWBBBWWBBBWWWBWBWW", 15) << endl;



    return 0;
}