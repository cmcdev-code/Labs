#include <iostream>
#include <iomanip>
#include "employee.h"
#include <string>
#include <fstream>
#include <stdlib.h>

using namespace std;

void menuFunction(Employee& localObj);//outputs menu 
int menuChoice();//will error check and ask for user input 
Employee userDefined();//will ask for user input for names 
string fileName();//will ask for the name user input for file names
string ReadinGetLine(ifstream& in);//will get the file value on that line
void allFileInput(int index, ifstream& in, Employee& loclaObj);//will take file input and store in Employee object
double scoreIn();//Will ask for the score
void allFileOut(ofstream& out, Employee& localObj);//will output to file
void clearObj(Employee& localObj);//will clear object 


int main() {

    Employee employee;//creating object
    ifstream in;//creating the if and of stream variables 
    ofstream out;
    cout << "Collin McDevitt CSCN 112 Lab-3 \n";

    while (true) {//main loop 
        system("CLS");
        string fName = "";//filename string 
        menuFunction(employee);//Function that will output the main menu 
        int menuOption = 0;//varriable that will hold which menu option they chose 

        menuOption = menuChoice();//asks which menu option they chose and stores it 



        if (menuOption == 1) {//checks the menu option 
            system("CLS");

            clearObj(employee);//function that will clear the data for the employee object 

            fName = fileName();//stores the name that the user entered for the file

            in.open(fName);//trys to open the file

            if (in.is_open()) {//checks if the file opened 
                allFileInput(0, in, employee);//checks the file for  the correct data and stores it 
            }
            else {//if file doesn't open it will clear the ifstream 
                cout << "Error couldn't open please try again \n";//prompts the user 
                in.clear();
                cin.ignore();
            }
        }
        if (menuOption == 2) {//creates new user and the userDefined will ask for name and create an employee object from the constructor
            system("CLS");
            employee = userDefined();
        }
        if (menuOption == 3) {//adds score to vector 
            system("CLS");
            employee.vectorPushBack(scoreIn());
        }
        if (menuOption == 4) {//will store the data to a file 
            system("CLS");
            fName = employee.getName() + ".txt";//will store the name of the file 
            ofstream out;//creating the ofStream variable
            employee.sortVector();//sorts vector 
            out.open(fName);//opening the file 
            allFileOut(out, employee);//function that will output all the necasary class info to file
            out.close();//closes the file 
            cout << "Wrote the data to file " << fName << "\n";
            std::string pause;
            std::cout << "Hit enter to continue. \n";
            std::cin.ignore();
            std::getline(std::cin, pause);
        }
        if (menuOption == 5) {
            system("CLS");
            employee.sortVector();//sorts vector 
            employee.printEmployeeInfo();
        }//prints employee info 
        if (menuOption == 6) {
            break;//breaks out of loop
        }
    }

    cout << "Program terminated succsefully";
    return 0;
}
Employee userDefined() {
    string localCity(""), localName(""), localId("");
    cout << "What is the name of the employee? \n";//asks name of employee
    cin.ignore();
    getline(cin, localName);

    cout << "What is the name of the city? \n";//asks city name
    getline(cin, localCity);

    cout << "What is their ID?\n";//asks for the name of the ID
    getline(cin, localId);
    Employee local(localName, localCity, localId);//creates local Employee Obj and calls the 3 arg constructor
    return local;//returns local object
}

string fileName() {//asks for the name of the file
    string localfileNAme;
    cin.clear();
    cout << "What is the name of the file (including extension)?\n";
    cin.ignore();
    getline(cin, localfileNAme);//gets the name of the file
    return localfileNAme;//returns name of the file 
}


void menuFunction(Employee& localObj) {//function that will output the main menu 
    cout << "************************************************** \n \n";
    cout << setw(20) << right << "MENU\n";
    cout << setw(20) << left << "Current Employee:" << right << localObj.getName();//local object name
    cout << endl;
    cout << "1- Switch/Open Employee File \n";
    cout << "2- Create New Employee\n";
    cout << "3- Add Score to current Employee \n";
    cout << "4- Save Current Employee Info to File \n";
    cout << "5- Print Employee Info \n";
    cout << "6- Quit \n \n";
    cout << "************************************************** \n";
}

