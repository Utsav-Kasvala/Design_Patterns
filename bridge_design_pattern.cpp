#include <iostream>
using namespace std;

// Implementation interface
class Breathing {
public:
    virtual void breathe() = 0;
    virtual ~Breathing() = default;
};

// Concrete Implementation 1
class Lungs : public Breathing {
public:
    void breathe() override {
        cout << "Breathing using lungs (takes in oxygen from air)" << endl;
    }
};

// Concrete Implementation 2
class Gills : public Breathing {
public:
    void breathe() override {
        cout << "Breathing using gills (extracts oxygen from water)" << endl;
    }
};

// Abstraction
class LivingThing {
protected:
    Breathing* breathingMethod;

public:
    LivingThing(Breathing* method) : breathingMethod(method) {}
    virtual void breathe() {
        breathingMethod->breathe();
    }
    virtual ~LivingThing() = default;
};

// Refined Abstraction 1
class Human : public LivingThing {
public:
    Human(Breathing* method) : LivingThing(method) {}
    void breathe() override {
        cout << "Human: ";
        breathingMethod->breathe();
    }
};

// Refined Abstraction 2
class Fish : public LivingThing {
public:
    Fish(Breathing* method) : LivingThing(method) {}
    void breathe() override {
        cout << "Fish: ";
        breathingMethod->breathe();
    }
};

// Test
int main() {
    Lungs lungs;
    Gills gills;

    Human human(&lungs);
    Fish fish(&gills);

    human.breathe();
    fish.breathe();

    return 0;
}
