#include <bits/stdc++.h>
using namespace std;

class Order; // Forward declaration of Order class

// Observer Interface: Defines an update method that observers must implement
class Observer {
public:
    virtual void update(Order* order) = 0; // Pure virtual function
};

// Subject Class (Observable): Order
class Order {
private:
    int id;                    // Unique order ID
    string status;              // Order status
    vector<Observer*> observers; // List of observers (subscribers)

public:
    // Constructor initializes the order with an ID and default status
    Order(int id) : id(id), status("Order Placed") {}

    // Setter for order ID
    void setid(int id) {
        this->id = id;
    }

    // Setter for order status (triggers notification to observers)
    void setstatus(string status) {
        this->status = status;
        notifyObservers(); // Notify all observers about the status change
    }

    // Getter for order ID
    int getid() {
        return id;
    }

    // Getter for order status
    string getstatus() {
        return status;
    }

    // Method to add an observer to the list
    void add(Observer* observer) {
        observers.push_back(observer);
    }

    // Notify all observers about the status change
    void notifyObservers() {
        for (Observer* observer : observers) {
            observer->update(this); // Call update method of each observer
        }
    }
};

// Concrete Observer 1: Driver
class driver : public Observer {
private:
    string name; // Driver's name
public:
    driver(string name) : name(name) {}

    // Update method is called when the order status changes
    void update(Order* order) {
        cout << name << " received update: Order " << order->getid() << " is " << order->getstatus() << "\n";
    }
};

// Concrete Observer 2: Customer
class customer : public Observer {
private:
    string name; // Customer's name
public:
    customer(string name) : name(name) {}

    // Update method is called when the order status changes
    void update(Order* order) {
        cout << name << " received update: Order " << order->getid() << " is " << order->getstatus() << "\n";
    }
};

// Main function demonstrating the Observer pattern in action
int main() {
    // Create an order with ID 1
    Order order1(1);

    // Change order status (no observers yet)
    order1.setstatus("Order Freezed");

    // Create observers (Driver and Customer)
    driver driver1("Suresh");
    customer customer1("Utsav");

    // Attach observers to the order
    order1.add(&driver1);
    order1.add(&customer1);

    // Change order status, which will notify all observers
    order1.setstatus("Order Delivered");

    return 0;
}
