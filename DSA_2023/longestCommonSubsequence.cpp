#include<iostream>
#include<map>
#include<string>
using namespace std;

int debug_print =1;
int debug_print2=1;

string s1,s2;
map < pair<int, int>, int > m;

int lcs(int index1, int index2){
    if (debug_print) cout << "NewCall lcs(" << index1 << ":" << index2 <<") "<<endl; 
    if(index1>=s1.size() || index2>=s2.size()) return 0;

    pair<int, int> p(index1, index2);
    if(m.count(p)){ return m[p]; }

    int val1 = index1+1 <s1.size()? lcs(index1+1, index2) :0;
    int val2 = index2+1 <s2.size()? lcs(index1, index2+1) :0;
    int val3 = s1[index1]==s2[index2] ? val3=lcs(index1+1, index2+1)+1 :0;

    if (debug_print) cout  << "\tReturning after new Map entry (" << index1 << "," << index2 << ")..." <<endl;
    return m[p]= max(max(val1,val2),val3);
}

int main(){
    cout << "Enter the first sequence: ";  cin >> s1;
    cout << "Enter the second sequence: "; cin >> s2; 
    auto res = lcs(0,0);
    cout << "Longest common substring length is: " << res <<endl;
    return 0;
}