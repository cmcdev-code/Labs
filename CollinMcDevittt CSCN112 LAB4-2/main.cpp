#include <iostream>
#include <iomanip>
#include "house.h"
#include <string>
#include <fstream>


using namespace std;

//outputs menu
void menuFunction(house& localObj);

//will error check and ask for user input 
char menuChoice();
//will ask for user input for the room that will be stored in the house  
rooms roomAddVector();
//will get the name on that line

void allFileOut(ofstream& out, house& localObj);//will output to file

//will ask and error check if the user wants to store to a file 
bool wantsToStoreTofile();

//function that will print out the details for the rooms 
void printRooms(house& localObj);

//functions that will ask the user for input and error check it 
string userName();
int maxNumRooms();
double distance();



int main() {

    //getting user inputs and will error check for the constructor 
    string obj = userName();
    int numRoom = maxNumRooms();
    double dist = distance();

    house Test(obj, numRoom, dist);//creating object



    cout << "Collin McDevitt CSCN 112 Lab-4 \n";

    while (true) {//main loop 

        menuFunction(Test);//Function that will output the main menu
        char menuOption = menuChoice();//asks which menu option they chose and stores it 

        Test.sizeVectorRooms();

        if (menuOption == 'A' || menuOption == 'a') {//checks the menu option 
            if (Test.sizeVectorRooms() == Test.getNumberOfRooms()) {
                cout << "The max number of rooms has been reached. \n";
            }
            else {
                rooms localObj = roomAddVector();
                Test.vectorPushBack(localObj); //will call the function that will ask for the input and then return that object

            }
        }
        if (menuOption == 'L' || menuOption == 'l') {//creates new user and the userDefined will ask for name and create an employee object from the constructor

            printRooms(Test);
        }

        if (menuOption == 'Q' || menuOption == 'q') {//will store the data to a file 
            Test.printHouseInfo();//letting the user see the data before they save to a file 
            if (wantsToStoreTofile()) {
                string fName = "";//filename string 
                cout << "What is the name of the file?";
                cin.ignore();
                getline(cin, fName);
                ofstream out;
                out.open(fName);//opening a file to output too 
                allFileOut(out, Test);
                out.close();//closing the FILE!!

            }
            break;
        }
    }


    cout << "Program terminated succsefully";
    return 0;
}


rooms roomAddVector() {
    rooms localObj;//localObject that will be returned 
    localObj.setHeight(localObj.inputFromUserHeight());//getting the user input for length width and height
    localObj.setLength(localObj.inputFromUserLength());
    localObj.setWidth(localObj.inputFromUserWidth());

    localObj.setNumberOfCoats(localObj.inputFromUserNumCoats());//setting number of coats


    //setting the volume and the ammount of paint needed for the object  
    localObj.setVolume();
    localObj.setPaintNeeded();

    return localObj;
}

string fileName() {//asks for the name of the file
    string localfileNAme;
    cin.clear();
    cout << "What is the name of the file (including extension)?\n";
    cin.ignore();
    getline(cin, localfileNAme);//gets the name of the file
    return localfileNAme;//returns name of the file 
}


void menuFunction(house& localObj) {//function that will output the main menu 
    cout << "************************************************** \n \n";
    cout << setw(20) << right << "MENU\n";
    cout << "A- Add a room to the house\n";
    cout << "L- List all the rooms currently in the house\n";
    cout << "Q- Quit and prepare invoice \n \n";
    cout << "************************************************** \n";
}

