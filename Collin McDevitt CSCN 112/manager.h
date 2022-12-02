#pragma once
#include "person.h"
#include <string>
#include <iostream>



class manager : public person

{

public:
    ~manager();

    //constuctor    
    manager();
    //multi argument constructor
    manager(string jobTitle, double salary, int promotionDay, int promotionMonth, int promotionYear, string Fname, string lName, int ID, int birthDayD, int birthDayMonth, int birthDayYear, int hirringDay, int hirringMonth, int hirringYear);

    //sets private member variables
    void setJobTitle(string jobTitle);
    void setSalary(double salary);
    void setPromotionDate(int day, int month, int year);

    //gets private member variables
    string getJobTitle() const;
    double getSalary() const;

    //asks for the job title from the user
    void askForJobTitle();
    //asks for the salary from the user and error checks it 
    void askForSalary();


    //overloading << operator
    friend std::ostream& operator << (std::ostream& out, const manager& localObj);

    //date object
    Date promotionDate;
private:

    string jobTitle;
    double salary;




};