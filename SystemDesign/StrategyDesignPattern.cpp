#include <iostream>

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
        cout << "Sports drive capability." << endl;
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

public:
    // Constructor injection
    Vehicle(DriveStrategy* driveObj) : driveObject(driveObj) {}

    void drive() {
        driveObject->drive();
    }

    virtual ~Vehicle() { // Virtual destructor
        delete driveObject; // Clean up the strategy object
    }
};

// Derived Classes
class SportyVehicle : public Vehicle {
public:
    SportyVehicle() : Vehicle(new SportsDriveStrategy()) {}
};

class PassengerVehicle : public Vehicle {
public:
    PassengerVehicle() : Vehicle(new NormalDriveStrategy()) {}
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

    // Drive each vehicle
    sportyCar->drive();        // Output: Sports drive capability.
    passengerCar->drive();     // Output: Driving in normal mode.
    utilityTruck->drive();     // Output: Driving in utility mode.

    // Clean up
    delete sportyCar;
    delete passengerCar;
    delete utilityTruck;

    return 0;
}
