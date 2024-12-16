//example1

#include <iostream>
using namespace std;

double volume( double radius, double height );
void display( double volume);

int main() {
    double radius;
    double height;
    cout << "Enter radius and height of cylinder: ";
    cin >> radius >> height;
    display(volume(radius, height));
    return 0;
}

// Function to calculate the volume of a cylinder
double volume(double radius, double height) {
    return 3.141592653589793238 * radius * radius * height;
}

// Function to display the volume
void display(double vol) {
    cout << "The volume of the cylinder is: " << vol << endl;
}

//example 2


#include <iostream>
using namespace std;

// Function that takes an integer by value
void increment(int x) {
    x = x + 1;
    cout << "Inside function: " << x << endl;
}

int main() {
    int a = 5;
    increment(a); // Pass by value
    cout << "Outside function: " << a << endl; // a remains unchanged
    return 0;
}


//example 3

#include <iostream>
using namespace std;

// Function that takes an integer by reference
void increment(int &x) {
    x = x + 1;
    cout << "Inside function: " << x << endl;
}

int main() {
    int a = 5;
    increment(a); // Pass by reference
    cout << "Outside function: " << a << endl; // a is modified
    return 0;
}


//example 4

#include <iostream>
using namespace std;

void max3(int &max, int x);

int main()
{
   int n;
   int biggest = 0;  // Initialize biggest to a small number or 0
   for(;;) {
      cin >> n;
      if (n == 999) break;  // Stop input if the user enters 999
      max3(biggest, n);     // Update the biggest value if necessary
   }
   cout << "The largest number entered is: " << biggest << endl;
   return 0;
}

void max3(int &max, int x)
{
   if (x > max) 
   {  
      max = x;  // Update max if the current number is greater
   }
}

// example 4

#include <iostream>
using namespace std;

void swap(float &a, float &b);

int main()
{
   float f1, f2, f3;
   cout << "Enter three float values: ";
   cin >> f1 >> f2 >> f3;

   if (f2 < f1)
      swap(f1, f2);  // Ensure f1 is the smallest of the first two
   if (f3 < f1)
      swap(f1, f3);  // Ensure f1 is the smallest of all three
   if (f3 < f2)
      swap(f2, f3);  // Ensure f2 is smaller than or equal to f3

   cout << "Sorted values: " << f1 << ", " << f2 << ", " << f3 << endl;

   return 0;
}

void swap(float &a, float &b)
{
   float temp = a;
   a = b;
   b = temp;
}


// example 5

#include <iostream>  // Use <iostream> instead of <iostream.h>
using namespace std;

void inc1(int &);
void inc2(int &);

int main() {
    int x = 0;
    cout << "x before call of inc1 is " << x << endl;
    inc1(x);
    cout << "x after call of inc1 is " << x << endl;
    return 0;
}

void inc1(int &x) {
    x++;
    cout << "x before call of inc2 is " << x << endl;
    inc2(x);
    cout << "x after call of inc2 is " << x << endl;
}

void inc2(int &x) {
    x++;
    cout << "x in inc2 is " << x << endl;
}

// example 6

#include <iostream>  // Correct the header file

void inc1(int x);    // Function declaration: passing by value
void inc2(int &x);   // Function declaration: passing by reference

int main() {
    int x = 0;
    std::cout << "x before call of inc1 is " << x << std::endl;
    inc1(x);
    std::cout << "x after call of inc1 is " << x << std::endl;
    return 0;
}

void inc1(int x) {   // Definition of inc1, x is passed by value
    x++;
    std::cout << "x before call of inc2 is " << x << std::endl;
    inc2(x);  // Even though x is passed by reference in inc2, it's still a copy
    std::cout << "x after call of inc2 is " << x << std::endl;
}

void inc2(int &x) {  // Definition of inc2, x is passed by reference
    x++;
    std::cout << "x in inc2 is " << x << std::endl;
}


// example 7

#include <iostream>

void inc1(int &);
void inc2(int);

int main() {
    int x = 0;
    std::cout << "x before call of inc1 is " << x << std::endl;
    inc1(x);
    std::cout << "x after call of inc1 is " << x << std::endl;
    return 0;
}

