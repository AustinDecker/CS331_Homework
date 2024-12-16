#include <iostream>

template <typename T>
T add(T a, T b) {
    return a + b;
}

int main() {
    std::cout << "Integers: " << add(3, 4) << std::endl;
    std::cout << "Floats: " << add(3.5, 4.2) << std::endl;

    return 0;
}

