#include <iostream>
#include <string>
using namespace std;

// Product class
class House {
public:
    string walls;
    string roof;
    string windows;

    void show() {
        cout << "House with: " << walls << ", " << roof << ", " << windows << endl;
    }
};

// Abstract Builder
class HouseBuilder {
public:
    virtual void buildWalls() = 0;
    virtual void buildRoof() = 0;
    virtual void buildWindows() = 0;
    virtual House* getHouse() = 0;
    virtual ~HouseBuilder() = default;
};

// Concrete Builder 1
class WoodenHouseBuilder : public HouseBuilder {
private:
    House* house;
public:
    WoodenHouseBuilder() { house = new House(); }

    void buildWalls() override {
        house->walls = "Wooden Walls";
    }

    void buildRoof() override {
        house->roof = "Wooden Roof";
    }

    void buildWindows() override {
        house->windows = "Glass Windows";
    }

    House* getHouse() override {
        return house;
    }
};

// Concrete Builder 2
class BrickHouseBuilder : public HouseBuilder {
private:
    House* house;
public:
    BrickHouseBuilder() { house = new House(); }

    void buildWalls() override {
        house->walls = "Brick Walls";
    }

    void buildRoof() override {
        house->roof = "Concrete Roof";
    }

    void buildWindows() override {
        house->windows = "Aluminium Windows";
    }

    House* getHouse() override {
        return house;
    }
};

// Director class
class Engineer {
private:
    HouseBuilder* builder;
public:
    Engineer(HouseBuilder* b) : builder(b) {}

    void constructHouse() {
        builder->buildWalls();
        builder->buildRoof();
        builder->buildWindows();
    }

    House* getHouse() {
        return builder->getHouse();
    }
};

// Test
int main() {
    // Build a wooden house
    WoodenHouseBuilder woodenBuilder;
    Engineer engineer1(&woodenBuilder);
    engineer1.constructHouse();
    House* woodenHouse = engineer1.getHouse();
    woodenHouse->show();

    // Build a brick house
    BrickHouseBuilder brickBuilder;
    Engineer engineer2(&brickBuilder);
    engineer2.constructHouse();
    House* brickHouse = engineer2.getHouse();
    brickHouse->show();

    return 0;
}
