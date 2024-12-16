// This program uses a loop to compute letter grades for multiple students.  
#include <iostream>  
using namespace std;  

int main()  
{  
    // Create named constants to hold minimum scores for each letter grade  
    const int MIN_A_SCORE = 90,  
              MIN_B_SCORE = 80,  
              MIN_C_SCORE = 70,  
              MIN_D_SCORE = 60,  
              MIN_POSSIBLE_SCORE = 0;  

    int numStudents,         // The total number of students  
        student,             // The current student being processed  
        testScore;           // Current student's numeric test score  
    char grade;              // Current student's letter grade  
    bool goodScore = true;  

    // Get the number of students  
    cout << "How many students do you have grades for? ";  
    cin  >> numStudents;  

    // Initialize the loop control variable  
    student = 1;  

    // Loop once for each student  
    while (student <= numStudents)  
    {  
        // Get this student's numeric score  
        cout << "\nEnter the numeric test score for student #"  
             << student << ": ";  
        cin  >> testScore;  

        // Determine the letter grade  
        if (testScore >= MIN_A_SCORE)  
            grade = 'A';  
        else if (testScore >= MIN_B_SCORE)  
            grade = 'B';  
        else if (testScore >= MIN_C_SCORE)  
            grade = 'C';  
        else if (testScore >= MIN_D_SCORE)  
            grade = 'D';  
        else if (testScore >= MIN_POSSIBLE_SCORE)  
            grade = 'F';  
        else  
            goodScore = false;  // The score was below 0  

        // Display the letter grade  
        if (goodScore)  
            cout << "The letter grade is " << grade << ".\n";  
        else  
            cout << "The score cannot be below zero. \n";  

        // Set student to the next student  
        student = student + 1;  
    }  
    return 0;  
}  


// example 2

// This program calculates the number of soccer teams a  
// youth league can create from the number of available  
// players. It performs input validation using while loops.  
#include <iostream>  
using namespace std;  
  
int main()  
{  
    // Constants for minimum and maximum players per team  
    const int MIN_PLAYERS = 9,  
              MAX_PLAYERS = 15;  
  
    // Variables  
    int players,      // Number of available players  
        teamSize,     // Number of desired players per team  
        numTeams,     // Number of teams  
        leftOver;     // Number of players left over  
  
    // Get the number of players per team  
    cout << "How many players do you wish per team?\n";  
    cout << "(Enter a value in the range "  
         << MIN_PLAYERS << " − " << MAX_PLAYERS << "): ";  
    cin  >> teamSize;  
  
    // Validate the input  
    while (teamSize < MIN_PLAYERS || teamSize > MAX_PLAYERS)  
    {  
        cout << "\nTeam size should be "  
             << MIN_PLAYERS << " to " << MAX_PLAYERS << " players.\n";  
        cout << "How many players do you wish per team? ";  
        cin  >> teamSize;  
    }  
  
    // Get and validate the number of players available  
    cout << "\nHow many players are available? ";  
    cin  >> players;  
  
    while (players <= 0)  
    {  
        cout << "Please enter a positive number: ";  
        cin  >> players;  
    }  
  
    // Calculate the number of teams and number of leftover players  
    numTeams = players / teamSize;  
    leftOver = players % teamSize;  
  
    // Display the results  
    cout << "\nThere will be " << numTeams << " teams with ";  
    cout << leftOver << " players left over.\n";  
  
    return 0;  
}

//example 3


// This program averages test scores. It asks the user for the  
// number of students and the number of test scores per student.  
#include <iostream>  
using namespace std;  
  
int main()  
{  
    int numStudents,    // Number of students  
        numTests;       // Number of tests per student  
    double average;     // Average test score for a student  
  
    // Get the number of students  
    cout << "This program averages test scores.\n";  
    cout << "How many students are there? ";  
    cin  >> numStudents;  
  
    // Get the number of test scores per student  
    cout << "How many test scores does each student have? ";  
    cin  >> numTests;  
    cout << endl;  
  
    // Read each student's scores and compute their average  
    for (int snum = 1; snum <= numStudents; snum++)    // Outer loop  
    {   
        double total = 0.0;   // Initialize accumulator  
  
        for (int test = 1; test <= numTests; test++)   // Inner loop  
        {   
            int score;  
  
            // Read a score and add it to the accumulator  
            cout << "Enter score " << test << " for ";  
            cout << "student " << snum << ": ";  
            cin  >> score;  
            total += score;  
        }   // End inner loop  
  
        // Compute and display the student's average  
        average = total / numTests;  
        cout << "The average score for student " << snum;  
        cout << " is " << average << "\n\n";  
    }   // End outer loop  
  
    return 0;  
}
