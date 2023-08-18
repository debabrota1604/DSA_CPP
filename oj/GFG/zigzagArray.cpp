#include<bits/stdc++.h>
using namespace std;

void swap(vector<int> &arr, int index1, int index2){
    int tempVar = arr[index2];
    arr[index2] = arr[index1];
    arr[index1] = tempVar;
}

void zigzagPattern(vector<int> &arr){
    bool flipFlag=false;
    for(int iter=0;iter <arr.size()-1; iter++){

        //check and swap based on conditions
        if (flipFlag == false && arr[iter] >= arr[iter+1])      swap(arr, iter, iter+1);
        else if (flipFlag == true && arr[iter] <= arr[iter+1] ) swap(arr, iter, iter+1);

        //toogle the flag at every iteration
        flipFlag = !flipFlag;
    }
}


int main(){

    vector<int> vec {1,2,3,4,5,6,7,8,9};

    zigzagPattern(vec);

    for(auto item: vec) cout << item << " ";
    cout << endl;



    return 0;
}