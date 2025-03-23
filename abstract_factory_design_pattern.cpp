#include <iostream>
using namespace std;

// ======================== Abstract Car Classes ==========================

// Abstract base class for luxury cars
class luxurycar {
public:
    virtual void drive() = 0;  // Pure virtual function to enforce implementation in derived classes
    virtual ~luxurycar() {}    // Virtual destructor to ensure proper cleanup of derived objects
};

// Abstract base class for ordinary cars
class ordinarycar {
public:
    virtual void drive() = 0;  // Pure virtual function
    virtual ~ordinarycar() {}  // Virtual destructor
};

// ======================== Concrete Car Implementations ==========================

// Concrete class representing a BMW (Luxury Car)
class bmw : public luxurycar {
public:
    void drive() {
        cout << "Driving BMW" << endl;
    }
};

// Concrete class representing a Mercedes (Luxury Car)
class mercedes : public luxurycar {
public:
    void drive() {
        cout << "Driving Mercedes" << endl;
    }
};

// Concrete class representing a Swift (Ordinary Car)
class swift : public ordinarycar {
public:
    void drive() {
        cout << "Driving Swift" << endl;
    }
};

// Concrete class representing a Creta (Ordinary Car)
class creta : public ordinarycar {
public:
    void drive() {
        cout << "Driving Creta" << endl;
    }
};

// ======================== Abstract Factory Class ==========================

// Abstract Factory class that serves as a blueprint for car factories
class CarFactory {
public:
    // Virtual function to create luxury cars (returns nullptr by default)
    virtual luxurycar* createluxuryCar(string type) { return nullptr; }

    // Virtual function to create ordinary cars (returns nullptr by default)
    virtual ordinarycar* createOrdinaryCar(string type) { return nullptr; }

    // Static function to create an instance of a specific factory type
    static CarFactory* CreatecarFactory(string type);
};

// ======================== Concrete Factory Implementations ==========================

// Concrete factory class to create luxury cars
class luxurycarfactory : public CarFactory {
public:
    // Creates a luxury car based on the requested type
    luxurycar* createluxuryCar(string type) override {
        if (type == "bmw") return new bmw();       // Creates a BMW object
        if (type == "mercedes") return new mercedes(); // Creates a Mercedes object
        return nullptr;  // Returns nullptr if the car type is invalid
    }
};

// Concrete factory class to create ordinary cars
class ordinarycarfactory : public CarFactory {
public:
    // Creates an ordinary car based on the requested type
    ordinarycar* createOrdinaryCar(string type) override {
        if (type == "swift") return new swift();   // Creates a Swift object
        if (type == "creta") return new creta();   // Creates a Creta object
        return nullptr;  // Returns nullptr if the car type is invalid
    }
};

// ======================== Factory Creator Method ==========================

// Static method to create a specific car factory based on input type
CarFactory* CarFactory::CreatecarFactory(string type) {
    if (type == "luxury") {
        return new luxurycarfactory();  // Returns a luxury car factory
    } else if (type == "ordinary") {
        return new ordinarycarfactory();  // Returns an ordinary car factory
    } else {
        return nullptr;  // Returns nullptr if the factory type is invalid
    }
}

// ======================== Main Function (Test the Factory Pattern) ==========================

int main() {
    // Create a factory for luxury cars
    CarFactory* factory = CarFactory::CreatecarFactory("luxury");

    // Ensure the factory was created successfully
    if (factory) {
        // Create a luxury car (Mercedes) and call its drive function
        luxurycar* myLuxuryCar = factory->createluxuryCar("mercedes");
        if (myLuxuryCar) {
            myLuxuryCar->drive();  // Output: "Driving Mercedes"
            delete myLuxuryCar;  // Prevent memory leak
        }

        // Clean up the factory instance
        delete factory;
    }

    return 0;
}
