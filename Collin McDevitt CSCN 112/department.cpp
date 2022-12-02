#include "department.h"
#include <iostream>
#include <iomanip>
#include <algorithm>

//constants
double const  PRICE_PER_MILE = 5.00;
double const COST_OF_LABOR = 200;

department::~department() {

};


//removes an employee at a specific index
void department::removeEmployee(int index)
{
    if (index >= 0 && index < employees.size())
    {
        employees.erase(employees.begin() + index);
    }
    else//error checks that it actually is in the vector 
    {
        std::cout << "Out of range of vector" << std::endl;
    }
}
//default constructor
department::department()
{
    departmentName = "";
    amountOfProdutcsUsed = 0.0;
    maxEmployees = 0;
}
//multi argument constructor
department::department(string departmentName, double ammountOfProductsUsed, int maxNumOfEmployees)
{
    this->departmentName = departmentName;
    this->amountOfProdutcsUsed = ammountOfProductsUsed;
    this->maxEmployees = maxNumOfEmployees;
}
//sets private member variables
void department::setDepartmentName(string departmentName)
{
    this->departmentName = departmentName;
}

//gets private member variables

int department::getMaxEmployees() const
{
    return this->maxEmployees;
}

int department::getSizeOfVector() const
{
    return employees.size();
}
string department::getDepartmentName() const
{
    return this->departmentName;
}
//creates a new employee object and places it at the back of the vector
Employee department::createNewEmployee()
{
    //temp employee object that will be returned 
    Employee tempEmployee;
    //asking for the data for the employee 
    tempEmployee.askForFname();
    tempEmployee.askForLname();

    //setting their ID to be their index in the vector+1
    tempEmployee.setID(employees.size() + 1);
    //month day year
    int m(0), d(0), y(0);

    //tokinizes the data and error checks it 
    tokenizeDate("Enter birth date: ", m, d, y);

    //sets the birth day
    tempEmployee.birthDay.setDate(d, m, y);

    //tokinizes the data and error checks it
    tokenizeDate("Enter hiring date: ", m, d, y);

    //sets the hirring date
    tempEmployee.hirringDate.setDate(d, m, y);

    //asks for the employee score
    tempEmployee.askForEmployeeScore();
    //asks for the ammount of miles traveled
    tempEmployee.askForMilesTraveled();
    //will ask the user to add jobs till they do not want to 
    bool userChoice = true;
    while (userChoice)
    {
        std::cout << "Enter a 1 to add another job entry or 0 to exit: \n";
        std::cin >>std::ws >>userChoice;
        if (userChoice && !std::cin.fail())
        {
            tempEmployee.askForJobs();
        }
        else if (!userChoice) {}
        else {
            std::cout << "Invalid input, please enter a 1 or 0\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }


    //returns the employee objcet
    return tempEmployee;
}
//tokinizes the data 
void department::tokenizeDate(string output, int& mon, int& day, int& year)
{
    //to see if they entered valid data 
    bool validInput = 1;
    while (true) {

        validInput = 1;
        //telling the user what to ente 
        std::cout << "\n" + output + " as mm/dd//yyyy:";
        //string to hold what the user enters
        string dateString;


        getline(std::cin >> std::ws, dateString);

        //string to add the data too 
        string tempString;

        //checks that the user input is in the right format 
        for (int i = 0; i < dateString.length(); i++) {
            //ascii value of / is 47 and ascii value of 9 is 57 
            if (int(dateString[i]) < 47 || int(dateString[i] > 57))
            {
                //will set that the valid input is false and break out of the loop and let the user know 
                validInput = 0;
                std::cout << "Non valid value was entered please try again\n";
                break;
            }

        }

        if (dateString.length() != 10)
        {
            validInput = 0;
            std::cout << "Non valid value was entered please try again\n";
        }

        int counter = 0;


        if (validInput)
        {
            for (int i = 0; i < dateString.length(); i++)//for loop that will go through and toknize the data 
            {
                //if the char does != '/' then it will add that char to the temp string
                if (dateString[i] != '/') {
                    tempString += dateString[i];
                }

                //when the char is == '/' or the index is at the last
                if (int(dateString[i]) == 47 || i == dateString.length() - 1)
                {
                    //year
                    if (counter == 2)
                    {
                        //if i != 9 then there two too many digits and it will tell the user to renter the date 
                        if (i != 9) {
                            validInput = 0;
                            std::cout << "Non valid value was entered please try again\n";
                            break;
                        }
                        //else it will convert the temp string to an int and will set it = to empty string 
                        year = std::stoi(tempString);
                        tempString = "";

                        counter++;
                    }
                    //mon
                    if (counter == 1)
                    {
                        //if i != 5 then it is too long and there is an error and it will ask the user to enter the the data again 
                        if (i != 5) {
                            validInput = 0;
                            std::cout << "Non valid value was entered please try again\n";
                            break;
                        }
                        //setting the mon to the int tempSTring
                        mon = std::stoi(tempString);
                        tempString = "";//clearing the string 

                        counter++;
                    }
                    //day
                    if (counter == 0)
                    {   //if i !=2 then there is an error and it will tell the user 
                        if (i != 2) {
                            validInput = 0;
                            std::cout << "Non valid value was entered please try again\n";
                            break;
                        }
                        // will turn the tempsting to an int and set it = to the day 
                        day = std::stoi(tempString);
                        tempString = "";
                        counter++;
                    }
                }
            }
        }
        //if it gets through and there was valid input it will break 
        if (validInput) {
            break;
        }
    }

}

//will create a new manager 
void department::createNewManager()
{
    //if the salary != -1 then there already is a manager 
    if (Manager.getSalary() != -1) {
        std::cout << "Manager Already Exists " + Manager.getFname() + " " + Manager.getLname() + "\n";
    }
    //asks them for the data about the manager 
    else
    {//same as the employee 
        Manager.askForFname();
        Manager.askForLname();
        Manager.askForID();
        Manager.askForJobTitle();
        int m(0), d(0), y(0);
        tokenizeDate("Enter birth date: ", m, d, y);
        Manager.birthDay.setDate(d, m, y);
        tokenizeDate("Enter hiring date: ", m, d, y);
        Manager.hirringDate.setDate(d, m, y);
        tokenizeDate("Enter promotion date: ", m, d, y);
        Manager.promotionDate.setDate(d, m, y);
        Manager.askForSalary();

    }
}


void department::sortVectorOfEmployees()
{//will sort the vector of employees 
    std::sort(employees.begin(), employees.end());
}
//puts employee object at the back of the vector 
void department::vectorOfEmployeesPushBack(Employee employeeObj)
{
    employees.push_back(employeeObj);
}

// will print all the info for the employees in the vector 
void department::printVectorOfEmployees() const
{
    for (int i = 0; i < employees.size(); i++)
    {
        std::cout << "----------------------------------------\n";
        std::cout << employees[i];
        std::cout << "----------------------------------------\n";
    }
}
//will print all the infor for the department and will check if there actualy is a manager and employees
void department::printDepartmentInfo() const
{
    std::cout << "----------------------------------------\n";
    std::cout << "Department Name: " << getDepartmentName() << std::endl;
    std::cout << "----------------------------------------\n";
    std::cout << "Capacity: " << getMaxEmployees() << std::endl;
    std::cout << "Product Cost: " << amountOfProdutcsUsed << std::endl;
    if (Manager.getSalary() != -1) {
        std::cout << "Manager Info: \n";
        std::cout << Manager;
    }
    else { std::cout << "No Manager\n"; }
    if (employees.size() > 0) {
        std::cout << "Employees Info: \n";
        printVectorOfEmployees();
    }


}
//will output the final profit for the department 
void department::printFinalProfit() const {
    std::cout << "--------------------------------------------------------------\n";
    std::cout << "                      Wepainthouses LLC \n";
    std::cout << "--------------------------------------------------------------\n";
    std::cout << "Department Profit Calculation for: " + getDepartmentName() + "\n";
    if (Manager.getSalary() != -1) {
        std::cout << "Manager                   " + Manager.getFname() + " " + Manager.getLname() + "\n";
    }
    std::cout << "Total income:" << std::right << std::setw(28) << std::fixed << std::setprecision(2) << "$" << totalIncome() << "\n";
    std::cout << "Cost of Products:" << std::right << std::setw(25) << std::fixed << std::setprecision(2) << "$" << amountOfProdutcsUsed << "\n";
    std::cout << "Cost of Labor:" << std::right << std::setw(27) << std::fixed << std::setprecision(2) << "$" << employees.size() * COST_OF_LABOR << "\n";
    std::cout << "Cost of travel:" << std::right << std::setw(26) << std::fixed << std::setprecision(2) << "$" << costOfDistance() << '\n';
    std::cout << "Avg employee raiting:" << std::right << std::setw(20) << std::fixed << std::setprecision(2) << "$" << avgEmployeeRaiting() << "\n";
    std::cout << "Final Profit:" << std::right << std::setw(28) << std::fixed << std::setprecision(2) << "$" << totalIncome() - amountOfProdutcsUsed - employees.size()
        * COST_OF_LABOR - costOfDistance() - ((Manager.getSalary()==-1) ? 0: Manager.getSalary()) << "\n";//inline if else


}
//will return the totall income for all the employees
double department::totalIncome() const
{
    double totalIncome = 0;
    for (int i = 0; i < employees.size(); i++)
    {
        totalIncome += employees.at(i).employeeRev();
    }
    return totalIncome;
}
//will calculate the cost for all the distance that was traveled from all the employees 
double department::costOfDistance() const
{
    double cost = 0;
    for (int i = 0; i < employees.size(); i++)
    {
        cost += employees.at(i).getMilesTraveled();
    }
    return cost * PRICE_PER_MILE;


}
//will calculate the avg employee raiting 
double department::avgEmployeeRaiting() const {
    double avg = 0;
    for (int i = 0; i < employees.size(); i++)
    {
        avg += employees.at(i).getEmployeeScore();
    }
    if (employees.size() > 0)
    {
        avg = avg / employees.size();
    }
    else { avg = 0; }
    return avg;
}