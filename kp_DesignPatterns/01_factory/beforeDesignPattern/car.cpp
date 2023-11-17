#include<bits/stdc++.h>
#include "vehicle.cpp"
using namespace std;


class Car: public Vehicle{
    public:
    void createVehicle(){
        cout << "Creating Car...\n";
    }
};