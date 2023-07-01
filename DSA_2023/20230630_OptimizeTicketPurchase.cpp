#include<bits/stdc++.h>
using namespace std;

class OptimizeTicketPurchase{
    vector<int> ticketValue_dwm;
    public:
    OptimizeTicketPurchase(vector<int> ticketCosts){
        this->ticketValue_dwm = ticketCosts;
    }
    int calculateMinTicketExpense(vector<int> travelDays, int endDate){
        int res=0;
        for(int iter=0; iter<3; iter++){

        }

    }
};




int main(){

    OptimizeTicketPurchase otp({1,1,1});
    cout << "Minimum cost for travel: " << otp.calculateMinTicketExpense({2,5,10},365) << endl;




    return 0;
}