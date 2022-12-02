#pragma once
#include "employee.h"
#include "manager.h"
#include <vector>




class department {

public:


    ~department();

    //function to remove an employee object at a specific index in the vector
    void removeEmployee(int index);

    //default constructor
    department();
    //multi argument constructor
    department(string departmentName, double ammountOfProdcutsUsed, int maxNumOfEmployees);

    //function to set the private member variables/
    void setDepartmentName(string departmentName);

    //function to get private member variables
    string getDepartmentName() const;
    int getSizeOfVector() const;
    int getMaxEmployees() const;


    //function to create a new manager
    void createNewManager();

    //sorts vector of employees by employee ID
    void sortVectorOfEmployees();

    //places employee object at the back of the vector
    void vectorOfEmployeesPushBack(Employee employeeObj);


    //prints deparment info
    void printDepartmentInfo() const;
    //prints final data 
    void printFinalProfit() const;
    //function to create a new employee object and push it back into the vector
    Employee createNewEmployee();


private:

    std::vector<Employee> employees;
    manager Manager;
    int maxEmployees;
    string departmentName;
    double amountOfProdutcsUsed;

    double totalIncome() const;
    double costOfDistance() const;
    double avgEmployeeRaiting() const;

    //function that will print out all the employees in the vector
    void printVectorOfEmployees() const;


    //function to tokenize data 
    void tokenizeDate(string output, int& mon, int& day, int& year);




};
