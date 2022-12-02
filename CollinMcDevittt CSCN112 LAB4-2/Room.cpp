#include "Room.h"
#include <iostream>
#include <iomanip>
// Collin McDevitt initializing variables and creating function definitions for the class rooms


//ammount of surface area one gallon of paint can cover 
int const paint = 400;

//constructor
rooms::rooms() {
    length = 0.0f;//initializing the variable to 0.0
    width = 0.0f;//initializing the variable to 0.0
    height = 0.0f;//initializing the variable to 0.0
    volume = 0.0f;//initializing the variable to 0.0
    paintNeeded = 0.0f;//initializing the variable to 0.0
    numberOfCoats = 0;
}
rooms::rooms(double length, double height, double width) {
    this->length = length;
    this->height = height;
    this->width = width;
    volume = 0;
    paintNeeded = 0;
    numberOfCoats = 0;

}


//Set methods  
//takes in the length as a paramter and will set it to the member variable 
void rooms::setLength(double length) {
    this->length = length;
}
//takes in the width as a paramter and will set it to the member variable
void rooms::setWidth(double width) {
    this->width = width;
}
//takes in the height as a paramter and will set it to the member variable 
void rooms::setHeight(double height) {
    this->height = height;
}
//will set the volume and calculate it
void rooms::setVolume() {
    this->volume = height * length * width;
}

//will take in the ammount of paint needed and store it in the member variable 
void rooms::setPaintNeeded() {
    this->paintNeeded = getNumbeOfCoats() * getSurfaceArea() / paint;
}
//will take in the number of coats and store it in the member variable 
void rooms::setNumberOfCoats(int numberOfCoats) {
    this->numberOfCoats = numberOfCoats;
}

//Get methods 
//will return the length
double rooms::getLength() const {
    return length;
}
//will return the width
double rooms::getWidth() const {
    return width;
}
//will return the height 
double rooms::getHeight() const {
    return height;
}
//will return the volume 
double rooms::getVolume() const {
    return volume;
}
//will return the ammount of paint needed 
double rooms::getPaintNeeded() const {
    return paintNeeded;
}
int rooms::getNumbeOfCoats() const {
    return numberOfCoats;
}

//function that will return the Surface area
double rooms::getSurfaceArea() const {

    return  2 * (getWidth() * getHeight() + getLength() * getHeight());


}


//Function that will ask for the user input for the length
double rooms::inputFromUserLength() {
    double inLength = 0;//initializing variable for return
    while (true) {//if false won't ask for user input
        std::cout << "What is the length of the rooms that is being painted in meters?\n";
        std::cin >> inLength;//asking the user inputs 
        if ((inLength >= 1) && (inLength < 10000) && !(std::cin.fail())) {//checks that input is the correct value and not in a fail state 
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
double rooms::inputFromUserWidth() {
    double inWidth = 0;//local variable for return
    while (true) {
        std::cout << "What is the width of the rooms that is being painted?\n ";
        std::cin >> inWidth;//asking the user inputs 
        if ((inWidth >= 1) && (inWidth < 100000) && !(std::cin.fail())) {//checks that input is the correct value and not in a fail state 
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
double rooms::inputFromUserHeight() {
    double inHeight = 0;//local
    while (true) {//if false won't ask for user input
        std::cout << "What is the height of the rooms that is being painted?\n ";
        std::cin >> inHeight;//asking the user inputs 
        if ((inHeight >= 1) && (inHeight < 100000) && !(std::cin.fail())) {//checks that input is the correct value and not in a fail state 
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

double rooms::inputFromUserNumCoats() {//will get the number of coats needed 

    double inNumCoats = 0;//local
    while (true) {//if false won't ask for user input
        std::cout << "How many coats of paint was there? \n ";
        std::cin >> inNumCoats;//asking the user inputs 
        if ((inNumCoats >= 1) && (inNumCoats < 100000) && !(std::cin.fail())) {//checks that input is the correct value and not in a fail state 
            break;//will break out of the loop
        }
        else {
            std::cout << "Error please enter a valid input in the range from 1 to 10000. \n \n ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
    return inNumCoats;
}