int menuChoice() {//will ask for what choice they want and then error check and return it 
    int x = 0;//local variable to store what they  enter 

    while (true) {
        cout << "Please select your menu choice :\n";
        cin >> x;//asks for user input
        if ((x > 0) && (x < 7) && !(cin.fail())) {//checks wheather they stream is in a fial state and that the number the user entered is correct 
            break;//breaks out of loop 
        }
        else {//will clear stream and let the user know that they entered a wrong number 
            cout << "Error please select from one the options: Enter an int from 1-6 \n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
    return x;//returns the value 
}

string ReadinGetLine(ifstream& in) {//will get the entire line from a file and return it as a string 

    string local;//local string 
    getline(in, local);//getting the value 
    return local;
}

void allFileInput(int index, ifstream& in, Employee& localObj) {//will get the vale for name,city, and id from file and store it in obj

    double num = 0;// value to hold the value in the file that will be stored in the vector in th obj

    while (!in.fail() && num >= 0) {//if the ifstream in a fail state will not run 

        if (index == 0) {//on the first loop then will get the first three lines and store them in the member variable 
            localObj.setName(ReadinGetLine(in));//storing name from file
            localObj.setCity(ReadinGetLine(in));//storing city from file 
            localObj.setID(ReadinGetLine(in));//storing id from file
            index++;
        }
        in >> num;//getting the number from the file 

        if (in.fail() && !in.eof()) {//if in is in error and its not at the emd of the file will teriminate 
            cout << "A non numeric number was read in. Program will end. \n";
            in.close();//closing file
            exit(1);//in stdlib.h will terminate whole program
            //found documantation here https://learn.microsoft.com/en-us/cpp/cpp/program-termination?view=msvc-170
        }
        else if ((in.fail() && in.eof())) {
            cout << "End of file reached. \n";//if it is in a fail state, but is at the end of the file then it was reached without error 
        }
        else if (num < 1 || num>5) {
            cout << "Error a number either less than 1 or greater then 5 was found. Program will end.\n";
            in.close();//closing file 
            exit(1);//from stdlib.h will terminate whole program
            //found documantation here https://learn.microsoft.com/en-us/cpp/cpp/program-termination?view=msvc-170 
        }
        else {
            localObj.vectorPushBack(num);//will store the number in the vector 
        }
    }
    in.close();//will close the file 
}


double scoreIn() {//will be called if the user wants to add a score
    double localScore = 0;
    while (true) {
        std::cout << "What is the score of the employee? \n";
        std::cin >> localScore;//storing what the user entered 
        if (localScore >= 1 && localScore <= 5 && !(std::cin.fail())) {//checking that the score is double and in the correct range 
            break;//breaks out of loop 
        }
        else {//will clear the stream and tell the user how to enter the score
            std::cout << "Error please enter a number greater than or equal to 1 and also less than or equal to 5.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
    return localScore;
}

void allFileOut(ofstream& out, Employee& localObj) {

    out << localObj.getName() << '\n';//writes name to file 
    out << localObj.getCity() << '\n';//writes the city to the file
    out << localObj.getID() << '\n';//writes the ID to the file 

    if (localObj.sizeVectorScore() > 0) {//checks wheather the vector has any values in it and will

        for (int i = 0; i < localObj.sizeVectorScore(); i++) {
            //writes to the file the number from the vector 
            out << localObj.vectorAtIndex(i) << '\n';
        }
    }
}
//will be called if the user switches files 
void clearObj(Employee& localObj) {
    localObj.setCity("");//sets city to nothing 
    localObj.setID("");//sets ID to nothing
    localObj.setName("");//sets name to nothing
    localObj.delVector();//clears the vector 
}