char menuChoice() {//will ask for what choice they want and then error check and return it 
    char x = '0';//local variable to store what they  enter 

    while (true) {
        cout << "Please select your menu choice :\n";
        cin >> x;//asks for user input
        if ((x == 'A' || x == 'a' || x == 'L' || x == 'l' || x == 'Q' || x == 'q') && !(cin.fail())) {
            break;
        }
        else
        {//will clear stream and let the user know that they entered a wrong number 
            cout << "Error please select from one the options: Enter a letter from the following list (A,a,L,l,Q,q)\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
    return x;//returns the value 
}
//function that will ask wheather they want to output to a file
bool wantsToStoreTofile() {
    int input = 0;
    bool localBool;
    while (true) {
        cout << "Would you like to store the invoice to a file? \n";
        cout << "Enter a 1 for yes and a 0 for no.";
        cin >> input;
        if (input == 0 && !(cin.fail())) {
            localBool = false;
            break;
        }if (input == 1 && !(cin.fail())) {
            localBool = true;
            break;
        }
        else {
            cout << "Error please enter either a 1 or a 0. \n";
            cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
    return localBool;
}


//function that will take in the ofstream and the object and will output to the file 
void allFileOut(ofstream& out, house& localObj) {



    double localCost = 0;

    //outputs the info  for the house
    out << "***************************************************************************" << '\n';

    out << std::setw(40) << std::right << localObj.getName() << '\n';
    out << std::setw(45) << "Final Invoice \n";

    out << "***************************************************************************" << '\n' << '\n';

    out << "WePaintHouses LLC\n";
    out << "1971 University Blvd\n";
    out << "Lychburg,VA 24502 \n";
    out << "4344554545\n";
    out << "wepainthousesllc.com\n";
    out << "Billed to:" << localObj.getName() << '\n';





    out << "---------------------------------------------------------------------------" << "\n";

    out << std::setw(45) << std::right << "Labor Charges\n";
    out << std::setw(45) << std::right << "-------------\n";
    out << std::left << "Rooms" << std::setw(17) << std::right << "Number of Coats" << std::setw(17) << std::right << "Hourly Rate" << std::setw(17) << std::right << "Total\n";
    out << std::setw(4) << std::right << localObj.getNumberOfRooms() << std::setw(17) << std::right << localObj.getNumberOfCoats() << std::setw(17) << std::right << HOURLYRATE << std::setw(15) << std::right << std::fixed
        << std::setprecision(2) << '$' << localObj.getNumberOfCoats() * HOURLYRATE << std::endl << std::endl;


    //checks that the vector isnt 0 elements
    if (localObj.sizeVectorRooms() > 0) {

        //ouputs the data that will depened on the vector 
        out << std::setw(45) << "Product Charges: \n";
        out << std::setw(45) << "---------------- \n";

        //formating for the table 
        //std::cout<<std::left<<"Rooms"<<std::setw(17)<<std::right<<"Number of Coats"<<std::setw(17)<<std::right<<"Hourly Rate"<<std::setw(17)<<std::right<<"Total\n";
        out << std::left << "Room#" << std::setw(17) << std::right << "Paint Cans" << std::setw(24) << std::right << "Unit Cost" << std::setw(17) << std::right << "Ammount\n";

        //outputs all the values in the vector 
        for (int i = 0; i < localObj.sizeVectorRooms(); i++) {
            double cost = localObj.vectorAtIndex(i).getPaintNeeded() * COSTOFPAINT;
            out << std::setw(5) << std::right << i + 1 << std::fixed << std::setprecision(2) << std::setw(16)
                << std::right << localObj.vectorAtIndex(i).getPaintNeeded() << std::setw(20) << '$' << COSTOFPAINT << std::setw(10) << std::right << '$' << cost << std::endl;
            localCost = localCost + cost;

        }
        out << "-------------------------------------------------------------" << std::endl;
        out << "Total Product Charges:" << std::setw(33) << std::right << std::fixed << std::setprecision(2) << '$' << localCost << std::endl;
    }
    //checks if the vector is empty 
    else {
        out << "There is no rooms \n";
    }
    out << std::setw(30) << "Travel Charges \n";
    out << std::setw(30) << "-------------- \n";
    out << "Mileage" << std::setw(20) << "Rate Per Mile" << std::setw(15) << "Total \n";
    out << localObj.getDistanceTraveled() << std::setw(20) << std::fixed << std::setprecision(2) << std::right << '$' << MILECHARGE << std::setw(7) << std::right << '$' << MILECHARGE * localObj.getDistanceTraveled() << std::endl;

    out << "Final Total:" << std::setw(35) << std::fixed << std::setprecision(2) << MILECHARGE * localObj.getDistanceTraveled() + localCost + localObj.getNumberOfCoats() * HOURLYRATE << std::endl;


}
//function that will output the data for the rooms
void printRooms(house& localObj) {
    cout << "***********************************\n";
    cout << "Client Name: " << localObj.getName() << "\n";
    cout << "Distance: " << localObj.getDistanceTraveled() << "\n";
    cout << "Current Rooms: " << localObj.getNumberOfRooms() << '\n';
    cout << "\n";

    //for loop to print out all the info for the rooms
    for (int i = 0; i < localObj.sizeVectorRooms(); i++) {
        cout << "------------ Room Details ------------\n";
        cout << "Length: " << localObj.vectorAtIndex(i).getLength() << endl;
        cout << "Width: " << localObj.vectorAtIndex(i).getWidth() << endl;
        cout << "Height: " << localObj.vectorAtIndex(i).getHeight() << endl;
        cout << "Coats: " << localObj.vectorAtIndex(i).getNumbeOfCoats() << endl;
        cout << "Volume: " << localObj.vectorAtIndex(i).getVolume() << endl;
        cout << "Area: " << localObj.vectorAtIndex(i).getSurfaceArea() << endl;
        cout << "-- Paint Required -- " << localObj.vectorAtIndex(i).getPaintNeeded() << " gallons" << endl;
    }
}
//will ask the user for their name 
string userName() {
    cout << "Please enter the name of the client you wish to generate the invoice for: ";
    string str;
    getline(cin, str);
    return str;
}

//asks for the max number of rooms and error checks it 
int maxNumRooms() {
    int localInt = 0;//local variable
    while (true) {
        cout << "Please enter the maximum number of rooms in the house that can be painted:\n";
        cin >> localInt;
        if ((localInt > 0) && (localInt < 10000) && !(cin.fail()))
        {
            break;//if there is no cin.fail and also it is greater then 0 but less then 10000 will break 
        }
        else {
            std::cout << "Error please enter a valid input in the range from 1 to 10000. \n \n ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
    return localInt;
}

//asking for the total distance traveled 
double distance() {
    double localDouble;
    while (true) {
        cout << "Please enter how far (in miles) the client is from the store: \n";
        cin >> localDouble;
        if (localDouble > 0.01 && localDouble <= 10000 && !(cin.fail())) {
            break;
        }
        else {
            std::cout << "Error please enter a valid input in the range from 0.01 to 10000. \n \n ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }

    return localDouble;
}