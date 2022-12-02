#include "completedJobs.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <time.h>
#include <iomanip>

//doing this so i don't have to type out "std::" for things i am using often 
using std::cout;
using std::cin;
using std::getline;
using std::to_string;

//function to return the price of all the stuff for the job
double completeJobs::totalPriceStuff() const
{
    return getTravelCharges() + getLaborCharges() + getProductCharges();
}
//function that will set everything to empty if there was an error in the file
void completeJobs::setValuesNull()
{
    clientName = "";
    roomsPainted = 0;
    laborCharges = 0.0f;
    numPaintCans = 0;
    productCharges = 0.0f;
    mileage = 0;
    travelCharges = 0.0f;
}
//destructor 
completeJobs::~completeJobs() {};
//default constructor 
completeJobs::completeJobs() {
    clientName = "";
    roomsPainted = 0;
    laborCharges = 0.0f;
    numPaintCans = 0;
    productCharges = 0.0f;
    mileage = 0;
    travelCharges = 0.0f;

    invoiceNumber =0;
}

//sets and gets
void completeJobs::setClientName(string clientName)
{
    this->clientName = clientName;
}
void completeJobs::setRandNum(int randNumber) {
    invoiceNumber = randNumber;

}
string completeJobs::getClientName() const
{
    return clientName;
}

void completeJobs::setRoomsPainted(int roomsPainted)
{
    this->roomsPainted = roomsPainted;
}

int completeJobs::getRoomsPainted() const
{
    return roomsPainted;
}

void completeJobs::setLaborCharges(double laborCharges)
{
    this->laborCharges = laborCharges;
}
double completeJobs::getLaborCharges() const
{
    return laborCharges;
}
void completeJobs::setNumPaintCans(int  numPaintCans)
{
    this->numPaintCans = numPaintCans;
}

int completeJobs::getNumPaintCans() const
{
    return numPaintCans;
}

void completeJobs::setProductCharges(double productCharges)
{
    this->productCharges = productCharges;
}

double completeJobs::getProductCharges() const
{
    return productCharges;
}

void completeJobs::setMileage(int mileage)
{
    this->mileage = mileage;
}

int completeJobs::getMileage() const
{
    return this->mileage;
}
void completeJobs::setTravelCharges(double travelCharges)
{
    this->travelCharges = travelCharges;
}

double completeJobs::getTravelCharges() const
{
    return travelCharges;
}
int completeJobs::getInvoiceNumber() const
{
    return invoiceNumber;
}
//function that will ask for teh client name 
void completeJobs::askForClientName()
{
    string userInputString;
    std::cout << "What is the name of the client?\n";
    cin.ignore();
    getline(cin, userInputString);
    setClientName(userInputString);
}

