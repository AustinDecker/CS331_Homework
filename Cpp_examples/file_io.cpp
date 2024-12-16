#include <iostream>
#include <fstream>
#include <string>

void writeToFile(const std::string& filename) {
    std::ofstream outFile(filename, std::ios::out | std::ios::app); // Open file in append mode
    if (!outFile) {
        std::cerr << "Error: Unable to open file for writing.\n";
        return;
    }
    outFile << "This is a test file.\n";
    outFile << "Appending a new line.\n";
    std::cout << "Data written to " << filename << "\n";
}

void readFromFile(const std::string& filename) {
    std::ifstream inFile(filename, std::ios::in); // Open file for reading
    if (!inFile) {
        std::cerr << "Error: Unable to open file for reading.\n";
        return;
    }

    std::string line;
    std::cout << "Contents of " << filename << ":\n";
    while (std::getline(inFile, line)) {
        std::cout << line << std::endl;
    }
}

int main() {
    const std::string filename = "example.txt";

    // Write to file
    writeToFile(filename);

    // Read from file
    readFromFile(filename);

    return 0;
}
