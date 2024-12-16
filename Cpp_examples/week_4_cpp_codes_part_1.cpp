//example 1

// This program correctly averages 3 test scores.
#include <iostream>  
#include <iomanip>  
using namespace std;  

int main()  
{  
    int score1, score2, score3;  
    double average;  

    // Get the three test scores  
    cout << "Enter 3 test scores and I will average them: ";  
    cin >> score1 >> score2 >> score3;  

    // Calculate and display the average score  
    average = (score1 + score2 + score3) / 3.0;  
    cout << fixed << showpoint << setprecision(1);  
    cout << "Your average is " << average << endl;  

    // If the average equals 100, congratulate the user  
    if (average == 100)  
    {  
        cout << "Congratulations! ";  
        cout << "That's a perfect score!\n";  
    }  

    return 0;  
}



//example 2

#include <iostream>  
#include <iomanip>  
using namespace std;  

int main()  
{  
    // Constants for membership rates  
    const double ADULT_RATE  = 120.0;  
    const double CHILD_RATE  =  60.0;  
    const double SENIOR_RATE = 100.0;  

    int choice;           // Menu choice  
    int months;           // Number of months  
    double charges;       // Monthly charges  

    // Display the menu and get the user's choice  
    cout << "   Health Club Membership Menu\n\n"; 
    cout << "1. Standard Adult Membership\n";  
    cout << "2. Child Membership\n";  
    cout << "3. Senior Citizen Membership\n";  
    cout << "4. Quit the Program\n\n";  
    cout << "Enter your choice: ";  
    cin >> choice;  

    // Set the numeric output formatting  
    cout << fixed << showpoint << setprecision(2);  

    // Use the menu selection to execute the correct set of actions  
    if (choice == 1)  
    {   
        cout << "For how many months? ";  
        cin >> months;  
        charges = months * ADULT_RATE;  
        cout << " \nThe total charges are $" << charges << endl;  
    }  
    else if (choice == 2)  
    {   
        cout << "For how many months? ";  
        cin >> months;  
        charges = months * CHILD_RATE;  
        cout << " \nThe total charges are $" << charges << endl;  
    }  
    else if (choice == 3)  
    {   
        cout << "For how many months? ";  
        cin >> months;  
        charges = months * SENIOR_RATE;  
        cout << " \nThe total charges are $" << charges << endl;  
    }  
    else if (choice != 4)  
    {   
        cout << " \nThe valid choices are 1 through 4.\n"  
             << "Run the program again and select one of those.\n";  
    }  

    return 0;  
}

//example 3

// This program determines whether a loan applicant qualifies for  
// a special loan interest rate. It uses nested if/else statements.  
#include <iostream>  
using namespace std;  

int main()  
{  
    char employed,        // Currently employed? (Y or N)  
         recentGrad;      // Recent college graduate? (Y or N)  

    // Is the applicant employed and a recent college graduate?  
    cout << "Answer the following questions\n"; 
    cout << "with either Y for Yes or N for No.\n"; 

    cout << "Are you employed? ";  
    cin >> employed;  
    cout << "Have you graduated from college in the past two years? ";  
    cin >> recentGrad;  

    // Determine the applicant's loan qualifications  
    if (employed == 'Y')  
    {  
        if (recentGrad == 'Y')         // Employed and a recent grad  
        {  
            cout << "You qualify for the special interest rate.\n";  
        }  
        else                           // Employed but not a recent grad  
        {  
            cout << "You must have graduated from college in the past\n";  
            cout << "two years to qualify for the special interest rate.\n";  
        }  
    }  
    else                               // Not employed  
    {  
        cout << "You must be employed to qualify for the "  
             << "special interest rate. \n";  
    }  
    return 0;  
}

//example 4

// This menu-driven program uses a switch statement to carry out  
// the appropriate set of actions based on the user's menu choice.  
#include <iostream>  
#include <iomanip>  
using namespace std;  

int main()  
{  
    // Constants for membership rates  
    const double ADULT_RATE  = 120.0;  
    const double CHILD_RATE  =  60.0;  
    const double SENIOR_RATE = 100.0;  

    int choice;           // Menu choice  
    int months;           // Number of months  
    double charges;       // Monthly charges  

    // Display the menu and get the user's choice  
    cout << "   Health Club Membership Menu\n\n";  
    cout << "1. Standard Adult Membership\n";  
    cout << "2. Child Membership\n";  
    cout << "3. Senior Citizen Membership\n";  
    cout << "4. Quit the Program\n\n";  
    cout << "Enter your choice: ";  
    cin >> choice;  

    // Validate and process the menu choice  
    if (choice >= 1 && choice <= 3)  
    {  
        cout << "For how many months? ";  
        cin >> months;  

        // Set charges based on user input  
        switch (choice)  
        {  
            case 1: 
                charges = months * ADULT_RATE;  
                break;  
            case 2: 
                charges = months * CHILD_RATE;  
                break;  
            case 3: 
                charges = months * SENIOR_RATE;  
        }  

        // Display the monthly charges  
        cout << fixed << showpoint << setprecision(2);  
        cout << "The total charges are $" << charges << endl;  
    }  
    else if (choice != 4)  
    {    
        cout << "The valid choices are 1 through 4.\n"; 
        cout << "Run the program again and select one of these.\n";  
    }  

    return 0;  
}


