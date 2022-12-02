#include "manager.h"
#include <iomanip>
#include <iostream>
using std::cin;
using std::cout;


manager::~manager() {

};


//default constructor
manager::manager() : person()
{

    jobTitle = "";
    salary = -1;
    promotionDate.setDate(0, 0, 0000);

}
//multi argument constructor
manager::manager(string jobTitle, double salary, int promotionDay, int promotionMonth, int promotionYear,
    string Fname, string lName, int ID,
    int birthDayD, int birthDayMonth, int birthDayYear, int hirringDay, int hirringMonth, int hirringYear)
    :person(Fname, lName, ID, birthDayD, birthDayMonth, birthDayYear, hirringDay, hirringMonth, hirringYear)
{

    this->jobTitle = jobTitle;
    this->salary = salary;
    this->promotionDate.setDate(promotionDay, promotionMonth, promotionYear);
}
//sets private member variables 
void manager::setJobTitle(string jobTitle)
{
    this->jobTitle = jobTitle;
}
void manager::setSalary(double salary)
{
    this->salary = salary;
}
void manager::setPromotionDate(int day, int month, int year)
{
    promotionDate.setDate(day, month, year);
}
//gets private member variables
string manager::getJobTitle() const
{
    return jobTitle;
}

double manager::getSalary() const
{
    return salary;
}
//defining << operator overload 
std::ostream& operator <<(std::ostream& out, const manager& localObj)
{
    out << std::left << std::setw(30) << "Name:" << std::right << localObj.getFname() + " " + localObj.getLname() + "\n";
    out << std::left << std::setw(30) << "Title:" << std::right << localObj.getJobTitle() + "\n";
    out << std::left << std::setw(30) << "Employee ID:" << std::right << localObj.getId() << "\n";
    out << std::left << std::setw(30) << "Birth Day:" << std::right << localObj.birthDay << "\n";
    out << std::left << std::setw(30) << "Date Hirred:" << std::right << localObj.hirringDate << "\n";
    out << std::left << std::setw(30) << "Promotion Date:" << localObj.promotionDate << "\n";
    out << std::left << std::setw(30) << "Salary:" << std::fixed << std::setprecision(2) << localObj.getSalary() << "\n";
    return out;
}
//asks for the job title from the user
void manager::askForJobTitle()
{
    std::string jobTitle;
    std::cout << "Enter the job title: ";
    std::getline(std::cin >> std::ws, jobTitle);
    setJobTitle(jobTitle);
}

//asks for the salary from the user and error checks it
void manager::askForSalary()
{//error check and ask for user input 
    double salary = 0.0f;
    while (true) {
        cout << "Enter manager Salary: ";
        cin >> salary;
        if (salary >= 0 && salary <= 10000000 && !cin.fail()) {
            break;
        }
        else {
            cout << "Invalid Input please enter a salary between 0 and 10000000\n";
            cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
    setSalary(salary);
}
