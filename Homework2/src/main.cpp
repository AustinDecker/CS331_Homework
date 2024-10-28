#include <iostream>
#include <string>
#include <limits>

enum DaysOfWeek {MONDAY, TUESDAY, WEDNESDAY, THURSDAY, FRIDAY, SATURDAY, SUNDAY};
const int DAYS = 7;

typedef struct 
{
    int size;
    double total;
    double avg;
    double max;
    double min;
    DaysOfWeek maxDay;
    DaysOfWeek minDay;

} ArrayMetaData;

std::string enumToString(DaysOfWeek day){
    std::string dayString;
    switch (day){
        case MONDAY: 
            dayString = "Monday";
            break;
        case TUESDAY:
            dayString = "Tuesday";
            break;
        case WEDNESDAY:
            dayString = "Wednesday";
            break;
        case THURSDAY:
            dayString = "Thursday";
            break;
        case FRIDAY: 
            dayString = "Friday";
            break;
        case SATURDAY:
            dayString = "Saturday";
            break;
        case SUNDAY:
            dayString = "Sunday";
            break;
        default:
            dayString = "";
            break;
    }
    return dayString;
}

//analyzes the contents of the array and finds the min, max, average, and total.
ArrayMetaData analyseHoursStudied(double * weeklyHoursStudiedArr, int length)
{
    double* index {weeklyHoursStudiedArr};
    double total {0};
    double average {0};
    double min {*index};
    double max {*index};
    DaysOfWeek minDay{MONDAY};
    DaysOfWeek maxDay{MONDAY};

    for(DaysOfWeek i = MONDAY; i <= SUNDAY; i = (DaysOfWeek)(i + 1)){
        //max 
        if(max < *(index + i))
        {
            max = *(index + i);
            maxDay = i;
        }

        //min
        if(min > *(index + i))
        {
            min = *(index + i);
            minDay = i;
        }

        //total
        total += *(index + i);
    }
    average = total / length;
    
    ArrayMetaData data;
    data.avg = average;
    data.max = max;
    data.min = min;
    data.total = total;
    data.size = length;
    data.minDay = minDay;
    data.maxDay = maxDay;

    return data;
}

//Reusing getUserInput from homework #1
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



//Problem 1 implemented here
void problem1()
{

    double hoursStudiedWeekly[DAYS];
    DaysOfWeek day = MONDAY;

    while (day <= SUNDAY)
    {
        getUserInput("How long did you study on " + enumToString(day) + "?: ", hoursStudiedWeekly + day);
        day = (DaysOfWeek)(day + 1);
    }

    ArrayMetaData data = analyseHoursStudied(hoursStudiedWeekly, DAYS);
    std::cout << "Hours Spent Studying this week:" << std::endl;
    std::cout << "Total Hours: " << data.total 
              << "\nAverage Hours: " << data.avg 
              << "\nMax Hours: " << data.max
              << "\nMin Hours:" << data.min 
              << std::endl;

    std::cout << "Max hours spent studying was on " << enumToString(data.maxDay) << std::endl; 
}

//problem 3 implementation
void problem3()
{
    int studentCount {0};

    getUserInput("How many students are there?: ", &studentCount);

    std::string * studentArr = new std::string[studentCount];
    int * studentGradeArr = new int[studentCount];

    //gathering the student names and grade
    int index = 0;
    while(index < studentCount)
    {
        std::string studentName;
        int studentGrade;
        getUserInput("What is the student's name?: ", &studentName);
        getUserInput("What is the student's grade?: ", &studentGrade);

        *(studentArr + index) = studentName;
        *(studentGradeArr + index) = studentGrade;

        index++;
    }

    //finding the highest grade and student with the grade.
    int max {*studentGradeArr};
    std::string studentWithHighestGrade {*studentArr};
    
    for(int i = 0; i < studentCount; i++){
        //max 
        if(max < *(studentGradeArr + i))
        {
            max = *(studentGradeArr + i);
            studentWithHighestGrade = *(studentArr + i);
        }
    }
    std::cout << "The student " << studentWithHighestGrade << " has the highest grade with a grade of: " << max << std::endl;

    //freeing the memory
    delete(studentGradeArr);
    delete(studentArr);
}

int main(){
    problem1();

    //problem 2
    /*
        In C++, a constant pointer and a pointer to a constant serve different purposes. 
        A pointer to a constant, declared as const Type*, allows the pointer to change which address it points to, but it cannot modify the value at that address. 
        A constant pointer, declared as Type* const, fixes the pointer to a specific address, although it can modify the value at that address.
    */
   
    problem3();

    return 0;
}