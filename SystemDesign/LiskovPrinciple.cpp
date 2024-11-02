#include <bits/stdc++.h>

using namespace std;

// Base class
class Vehicle {
public:
    virtual int getNumberOfWheels() const {
        return 2; // Default: 2 wheels
    }

    virtual optional<bool> hasEngine() const {
        return true; // Default: has an engine
    }

    virtual ~Vehicle() {
        // Base class destructor
    }
};

// Derived class - Bike
class Bike : public Vehicle {
public:
    ~Bike() {
        cout << "Bike destroyed." << endl;
    }
};

// Derived class - Car
class Car : public Vehicle {
public:
    int getNumberOfWheels() const override {
        return 4; // A car has 4 wheels
    }

    ~Car() {
        cout << "Car destroyed." << endl;
    }
};

// Derived class - Bicycle
class Bicycle : public Vehicle {
public:
    optional<bool> hasEngine() const override {
        return nullopt; // Bicycles do not have an engine
    }
};

int main() {
    // Create a vector to hold pointers to Vehicle objects
    vector<Vehicle*> vehicles;

    // Create instances of Bike, Car, and Bicycle
    Vehicle* bike = new Bike();
    Vehicle* car = new Car();
    Vehicle* bicycle = new Bicycle();

    // Add them to the vector
    vehicles.push_back(bike);
    vehicles.push_back(car);
    vehicles.push_back(bicycle);

    // Check the engine status of the Bicycle
    auto it = bicycle->hasEngine();
    cout << boolalpha; // Use boolalpha to print bool values as "true" or "false"
    if (it.has_value()) {
        cout << "Bicycle has engine: " << it.value() << endl;
    } else {
        cout << "Bicycle has engine: No" << endl;
    }

    // Output the details of each vehicle in the list
    for (const auto& vehicle : vehicles) {
        cout << "Vehicle: " << vehicle->getNumberOfWheels() << " wheels, Engine: ";
        auto engineStatus = vehicle->hasEngine();
        if (engineStatus.has_value()) {
            cout << (engineStatus.value() ? "Yes" : "No") << endl;
        } else {
            cout << "No" << endl;
        }
    }

    // Clean up allocated memory
    for (auto& vehicle : vehicles) {
        delete vehicle; // Calls appropriate destructors
    }

    return 0;
}
