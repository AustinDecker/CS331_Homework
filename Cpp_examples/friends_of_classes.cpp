#include <iostream>

class Box {
    int width;

public:
    Box(int w) : width(w) {}
    friend void printWidth(const Box& b);
};

void printWidth(const Box& b) {
    std::cout << "Width: " << b.width << std::endl;
}

int main() {
    Box b(50);
    printWidth(b);
    return 0;
}
