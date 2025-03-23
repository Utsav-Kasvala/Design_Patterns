// BEHAVIOURAL DESIGN PATTERN

#include <bits/stdc++.h>
using namespace std;


// Strategy Interface: Defines an abstract drive method
class Drivestrategy {
public:
    virtual void drive() = 0;  // Pure virtual function for driving behavior
    virtual ~Drivestrategy() {} // Virtual destructor for proper cleanup
};

// Concrete Strategy 1: Implements normal driving behavior
class Normaldrive : public Drivestrategy {
public:
    void drive() {
        cout << "Normal Drive\n";
    }
};

// Concrete Strategy 2: Implements sports driving behavior
class Sportsdrive : public Drivestrategy {
public:
    void drive() {
        cout << "Sports Drive\n";
    }
};

// Concrete Strategy 3: Implements special driving behavior
class Specialdrive : public Drivestrategy {
public:
    void drive() {
        cout << "Special Drive\n";
    }
};

// Context Class: Vehicle
// This class allows setting different driving strategies at runtime.
class Vehicle {
public:
    Drivestrategy* obj; // Pointer to the current driving strategy

    // Method to set a driving strategy dynamically
    void setdrive(Drivestrategy* selectedobj) {
        obj = selectedobj;
    }

    // Method to execute the current strategy's drive function
    void showdrive() {
        if (obj) obj->drive();
    }

    // Destructor to prevent memory leaks
    ~Vehicle() {
        if (obj) delete obj;
    }
};

int main() {
    // Creating a vehicle object
    Vehicle* car = new Vehicle();

    // Creating a special driving strategy and setting it to the car
    Drivestrategy* special = new Specialdrive();
    car->setdrive(special);
    
    // Display the driving strategy
    car->showdrive();

    // Cleanup
    delete car;

    return 0;
}
