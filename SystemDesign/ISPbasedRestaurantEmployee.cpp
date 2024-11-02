#include <iostream>
#include <string>
using namespace std;

// Interface for roles related to serving food
class Serve {
public:
    virtual void serveFood() = 0;
    virtual ~Serve() {}
};

// Interface for roles related to cooking
class Cook {
public:
    virtual void cookFood() = 0;
    virtual ~Cook() {}
};

// Interface for roles related to cleaning
class Cleaner {
public:
    virtual void cleanRestaurant() = 0;
    virtual ~Cleaner() {}
};

// Derived class for a Waiter, who only serves food
class Waiter : public Serve {
public:
    void serveFood() override {
        cout << "Waiter is serving food to the customers." << endl;
    }
};

// Derived class for a Chef, who only cooks food
class Chef : public Cook {
public:
    void cookFood() override {
        cout << "Chef is cooking delicious meals in the kitchen." << endl;
    }
};

// Derived class for a Janitor, who only cleans
class Janitor : public Cleaner {
public:
    void cleanRestaurant() override {
        cout << "Janitor is cleaning the restaurant." << endl;
    }
};

// Main function to demonstrate the ISP-compliant design
int main() {
    Waiter waiter;
    Chef chef;
    Janitor janitor;

    // Using the waiter, chef, and janitor objects
    waiter.serveFood();
    chef.cookFood();
    janitor.cleanRestaurant();

    return 0;
}