//function that will ask for the number of rooms that where painted for the job
void completeJobs::askForNumRoomsPainted()
{
    //int that will hold the user input 
    int userInputInt;

    while (true) {

        cout << "How many rooms where painted\n";

        cin >> userInputInt;
        //checks that the value is in a realalistic range 
        if ((userInputInt >= 0 && userInputInt <= 10000) && !cin.fail()) {
            break;
        }
        //letting the user know something about their input was not right 
        else {
            cout << "Error enter an int between 0 and 10000.\n";
            cin.clear();//clearing the input stream 
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
    //clearing the input stream
    cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    //setting number of rooms painted to the input after error checking     
    setRoomsPainted(userInputInt);
}
//function to ask for the labor charges
void completeJobs::askForLaborCharges()
{   //double to store the user input value 
    double userInputDouble;

    while (true)
    {
        cout << "What are the labor charges?\n";
        cin >> userInputDouble;
        //checks that the value is in a somewhat resonable range and that the cin isn't in fail state
        if ((userInputDouble >= 0 && userInputDouble <= 100000000 && !cin.fail())) {
            break;
        }
        else {
            //clearing cin stream and ignoring rest of stream
            cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << "Error enter a floating point number between 0 and 100000000.\n";
        }
    }
    //clearing and ignoring rest of input stream
    cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    setLaborCharges(userInputDouble);
}

//asking for how many paint cans where used 
void completeJobs::askForNumPaintCans()
{
    int userInputInt;

    while (true) {
        cout << "How many cans of paint were used?\n";
        cin >> userInputInt;
        //checks that the value is in a good range and cin not in fail state 
        if ((userInputInt >= 0 && userInputInt <= 100000) && !cin.fail()) {
            break;
        }
        else
        {
            cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << "Error enter an int between 0 and 100000.\n";
        }
    }
    //clearing and ignoring rest of input stream
    cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    setNumPaintCans(userInputInt);
}

void completeJobs::askForProductCharges()
{   //variable to hold user input 
    double userInputDouble;
    while (true) {

        cout << "How much did all the products cost?\n";
        cin >> userInputDouble;
        //checks that the input stream is not in a fail state and that the range makes sense 
        if ((userInputDouble >= 0 && userInputDouble <= 10000000) && !cin.fail()) {
            break;
        }
        else {
            cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << "Error enter a floating point number between 0 and 10000000.\n";
        }
    }
    //clearing and ignoring rest of input stream
    cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    setProductCharges(userInputDouble);
}

void completeJobs::askForMileage()
{
    //double to hold user input 
    double userInputDouble;
    while (true) {
        cout << "How many miles did you travel?\n";
        cin >> userInputDouble;
        //checks that miles travled is reasonable and that cin not in a fail state 
        if ((userInputDouble >= 0 && userInputDouble <= 25000) && !cin.fail()) {
            break;
        }
        else {
            cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << "Error enter a float between 0 and 100000.\n";

        }
    }//clearing cin and stream 
    cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    setMileage(userInputDouble + 0.4999999);//will turn to an int and append the rest of the decimal 
}

//function to ask for travel charges and error check them 
void completeJobs::askForTravelCharges()
{
    //double to hold user input 
    double userInputDouble;
    while (true)
    {
        cout << "How much were the travel charges?\n";
        cin >> userInputDouble;
        //checks that the user input is reasonable and that it isn't in a failstate
        if ((userInputDouble >= 0 && userInputDouble <= 100000000) && !cin.fail()) {
            break;
        }
        else {
            cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << "Error enter a float between 0 and 100000000.\n";

        }
    }
    //clearing stream
    cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    setTravelCharges(userInputDouble);
}

//function that will print the data for this object 
void completeJobs::printCompleteJob() const
{
    cout << "Client Name: " + getClientName() + "\n";
    cout << "Invoice number " << getInvoiceNumber() << "\n";
    cout << " Rooms Painted: " << getRoomsPainted() << "\n";
    cout << " Labor Charges: " << std::fixed << std::setprecision(2) << getLaborCharges() << '\n';
    cout << " Paint Cans: " << getNumPaintCans() << '\n';
    cout << " Product Charges: " << std::fixed << std::setprecision(2) << getProductCharges() << '\n';
    cout << " Mileage: " << getMileage() << '\n';
    cout << " Travel Charges: " << std::fixed << std::setprecision(2) << getTravelCharges() << '\n';
    cout << "Total Cost: " << std::right << std::setw(30) << std::fixed << std::setprecision(2) << totalPriceStuff() << '\n';


}
//function that will print out the data for this object to a file that is pased in 
void completeJobs::printCompleteJob(std::ofstream& out) const
{
    out << "Client Name: " + getClientName() + "\n";
    out << "Invoice number " << getInvoiceNumber() << "\n";
    out << " Rooms Painted: " << getRoomsPainted() << "\n";
    out << " Labor Charges: " << std::fixed << std::setprecision(2) << getLaborCharges() << '\n';
    out << " Paint Cans: " << getNumPaintCans() << '\n';
    out << " Product Charges: " << std::fixed << std::setprecision(2) << getProductCharges() << '\n';
    out << " Mileage: " << getMileage() << '\n';
    out << " Travel Charges: " << std::fixed << std::setprecision(2) << getTravelCharges() << '\n';
    out << "Total Cost: " << std::right << std::setw(30) << std::fixed << std::setprecision(2) << totalPriceStuff() << '\n';
}


//function that will read in the data from the file and error check it 
void completeJobs::readInFile()
{
    //if they fail to open a file 4 times then it will just set everything to null 
    int trysLeft = 4;


    while (true) {

        //goto statment if there is an execption 
        if (false)
        {
        badDataInFile:
            cout << "Non valid value was found in file.\n";
            setValuesNull();
        }
        //trys left is one less if the file had an invalid value in it or if it was unable to open
        trysLeft--;


        string userInputString("");
        cout << "What is the name of the file that you would like to open?";
        //getting rid of the white space that is in the cin stream. 
        getline(cin >> std::ws, userInputString);


        //checks that they have still have attempts left at opening the file 
        if (trysLeft < 1)
        {
            cout << "Failed to open file too many times\n";
            setValuesNull();
            break;
        }

        //creating ifstream object 
        std::ifstream in;
        //opeing the file with user input 
        in.open(userInputString);

        //checks that the file is oppened 

        if (in.is_open())
        {
            //string that will hold the data from the file 
            string string_for_file;

            //using getline for the file input 
            getline(in, string_for_file);

            setClientName(string_for_file);

            //using getline again to grab the data in the file
            getline(in, string_for_file);

            /*checking the ascii values of every char that was grabbed if
            its value is not in the right range it will close the value set everything to empty and then ask
            for the name of a new file*/
            for (int i = 0; i < string_for_file.length(); i++) {
                if (int(string_for_file[i] > 57) || int(string_for_file[i] < 48)) {
                    in.close();
                    goto badDataInFile;
                }
            }
            //if the values are in the right ascii range then it will convert the string to an int and store it in the object
            setRoomsPainted(std::stoi(string_for_file));


            getline(in, string_for_file);
            /*checking the ascii values of every char that was grabbed if
            its value is not in the right range it will close the value set everything to empty and then ask
            for the name of a new file*/
            for (int i = 0; i < string_for_file.length(); i++) {
                //the 46 value is for the '.' because this type should be a double 
                if (int(string_for_file[i] > 57) || int(string_for_file[i] < 48) && int(string_for_file[i] != 46)) {
                    in.close();
                    goto badDataInFile;
                }
            }
            //if it passed then it will convert string to double and store it in object
            setLaborCharges(std::stod(string_for_file));

            getline(in, string_for_file);
            /*checking the ascii values of every char that was grabbed if
           its value is not in the right range it will close the value set everything to empty and then ask
           for the name of a new file*/
            for (int i = 0; i < string_for_file.length(); i++) {
                if (int(string_for_file[i] > 57) || int(string_for_file[i] < 48)) {
                    in.close();
                    goto badDataInFile;
                }
            }
            //if it passed then it will convert string to an int and store it in object
            setNumPaintCans(std::stoi(string_for_file));

            getline(in, string_for_file);
            /*checking the ascii values of every char that was grabbed if
            its value is not in the right range it will close the value set everything to empty and then ask
            for the name of a new file*/
            for (int i = 0; i < string_for_file.length(); i++) {
                if (int(string_for_file[i] > 57) || int(string_for_file[i] < 48) && int(string_for_file[i] != 46)) {
                    in.close();
                    goto badDataInFile;
                }
            }
            setProductCharges(std::stod(string_for_file));


            getline(in, string_for_file);
            /*checking the ascii values of every char that was grabbed if
           its value is not in the right range it will close the value set everything to empty and then ask
           for the name of a new file*/
            for (int i = 0; i < string_for_file.length(); i++) {
                if (int(string_for_file[i] > 57) || int(string_for_file[i] < 48) && int(string_for_file[i] != 46)) {
                    in.close();
                    goto badDataInFile;
                }
            }
            setMileage(std::stoi(string_for_file));


            getline(in, string_for_file);
            for (int i = 0; i < string_for_file.length(); i++) {
                if (int(string_for_file[i] > 57) || int(string_for_file[i] < 48) && int(string_for_file[i] != 46)) {
                    in.close();
                    goto badDataInFile;
                }
            }
            //if it passed all of the casses then it convert this to a double close the file and break out of the loop
            setTravelCharges(std::stod(string_for_file));
            in.close();
            break;
        }
        else {
            in.clear();
            cout << "Error when opening file you have " << trysLeft << " attempts left before the object's values are set as empty.";
            cin.ignore();
        }
    }
}