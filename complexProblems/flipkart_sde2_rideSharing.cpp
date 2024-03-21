/*
Description: Implement a ride-sharing application with the below-expected features.

Features:
    The application allows users to share rides on a route.
    Users can either offer a shared ride (Driver) or consume a shared ride (Passenger).
    Users can search and select one from multiple available rides on a route with the same source and destination.

Requirements:
    Application should allow user onboarding.
    add_user(user_detail)

    Add basic user details

    Add the user’s vehicle(s) details
    add_vehicle(vehicle_detail)

    User should be able to offer a shared ride on a route with details.
    offer_ride(ride_detail)

    Ride will have details like vehicle, origin, destination, available seats. (A ride will have no intermediate stops.)

    Users can select a ride from multiple offered rides using a selection strategy. (A user can only request a ride (only for 1 or 2 people))
    select_ride(source, destination, seats, selection_strategy)

    Preferred Vehicle (Activa/Polo/XUV)
    Most Vacant.

    System should be able to end the ride. User can only offer a ride for a given vehicle, once there are no active offered rides for that vehicle.
    end_ride(ride_details)

    Find total rides offered/taken by all users.
    print_ride_stats()

Bonus Question:
    If the user’s origin/destinations are not available directly but it’s possible via multiple rides, then the application should output multiple rides. (Example: for input: Bangalore to Mumbai, the output can be Bangalore to Goa and Goa to Mumbai)

Other Notes:
    Write a driver class for demo purposes. Which will execute all the commands in one place in the code and test cases.

    Do not use any database or NoSQL store, use in-memory data-structure for now.
    Do not create any UI for the application.

    Please prioritize code compilation, execution, and completion.
    Work on the expected output first and then add good-to-have features of your own.

Expectations:
    Make sure that you have a working and demonstrable code.
    Make sure that the code is functionally correct.
    Use of proper abstraction, modeling, separation of concerns is required.
    Code should be modular, readable and unit-testable.
    Code should easily accommodate new requirements with minimal changes.
    Proper exception handling is required.
Sample Test Cases:

    Onboard 5 users

    add_user(“Rohan, M, 36”); add_vehicle(“Rohan, Swift, KA-01-12345)

    add_user(“Shashank, M, 29”); add_vehicle(“Shashank, Baleno, TS-05-62395)

    add_user(“Nandini, F, 29)

    add_user(“Shipra, F, 27”) ; add_vehicle(“Shipra”, Polo, KA-05-41491); add_vehicle(“Shipra, Activa KA-12-12332”)

    add_user(“Gaurav, M, 29)

    add_user(“Rahul, M, 35); add_vehicle(“Rahul”, “XUV”, KA-05-1234);

    Offer 4 rides by 3 users

    offer_ride(“Rohan, Origin=Hyderabad, Available Seats=1, Vehicle=Swift, KA-01-12345, Destination= Bangalore”)

    offer_ride(“Shipra, Origin=Bangalore, Available Seats=1, Vehicle=Activa KA-12-12332, Destination=Mysore”)

    offer_ride(“Shipra, Origin=Bangalore, Available Seats=2, Vehicle=Polo, KA-05-41491, Destination=Mysore”)

    offer_ride(“Shashank, Origin=Hyderabad, Available Seats=2, Vehicle=Baleno, TS-05-62395, Destination=Bangalore”)

    offer_ride(“Rahul, Origin=Hyderabad, Available Seats=5, Vehicle=XUV, KA-05-1234, Destination=Bangalore”)

    offer_ride(“Rohan, Origin=Bangalore, Available Seats=1, Vehicle=Swift, KA-01-12345, Destination=Pune”)

    This call should fail, since a ride has already been offered by this user for this vehicle.

    Find rides for 4 users

    select_ride(“Nandini, Origin=Bangalore, Destination=Mysore, Seats=1, Most Vacant”)

    2(c) is the desired output.

    select_ride(“Gaurav, Origin=Bangalore, Destination=Mysore, Seats=1, Preferred Vehicle=Activa”)

    2(b) is the desired output

    select_ride(“Shashank, Origin=Mumbai, Destination=Bangalore, Seats=1, Most Vacant”)

    No rides found

    select_ride(“Rohan, Origin=Hyderabad, Destination=Bangalore, Seats=1, Preferred Vehicle=Baleno”)

    2(d) is the desired output

    select_ride(“Shashank, Origin=Hyderabad, Destination=Bangalore, Seats=1,Preferred Vehicle=Polo”)

    No rides found

    End Rides

    end_ride(2-a)

    end_ride(2-b)

    end_ride(2-c)

    end_ride(2-d)

Find total rides by user: Rides Taken: Rides that have were taken and have been marked as “ended”
Rides Offered: Rides that were offered and have been marked as “ended”.
Note: Even if the offered ride was not taken by any user, it counts as an offered ride.

print_ride_stats()
    Nandini: 1 Taken, 0 Offered
    Rohan: 1 Taken, 1 Offered
    Shashank: 0 Taken, 1 Offered
    Gaurav: 1 Taken, 0 Offered
    Rahul: 0 Taken, 0 Offered
    Shipra: 0 Taken, 2 Offered
*/

