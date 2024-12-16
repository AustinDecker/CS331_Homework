// write the code for a bank account
//write the code for a circle
// write the rectangle code

// Example 1

#include <iostream>
#include <cmath> // For M_PI
using namespace std;

// Circle class declaration
class Circle
{
  private:
      double radius;

  public:
      // Constructor to initialize the radius
      Circle(double r = 0) : radius(r) {}

      void setRadius(double r)
      {
          radius = r;
      }

      double calcArea()
      {
          return M_PI * pow(radius, 2);  // Use M_PI for a more accurate value of pi
      }
};

int main()
{
   // Define 2 Circle objects with default radius
   Circle circle1, circle2;

   // Call the setRadius function for each circle
   circle1.setRadius(1);    // This sets circle1's radius to 1.0
   circle2.setRadius(2.5);  // This sets circle2's radius to 2.5

   // Call the calcArea function for each circle and
   // display the returned result
   cout << "The area of circle1 is " << circle1.calcArea() << endl;
   cout << "The area of circle2 is " << circle2.calcArea() << endl;

   return 0;
}

// This program demonstrates a simple class with member functions
// defined outside the class declaration.
#include <iostream>
#include <cmath>  // For M_PI
using namespace std;

// Circle class declaration
class Circle
{  
  private:
      double radius;              // This is a member variable.

  public:
      void  setRadius(double);    // These are just prototypes
      double calcArea();          // for the member functions.
};

// The member function implementation section follows. It contains the
// actual function definitions for the Circle class member functions.

/*******************************************************************  
 *                       Circle::setRadius                         *  
 *  This function copies the argument passed into the parameter to *  
 *  the private member variable radius.                            *  
 *******************************************************************/  
void Circle::setRadius(double r)
{
    radius = r;
}

/******************************************************************  
 *                        Circle::calcArea                        *  
 * This function calculates and returns the Circle object's area. *  
 * It does not need any parameters because it already has access  *  
 * to the member variable radius.                                 *  
 ******************************************************************/  
double Circle::calcArea()
{
    return M_PI * pow(radius, 2);  // Use M_PI for a more accurate value of pi
}

/****************************************************************  
 *                            main                              *  
 ****************************************************************/
int main()
{
    Circle circle1,               // Define 2 Circle objects
           circle2;

    circle1.setRadius(1);         // This sets circle1's radius to 1.0
    circle2.setRadius(2.5);       // This sets circle2's radius to 2.5

                                  // Get and display each circle's area
    cout << "The area of circle1 is " << circle1.calcArea() << endl;
    cout << "The area of circle2 is " << circle2.calcArea() << endl;

    return 0;
}


// This program implements a Rectangle class.
#include <iostream>
using namespace std;

// Rectangle class declaration
class Rectangle
{
  private:
      double length;
      double width;

  public:
      // Constructor to initialize the default values
      Rectangle() : length(1.0), width(1.0) {}

      void setLength(double);
      void setWidth(double);
      double getLength();
      double getWidth();
      double calcArea();
};

// Member function implementation section

/********************************************************************  
 *                     Rectangle::setLength                         *  
 * This function sets the value of the member variable length.      *  
 * If the argument passed to the function is zero or greater, it is *  
 * copied into length. If it is negative, 1.0 is assigned to length.*  
 ********************************************************************/
void Rectangle::setLength(double len)
{
    if (len >= 0.0)
        length = len;
    else
    {
        length = 1.0;
        cout << "Invalid length. Using a default value of 1.0\n";
    }
}

/********************************************************************  
 *                      Rectangle::setWidth                         *  
 * This function sets the value of the member variable width.       *  
 * If the argument passed to the function is zero or greater, it is *  
 * copied into width. If it is negative, 1.0 is assigned to width.  *  
 ********************************************************************/
void Rectangle::setWidth(double w)
{
    if (w >= 0.0)
        width = w;
    else
    {
        width = 1.0;
        cout << "Invalid width. Using a default value of 1.0\n";
    }
}

/**************************************************************  
 *                     Rectangle::getLength                   *  
 * This function returns the value in member variable length. *  
 **************************************************************/
double Rectangle::getLength()
{
    return length;
}

/**************************************************************  
 *                     Rectangle::getWidth                    *  
 * This function returns the value in member variable width.  *  
 **************************************************************/
double Rectangle::getWidth()
{
    return width;
}

/*******************************************************************  
 *                        Rectangle::calcArea                      *  
 * This function calculates and returns the area of the rectangle. *  
 *******************************************************************/
double Rectangle::calcArea()
{
    return length * width;
}

/*************************************************************  
 *                            main                           *  
 *************************************************************/
int main()
{
    Rectangle box;         // Declare a Rectangle object
    double boxLength, boxWidth;

    // Get box length and width
    cout << "This program will calculate the area of a rectangle.\n";
    cout << "What is the length? ";
    cin  >> boxLength;
    cout << "What is the width? ";
    cin  >> boxWidth;

    // Call member functions to set box dimensions
    box.setLength(boxLength);
    box.setWidth(boxWidth);

    // Call member functions to get box information to display
    cout << "\nHere is the rectangle's data:\n";
    cout << "Length: " << box.getLength() << endl;
    cout << "Width : " << box.getWidth()  << endl;
    cout << "Area  : " << box.calcArea()  << endl;

    return 0;
}


// This program demonstrates when a constructor executes.
#include <iostream>  
using namespace std;

class Demo  
{  
  public:  
    Demo()  // Constructor  
    {  
       cout << "Now the constructor is running.\n";  
    }  
};  
  
int main()  
{  
    cout << "This is displayed before the object is created.\n";  
  
    Demo demoObj;  // Define a Demo object  
  
    cout << "This is displayed after the object is created.\n";  
    return 0;  
}


// This program uses a constructor to initialize a member variable.
#include <iostream>
#include <cmath>  // For pow() and M_PI
using namespace std;

// Circle class declaration
class Circle
{
  private:
      double radius;

  public:
      Circle();          // Constructor
      void setRadius(double);
      double calcArea();
};

// Circle member function implementation section

/********************************************  
 *             Circle::Circle               *  
 * This is the constructor. It initializes  *  
 * the radius class member variable.        *  
 ********************************************/
Circle::Circle()
{
    radius = 1.0;
}

/********************************************  
 *             Circle::setRadius            *  
 * This function validates the value passed *  
 * to it before assigning it to the radius  *  
 * member variable.                         *  
 ********************************************/
void Circle::setRadius(double r)
{
    if (r >= 0.0)
        radius = r;
    // else leave it set to its previous value
}

/**********************************************  
 *               Circle::calcArea             *  
 * This function calculates and returns the   *  
 * Circle object's area.                      *  
 **********************************************/
double Circle::calcArea()
{
    return M_PI * pow(radius, 2);  // Using M_PI for better precision
}

/********************************************  
 *               main                       *  
 * The main function creates and uses       *  
 * Circle objects.                          *  
 ********************************************/
int main()
{
    // Define a Circle object. It will use the constructor's value.
    Circle circle1;

    // Define a second Circle object and set its radius to 2.5
    Circle circle2;
    circle2.setRadius(2.5);

    // Get and display each circle's area
    cout << "The area of circle1 is " << circle1.calcArea() << endl;
    cout << "The area of circle2 is " << circle2.calcArea() << endl;

    return 0;
}



