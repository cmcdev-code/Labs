//file that has all the class function definitions
#include "employee.h"//header file
#include <iomanip> //manipulate the output 
#include <string>//for strings
#include <algorithm>//sorting algorithm for vector 
#include <iostream>//i/o


//0 argument constructor 
Employee::Employee() {
    name = "";
    city = "";
    ID = "";
}

//3 argument constructor 
Employee::Employee(std::string name, std::string city, std::string ID) {
    this->name = name;
    this->city = city;
    this->ID = ID;
}

//sets employee Object name
void Employee::setName(std::string name) {
    this->name = name;
}
//sets employee Object city
void Employee::setCity(std::string city) {
    this->city = city;
}
//sets employee Object ID
void Employee::setID(std::string ID) {
    this->ID = ID;
}
//gets the size of the employee vector of scores 
int Employee::sizeVectorScore() const {
    return this->score.size();
}

//adds a score to the back of the vector 
void Employee::vectorPushBack(double score) {
    this->score.push_back(score);
}
//gets the value at a certain index in the vector 
double Employee::vectorAtIndex(int index) const {
    return this->score.at(index);
}

//sorts the vector 
void Employee::sortVector() {
    std::sort(score.begin(), score.end());
}
//calculates the smallest value in teh vector 
double Employee::smallestVector() const {

    double smallestInvector = vectorAtIndex(0);//sets the first value as the smallest 
    for (int i = 0; i < sizeVectorScore(); i++) {//checks every value in the vector to the first 
        if (smallestInvector > vectorAtIndex(i)) {
            smallestInvector = vectorAtIndex(i);//if it is larger then flips it
        }
    }
    return smallestInvector;//returns the smallest value 
}
//function to get the largest value in the vector 
double Employee::largestVector() const {
    double largestInvector = vectorAtIndex(0);//sets the first value as the largest 

    //checks the first value and if it is smaller then the 2nd it will change the first value to the value of the 2nd
    for (int i = 0; i < sizeVectorScore(); i++) {
        if (largestInvector < vectorAtIndex(i)) {
            largestInvector = vectorAtIndex(i);
        }
    }

    return largestInvector;//returns the largest value 

}
//calculates the avg value of teh vector 
double Employee::avgVector() const {
    double avg = 0;//local variable that will hold the sum 

    //sums all values of the vector 
    for (int i = 0; i < sizeVectorScore(); i++) {
        avg = avg + vectorAtIndex(i);
    }
    //if vector is only 0 then it won't avg 
    if (sizeVectorScore() > 0) {
        avg = avg / sizeVectorScore();
    }
    else {//if vector only 0 elements then avg will be a 0
        avg = 0;
    }
    return avg;
}

//member function to delete all values in the vector 
void Employee::delVector() {
    this->score.clear();
}

//member function to get the object name 
std::string Employee::getName() const {
    return this->name;
}
//member function to get the object city
std::string Employee::getCity() const {
    return this->city;
}
//member function to get the object ID 
std::string Employee::getID() const {
    return this->ID;
}

//member function to print out employee information 
void Employee::printEmployeeInfo() const {

    //outputs the info for the employee
    std::cout << "***********************************************" << '\n';
    std::cout << std::setw(30) << std::right << "Employee Info \n";
    std::cout << std::setw(20) << std::left << "Employee name:" << std::right << getName() << '\n';
    std::cout << std::setw(20) << std::left << "City:" << std::right << getCity() << '\n';
    std::cout << std::setw(20) << std::left << "ID:" << std::right << getID() << '\n';
    std::cout << "***********************************************" << '\n' << '\n';


    std::cout << std::setw(30) << std::right << "Customer Satisfaction Info \n";

    //checks that the vector isnt 0 elements
    if (sizeVectorScore() > 0) {

        //ouputs the data that will depened on the vector 
        std::cout << std::fixed << std::setprecision(1) << std::setw(20) << std::left << "Average Score:" << std::right << avgVector() << '\n';
        std::cout << std::fixed << std::setprecision(1) << std::setw(20) << std::left << "Highest Score:" << std::right << largestVector() << '\n';
        std::cout << std::fixed << std::setprecision(1) << std::setw(20) << std::left << "Lowest Score:" << std::right << smallestVector() << '\n';
        std::cout << "List of all recorded Scores: \n";

        //outputs all the values in the vector 
        for (int i = 0; i < sizeVectorScore(); i++) {
            std::cout << vectorAtIndex(i) << '\n';
        }
    }

    else {
        //if the vector has no values in it then it will just store 0 for the values
        std::cout << std::fixed << std::setprecision(1) << std::setw(20) << std::left << "Average Score:" << std::right << 0 << '\n';
        std::cout << std::fixed << std::setprecision(1) << std::setw(20) << std::left << "Highest Score:" << std::right << 0 << '\n';
        std::cout << std::fixed << std::setprecision(1) << std::setw(20) << std::left << "Lowest Score:" << std::right << 0 << '\n';

        std::cout << "List of all recorded scores: \n";
    }


    std::cout << std::setw(26) << std::left << "End of information for:" << std::right << getName() << "\n";

    std::string pause;
    std::cout << "Hit enter to continue. \n";
    std::cin.ignore();
    std::getline(std::cin, pause);
}
