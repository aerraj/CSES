#include <bits/stdc++.h>

using namespace std;

// Strategy Interface
class DriveStrategy {
public:
    virtual void drive() = 0; // Pure virtual function
    virtual ~DriveStrategy() {} // Virtual destructor
};

// Concrete Strategy Classes
class NormalDriveStrategy : public DriveStrategy {
public:
    void drive() override {
        cout << "Driving in normal mode." << endl;
    }
};

class SportsDriveStrategy : public DriveStrategy {
public:
    void drive() override {
        cout << "Driving in Sports Mode." << endl;
    }
};

class UtilityDriveStrategy : public DriveStrategy {
public:
    void drive() override {
        cout << "Driving in utility mode." << endl;
    }
};

// Base Class
class Vehicle {
protected:
    DriveStrategy* driveObject; // Member object of type DriveStrategy
    vector<DriveStrategy*> gearbox; // Vector to hold multiple strategies

public:
    // Constructor injection
    Vehicle(DriveStrategy* driveObj) : driveObject(driveObj) {}

    // Gearbox based initialization
    Vehicle(vector<DriveStrategy*> gearbox) : gearbox(gearbox) {}

    void drive() {
        if (driveObject) {
            driveObject->drive();
        }
    }

    void drivemode() {
        for (auto it : gearbox) {
            it->drive();
        }
    }

    virtual ~Vehicle() { // Virtual destructor
        delete driveObject; // Clean up the single strategy object
        for (auto it : gearbox) {
            delete it; // Clean up each strategy in the gearbox
        }
    }
};

// Derived Classes
class SportyVehicle : public Vehicle {
public:
    SportyVehicle() : Vehicle(new SportsDriveStrategy()) {}
};

class SuperCar : public Vehicle {
public:
    SuperCar() : Vehicle({new SportsDriveStrategy(), new NormalDriveStrategy(), new UtilityDriveStrategy()}) {}
};

class RacingVehicle : public Vehicle {
public:
    RacingVehicle() : Vehicle(new SportsDriveStrategy()) {}
};

class PassengerVehicle : public Vehicle {
public:
    PassengerVehicle() : Vehicle(new NormalDriveStrategy()) {}
};

class CityVehicle : public Vehicle {
public:
    CityVehicle() : Vehicle(new NormalDriveStrategy()) {}
};

class UtilityVehicle : public Vehicle {
public:
    UtilityVehicle() : Vehicle(new UtilityDriveStrategy()) {}
};

// Main Function
int main() {
    // Create instances of vehicles with their respective driving strategies
    Vehicle* sportyCar = new SportyVehicle();
    Vehicle* passengerCar = new PassengerVehicle();
    Vehicle* utilityTruck = new UtilityVehicle();
    Vehicle* ferrari = new RacingVehicle();

    // Drive each vehicle
    sportyCar->drive();        // Output: Driving in Sports Mode.
    passengerCar->drive();     // Output: Driving in normal mode.
    utilityTruck->drive();     // Output: Driving in utility mode.
    ferrari->drive();          // Output: Driving in Sports Mode.

    // Create a Car object and use drivemode method
    Vehicle* car = new SuperCar();
    cout << "This Vehicle has various modes in which it drives:" << endl;
    car->drivemode(); // Call drivemode to see all modes

    // we can use combination of drive strategy like car has all 3

    // Clean up
    delete ferrari;
    delete sportyCar;
    delete passengerCar;
    delete utilityTruck;
    delete car; // Clean up the Car object

    return 0;
}
