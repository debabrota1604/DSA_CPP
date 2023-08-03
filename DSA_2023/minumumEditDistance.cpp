#include<iostream>
#include<string>
#include<map>
using namespace std;

#define debugPrint 1
#define map_print 1
#define cost_i 1 // cost of insertion
#define cost_d 1 // cost of deletion
#define cost_r 1 // cost of replacement

string s1, s2;
map<pair<int, int>, int> m; int max_cost=0;

int min3(int x, int y, int z){return min(min(x,y),z);} 
int max3(int x, int y, int z){return max(max(x,y),z);} 
void printMap(){
    if(map_print){
        cout << "Map entries are: " <<endl;
        for(auto i:m){ cout << "map[" << (i.first).first << "," << (i.first).second << "]= " << i.second <<endl; }
    }
}

int med(int i1, int i2){
    if(debugPrint){ cout << "Entering med("<< i1 << "," << i2 << ")..." << endl;}
    if(i1>=s1.size()){ if(debugPrint) cout << "\tMaxIndex: Returning with insert cost from B to A: " << s2.size() - i2 << endl; return (s2.size() - i2) * cost_i;} 
    if(i2>=s2.size()){ if(debugPrint) cout << "\tMaxIndex: Returning with delete cost from A: " << s1.size() - i1 << endl; return (s1.size() - i1) * cost_d;} 

    pair<int, int> p(i1, i2);
    if(m.count(p)){ cout << "\tPre-computed: Returning with value: "<< m[p] <<endl; return m[p]; }
    int val1, val2,next_i1, next_i2; val1 = val2 = max_cost; next_i1= i1 + 1; next_i2 = i2+1; 

    if(s1[i1] == s2[i2]) val1 = med(i1+1, i2+1);
    else val2= min3(med(next_i1, i2)+cost_d, med(i1,next_i2)+cost_i, med(next_i1, next_i2) + cost_r);
   
    if(debugPrint) cout << "For ("<<i1<< ","<<i2<<") comparing: " << val1 << val2 << endl;

    m[p]=min(val1,val2); printMap();        
    if (debugPrint) cout  << "\tReturning after new Map entry (" << i1 << "," << i2 << ")= " << m[p] << endl;
    return m[p];

}
int main(){
    cout << "This program converts a string into a new string with minimum cost in insert/delete/replace.\nPresent cost settings are: Insert " << cost_i << ", Delete " << cost_d << ", Replace " << cost_r << endl;
    cout << "Enter first string: "; cin >> s1;
    cout << "Enter second string: "; cin >> s2;

    max_cost=(s1.size() + s2.size()) * max3(cost_d, cost_i, cost_r);

    auto res = med(0,0);
    cout << "Minimum edit distance for converting " << s1 << " to " << s2 << " is: " << res << endl;


    return 0;
}