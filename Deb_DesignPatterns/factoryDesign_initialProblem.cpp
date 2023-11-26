#include<bits/stdc++.h>
using namespace std;


class Vehicle{
    public:
    virtual void createVehicle() = 0;
};

class Car: public Vehicle{
    public:
    void createVehicle(){
        cout << "Creating Car...\n";
    }
};
class Bike: public Vehicle{
    public:
    void createVehicle(){
        cout << "Creating Bike...\n";
    }
};


//Client code
int main(){
    string vehicleType;
    cin >> vehicleType;

    Vehicle* vehicle;
    if(vehicleType == "Car") vehicle = new Car();
    else if(vehicleType == "Bike") vehicle = new Bike();

    vehicle->createVehicle();

    /*
        Problem: To add a new vehicle type, we need to modify the client code (add a new if case)
         which is a tight coupling of library with client code.
    */


    return 0;
}