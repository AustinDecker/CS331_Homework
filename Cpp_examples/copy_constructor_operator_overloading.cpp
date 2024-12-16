#include <iostream>

class Number {
    int value;

public:
    Number(int val) : value(val) {}
    Number(const Number& other) : value(other.value) { // Copy constructor
        std::cout << "Copy constructor called\n";
    }
    Number& operator=(const Number& other) { // Assignment operator
        if (this != &other) {
            value = other.value;
        }
        return *this;
    }

    void display() const { std::cout << "Value: " << value << std::endl; }
};

int main() {
    Number num1(100);
    Number num2 = num1; // Copy constructor
    num2.display();

    Number num3(200);
    num3 = num1; // Assignment operator
    num3.display();

    return 0;
}
