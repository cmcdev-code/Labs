#include <iostream>
#include <fstream>
#include "department.h"

#define pause system("pause")


using namespace std;
//functuion to ask for the max num of employees 
int maxNumberOfEmployees();
//will ask for the amount of products used and error check it 
double amountOfProductsUsed();
//menu function
void menu();
//will ask for a specific char and return it 
char ErrorCheckUserInput();
//will output the strinh and will error check between those bounds
int askForUserInput(string output, int lowerBound, int upperBound);



int main() {

    cout << "Collin McDevitt Lab 7 CSCN 112 \n";
    cout << "What is the name of the department ?:";
    string nameOfDepartment;
    getline(cin >> ws, nameOfDepartment);
    
    //creating department obj with constructor 
    department departmentObj(nameOfDepartment, amountOfProductsUsed(), maxNumberOfEmployees());

    //will keep looping till user enters the P
    while (true)
    {
        system("CLS");
        menu();
       
        char userChoice = ErrorCheckUserInput();//returns menu choice 
        if (userChoice == 'M') {
            departmentObj.createNewManager();
            pause;
        }
        if (userChoice == 'E') {
            if (departmentObj.getMaxEmployees() > departmentObj.getSizeOfVector())
            {
                departmentObj.vectorOfEmployeesPushBack(departmentObj.createNewEmployee());
                pause;
            }
            else {
                cout << "Max number of employees reached\n";
                pause;
            }
        }
        if (userChoice == 'R') {
            if (departmentObj.getSizeOfVector() > 0) {
                int employeeId = askForUserInput("Enter the employee ID of the employee you want to remove", 1, departmentObj.getSizeOfVector());
                departmentObj.removeEmployee(employeeId - 1);
                pause;

            }
            else {
                cout << "No employees to remove\n";
                pause;
            }
        }
        if (userChoice == 'L') {
            if (departmentObj.getSizeOfVector() > 1) 
            departmentObj.sortVectorOfEmployees();
            departmentObj.printDepartmentInfo();
            pause;
        }
        if (userChoice == 'P') {
            departmentObj.printFinalProfit();
            pause;
            break;
        }


    }


    return 0;
}







//asks for max number of EMployees and error checks it 
int maxNumberOfEmployees() {
    int maxNumOfEmployees;
    while (true) {
        cout << "Please enter the maximum number of employees: Has to be less then 50 ";
        cin >> maxNumOfEmployees;
        if (maxNumOfEmployees > 50 || maxNumOfEmployees < 0 || cin.fail()) {
            cout << "Please enter a number less then 50: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        else {
            break;
        }
    }
    return maxNumOfEmployees;
}

// asks for the amount of products used
double amountOfProductsUsed() {
    double ammountOfProducts;
    while (true) {
        cout << "Please enter the dollar amount that this department spent on products: ";
        cin >> ammountOfProducts;
        if (ammountOfProducts > 0 && ammountOfProducts < 1000000000 && !cin.fail()) {
            break;
        }
        else {
            cout << "Please enter a number between 0 and 1000000000: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
    return ammountOfProducts;
}
//menu ouput
void menu()
{
    cout << "     Main Menu\n";
    cout << " M--Add Manager\n";
    cout << " E--Add Employee\n";
    cout << " R--Remove Employee\n";
    cout << " L--List Department Info\n";
    cout << " P--Print Final Profit\n";

}

//checks the user input and will return the char 
char ErrorCheckUserInput()
{
    char userInput;
    while (true)
    {
        cout << "Please enter a single character. Example 'M': \n";

        cin >> userInput;
        if (userInput == 'M' || userInput == 'E' || userInput == 'R' || userInput == 'L' || userInput == 'P' && !cin.fail())
        {
            break;
        }
        else
        {
            cout << "Invalid input... \n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

    }
    return userInput;
}

//will output the string and error check between the bounds 
int askForUserInput(string output, int lowerBound, int upperBound)
{
    int userChoice;
    while (true)
    {
        cout << output + "\n";
        cin >> userChoice;
        if (userChoice >= lowerBound && userChoice <= upperBound && !cin.fail())
        {
            break;
        }
        else
        {
            cout << "Invalid input please enter a number between " << lowerBound << " and " << upperBound << "\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

    }

    return userChoice;

}