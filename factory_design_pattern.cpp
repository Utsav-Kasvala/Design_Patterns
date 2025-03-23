#include <bits/stdc++.h>  // Includes all standard C++ libraries
using namespace std;

// Abstract base class representing a generic shape
class Shape {
public:
    // Pure virtual function that must be implemented by derived classes
    virtual void draw() = 0;  
};

// Derived class representing a Circle
class circle : public Shape {
public:
    // Implementation of the draw function for Circle
    void draw() {
        cout << "circle\n";
    }
};

// Derived class representing a Square
class square : public Shape {
public:
    // Implementation of the draw function for Square
    void draw() {
        cout << "square\n";
    }
};

// Factory class responsible for creating Shape objects
class Factory {
public:
    // Constructor (currently does nothing, but can be extended)
    Factory() {}

    // Function to create and return a Shape object based on input string
    Shape* createshape(string s) {
        if (s == "square") {
            return new square();  // Return a new Square object
        } else if (s == "circle") {
            return new circle();  // Return a new Circle object
        } else {
            return NULL;  // Return NULL if shape type is unknown
        }
    }
};

int main() {
    Factory* factory = new Factory();  // Create a Factory object

    // Create Shape objects using the factory
    Shape* square = factory->createshape("square");
    Shape* circle = factory->createshape("circle");

    // Call the draw function for each shape
    square->draw();
    circle->draw();

    // Free allocated memory to prevent memory leaks
    delete factory;
    delete circle;
    delete square;

    return 0;
}
