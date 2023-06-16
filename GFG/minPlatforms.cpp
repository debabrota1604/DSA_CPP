#include<bits/stdc++.h>
using namespace std;

int minPlatformsNeededToPark(vector<int> arv, vector<int> dep){
    int minPlatforms, maxTime=0, maxPlatforms=0;
    
    for(int iter=0; iter< arv.size(); iter++){
        if (arv[iter] < maxTime ) minPlatforms++;
        if(dep[iter] > maxTime) maxTime = dep[iter];
        maxPlatforms = maxPlatforms > minPlatforms ? maxPlatforms:minPlatforms;
        maxTime = maxTime > dep[iter] ? maxTime:dep[iter];
    }


    return minPlatforms;
}




int main(){
    vector<int> arrival {900,940,950, 1100, 1500, 1800}, departure {910, 1200, 1120, 1130, 1900, 2000};
    cout << "Minimum number of platforms needed: " << minPlatformsNeededToPark(arrival, departure) << endl;


    return 0;
} 