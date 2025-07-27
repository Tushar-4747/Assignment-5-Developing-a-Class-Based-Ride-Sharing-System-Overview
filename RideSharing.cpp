#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Base Ride class
class Ride {
protected:
    string rideID;
    string pickupLocation;
    string dropoffLocation;
    double distance; // in kilometers
public:
    Ride(string id, string pickup, string dropoff, double dist)
        : rideID(id), pickupLocation(pickup), dropoffLocation(dropoff), distance(dist) {}

    virtual double fare() const {
        return distance * 10.0; // Base fare per km for a standard ride
    }

    virtual void rideDetails() const {
        cout << "Ride ID: " << rideID
             << ", From: " << pickupLocation
             << ", To: " << dropoffLocation
             << ", Distance: " << distance << " km"
             << ", Fare: $" << fare() << endl;
    }

    virtual ~Ride() {}
};

// Derived class - Standard Ride
class StandardRide : public Ride {
public:
    StandardRide(string id, string pickup, string dropoff, double dist)
        : Ride(id, pickup, dropoff, dist) {}

    double fare() const override {
        return distance * 10.0; // Standard rate
    }

    void rideDetails() const override {
        cout << "[Standard] ";
        Ride::rideDetails();
    }
};

// Derived class - Premium Ride
class PremiumRide : public Ride {
public:
    PremiumRide(string id, string pickup, string dropoff, double dist)
        : Ride(id, pickup, dropoff, dist) {}

    double fare() const override {
        return distance * 20.0; // Premium rate
    }

    void rideDetails() const override {
        cout << "[Premium] ";
        Ride::rideDetails();
    }
};

// Driver class
class Driver {
private:
    string driverID;
    string name;
    double rating;
    vector<Ride*> assignedRides; // Encapsulated
public:
    Driver(string id, string nm, double rt)
        : driverID(id), name(nm), rating(rt) {}

    void addRide(Ride* ride) {
        assignedRides.push_back(ride);
    }

    void getDriverInfo() const {
        cout << "Driver ID: " << driverID << ", Name: " << name << ", Rating: " << rating << endl;
        cout << "Completed Rides:" << endl;
        for (Ride* ride : assignedRides) {
            ride->rideDetails();
        }
    }
};

// Rider class
class Rider {
private:
    string riderID;
    string name;
    vector<Ride*> requestedRides;
public:
    Rider(string id, string nm) : riderID(id), name(nm) {}

    void requestRide(Ride* ride) {
        requestedRides.push_back(ride);
    }

    void viewRides() const {
        cout << "Rider ID: " << riderID << ", Name: " << name << endl;
        cout << "Ride History:" << endl;
        for (Ride* ride : requestedRides) {
            ride->rideDetails();
        }
    }
};

// Main function to demonstrate system functionality
int main() {
    // Create rides
    Ride* r1 = new StandardRide("R001", "A", "B", 5.0);
    Ride* r2 = new PremiumRide("R002", "C", "D", 8.0);
    Ride* r3 = new StandardRide("R003", "E", "F", 3.5);

    // Create driver and assign rides
    Driver d1("D123", "Alice", 4.9);
    d1.addRide(r1);
    d1.addRide(r2);

    // Create rider and request rides
    Rider rider1("U101", "Bob");
    rider1.requestRide(r1);
    rider1.requestRide(r3);

    // Display driver and rider details
    cout << "=== Driver Info ===" << endl;
    d1.getDriverInfo();

    cout << "\n=== Rider Info ===" << endl;
    rider1.viewRides();

    // Demonstrate polymorphism
    cout << "\n=== Polymorphism Demo ===" << endl;
    vector<Ride*> rideList = {r1, r2, r3};
    for (Ride* ride : rideList) {
        ride->rideDetails();  // Polymorphic call
    }

    // Clean up
    delete r1;
    delete r2;
    delete r3;

    return 0;
}
