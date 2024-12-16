// Solution: Problem 2

#include <iostream>
using namespace std;

// Function to calculate the area by value
double calculateAreaByValue(double length, double width) {
    return length * width;
}

// Function to update the dimensions by reference
void updateDimensions(double &length, double &width) {
    double newLength, newWidth;
    cout << "Enter the new length: ";
    cin >> newLength;
    cout << "Enter the new width: ";
    cin >> newWidth;

    // no negative values are accepted
    if (newLength < 0 || newWidth < 0) {
        cout << "Warning: Negative values are not allowed. Dimensions remain unchanged." << endl;
    } else {
        length = newLength;
        width = newWidth;
    }
}

int main() {
    double length, width;

    cout << "Enter the length of the rectangle: ";
    cin >> length;
    cout << "Enter the width of the rectangle: ";
    cin >> width;

    // display initial area
    double area = calculateAreaByValue(length, width);
    cout << "The area of the rectangle is: " << area << endl;

    // update dimensions
    updateDimensions(length, width);

    // display updated area
    area = calculateAreaByValue(length, width);
    cout << "The updated area of the rectangle is: " << area << endl;

    return 0;
}

//Solution problem 4

#include <iostream>
using namespace std;

int main() {
    int size1, size2;

    // Prompt user for sizes of the two arrays
    cout << "Enter the size of the first array: ";
    cin >> size1;
    cout << "Enter the size of the second array: ";
    cin >> size2;

    // Dynamic memory allocation for the two arrays and the merged array
    int* arr1 = new int[size1];
    int* arr2 = new int[size2];
    int* merged = new int[size1 + size2];

    // Input elements for the first array
    cout << "Enter elements of the first array:\n";
    for (int i = 0; i < size1; i++) {
        cout << "Element " << i + 1 << ": ";
        cin >> arr1[i];
    }

    // Input elements for the second array
    cout << "Enter elements of the second array:\n";
    for (int i = 0; i < size2; i++) {
        cout << "Element " << i + 1 << ": ";
        cin >> arr2[i];
    }

    // Merge arrays
    for (int i = 0; i < size1; i++) {
        merged[i] = arr1[i];
    }
    for (int i = 0; i < size2; i++) {
        merged[size1 + i] = arr2[i];
    }

    // Display merged array
    cout << "Merged array: ";
    for (int i = 0; i < size1 + size2; i++) {
        cout << merged[i] << " ";
    }
    cout << endl;

    // Free allocated memory
    delete[] arr1;
    delete[] arr2;
    delete[] merged;

    return 0;
}

