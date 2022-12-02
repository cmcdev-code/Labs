//file that has all the class function definitions
#include "employee.h"//header file

#include <iomanip>
#include <iostream>

using std::cin;
using std::cout;

Employee::~Employee() {

};
//0 argument constructor 
Employee::Employee() :person() {
    employeeScore = 0000;
    milesTraveled = 0.0f;
}

//3 argument constructor 
Employee::Employee(double milesTraveled, double employeeScore, string Fname, string lName, int ID, int birthDayD,
    int birthDayMonth, int birthDayYear, int hirringDay, int hirringMonth, int hirringYear)

    :person(Fname, lName, ID, birthDayD, birthDayMonth, birthDayYear, hirringDay, hirringMonth, hirringYear)
{
    this->milesTraveled = milesTraveled;
    this->employeeScore = employeeScore;
}

//adds a jobs to the back of the vector 
void Employee::vectorPushBack(double jobs) {
    this->jobs.push_back(jobs);
}
//gets the value at a certain index in the vector 
double Employee::vectorAtIndex(int index) const {
    return this->jobs.at(index);
}
//sets private member variabls 
void Employee::setEmployeeScore(double employeeScore) {
    this->employeeScore = employeeScore;
}
void Employee::setMilesTraveled(double milesTravelled)
{
    this->milesTraveled = milesTravelled;
}

//gets private member variables
double Employee::getEmployeeScore() const {
    return this->employeeScore;
}

double Employee::getMilesTraveled() const
{
    return milesTraveled;
}

//will return the total revenue of all the jobs in the vector 
double Employee::employeeRev() const {
    double total=0;
    for (int i = 0; i < jobs.size(); i++)
    {
        total += jobs.at(i);
    }
    return total;
}


//will return the size of the jobs vector
int Employee::sizeVectorjobs() const
{
    return this->jobs.size();
}


//definition of the overloaded << operator
std::ostream& operator <<(std::ostream& out, const Employee& localObj)
{
    out << std::left << std::setw(30) << "Name:" << std::right << localObj.getFname() + " " + localObj.getLname() + "\n";
    out << std::left << std::setw(30) << "Employee ID:" << std::right << localObj.getId() << "\n";
    out << std::left << std::setw(30) << "Birth Day:" << std::right << localObj.birthDay << "\n";
    out << std::left << std::setw(30) << "Date Hirred:" << std::right << localObj.hirringDate << "\n";
    out << std::left << std::setw(30) << "Miles Traveled:" << std::right << localObj.getMilesTraveled() << "\n";
    out << std::left << std::setw(30) << "Employee Rating:" << std::right << localObj.getEmployeeScore() << "\n";
    out << std::left << "Completed Job Revenue: \n";
    for (int i = 0; i < localObj.sizeVectorjobs(); i++)
    {
        out << std::setw(30) << std::right << "$" << std::fixed << std::setprecision(2) << localObj.vectorAtIndex(i) << "\n";
    }
    return out;
}
//deifnition of the overloaded < operator
bool Employee::operator<(const Employee& localObj) const
{
    bool res;
    //compare function 
    int result = this->getLname().compare(localObj.getLname());
    if (result < 0) {
        res = true;
    }
    else {
        res= false;
    }
    return res;
}

//asks user for the employee score and error checks it
void Employee::askForEmployeeScore()
{//error check and ask for user input 
    double score;
    while (true) {
        cout << "Enter Employee Score between 0-5\n";
        cin >> score;
        if (score >= 0 && score <= 5 && !cin.fail()) {

            break;
        }
        else {
            cout << "Invalid Input please enter a score between 0 and 5\n";
            cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
    setEmployeeScore(score);
}

//asks user for the miles traveled and error checks it
void Employee::askForMilesTraveled()
{//error check and ask for user input 
    double miles = 0.0f;
    while (true) {
        cout << "Enter Miles Traveled: ";
        cin >> miles;
        if (miles >= 0 && miles <= 10000 && !cin.fail()) {

            break;
        }
        else {
            cout << "Invalid input please enter a value between 0 and 10000\n";
            cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
    setMilesTraveled(miles);
}

//asks user for a completed job and stores it in the vector
void Employee::askForJobs()
{
    double jobsCompleted = 0.0f;
    while (true) {
        cout << "What was the total revenue of the job? \n";
        cin >> jobsCompleted;
        if (jobsCompleted >= 0 && jobsCompleted <= 100000000 && !cin.fail()) {
            break;
        }
        else {
            cout << "Error please enter a number between 0 and 100000000\n";
            cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        }
    }
    vectorPushBack(jobsCompleted);
}