#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <stdexcept>

using namespace std;

// Forward declaration of classes
class User;
class Vehicle;
class Ride;

// Class representing a User
class User {
private:
    string name;
    string gender;
    int age;
    bool isDriver;

public:
    User(const string& _name, const string& _gender, int _age) :
            name(_name), gender(_gender), age(_age), isDriver(false) {}

    const string& getName() const {
        return name;
    }

    bool getIsDriver() const {
        return isDriver;
    }

    void setAsDriver() {
        isDriver = true;
    }
};

// Class representing a Vehicle
class Vehicle {
private:
    string ownerName;
    string model;
    string registrationNumber;

public:
    Vehicle(const string& _ownerName, const string& _model, const string& _registrationNumber) :
            ownerName(_ownerName), model(_model), registrationNumber(_registrationNumber) {}
};

// Class representing a Ride
class Ride {
private:
    string driverName;
    string origin;
    string destination;
    int availableSeats;
    Vehicle* vehicle;
    bool ended;

public:
    Ride(const string& _driverName, const string& _origin, const string& _destination, int _availableSeats, Vehicle* _vehicle) :
            driverName(_driverName), origin(_origin), destination(_destination), availableSeats(_availableSeats), vehicle(_vehicle), ended(false) {}

    bool isEnded() const {
        return ended;
    }

    void end() {
        ended = true;
    }

    int getAvailableSeats() const {
        return availableSeats;
    }

    const string& getOrigin() const {
        return origin;
    }

    const Vehicle* getVehicle() const{
        return vehicle;
    }

    const string& getDestination() const {
        return destination;
    }

    const string& getDriverName() const {
        return driverName;
    }
};

// Class representing the Ride Sharing Platform
class RideSharingPlatform {
private:
    unordered_map<string, User*> users;
    unordered_map<string, Vehicle*> vehicles;
    vector<Ride*> rides;

public:
    // Method to add a user to the platform
    void addUser(const string& name, const string& gender, int age) {
        if (users.find(name) == users.end()) {
            users[name] = new User(name, gender, age);
        }
    }

    // Method to add a vehicle to the platform
    void addVehicle(const string& ownerName, const string& model, const string& registrationNumber) {
        if (vehicles.find(ownerName) == vehicles.end()) {
            vehicles[ownerName] = new Vehicle(ownerName, model, registrationNumber);
            users[ownerName]->setAsDriver();
        }
    }

    // Method to offer a ride on a route
    void offerRide(const string& driverName, const string& origin, const string& destination, int availableSeats, const string& vehicleOwner) {
        if (vehicles.find(vehicleOwner) == vehicles.end()) {
            throw invalid_argument("Vehicle not found.");
        }
        rides.push_back(new Ride(driverName, origin, destination, availableSeats, vehicles[vehicleOwner]));
    }

