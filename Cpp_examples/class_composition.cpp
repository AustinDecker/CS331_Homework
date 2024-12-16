#include <iostream>
#include <string>

// Component Class: Engine
class Engine {
    int horsepower;

public:
    Engine(int hp) : horsepower(hp) {}

    void start() const {
        std::cout << "Engine with " << horsepower << " HP starts.\n";
    }
};

// Component Class: Wheels
class Wheels {
    int count;

public:
    Wheels(int count) : count(count) {}

    void roll() const {
        std::cout << count << " wheels are rolling.\n";
    }
};

// Composite Class: Car
class Car {
    std::string brand;
    Engine engine; // Engine is part of Car
    Wheels wheels; // Wheels are part of Car

public:
    Car(const std::string& brand, int hp, int wheelCount)
        : brand(brand), engine(hp), wheels(wheelCount) {}

    void drive() const {
        std::cout << "Driving a " << brand << " car.\n";
        engine.start();
        wheels.roll();
    }
};

int main() {
    Car myCar("Toyota", 150, 4);
    myCar.drive();

    return 0;
}
