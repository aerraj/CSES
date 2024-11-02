#include <bits/stdc++.h>

using namespace std;

// Base class
class Vehicle {
public:
    virtual int getNumberOfWheels() const = 0; // Pure virtual function

    virtual ~Vehicle() {
        // Base class destructor
    }
};

// Derived class - EngineVehicle
class EngineVehicle : public Vehicle {
public:
    virtual bool hasEngine() const {
        return true; // Engine vehicles have an engine
    }
    
    virtual ~EngineVehicle() {
        // EngineVehicle destructor
    }
};

// Derived class - Bike (inherits from EngineVehicle)
class Bike : public EngineVehicle {
public:
    int getNumberOfWheels() const override {
        return 2; // A bike has 2 wheels
    }

    ~Bike() {
        cout << "Bike destroyed." << endl;
    }
};

// Derived class - Car (inherits from EngineVehicle)
class Car : public EngineVehicle {
public:
    int getNumberOfWheels() const override {
        return 4; // A car has 4 wheels
    }

    ~Car() {
        cout << "Car destroyed." << endl;
    }
};

// Derived class - Bicycle (inherits directly from Vehicle)
class Bicycle : public Vehicle {
public:
    int getNumberOfWheels() const override {
        return 2; // A bicycle has 2 wheels
    }

    ~Bicycle() {
        cout << "Bicycle destroyed." << endl;
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

    // Output the details of each vehicle in the list
    for (const auto& vehicle : vehicles) {
        cout << "Vehicle: " << vehicle->getNumberOfWheels() << " wheels, Engine: ";

        // Use dynamic_cast to check if the vehicle is an EngineVehicle
        if (auto engineVehicle = dynamic_cast<EngineVehicle*>(vehicle)) {
            cout << (engineVehicle->hasEngine() ? "Yes" : "No") << endl;
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


// Explanation of Changes:
// Pure Virtual Function: Vehicle now has a pure virtual method getNumberOfWheels() to make it an abstract class.
// EngineVehicle Class: Created a new class EngineVehicle that inherits from Vehicle and provides the hasEngine() method.
//  Only classes with engines (like Bike and Car) inherit from EngineVehicle.
// Bicycle Class: Inherits directly from Vehicle and does not have the hasEngine() method, 
// since a bicycle does not have an engine.
// Dynamic Casting: Used dynamic_cast to check if a 
// Vehicle object is an EngineVehicle and call hasEngine() only if it is.
// This design adheres to the Liskov Substitution Principle, as Bike and Car
//  can be substituted for EngineVehicle without altering the expected behavior,
//   while Bicycle remains a valid Vehicle that does not have an engine.