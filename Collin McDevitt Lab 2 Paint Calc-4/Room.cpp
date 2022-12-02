#include "Room.h"
#include <iostream>
#include <iomanip>
// Collin McDevitt initializing variables and creating function definitions for the class room


//ammount of surface area one gallon of paint can cover 
int const paint = 400;

//constructor
room::room() {
    length = 0.0f;//initializing the variable to 0.0
    width = 0.0f;//initializing the variable to 0.0
    height = 0.0f;//initializing the variable to 0.0
    volume = 0.0f;//initializing the variable to 0.0
    paintNeeded = 0.0f;//initializing the variable to 0.0
    wantsRoomsPainted = true;//initializing the bool variable 
    numberOfRoomsPainted = 0;
}

//Set methods  
//takes in the length as a paramter and will set it to the member variable 
void room::setLength(double length) {
    this->length = length;
}
//takes in the width as a paramter and will set it to the member variable
void room::setWidth(double width) {
    this->width = width;
}
//takes in the height as a paramter and will set it to the member variable 
void room::setHeight(double height) {
    this->height = height;
}
//will set the volume and calculate it
void room::setVolume() {
    this->volume = height * length * width;
}
//will take in a bool and set it to the member variable 
void room::setWantsRoomsPainted(bool wantsRoomsPainted) {
    this->wantsRoomsPainted = wantsRoomsPainted;
}
//will take in the ammount of paint needed and store it in the member variable 
void room::setPaintNeeded(double paintNeeded) {
    this->paintNeeded = paintNeeded;
}
//will take in the number of rooms and store it in the member variable 
void room::setNumberOfRoomsPainted(int numberOfRoomsPainted) {
    this->numberOfRoomsPainted = numberOfRoomsPainted;
}

//Get methods 
//will return the length
double room::getLength() const {
    return length;
}
//will return the width
double room::getWidth() const {
    return width;
}
//will return the height 
double room::getHeight() const {
    return height;
}
//will return the volume 
double room::getVolume() const {
    return volume;
}
//will return wheather they want the rooms painted 
bool room::getWantsRoomsPainted() const {
    return wantsRoomsPainted;
}
//will retunr the ammount of paint needed for all the rooms 
double room::getPaintNeeded() const {
    return paintNeeded;
}
int room::getNumberOfRoomsPainted() const {
    return numberOfRoomsPainted;
}

