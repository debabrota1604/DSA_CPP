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

// This class solves the earlier problem. It also moves the client if-else code into itself.
class VehicleFactory: public Vehicle{
    public:
    static Vehicle* getVehicle(string vehicleType){ //static member can be accessed without class object
        Vehicle* vehicle;
        if(vehicleType == "Car") vehicle = new Car();
        else if(vehicleType == "Bike") vehicle = new Bike();

        return vehicle;
    }
};


//Client code
int main(){
    string vehicleType;
    cin >> vehicleType;

    Vehicle* vehicle = VehicleFactory::getVehicle(vehicleType);
    vehicle->createVehicle();

    /*
    Client code is now generic, adding new vehicles is completely within VehicleFactory scope.
    */


    return 0;
}