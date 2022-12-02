#include <iostream>
#include "completedJobs.h"
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <time.h>

using namespace std;

//function that will output what the string is and will error check between the two int bounds and return the int 
int userInputint(string, int, int);

//function that will output the string and use getline to return what the user entered 
string inputFromUserStr(string);

//function for the menu 
void menu();
//function that will output all the data to the terminal 
void finalOutput(completeJobs* array[], int length, string month);
//functon that will output all the data to the file 
void finalOutputFile(completeJobs* array[], int length, string month);

int randFunc();

int main() {

    cout << "Collin McDevitt Lab 6\n";

    
    //month that will be brought in from user 
    string month = inputFromUserStr("Month: ");

    //will ask the user for the number of jobs completed and error check for a reasonable amount of jobs completed in this case 0-100
    int numberOfJobsCompleted = userInputint("How many jobs were completed in " + month + "?", 0, 100);

    //dynamic array of ptrs 
    completeJobs** jobs = new completeJobs * [numberOfJobsCompleted];

    //will loop through array and ask for the choice if they want the input from the file or entered manually 
    for (int i = 0; i < numberOfJobsCompleted; i++)
    {
        //dynamic object 
        jobs[i] = new completeJobs();
        jobs[i]->setRandNum(randFunc());
        //menu
        menu();

        //will ask the user for the input and error check between 1-2
        int chosenOption = userInputint("", 1, 2);


        /*if the user enters a 1 it will ask call the readInFile function that will
        error check both file and if it oppend and store it in the object*/
        if (chosenOption == 1)
        {
            jobs[i]->readInFile();
        }
        /* if they entered a 2 then it will ask for all the member variables of the object*/
        if (chosenOption == 2)
        {
            jobs[i]->askForClientName();
            jobs[i]->askForNumRoomsPainted();
            jobs[i]->askForLaborCharges();
            jobs[i]->askForNumPaintCans();
            jobs[i]->askForProductCharges();
            jobs[i]->askForMileage();
            jobs[i]->askForTravelCharges();
        }
    }

    //will print out the output with all the info to the terminal 
    finalOutput(jobs, numberOfJobsCompleted, month);

    //will ask the user if they would like to store the info in a file or not 
    int storeinFile = userInputint("Store in file? \n 1-Yes \n 2-No ", 1, 2);
    if (storeinFile == 1)
    {
        //if they entered a 1 then it will output all the data to the file 
        finalOutputFile(jobs, numberOfJobsCompleted, month);
    }

    //clearing memory   
    for (int i = 0; i < numberOfJobsCompleted; i++)
    {
        delete jobs[i];
        jobs[i] = nullptr;
    }
    delete[] jobs;

    return 0;
}


//will take in three paramters and will output the string and error check that the users entered value is between the two bounds 
int userInputint(string outputStr, int lowerBound, int upperBound)
{
    //local int that will be returned
    int localInt;

    while (true)
    {

        cout << outputStr << '\n';
        cin >> localInt;

        //will check that user entered value is between the lower and upper bound and that the input stream isn't in a fail state 
        if (localInt >= lowerBound && localInt <= upperBound && !cin.fail())
        {
            break;
        }
        //if they did not enter the value then it will tell them that they need to enter a value between the values
        else
        {

            cout << "You must enter an int between " << lowerBound << " and " << upperBound << '\n';
            cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }

    return localInt;
}
//will output the string that is in the paramter and return the string 
string inputFromUserStr(string outPut)
{
    string localString;
    cout << outPut;
    getline(cin, localString);
    return localString;
}

//just the menu 
void menu()
{
    cout << "1- Read in from file. \n";
    cout << "2- Enter data manually.";
}

//will output all the data from all  the arrays and will go to the terminal 
void finalOutput(completeJobs* array[], int length, string month) {
    cout << "*****************************************\n";
    cout << "           WE PAINT HOUSES LLC   \n";
    cout << "            Revenue for " + month + "\n";
    cout << "*****************************************\n";
    cout << "We Paint Houses LLC\n";
    cout << "1971 University Blvd \n";
    cout << "Lynchburg, VA 24502\n";
    cout << "123-456-7891\n";
    cout << "wepainthousesllc.com\n";
    cout << "-----------------------------------------\n";
    //will call the print function on that object 
    for (int i = 0; i < length; i++)
    {
        array[i]->printCompleteJob();
        cout << "\n";
    }

    double totalRev=0;
    //will calc the total rev from all the completed jobs
    for (int i = 0; i < length; i++)
    {
        totalRev += array[i]->totalPriceStuff();
    }
    //will output the total rev 
    cout << "-----------------------------------------\n";
    cout << "Total revanue for " + month << "              " << std::fixed << std::setprecision(2) << "$" << totalRev << "\n";
    cout << "-----------------------------------------\n";
}

//will output all the data from all  the arrays and will go to the file
void finalOutputFile(completeJobs* array[], int length, string month)
{
    //will try to open the file and if it doesn't open it will allow them 4 more chances 
    int trysLeft = 4;

    while (true)
    {
        string lclStr;
        cout << "What is the name of the file that you would like to output to?\n";
        cin.ignore();

        getline(cin, lclStr);

        if (trysLeft < 1)
        {
            cout << "Failed to open the file too many times \n";
        }
        //creating ofstream object    
        ofstream out;
        //opening the object 
        out.open(lclStr);

        //checks whather the file is open or not if it is then it will output the same thing as the finalOutput but to a file instead 
        if (out.is_open()) {

            out << "*****************************************\n";
            out << "          WE PAINT HOUSES LLC   \n";
            out << "          Revenue for " + month + "\n";
            out << "*****************************************\n";
            out << "We Paint Houses LLC\n";
            out << "1971 University Blvd \n";
            out << "Lynchburg, VA 24502\n";
            out << "123-456-7891\n";
            out << "wepainthousesllc.com\n";
            out << "-----------------------------------------\n";
            for (int i = 0; i < length; i++) {
                array[i]->printCompleteJob(out);
                out << "\n";
            }

            double totalRev=0;
            for (int i = 0; i < length; i++)
            {
                totalRev += array[i]->totalPriceStuff();
            }
            out << "-----------------------------------------\n";
            out << "Total revanue for " + month << "              " << std::fixed << std::setprecision(2) << "$" << totalRev << "\n";
            out << "-----------------------------------------\n";
            break;
        }
        else {
            out.clear();
            trysLeft--;
            cout << "Error when opening file you have " << trysLeft << " attempts left before the program will terminate.\n";
        }

        //closing the file 
        out.close();
    }
}
int randFunc() {
    //https://www.geeksforgeeks.org/rand-and-srand-in-ccpp/
    //creates a seed for the random number generator 
    std::srand(time(0));
    //mod the rand to get the numbers between 0-1000
     return std::rand() % 1001;
}