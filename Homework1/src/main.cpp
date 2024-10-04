#include <iostream>
#include <string>
#include <vector>


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
};

template <typename T>
ArrayMetadata<T> smallest_largest_item(std::vector<T> &list){
    ArrayMetadata<T> data;
    data.array_size = list.size();

    T smallest = list.at(0);
    T biggest = list.at(0);

    for(int i = 1; i < list.size(); i++){

        if(biggest < list.at(i)){
            biggest = list.at(i);
        }

        if(smallest > list.at(i)){
            smallest = list.at(i);
        }
    }
    data.min = smallest;
    data.max = biggest;

    return data;

}

//Problem 2

//arbitrary enum. All students take these classes.
enum class StudentClasses {
    MATH,
    SCIENCE,
    ENGLISH,
    SOCIAL_STUDIES,
    LANGUAGE_STUDIES,
    CLASS_SIZE
};

class Student {
public:
    Student(const std::string& name) 
        : name{name}, 
          grades{} {}

    void insertGrade(StudentClasses studentClass, double grade) {
        if (grade > 100 || grade < 0) {
            std::cout << "Student grade cannot be less than 0 or greater than 100." << std::endl;
            return;
        }

        // Add grade to the respective class
        this->grades.at(static_cast<std::size_t>(studentClass)).push_back(grade);
    }

    void viewStudentReport(){
        std::array<double, static_cast<int>(StudentClasses::CLASS_SIZE)> gradeAverages = this->calculateGradeAverages();

        std::cout << "Student:\t" << this->name << std::endl;
        std::cout << "=======================================================================================" << std::endl;
        std::cout << "Math\t" << "Science\t" << "English\t" << "Social Studies\t" << "Language Studies\t" << std::endl;
        std::cout << gradeAverages.at(0) << "\t" << "\t" << gradeAverages.at(1) << "\t" << gradeAverages.at(2) << "\t" << gradeAverages.at(3) << "\t" << gradeAverages.at(4) << "\t" << std::endl;
        std::cout << passedClass(gradeAverages.at(0)) << "\t" << passedClass(gradeAverages.at(1)) << "\t" << passedClass(gradeAverages.at(2)) << "\t" << passedClass(gradeAverages.at(3)) << "\t" << passedClass(gradeAverages.at(4)) << "\t" << std::endl;

    }

    std::array<double, 5> calculateGradeAverages() {
        std::array<double, 5> classAverages{};

        for (std::size_t i = 0; i < grades.size(); ++i) {
            classAverages.at(i) = calcClassAverage(static_cast<StudentClasses>(i));
        }
        return classAverages; 
    }

private:
    std::string name;
    std::array<std::vector<double>, 5> grades;

    double calcClassAverage(StudentClasses studentClass) {
        double total{0.0};
        std::vector<double>& individualClassGrades = this->grades.at(static_cast<std::size_t>(studentClass));

        // Calculate total grades
        for (const double& grade : individualClassGrades) {
            total += grade;
        }

        // Avoid division by zero
        if (individualClassGrades.empty()) {
            return 0.0;

        return (total / individualClassGrades.size());
    }

    std::string passedClass(double grade){
        if(grade >= 60.0){
            return "PASS";
        }
        return "FAIL";
    };
}

void main(){
    
}