#include<iostream>
#include<map>
using namespace std;
int *seq,seqLen;
map<pair<int, int>, int> m; //pair of index, max_element

int las(int endIndex){
    pair<int, int> p=make_pair(endIndex,endIndex); int temp, temp2;

    if (endIndex==0) { return 1; }
    if (m.count(p)) { return m[p]; }
    else{

        return 0;
    }

}

int main(){
    cout << "Given an integer sequence, this program computes the longest subsequence which is in ascending order.\nInput sequence length: "; cin >> seqLen;
    cout << "Enter the sequence (space seperated): ";
    seq = new int[seqLen]; for(int i=0;i<seqLen; i++){ cin >> seq[i]; }
    for(auto i=0; i<seqLen; i++){ cout << seq[i] << " "; }
    
    
    cout << "Max Length is: " << las(seqLen-1) <<endl;


    return 0;
}