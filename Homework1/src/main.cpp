#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <random>
#include <iomanip>
#include <limits>


//Problem 1
/*
*   Problem 1 did not specify a particular type, just "elements" which could be anything.
*   therefore I tried my best to implement a generic function that should work for all types.
*   There might be a few edge cases I have not looked into, but this should cover all integer types.
*/

template <typename T>
struct ArrayMetadata {
    int array_size;
    T min;
    T max;

    void print(){
        std::cout << "\nmin: \t" << min << " " << "max:\t" << max << std::endl;
    }
};

template <typename T>
ArrayMetadata<T> smallest_largest_item(std::vector<T> &list)
{
    ArrayMetadata<T> data;
    data.array_size = list.size();

    T smallest = list.at(0);
    T biggest = list.at(0);

    for(int i = 1; i < list.size(); i++){

        if(biggest < list.at(i))
        {
            biggest = list.at(i);
        }

        if(smallest > list.at(i))
        {
            smallest = list.at(i);
        }
    }
    data.min = smallest;
    data.max = biggest;

    return data;

}

//Problem 2

//arbitrary enum. All students take these classes to simplify student class.
enum class StudentClasses 
{
    MATH,
    SCIENCE,
    ENGLISH,
    SOCIAL_STUDIES,
    LANGUAGE_STUDIES,
    CLASS_SIZE
};

//arbitrary enum used for displaying 
enum class Days{
    MONDAY, TUESDAY, WEDNESDAY, THURSDAY, FRIDAY, SATURDAY, SUNDAY
};

//used for displaying the Days enum in a string format.
std::string daysEnumToString(Days day){
    switch (day) {
        case Days::MONDAY:      return "Monday";
        case Days::TUESDAY:     return "Tuesday";
        case Days::WEDNESDAY:   return "Wednesday";
        case Days::THURSDAY:    return "Thursday";
        case Days::FRIDAY:      return "Friday";
        case Days::SATURDAY:    return "Saturday";
        case Days::SUNDAY:      return "Sunday";
        default:                return "Invalid Day";
    }
}

class Student 
{
public:
    Student(const std::string& name) 
        : name{name}, 
          grades{} {}

    void insertGrade(StudentClasses studentClass, double grade) 
    {
        if (grade > 100 || grade < 0) {
            std::cout << "Student grade cannot be less than 0 or greater than 100." << std::endl;
            return;
        }

        // Add grade to the respective class
        grades.at(static_cast<std::size_t>(studentClass)).push_back(grade);
    }

    //it isnt pretty but gets the job done.
    void viewStudentReport()
    {
        std::array<double, static_cast<int>(StudentClasses::CLASS_SIZE)> gradeAverages = calculateGradeAverages();

        std::cout << "\nStudent:\t" << name << std::endl;
        std::cout << "=======================================================================================" << std::endl;
        std::cout << "Math\t" << "Science\t" << "English\t" << "Social Studies\t" << "Language Studies\t" << std::endl;
        std::cout << gradeAverages.at(0) << "\t" << "\t" << gradeAverages.at(1) << "\t" << gradeAverages.at(2) << "\t" << gradeAverages.at(3) << "\t" << gradeAverages.at(4) << "\t" << std::endl;
        std::cout << passedClass(gradeAverages.at(0)) << "\t" << passedClass(gradeAverages.at(1)) << "\t" << passedClass(gradeAverages.at(2)) << "\t" << passedClass(gradeAverages.at(3)) << "\t" << passedClass(gradeAverages.at(4)) << "\t" << std::endl;

    }

    std::array<double, 5> calculateGradeAverages() 
    {
        std::array<double, 5> classAverages{};

        for (std::size_t i = 0; i < grades.size(); ++i) 
        {
            classAverages.at(i) = calcClassAverage(static_cast<StudentClasses>(i));
        }
        return classAverages; 
    }

private:
    std::string name;
    std::array<std::vector<double>, 5> grades;

    double calcClassAverage(StudentClasses studentClass) 
    {
        double total{0.0};
        std::vector<double>& individualClassGrades = grades.at(static_cast<std::size_t>(studentClass));

        // Calculate total grades
        for (const double& grade : individualClassGrades) 
        {
            total += grade;
        }

        // Avoid division by zero
        if (individualClassGrades.empty()) 
        {
            return 0.0;
        }

        return (total / individualClassGrades.size());
    }

    std::string passedClass(double grade){
        if(grade >= 60.0){
            return "PASS";
        }
        return "FAIL";
    };
};

//Problem 3
class TemperatureTracker 
{
    public:

    TemperatureTracker(std::vector<double> tempList) : readings{tempList}
    {
        this->tempInfo = smallest_largest_item(this->readings);
    };

    std::vector<double> & getWeeklyReadings()
    {
        return readings;
    };

    double getAverageTemp()
    {
        double total{0};

        for (int i = 0; i < readings.size(); i++)
        {
            total += readings.at(i);
        }
        return total / readings.size();
        
    }

    void info()
    {
        std::cout << std::endl;
        std::cout << "| Weather Info (c)|" << std::endl;
        std::cout << "| Average Temp: " << getAverageTemp() << " |" << std::endl;
        std::cout << "| Min Temp: " << tempInfo.min << " |" << std::endl;
        std::cout << "| Max Temp: " << tempInfo.max << " |" << std::endl;
    }

