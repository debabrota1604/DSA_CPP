#include<bits/stdc++.h>
using namespace std;

// Alice and Bob are traveling to Rome for separate business meetings.
// You are given 4 strings arriveAlice, leaveAlice, arriveBob, and leaveBob. Alice will be in the city 
// from the dates arriveAlice to leaveAlice (inclusive), while Bob will be in the city from the dates 
// arriveBob to leaveBob (inclusive). Each will be a 5-character string in the format "MM-DD", 
// corresponding to the month and day of the date.
// Return the total number of days that Alice and Bob are in Rome together.
// You can assume that all dates occur in the same calendar year, which is not a leap year. Note that 
// the number of days per month can be represented as: [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31].

// Input: arriveAlice = "08-15", leaveAlice = "08-18", arriveBob = "08-16", leaveBob = "08-19", Output: 3
// Explanation: Alice will be in Rome from August 15 to August 18. Bob will be in Rome from August 16 
// to August 19. They are both in Rome together on August 16th, 17th, and 18th, so the answer is 3.

// Input: arriveAlice = "10-01", leaveAlice = "10-31", arriveBob = "11-01", leaveBob = "12-31", Output: 0
// Explanation: There is no day when Alice and Bob are in Rome together, so we return 0.

class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        vector<int> days {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; 
        int sMon, eMon, sDay, eDay;
        int mArrAl = stoi(arriveAlice.substr(0,2)), mArrBb = stoi(arriveBob.substr(0,2)),
        mDepAl = stoi(leaveAlice.substr(0,2)), mDepBb = stoi(leaveBob.substr(0,2)),
        dArrAl = stoi(arriveAlice.substr(3)), dArrBb = stoi(arriveBob.substr(3)),
        dDepAl = stoi(leaveAlice.substr(3)), dDepBb = stoi(leaveBob.substr(3));

        cout << mArrAl << " " << mArrBb << " " << mDepAl << " " << mDepBb << 
        " " << dArrAl << " " << dArrBb << " " << dDepAl << " " << dDepBb << endl;

        //arrive last
        if(mArrAl < mArrBb){ //bob arrives last
            sMon = mArrBb; sDay = dArrBb;
        }
        else if (mArrAl > mArrBb) { //alice comes last
            sMon = mArrAl; sDay = dArrAl;
        }
        else{ // both come in same month
            if (dArrAl < dArrBb){ //bob last
                sMon = mArrBb; sDay = dArrBb;
            }
            else if (dArrAl > dArrBb){ // alice last
                sMon = mArrAl; sDay = dArrAl;
            }
            else{// both came same day!                
                sMon = mArrAl; sDay = dArrAl;
            }
        }

        //depart first
        if(mDepAl < mDepBb){ //bob departs last
            eMon = mDepAl; eDay = dDepAl;
        }
        else if (mDepAl > mDepBb) { //alice departs last
            eMon = mDepBb; eDay = dDepBb;
        }
        else{ // both come in same month
            if (dDepAl < dDepBb){ //bob last
                eMon = mDepAl; eDay = dDepAl;
            }
            else if (dDepAl > dDepBb){ // alice last
                eMon = mDepBb; eDay = dDepBb;
            }
            else{// both came same day!                
                eMon = mDepAl; eDay = dDepAl;
            }
        }
        cout << sMon << " " <<  sDay << " " << eMon << " " << eDay << endl;

        int numDays=0;
        if(sMon < eMon){
            for(int i=sMon; i<=eMon; i++){
                if(i==sMon){
                    numDays += days[i-1]-sDay+1;
                }
                else if(i==eMon){
                    numDays += eDay;
                }
                else{
                    numDays += days[i-1];
                }
            }           
        }
        else if(sMon == eMon){
            if (sDay <= eDay){
                numDays = eDay -sDay +1;                
            }           
        }
        else return 0;

        return numDays;
    }
};


int main(){
    Solution s;
    cout << s.countDaysTogether("08-15", "08-18", "08-16", "08-19") << endl;
    cout << s.countDaysTogether("10-01", "10-31", "11-01", "12-31") << endl;
    cout << s.countDaysTogether("09-01", "10-19", "06-19", "10-20") << endl;
    cout << s.countDaysTogether("08-15", "08-18", "08-16", "08-16") << endl;



    return 0;
}