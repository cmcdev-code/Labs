#pragma once 
#include <string>
#include "dateObj.h"

using std::string;


class person {
public:

    //destructor 
    ~person();

    //zero argument constructor 
    person();

    //multi argument constructor 
    person(
        string Fname,
        string lName,
        int ID,
        int birthDayD = 0, int birthDayMonth = 0, int birthDayYear = 0000,
        int hirringDay = 0, int hirringMonth = 0, int hirringYear = 0000
    );

    //functions to set private member variables
    void setFname(string Fname);
    void setLname(string lName);
    void setID(int ID);

    //function to ask for the First name from user
    void askForFname();
    //function to ask for the last name from user
    void askForLname();

    //function to ask for the ID from user and error check it
    void askForID();

    //gets private member variables 
    string getFname() const;
    string getLname() const;
    int getId() const;

    //date objects 
    Date birthDay;
    Date hirringDate;

private:


    string fName;
    string lName;
    int ID;



};