#include "person.h"
#include <iostream>

person::~person() {

};


//default constructor
person::person()
{
    fName = "";
    lName = "";
    ID = 0000;
    birthDay.setDate(0, 0, 0000);
    hirringDate.setDate(0, 0, 0000);
}
//multi argument constructor
person::person(string Fname, string lName, int ID,
    int birthDayD, int birthDayMonth, int birthDayYear,
    int hirringDay, int hirringMonth, int hirringYear)
{
    this->fName = Fname;
    this->lName = lName;
    this->ID = ID;
    this->birthDay.setDate(birthDayD, birthDayMonth, birthDayYear);
    this->hirringDate.setDate(hirringDay, hirringMonth, hirringYear);
}
//functions to set private member variables 
void person::setFname(string Fname)
{
    this->fName = Fname;
}

void person::setLname(string lName)
{
    this->lName = lName;
}
void person::setID(int ID)
{
    this->ID = ID;
}
string person::getFname() const
{
    return this->fName;
}
string person::getLname() const
{
    return this->lName;
}
int person::getId() const
{
    return this->ID;
}

//asks user for their first name
void person::askForFname()
{
    std::cout << "Enter first name: ";
    getline(std::cin >> std::ws, this->fName);
}
//asks user for their last name 
void person::askForLname()
{
    std::cout << "Enter last name: ";
    getline(std::cin >> std::ws, this->lName);
}
// asks user for their ID and error checks it 
void person::askForID()
{
    int tempID;
    while (true)
    {
        std::cout << "Enter ID: ";
        std::cin >>std::ws >>tempID;
        if (tempID >= 0 && tempID <= 100000 && !std::cin.fail()) {

            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            break;
        }
        else {
            std::cout << "Error ID must be between 0 and 100000 \n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        }
    }

    setID(tempID);

}