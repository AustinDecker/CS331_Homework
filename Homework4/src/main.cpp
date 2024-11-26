#include <iostream>
#include <string>
#include <cmath>


//Problem 1
class Employee {
    private: 
        unsigned int employeeID;
        std::string employeeName;
        unsigned long basicSalary;
    
    public:
        //getter methods to access employee details
        unsigned int getEmployeeID() {
            return this->employeeID;
        }

        const std::string & getEmployeeName() {
            return this->employeeName;
        }

        unsigned long getEmployeeSalary() {
            return this->basicSalary;
        }

        //function methods
        void displayDetails() {
            std::cout << "Employee no: " << std::to_string(this->getEmployeeID()) << "\n"
            << "Name: " << this->getEmployeeName() << "\n"
            << "Salary: $" << std::to_string(this->getEmployeeSalary()) 
            << "\n" << std::endl;
        }

        //constructor
        Employee (unsigned int id, const std::string & name, unsigned long salary = 50000) 
            : employeeID{id},
              employeeName{name},
              basicSalary{salary} {};
};

//Manager inherits from Employee
class Manager : public Employee {
    private: 
        unsigned long bonus;

    public:

        unsigned long getBonus() {
            return this->bonus;
        }

        //modified displayDetails method
        void displayDetails() {
            std::cout << "Employee no: " << std::to_string(this->getEmployeeID()) << "\n"
            << "Name: " << this->getEmployeeName() << "\n"
            << "Bonus: $" << std::to_string(this->getBonus()) << "\n"
            << "Base Salary: $" << std::to_string(this->getEmployeeSalary()) << "\n"
            << "Total Salary: $" << std::to_string(this->getEmployeeSalary() + this->getBonus()) 
            << "\n" << std::endl;
        }

        //uses the Employee constructor to initialize the values then initilizes the unique bonus value
        Manager(unsigned int id, const std::string & name, unsigned long salary, unsigned long bonus) 
            : Employee (id, name, salary),
              bonus{bonus} {};
};

class Shape {
    private:
        std::string shapeName;
    
    public: 
        const std::string & getName() {
            return this->shapeName;
        }

        virtual double calculateArea () = 0;

        void display() {

            std::cout << this->getName() << "\n" << std::endl;
        }

        Shape(const std::string & name) : shapeName{name} {};
};

class Rectangle: public Shape {
    private:
        int length;
        int width;
    public:

        int getLength() {
            return this->length;
        }

        int getWidth() {
            return this->width;
        }

        double calculateArea() override {
            return this->getLength() * this->getWidth();
        }

        void display() {
           std::cout << this->getName() << "\n" 
           << "Length: " << std::to_string(this->getLength()) << "\tWidth: " << std::to_string(this->getWidth()) << "\n" 
           << "Area: " << std::to_string(this->calculateArea()) 
           << "\n" << std::endl;
        }

        Rectangle (int length, int width) : Shape("Rectangle"), length{length}, width{width} {};

};

class Circle: public Shape {
    private:
        const double PI = 3.14159265358979323846;
        int radius;
        
    public:

        int getRadius() {
            return this->radius;
        }

        double calculateArea() override {
            return  PI * std::pow(this->getRadius(), 2);
        }

        void display() {
           std::cout << this->getName() << "\n" 
           << "Radius: " << std::to_string(this->getRadius()) << "\n" 
           << "Area: " << std::to_string(this->calculateArea()) 
           << "\n" << std::endl;
        }

        Circle (int radius) : Shape("Circle"), radius{radius} {};

};

int main(){
    //Problem 1
    Employee employeeA {1, "John Smith"};
    Employee employeeB {2, "Samuel Adams"};
    Manager managerA {3, "Bob Frank", 100000, 25000};
    Manager managerB {4, "Sarah Smith", 95000, 25000};

    //displaying details
    employeeA.displayDetails();
    employeeB.displayDetails();
    managerA.displayDetails();
    managerB.displayDetails();

    //Problem 2
    Rectangle rect{45, 25};
    Circle circle{25};

    //displaying details 
    //calculateArea is runned internally in display details
    rect.display();
    circle.display();

    //Problem 3
    /*
        When a pointer to a base class is used to call a member function that 
        has been overridden in a derived class, the default behavior in C++ is 
        determined by whether the function in the base class is declared as virtual.

        If the function in the base class is not declared as virtual, calling the 
        function through a base class pointer will invoke the base class version of 
        the function, even if the pointer actually points to an object of the derived class.

        If the function in the base class is declared as virtual, calling the function through 
        a base class pointer will invoke the derived class version of the function, provided 
        that the pointer points to an object of the derived class.
    */
   //problem 3 example
   Shape* myShapePtr;
   Rectangle myRect{5, 25};

   myShapePtr = &myRect;

   //calling a virtual function
   std::cout << std::to_string(myShapePtr->calculateArea()) << std::endl; //should work as intended, calls the Rectangles implementation

   //calling an overridden, but not virtual function
   myShapePtr->display(); //will display the default shape display function (just the name); 
   myRect.display(); //will display the proper display function because it is not a generic shape pointer.

    return 0;
}