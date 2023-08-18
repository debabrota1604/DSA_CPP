#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        for(int iter=0; iter<intervals.size(); iter++){
            cout << intervals[iter][0] << " " << intervals[iter][1] << endl;
        }

        priority_queue<int, vector<int>, greater<int> > maxFinish;

        for(int iter=0; iter<intervals.size(); iter++){

            if (!maxFinish.empty() && maxFinish.top() < intervals[iter][0]){
                cout << "Overwrite " << maxFinish.top() << " " << intervals[iter][1] << endl;
                maxFinish.pop(); 
            }
            maxFinish.push(intervals[iter][1]); 
        }

        return maxFinish.size();
        
    }
};



int main(){
    Solution s; 
    vector<vector<int>> v {{5,10},{6,8}, {1,5},{2,3}, {1,10}};
    vector<vector<int>> v2 {{1,3}, {5,6}, {8,10}, {11,13}};
    vector<vector<int>> v3 {{441459,446342},{801308,840640},{871890,963447},
        {228525,336985},{807945,946787},{479815,507766},{693292,944029},{751962,821744}};
    vector<vector<int>> v4 {{229966,812955},{308778,948377},{893612,952735},
        {395781,574123},{478514,875165},{766513,953839},{460683,491583},{133951,212694},
        {376149,838265},{541380,686845},{461394,568742},{804546,904032},{422466,467909},
        {557048,758709},{680460,899053},{110928,267321},{470258,650065},{534607,921875},
        {292993,994721},{645020,692560},{898840,947977},{33584,330630},{903142,970252},
        {17375,626775},{804313,972796},{582079,757160},{785002,987823},{599263,997719},
        {486500,527956},{566481,813653},{211239,863969},{808577,883125},{21880,516436},
        {264747,412144},{327175,772333},{984807,988224},{758172,916673},{23583,406006},
        {954674,956043},{379202,544291},{688869,785368},{841735,983869},{99836,916620},
        {332504,740696},{740840,793924},{896607,920924},{868540,922727},{125849,550941},{433284,685766}};

    cout << s.minGroups(v) << " for V1" << endl;
    cout << s.minGroups(v2) << " for V2"  << endl;
    cout << s.minGroups(v3) << " for V3"  << endl;
    cout << s.minGroups(v4) << " for V4"  << endl;



    


    return 0;
}