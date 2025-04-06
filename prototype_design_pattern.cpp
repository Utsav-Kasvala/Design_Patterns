#include <iostream>
#include <string>
using namespace std;

// Prototype Interface
class Animal {
public:
    virtual Animal* clone() = 0;
    virtual void makeSound() = 0;
    virtual ~Animal() = default;
};

// Concrete Prototype 1
class Dog : public Animal {
public:
    Dog() { cout << "Dog created" << endl; }

    Animal* clone() override {
        cout << "Cloning Dog..." << endl;
        return new Dog(*this); // copy constructor
    }

    void makeSound() override {
        cout << "Woof! Woof!" << endl;
    }
};

// Concrete Prototype 2
class Cat : public Animal {
public:
    Cat() { cout << "Cat created" << endl; }

    Animal* clone() override {
        cout << "Cloning Cat..." << endl;
        return new Cat(*this); // copy constructor
    }

    void makeSound() override {
        cout << "Meow! Meow!" << endl;
    }
};

// Test
int main() {
    Animal* originalDog = new Dog();
    originalDog->makeSound();

    Animal* clonedDog = originalDog->clone();
    clonedDog->makeSound();

    cout << endl;

    Animal* originalCat = new Cat();
    originalCat->makeSound();

    Animal* clonedCat = originalCat->clone();
    clonedCat->makeSound();

    delete originalDog;
    delete clonedDog;
    delete originalCat;
    delete clonedCat;

    return 0;
}