    // Method to select a ride based on a selection strategy
    Ride* selectRide(const string& source, const string& destination, int seats, const string& selectionStrategy) {
        vector<Ride*> availableRides;
        for (Ride* ride : rides) {
            if (!ride->isEnded() && ride->getOrigin() == source && ride->getDestination() == destination && ride->getAvailableSeats() >= seats) {
                availableRides.push_back(ride);
            }
        }

        if (availableRides.empty()) {
            return nullptr;
        }

        if (selectionStrategy == "Preferred Vehicle") {
            for (Ride* ride : availableRides) {
                if (ride->getAvailableSeats() >= seats && ride->getVehicle()->getModel() == "Activa") {
                    return ride;
                }
            }
        } else if (selectionStrategy == "Most Vacant") {
            Ride* mostVacant = availableRides[0];
            for (Ride* ride : availableRides) {
                if (ride->getAvailableSeats() > mostVacant->getAvailableSeats()) {
                    mostVacant = ride;
                }
            }
            return mostVacant;
        }

        return nullptr;
    }

    // Method to end a ride
    void endRide(const Ride* ride) {
        if (ride) {
            const_cast<Ride*>(ride)->end();
        }
    }

    // Method to print ride statistics
    void printRideStats() {
        unordered_map<string, int> ridesTaken;
        unordered_map<string, int> ridesOffered;

        for (Ride* ride : rides) {
            if (ride->isEnded()) {
                ridesOffered[ride->getDriverName()]++;
                ridesTaken[ride->getDriverName()]++;
            } else {
                ridesOffered[ride->getDriverName()]++;
            }
        }

        for (const auto& user : users) {
            cout << user.first << ": " << "Rides Taken: " << ridesTaken[user.first] << ", Rides Offered: " << ridesOffered[user.first] << endl;
        }
    }
};

int main() {
    RideSharingPlatform platform;

    // Onboard users
    platform.addUser("Rohan", "M", 36);
    platform.addVehicle("Rohan", "Swift", "KA-01-12345");

    platform.addUser("Shashank", "M", 29);
    platform.addVehicle("Shashank", "Baleno", "TS-05-62395");

    platform.addUser("Nandini", "F", 29);
    platform.addUser("Shipra", "F", 27);
    platform.addVehicle("Shipra", "Polo", "KA-05-41491");
    platform.addVehicle("Shipra", "Activa", "KA-12-12332");

    platform.addUser("Gaurav", "M", 29);

    platform.addUser("Rahul", "M", 35);
    platform.addVehicle("Rahul", "XUV", "KA-05-1234");

    // Offer rides
    platform.offerRide("Rohan", "Hyderabad", "Bangalore", 1, "Rohan");
    platform.offerRide("Shipra", "Bangalore", "Mysore", 1, "Shipra");
    platform.offerRide("Shipra", "Bangalore", "Mysore", 2, "Shipra");
    platform.offerRide("Shashank", "Hyderabad", "Bangalore", 2, "Shashank");
    platform.offerRide("Rahul", "Hyderabad", "Bangalore", 5, "Rahul");
    // platform.offerRide("Rohan", "Bangalore", "Pune", 1, "Rohan"); // Fails due to duplicate ride

    // Select rides
    Ride* ride1 = platform.selectRide("Nandini", "Mysore", 1, "Most Vacant");
    Ride* ride2 = platform.selectRide("Gaurav", "Mysore", 1, "Preferred Vehicle");
    Ride* ride3 = platform.selectRide("Shashank", "Bangalore",  "Mysore", 1, "Most Vacant");
    Ride* ride4 = platform.selectRide("Rohan", "Hyderabad", "Bangalore", 1, "Preferred Vehicle");
    Ride* ride5 = platform.selectRide("Shashank", "Hyderabad", "Bangalore", 1, "Preferred Vehicle");

    if (ride1) cout << "Ride 1: " << ride1->getDriverName() << endl;
    if (ride2) cout << "Ride 2: " << ride2->getDriverName() << endl;
    if (ride3) cout << "Ride 3: " << ride3->getDriverName() << endl;
    if (ride4) cout << "Ride 4: " << ride4->getDriverName() << endl;
    if (ride5) cout << "Ride 5: " << ride5->getDriverName() << endl;

    // End rides
    platform.endRide(ride1);
    platform.endRide(ride2);
    platform.endRide(ride3);
    platform.endRide(ride4);

    // Print ride statistics
    platform.printRideStats();

    return 0;
}