    private:
    std::vector<double> readings;
    ArrayMetadata<double> tempInfo;

    protected:

};

double randomDouble(double min, double max){
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> distr(min, max);

    return distr(gen);
}

void generateGrades(Student &student){
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            student.insertGrade(static_cast<StudentClasses>(i), randomDouble(50, 100));
        }
    }
    
}


//problem 3
class BankAccount 
{
    private:

    std::string accountHolderName;
    unsigned int accountNumber;
    unsigned int balance;

    public:

    unsigned int getBalance()
    {
        return balance;
    }

    unsigned int getAccountNumber()
    {
        return accountNumber;
    }

    std::string & getAccountHolderName()
    {
        return accountHolderName;
    }

    BankAccount(std::string name, unsigned int number, unsigned int startingBalance) 
        : 
            accountHolderName{name}, 
            accountNumber{number}, 
            balance{startingBalance} {};

    void accountInfo()
    {
        std::cout << "\nAccount: " << accountHolderName << " Account #: " << accountNumber << std::endl;
        std::cout << "============================================================================" << std::endl;
        std::cout << "Balance: " << balance << std::endl;
    }

    void withdraw(unsigned int amount)
    {
        if(balance >= amount){
            balance -= amount;
            std::cout << amount << " has been withdrawn from your account.\t" << "New Balance: (" << balance << ")" << std::endl;
        }
        else{
            std::cout << "Insufficient Balance" << std::endl; 
        }
    }

    void deposit(unsigned int amount)
    {
        balance += amount;
        std::cout << amount << " has been added to your account.\t" << "New Balance: (" << balance << ")" << std::endl;
    }
};

//generic helper function that gets user input and has simple error checking.
template<typename T>
void getUserInput(const std::string& message, T *var, const std::string& errorMessage="Invalid Entry, Try Again."){
    while(true) 
    {
        std::cout << message;
        std::cin >> *var;

        if(std::cin.fail())
        {
            std::cout << errorMessage << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            
        } 
        else 
        {
            break;
        }
    }
}

//creates a line seperator in the terminal with n symbols.
void seperatorGenerator(char symbol, unsigned int length){
    unsigned int count{0};

    while(count < length){
        std::cout << symbol;
        count++;
    }
    std::cout << std::endl;
}

//generates a simple header
void headerGenerator(const std::string & header, char headingSep='=', int amount=100){
    std::cout << std::endl;
    seperatorGenerator(headingSep, static_cast<unsigned int>(amount));
    std::cout << header << std::endl;
    seperatorGenerator(headingSep, static_cast<unsigned int>(amount));
}

//generates a simple menu interface.
void menuGenerator(const std::string & header, const std::vector<std::string> & menuItems ){
    headerGenerator(header);
    seperatorGenerator('=', 100);
    for (int i = 0; i < menuItems.size(); i++)
    {
        std::cout << i << ": " << menuItems.at(i) << std::endl;
    }
    seperatorGenerator('=', 100);
}

void temperatureReading()
{
    std::vector<double> tempInputs{};
    double userInput;

    int count {0};
    headerGenerator("Weekly Temperature Readings in Celcius");

    while(count < 7)
    {
        std::string message = "\nWhat was the temperature for " + daysEnumToString(static_cast<Days>(count)) + ": ";
        getUserInput<double>(message, &userInput, "Invalid User Input. Temperature must be a number.");
        tempInputs.push_back(userInput);
        count++;
    }

    TemperatureTracker tracker{tempInputs};
    tracker.info();
}

void accountManagement()
{
    std::string name;
    unsigned int accNumber;
    unsigned int startingBalance;
    unsigned int choice;

    headerGenerator("Account Creation");

    getUserInput<std::string>("Account Holder Name: ", &name);
    getUserInput<unsigned int>("Account Number: ", &accNumber);
    getUserInput<unsigned int>("Starting Balance: ", &startingBalance);

    BankAccount account{name, accNumber, startingBalance};

    do {
        menuGenerator("Account Management", {"View Account Information", "Deposit", "Withdraw", "Exit"});
        getUserInput<unsigned int>("Account Management option: ", &choice);

        if(choice == 0){
            account.accountInfo();
        }
        else if (choice == 1){

            unsigned int amount;
            getUserInput<unsigned int>("Amount you wish to deposit into your account: ", &amount);
            account.deposit(amount);
        }
        else if(choice == 2){
            unsigned int amount;
            getUserInput<unsigned int>("Amount you wish to withdraw from your account: ", &amount);
            account.withdraw(amount);
        }
        else if(choice == 3){
            break;
        }

    }
    while(true);

}

int main(){


    //Part 1
    std::vector<int> intCollection{28, 95, 32, 0, 34, 21};
    std::vector<double> doubleCollection{69.4, 23.5, 4, 76.2, 98.9};

    auto results = smallest_largest_item(intCollection);
    auto results2 = smallest_largest_item(doubleCollection);
    results.print();
    results2.print();

    //Part 2
    Student student1{"John Smith"};
    generateGrades(student1);
    student1.viewStudentReport();

    //part 3
    temperatureReading();

    //part 4
    accountManagement();

    return 0;
}