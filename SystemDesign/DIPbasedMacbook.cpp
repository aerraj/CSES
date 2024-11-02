#include <bits/stdc++.h>
using namespace std;

// Interface for Keyboard
class IKeyboard {
public:
    virtual void type() = 0; // Pure virtual function
};

// Interface for Mouse
class IMouse {
public:
    virtual void click() = 0; // Pure virtual function
};

// Concrete class for MechanicalKeyboard
class MechanicalKeyboard : public IKeyboard {
public:
    void type() override {
        cout << "Typing with a mechanical keyboard." << endl;
    }
};

// Concrete class for BluetoothKeyboard
class BluetoothKeyboard : public IKeyboard {
public:
    void type() override {
        cout << "Typing with a Bluetooth keyboard." << endl;
    }
};


// Concrete class for ChicletKeyboard
class ChicletKeyboard : public IKeyboard {
public:
    void type() override {
        cout << "Typing with a Chiclet keyboard." << endl;
    }
};

// Concrete class for OpticalMouse
class OpticalMouse : public IMouse {
public:
    void click() override {
        cout << "Clicking with an optical mouse." << endl;
    }
};
class TrackpadMouse : public IMouse {
public:
    void click() override {
        cout << "Clicking with an Trackpad mouse." << endl;
    }
};

// MacBook class that depends on Keyboard and Mouse interfaces
class MacBook {
private:
    IKeyboard* keyboard;
    IMouse* mouse;

public:
    // Constructor
    MacBook(IKeyboard* keyboard, IMouse* mouse) 
        : keyboard(keyboard), mouse(mouse) {}

    // Functions to use the keyboard and mouse
    void useKeyboard() {
        keyboard->type();
    }

    void useMouse() {
        mouse->click();
    }
};

int main() {
    // Creating concrete objects for keyboard and mouse
    MechanicalKeyboard keyboard;
    OpticalMouse mouse;
    ChicletKeyboard keybod;
    TrackpadMouse tp;
    // Creating a MacBook and injecting dependencies
    MacBook macbookpro(&keyboard, &mouse);
    MacBook macbookair(&keybod,&tp);
    // Using the MacBook
    cout<<"Pro Functionalities:"<<endl;
    macbookpro.useKeyboard();
    macbookpro.useMouse();


    cout<<"Air Functionalities:"<<endl;
    macbookair.useKeyboard();
    macbookair.useMouse();

    return 0;
}


//Dependency inversion principle states that:

// High-level modules should not depend on low-level modules. Both should depend on abstractions (e.g., interfaces).
// Abstractions should not depend on details. Details (concrete implementations) should depend on abstractions.


/*The Dependency Inversion Principle is applied in the following ways:

1.Use of Interfaces:

The IKeyboard and IMouse interfaces abstract the functionality of keyboards and mice, respectively. 
High-level components (like MacBook) depend on these abstractions rather than on concrete classes
 (like MechanicalKeyboard, OpticalMouse, etc.).
This allows MacBook to be decoupled from specific keyboard and mouse implementations.


2.Constructor Injection:

The MacBook class accepts pointers to IKeyboard and IMouse interfaces in its constructor. 
This is known as constructor injection, a common method of dependency injection.
When creating an instance of MacBook, you pass concrete implementations (like MechanicalKeyboard and OpticalMouse)
 as dependencies, rather than the MacBook class creating them internally. This promotes flexibility and reusability.
Flexibility and Extensibility:

If you want to add new types of keyboards or mice (for instance, a new type of keyboard like BluetoothKeyboard), 
you can do so without modifying the MacBook class. 
You simply implement the IKeyboard or IMouse interfaces and inject the new object.
This makes your code more maintainable and easier to extend, adhering to the Open/Closed Principle (another SOLID principle).
Example of How DIP Works in the Code
cpp code
// Creating a MacBook and injecting dependencies
MacBook macbookpro(&keyboard, &mouse); // Here, keyboard is a MechanicalKeyboard and mouse is an OpticalMouse.
MacBook macbookair(&keybod, &tp);       // Here, keybod is a ChicletKeyboard and tp is a TrackpadMouse.
Decoupling: The MacBook class does not need to know how each keyboard or mouse works. It only interacts with them through their interfaces. This means you can switch out the specific keyboard or mouse type without changing the MacBook class, promoting flexibility.
Testability: If you wanted to write unit tests for MacBook, you could create mock implementations of IKeyboard and IMouse to test MacBook without needing real keyboard or mouse objects.*/