//Function that will ask for the user input for the length
double room::inputFromUserLength() {
    double inLength = getLength();//initializing variable for return
    while (getWantsRoomsPainted()) {//if false won't ask for user input
        std::cout << "What is the length of the room that is being painted in meters?\n";
        std::cin >> inLength;//asking the user inputs 
        if (((inLength == -1) || inLength >= 1) && (inLength < 10000) && !(std::cin.fail())) {//checks that input is the correct value and not in a fail state 
            if (inLength == -1) {//checks if the user entered a -1 if so then it will break out of the loop
                setWantsRoomsPainted(false);
                inLength = getLength();//don't want to store the -1 so will set it = to 0 instead 
            }
            break;//will break out of the loop
        }
        else
        {//if they have entered a number other then the type or a letter then it will clear stream and ask again
            std::cout << "Error please enter a valid input in the range from 1 meter to 10000 meters. \n \n ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
    return inLength;
}

//Function that will ask for the user input for the width
double room::inputFromUserWidth() {
    double inWidth = getWidth();//local variable for return
    while (getWantsRoomsPainted()) {
        std::cout << "What is the width of the room that is being painted?\n ";
        std::cin >> inWidth;//asking the user inputs 
        if ((inWidth == -1) || (inWidth >= 1) && (inWidth < 100000) && !(std::cin.fail())) {//checks that input is the correct value and not in a fail state 
            if (inWidth == -1) {//checks if the user entered a -1 if so then it will break out of the loop
                setWantsRoomsPainted(false);
                inWidth = getWidth();//don't want to store the -1 so will set it = to 0 instead 
            }
            break;//will break out of the loop
        }
        else {
            std::cout << "Error please enter a valid input in the range from 1 to 10000. \n \n ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
    return inWidth;
}

//Function that will ask for the user input for the height
double room::inputFromUserHeight() {
    double inHeight = getHeight();//local
    while (getWantsRoomsPainted()) {//if false won't ask for user input
        std::cout << "What is the height of the room that is being painted?\n ";
        std::cin >> inHeight;//asking the user inputs 
        if ((inHeight == -1) || (inHeight >= 1) && (inHeight < 100000) && !(std::cin.fail())) {//checks that input is the correct value and not in a fail state 
            if (inHeight == -1) {//checks if the user entered a -1 if so then it will break out of the loop
                setWantsRoomsPainted(false);
                inHeight = getHeight();//don't want to store the -1 so will set it = to 0 instead 
            }
            break;//will break out of the loop
        }
        else {
            std::cout << "Error please enter a valid input in the range from 1 to 10000. \n \n ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
    return inHeight;
}

//method that will call the user inputs and will loop 
void room::setAndCallUserInput() {
    std::cout << "Press -1 at any time to exit.\n";//lets user know how to exit
    setNumberOfRoomsPainted(getNumberOfRoomsPainted() + 1);
    //Creating local variables 
    double length = getLength();//local variable for length needs to be a copy of the member variable so it can be set after the user has entered all values and not a -1
    double lengthForLast = getLength();//Need to have another variable for the past version in case they enter a -1 after entering a couple numbers already

    double width = getWidth();//local variable for length needs to be a copy of the member variable so it can be set after the user has entered all values and not a -1
    double widthForLast = getWidth();//Need to have another variable for the past version in case they enter a -1 after entering a couple numbers already

    double height = getHeight();//local variable for length needs to be a copy of the member variable so it can be set after the user has entered all values and not a -1
    double heightForLast = getHeight();//Need to have another variable for the past version in case they enter a -1 after entering a couple numbers already

    double gallonsNeeded = 0.0f;//ammount of paint needed
    double surface_area = 0.0f;//calculates the surface area of paintable area

    length = inputFromUserLength();
    width = inputFromUserWidth();
    height = inputFromUserHeight();

    if (getWantsRoomsPainted()) {//if the user didn't eneter a -1
        surface_area = 2 * (width * height + length * height);//only four walls are being painted 
        gallonsNeeded = surface_area / paint;//calculates the number of gallons needed 
        setPaintNeeded(getPaintNeeded() + gallonsNeeded);//sets the ammount of paint needed to the previous ammount + that instance of the rooms ammount 
        setWidth(width);//sets width to user input 
        setLength(length);//sets length to user input 
        setHeight(height);//sets height to user input 

    }if (!getWantsRoomsPainted()) {//if the user entered a -1 

        surface_area = 2 * (widthForLast * heightForLast) + 2 * (lengthForLast * heightForLast);//need to recalculate surface area 

        gallonsNeeded = surface_area / paint;//calculates the number of gallons needed 

        setPaintNeeded(getPaintNeeded() + gallonsNeeded);//sets the ammount of paint needed to the previous ammount + that instance of the rooms ammount 
        setWidth(widthForLast);//sets width to previous 
        setLength(lengthForLast);//sets length to previous 
        setHeight(heightForLast);//sets height to previous
        setNumberOfRoomsPainted(getNumberOfRoomsPainted() - 1);
    }
    setVolume();//method to calculate the volume 
    showData(gallonsNeeded, surface_area);//calls the method that will print the number of rooms that need paint 
}
//method that will output the data 
void room::showData(double gallonsNeeded, double surface_area) const {
    std::cout << std::setw(60) << std::left << "The number of gallons of paint needed for this room is:" << std::setfill('-') << std::fixed << std::setprecision(3) << std::right << gallonsNeeded << "\n";
    std::cout << std::setw(60) << std::left << "The number of gallons of paint needed in total is:" << std::setfill('-') << std::fixed << std::setprecision(3) << std::right << getPaintNeeded() << "\n";
    std::cout << std::setw(60) << std::left << "The height of the room is:" << std::setfill('-') << std::fixed << std::setprecision(2) << std::right << getHeight() << 'm' << "\n";
    std::cout << std::setw(60) << std::left << "The width of the room is:" << std::setfill('-') << std::fixed << std::setprecision(2) << std::right << getWidth() << 'm' << "\n";
    std::cout << std::setw(60) << std::left << "The length of the room is:" << std::setfill('-') << std::fixed << std::setprecision(2) << std::right << getLength() << 'm' << "\n";
    std::cout << std::setw(60) << std::left << "The volume of the room is:" << std::setfill('-') << std::fixed << std::setprecision(2) << std::right << getVolume() << "m^3" << "\n";
    std::cout << std::setw(60) << std::left << "The paintable surface area of the room is:" << std::setfill('-') << std::fixed << std::setprecision(2) << std::right << surface_area << "m^2" << "\n";
    std::cout << std::setw(60) << std::left << "The number of rooms painted is:" << std::setfill('-') << std::right << getNumberOfRoomsPainted() << "\n";
}