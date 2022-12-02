#pragma once
//file that has the class 
#include <vector>
#include <string>


class Employee {

public:

    //Method to set the name
    void setName(std::string  name);
    //method to get the name
    std::string getName() const;

    //method to set the city
    void setCity(std::string city);
    //method to get the city
    std::string getCity() const;

    //method to set the id
    void setID(std::string ID);
    //method to get the ID
    std::string getID() const;


    //constructor
    Employee();
    //3 argument constructor  
    Employee(std::string name, std::string city, std::string ID);

    //function to put a value in the vector
    void vectorPushBack(double score);

    //will return the value of the vector at that index 
    double vectorAtIndex(int index) const;
    //will get the size of the vector 
    int sizeVectorScore() const;
    //will sort the vector 
    void sortVector();
    //will find the smallest value in the vector 
    double smallestVector() const;
    //will find the largest value in the vector 
    double largestVector() const;

    //will find the avg value in the vector 
    double avgVector() const;
    //will clear the vector 
    void delVector();

    //will print all the employee object info
    void printEmployeeInfo() const;


private:
    std::string name;
    std::string city;
    std::string ID;
    std::vector<double> score;

};
