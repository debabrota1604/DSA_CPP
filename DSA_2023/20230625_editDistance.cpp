#include<bits/stdc++.h>
using namespace std;

//given two strings str1 and str2 anf three operations insert, delete & replace with their respective
//weights, compute the minimum weight to transform str1 and str2;


class editDistance{
    string s1, s2;
    int *opWeights;//0: insert, 1: delete, 2: replace

    public:
    editDistance(string ip1, string ip2, int insW, int delW, int replaceW){
        this->s1=ip1;
        this->s2=ip2;
        int temp[] = {insW, delW, replaceW};
        this->opWeights = temp;
    }

    bool editDistance(int pos1, int pos2,int cost){

    }


};

int main(){



    return 0;
}