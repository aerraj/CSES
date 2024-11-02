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

// Concrete class for OpticalMouse
class OpticalMouse : public IMouse {
public:
    void click() override {
        cout << "Clicking with an optical mouse." << endl;
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

    // Creating a MacBook and injecting dependencies
    MacBook macbook(&keyboard, &mouse);

    // Using the MacBook
    macbook.useKeyboard();
    macbook.useMouse();

    return 0;
}
