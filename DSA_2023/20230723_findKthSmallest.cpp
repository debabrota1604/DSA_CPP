#include<bits/stdc++.h>
using namespace std;

template<typename T>
void swp(T& val1, T& val2){
    T temp = val2;
    val2 = val1;
    val1 = temp;
}

void disp(vector<int>& inp){
    for(int iter=0; iter<inp.size(); iter++){
        cout << inp[iter] << " ";
    }
    cout << endl;
}

int partition(vector<int>& arr, int lo, int hi){
    int pivot, loInd, iter;
    pivot = arr[hi];
    loInd = lo;

    for(iter = lo; iter<hi; iter++){
        if(arr[iter] <= pivot){
            cout << "Swapping " << arr[iter] << " with " << arr[loInd] << endl;
            swp( arr[iter], arr[loInd]);
            loInd++;
            disp(arr);
        }
    }

    swp(arr[hi], arr[loInd]);
    return loInd;    
}

int main(){
    vector<int> arr {7, 3, 1, 9, 8, 2, 6};

    int x=5, y=6;

    cout << "Before partition: "<< endl;
    disp(arr);

    partition(arr, 0, arr.size()-1);

    cout << "After partition: "<< endl;
    disp(arr);

}