void inc1(int &x) {
    x++;
    std::cout << "x before call of inc2 is " << x << std::endl;
    inc2(x);
    std::cout << "x after call of inc2 is " << x << std::endl;
}

void inc2(int x) {
    x++;
    std::cout << "x in inc2 is " << x << std::endl;
}

// example 8

#include <iostream>

int& dangerousFunction() {
    int localVar = 42; // Automatic (local) variable
    return localVar;    // Returning a reference to localVar
}

int& safeFunction() {
    static int staticVar = 42; // Static variable
    return staticVar;           // Returning a reference to staticVar
}

int main() {
    int &dangerousRef = dangerousFunction(); // Dangling reference
    int &safeRef = safeFunction();           // Safe reference

    // dangerousRef now holds a reference to deallocated memory
    // Accessing it may cause undefined behavior
    std::cout << "Dangerous Reference: " << dangerousRef << std::endl;

    // safeRef holds a valid reference
    std::cout << "Safe Reference: " << safeRef << std::endl;

    return 0;
}

// example 9 

#include <iostream>

void exampleFunction(int a, int b = 20, int c = 30) {
    std::cout << "a: " << a << ", b: " << b << ", c: " << c << std::endl;
}

int main() {
    exampleFunction(10);          // Output: a: 10, b: 20, c: 30
    exampleFunction(10, 50);      // Output: a: 10, b: 50, c: 30
    exampleFunction(10, , 60);    // Error: Syntax error
    return 0;
}

// example 10

#include <iostream>

// Function to add two integers
int add(int a, int b) {
    return a + b;
}

// Function to add three integers
int add(int a, int b, int c) {
    return a + b + c;
}

// Function to add two floating-point numbers
double add(double a, double b) {
    return a + b;
}

int main() {
    // Calling different versions of the overloaded function
    std::cout << "Sum of two integers (3 + 4): " << add(3, 4) << std::endl;
    std::cout << "Sum of three integers (1 + 2 + 3): " << add(1, 2, 3) << std::endl;
    std::cout << "Sum of two floating-point numbers (2.5 + 3.5): " << add(2.5, 3.5) << std::endl;

    return 0;
}

//example 11

#include <iostream>

// Function with int first, double second
void print(int a, double b) {
    std::cout << "Integer: " << a << ", Double: " << b << std::endl;
}

// Function with double first, int second
void print(double a, int b) {
    std::cout << "Double: " << a << ", Integer: " << b << std::endl;
}

int main() {
    print(5, 7.5);    // Calls the function with int, double
    print(7.5, 5);    // Calls the function with double, int

    return 0;
}


// example 12

#include <iostream>  // Include the iostream header for input and output operations

// Inline function to calculate the cube of a number
inline double cube(const double side) {
    return side * side * side;  // Calculate and return the cube of the side
}

int main() {
    double sidevalue;  // Declare a variable to store the side length of the cube

    // Prompt the user to enter the side length
    std::cout << "Enter the side length of your cube: ";
    std::cin >> sidevalue;  // Read the side length from the user

    // Display the volume of the cube
    std::cout << "The volume of the cube with side " << sidevalue << " is " 
              << cube(sidevalue) << std::endl;

    return 0;  // Indicate successful completion of the program
}

// example 13

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

// Function declarations
int whiteBall();
int powerBall();

int main() {
    int i;
    char ans = 'y';  // Initialize the variable to enter the loop
    srand(time(0));  // Seed the random number generator
    
    while (ans == 'y') {
        // Generate and display five white ball numbers
        for (i = 1; i <= 5; i++) {
            cout << setw(4) << whiteBall();
        }
        cout << " PB " << powerBall() << endl;  // Display the PowerBall number
        
        // Prompt user for more entries
        cout << "Would you like another quick pick? (y/n): ";
        cin >> ans;
    }
    
    return 0;
}

// Function definitions
int whiteBall() {
    return 1 + rand() % 49;  // Return a random number between 1 and 49
}

int powerBall() {
    return 1 + rand() % 42;  // Return a random number between 1 and 42
}

// exampole 14

#include <iostream>
#include <cstdlib>

#ifndef HEAD_H
#define HEAD_H

// Function declarations
int createZipcode(void);
int correctionDigitOf(int);
void extract(int, int&, int&, int&, int&, int&);

#endif // HEAD_H
