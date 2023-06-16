#include<iostream>
#include<map>
#include<string>
using namespace std;

int debug_print =0;
int map_print=0;

string s1;
map < pair<int, int>, int > m;
// s1 is the input string of n characters. map stores the index (i, j ) 
//with length p where the maximum palindromic substring between index i & j is p.

int lps(int index1, int index2){
    if (debug_print) cout << "NewCall lps(" << index1 << ":" << index2 <<") "<<endl; 
    if(index1>index2) return 0;

    pair<int, int> p(index1, index2);
    if(m.count(p)){ return m[p]; }

    int next_i1=index1+1, next_i2 = index2-1;
    int val1 = (next_i1 <index2) ? lps(next_i1, index2) :0; //skips 1 left char and progresses to center
    int val2 = (index1 <next_i2) ? lps(index1, next_i2) :0; //skips 1 right char and progresses to center
    int val3 = (index1 < index2 && s1[index1]==s1[index2]) ? (next_i1 <= next_i2 ? lps(next_i1, next_i2): 0)+2 :0; //selects both end char and progresses to center
    int val4 = index1 == index2 ? val4=1 :0; //case odd palindrome of length 

    if (debug_print) cout  << "\tReturning after new Map entry (" << index1 << "," << index2 << ")..." <<endl;
    return m[p]= max(max(val1,val2),max(val3,val4));
}

int main(){
    cout << "Enter the binary sequence: ";  cin >> s1;
    auto res = lps(0,s1.size()-1);
    cout << "Longest palindromic substring length is: " << res <<endl;

    if(map_print){
        cout << "Map entries are: " <<endl;
        for(auto i:m){ cout << "map[" << (i.first).first << "," << (i.first).second << "]= " << i.second <<endl; }
    }
    return 0;
}