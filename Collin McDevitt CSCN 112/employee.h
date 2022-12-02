#pragma once
//file that has the class 
#include <vector>
#include <string>
#include "person.h"

class Employee : public person
{

public:

    ~Employee();

    //constructor
    Employee();
    //3 argument constructor  
    Employee(double milesTraveled, double employeeScore, string Fname, string lName, int ID, int birthDayD, int birthDayMonth, int birthDayYear, int hirringDay, int hirringMonth, int hirringYear);

    //function to put a value in the vector
    void vectorPushBack(double jobs);

    //functions to set the private member variables
    void setMilesTraveled(double milesTravelled);
    void setEmployeeScore(double employeeScore);

    //functions to get private member variables
    double getEmployeeScore() const;
    double getMilesTraveled() const;
    double employeeRev() const;

    //will return the value of the vector at that index 
    double vectorAtIndex(int index) const;
    //will get the size of the vector 
    int sizeVectorjobs() const;


    //function to ask for the score of the employee 
    void askForEmployeeScore();

    //function to ask for the miles traveled
    void askForMilesTraveled();

    //function to ask the user to enter a job and will error check it 
    void askForJobs();

    //overloaded << operator
    friend std::ostream& operator << (std::ostream& out, const Employee& localObj);


    //overloaded < operator
    bool operator < (const Employee& localObj) const;


private:
    double employeeScore;
    std::vector<double> jobs;
    double milesTraveled;


};