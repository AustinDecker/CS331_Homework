// ex1
#include <iostream>

int main() {
    // Write C++ code here
    std::cout << "Try programiz.pro";

    return 0;
}

// ex2

#include <iostream>
int main()
{
   int integer1, integer2, sum; 
   std::cout << "Enter first integer\n";  
   std::cin >> integer1;                  
   std::cout << "Enter second integer\n"; 
   std::cin >> integer2;                  
   sum = integer1 + integer2;        
   std::cout << "Sum is " << sum << std::endl; 
   return 0;   
}

// ex2

#include <iostream>
/* this is the program */
using namespace std;

int main()
{
   cout << "Hello World\n";
   cout << "Hello World\n";
   cout << "Hello World\n";
   cout << "Hello World\n";
   cout << "Hello World\n";
   return 0;   
}

//ex3

#include <iostream>
/* this is the program */
using namespace std;

int main()
{
   int n=0;
   while (n<5) {
       cout << "Hello World\n";
       n=n+1;
       
   }
   return 0;   
}

//ex4

#include <iostream>
/* this is the program */
using namespace std;

int main()
{
   int sum=0, val =1;
   while (val<=10) {
       sum=sum+val;
       //sum += val
       val=val+1;
       // ++val
   }
   cout << "the sum is" << sum;
   return 0;   
}

//ex5


# include <iostream>
using namespace std;

int main(){
    int sum=0;
    for(int val=1; val<=10; val=val+1)
        sum = sum+val;
    cout << sum;
}

//ex5

#include <iostream>
using std::cout;
using std::cin;
using std::endl;
int main()  {
   int num1, num2;
   cout << "Enter two integers, and I will tell you\n" << ”if they are equal or not: ";

   cin >> num1 >> num2;   // read two integers
   
   if ( num1 == num2 )
      cout << num1 << " is equal to " << num2 << endl;
   if ( num1 != num2 )
      cout << num1 << " is not equal to " << num2 << endl;
   return 0;   
}

//last example 

#include <iostream>
using namespace std;

int main()
{
    char ch;
    int total = 0;
    int upper = 0;
    int lower = 0; 
    int digits = 0;
    int other = 0; // Missing semicolon

    cout << "Enter your sentence and end with a period: "; // Moved before return statement
    cin >> ch;
    
    while (ch != '.') {
        total = total + 1; // Increment total before reading the next character

        if (ch >= 'A' && ch <= 'Z') 
            upper++;
        else if (ch >= 'a' && ch <= 'z') 
            lower++;
        else if (ch >= '0' && ch <= '9') 
            digits++;
        else 
            other++;

        cin >> ch; // Moved this after processing the character
    }

    // Outputs the counts
    cout << "Total characters: " << total << "\n";
    cout << "Uppercase letters: " << upper << "\n";
    cout << "Lowercase letters: " << lower << "\n";
    cout << "Digits: " << digits << "\n";
    cout << "Other characters: " << other << endl;

    return 0; // return should be here
}
