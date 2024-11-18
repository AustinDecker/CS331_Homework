#include <iostream>
#include <string>
#include <array>
#include <iomanip>
#include <limits>

//A generic vector class that can handle N number of numbers
template <typename T, int max> class Vect 
{
    private:
        int vectType{max};
        std::array<T, max> items;

    public:
        //creates a vector object from the std::array. Array must match the same type and size as the vector
        Vect(const std::array<T, max>& vectorNums) : items{vectorNums} {};

        int getVectType() const { return vectType; };

        //returns a copy of the internal vector structure.
        const std::array<T, max>& getVector() const {
            return this->items;
        }

        //returns the value of the vector at the index
        int getAt(int index) const {
            return this->items.at(index);
        }

        //returns a string with the proper formatting of the vector
        std::string print() const {
            std::string vectorString = "<";
            
            for(int i = 0; i < vectType; i++){
                std::string appendingString = std::to_string(this->items.at(i));
                //add comma up until the last item
                if(i < vectType - 1){
                    appendingString.append(",");
                }
                vectorString.append(appendingString);
            }
            vectorString.append(">");
            return vectorString;
        };

        //operator overloading the + symbol
        Vect<T, max> operator+(const Vect<T, max>& vect) const
        {
            std::array<T, max> summedItems;

            for(int i = 0; i < this->vectType; i++){
                summedItems.at(i) = this->getAt(i) + vect.getAt(i);
            }
            return Vect<T, max>(summedItems);

        }

    protected:

};

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

//Problem 1
void problem1(){
    const int vectorType = 3;

    int count = 0;
    std::array<int, vectorType> numbers;
    std::cout << "Vector 1" << std::endl;
    while(count < vectorType){
        int number;
        getUserInput<int>("vector component #" + std::to_string(count + 1) + " :", &number);
        numbers.at(count) = number;
        count++;
    }

    Vect<int, vectorType> vector1(numbers);

    std::cout << "Vector 2" << std::endl;
    count = 0;

    while(count < vectorType){
        int number;
        getUserInput<int>("vector component #" + std::to_string(count + 1) + " :", &number);
        numbers.at(count) = number;
        count++;
    }

    Vect<int, vectorType> vector2(numbers);

    std::cout << "Vector Addition" << std::endl;

    Vect<int, vectorType> summedVector = vector1 + vector2;

    std::cout << "summed results: " << summedVector.print() << std::endl;

}

void problem2()
{
    /*
    A copy constructor in C++ is a special member function that creates a new object as a copy of an existing object of the same class. 
    Its primary purpose is to initialize a new object with the values of another object, ensuring a proper deep copy of all member variables, including dynamically allocated memory. 
    The copy constructor is automatically called when an object is passed by value, returned by value, or explicitly initialized with another object of the same class. 
    It works by taking a constant reference to an object of the same class as a parameter and initializing the new object's members with the corresponding values from the passed object. 
    However, copy constructors can have limitations, such as potentially being inefficient for large objects, and not handling shallow copying of pointers correctly without explicit implementation.
    */

}

int main()
{
    problem1();

    return 0;
}
