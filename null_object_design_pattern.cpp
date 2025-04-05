#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Abstract base class for User
class User {
public:
    virtual string getName() = 0;
    virtual bool isNull() = 0;
    virtual ~User() {}
};

// Concrete class for a real, existing user
class RealUser : public User {
private:
    string name;
public:
    RealUser(const string& name) : name(name) {}

    string getName() override {
        return name;
    }

    bool isNull() override {
        return false;
    }
};

// Null object class for a non-existent user
class NullUser : public User {
public:
    string getName() override {
        return "Not Available in User Database";
    }

    bool isNull() override {
        return true;
    }
};

// Factory/Provider for returning User objects
class UserFactory {
private:
    static vector<string> names;

public:
    static User* getUser(const string& name) {
        for (const string& n : names) {
            if (n == name)
                return new RealUser(name);
        }
        return new NullUser();  // Return Null object instead of nullptr
    }
};

// Predefined user list
vector<string> UserFactory::names = {"Utsav", "Riya", "Amit"};

int main() {
    User* user1 = UserFactory::getUser("Utsav");
    User* user2 = UserFactory::getUser("Unknown");

    cout << "User 1: " << user1->getName() << endl;
    cout << "User 2: " << user2->getName() << endl;

    // Cleanup
    delete user1;
    delete user2;

    return 0;
}
