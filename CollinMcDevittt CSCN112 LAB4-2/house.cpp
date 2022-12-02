//file that has all the house class function definitions
#include "house.h"//header file
#include <iomanip> //manipulate the output 
#include <string>//for strings 
#include <iostream>//i/o



//0 argument constructor 
house::house() {
    name = "";
    maxNumberOfRooms = 0;
    distanceTraveled = 0.0f;
}

//3 argument constructor 
house::house(std::string name, int maxNumberOFRooms, double distanceTraveled) {
    this->name = name;
    this->maxNumberOfRooms = maxNumberOFRooms;
    this->distanceTraveled = distanceTraveled;
}
//function to get the number of coats needed 
int house::getNumberOfCoats() const {
    int local = 0;
    if (getNumberOfRooms() != 0) {
        for (int i = 0; i < sizeVectorRooms(); i++) {
            local = local + vectorAtIndex(i).getNumbeOfCoats();
        }
    }
    return local;
}

//sets employee Object name
void house::setName(std::string name) {
    this->name = name;
}
void house::setDistanceTraveled(double distanceTraveled) {
    this->distanceTraveled = distanceTraveled;
}
void house::setNumberOfRooms(int maxRooms) {
    this->maxNumberOfRooms = maxRooms;
}




//gets the size of the house vector of rooms
int house::sizeVectorRooms() const {
    return this->roomVector.size();
}
//adds a room object to the back of the vector 
void house::vectorPushBack(rooms& localObj) {
    roomVector.push_back(localObj);
}
//gets the value at a certain index in the vector 
rooms house::vectorAtIndex(int index) const {
    return this->roomVector.at(index);
}
//member function to get the object name 
std::string house::getName() const {
    return this->name;
}
//member function to get the max number of rooms
int house::getNumberOfRooms() const {
    return maxNumberOfRooms;
}
double house::getDistanceTraveled() const {
    return distanceTraveled;
}



//member function to print out information 
void house::printHouseInfo() const {


    double localCost = 0;

    //outputs the info for the house
    std::cout << "***************************************************************************" << '\n';

    std::cout << std::setw(40) << std::right << getName() << '\n';
    std::cout << std::setw(45) << "Final Invoice \n";

    std::cout << "***************************************************************************" << '\n' << '\n';

    std::cout << "WePaintHouses LLC\n";
    std::cout << "1971 University Blvd\n";
    std::cout << "Lychburg,VA 24502 \n";
    std::cout << "4344554545\n";
    std::cout << "wepainthousesllc.com\n";
    std::cout << "Billed to:" << getName() << "\n";

    std::cout << std::setw(45) << std::right << "Labor Charges\n";
    std::cout << std::setw(45) << std::right << "-------------\n";
    std::cout << std::left << "Rooms" << std::setw(17) << std::right << "Number of Coats" << std::setw(17) << std::right << "Hourly Rate" << std::setw(17) << std::right << "Total\n";
    std::cout << std::setw(4) << std::right << getNumberOfRooms() << std::setw(17) << std::right << getNumberOfCoats() << std::setw(17) << std::right << HOURLYRATE << std::setw(15) << std::right << std::fixed
        << std::setprecision(2) << '$' << getNumberOfCoats() * HOURLYRATE << std::endl << std::endl;


    //checks that the vector isnt 0 elements
    if (sizeVectorRooms() > 0) {

        //ouputs the data that will depened on the vector 
        std::cout << std::setw(45) << "Product Charges: \n";
        std::cout << std::setw(45) << "---------------- \n";

        //formating for the table 
        //std::cout<<std::left<<"Rooms"<<std::setw(17)<<std::right<<"Number of Coats"<<std::setw(17)<<std::right<<"Hourly Rate"<<std::setw(17)<<std::right<<"Total\n";
        std::cout << std::left << "Room#" << std::setw(17) << std::right << "Paint Cans" << std::setw(24) << std::right << "Unit Cost" << std::setw(17) << std::right << "Ammount\n";

        //outputs all the values in the vector 
        for (int i = 0; i < sizeVectorRooms(); i++) {
            double cost = vectorAtIndex(i).getPaintNeeded() * COSTOFPAINT;
            std::cout << std::setw(5) << std::right << i + 1 << std::fixed << std::setprecision(2) << std::setw(16)
                << std::right << vectorAtIndex(i).getPaintNeeded() << std::setw(20) << '$' << COSTOFPAINT << std::setw(10) << std::right << '$' << cost << std::endl;
            localCost = localCost + cost;

        }
        std::cout << "-------------------------------------------------------------" << std::endl;
        std::cout << "Total Product Charges:" << std::setw(33) << std::right << std::fixed << std::setprecision(2) << '$' << localCost << std::endl;
    }
    //checks if the vector is empty 
    else {
        std::cout << "There is no rooms \n";
    }
    std::cout << std::setw(30) << "Travel Charges \n";
    std::cout << std::setw(30) << "-------------- \n";
    std::cout << "Mileage" << std::setw(20) << "Rate Per Mile" << std::setw(15) << "Total \n";
    std::cout << getDistanceTraveled() << std::setw(20) << std::fixed << std::setprecision(2) << std::right << '$' << MILECHARGE << std::setw(7) << std::right << '$' << MILECHARGE * getDistanceTraveled() << std::endl;

    std::cout << "Final Total:" << std::setw(35) << std::fixed << std::setprecision(2) << MILECHARGE * getDistanceTraveled() + localCost + getNumberOfCoats() * HOURLYRATE << std::endl;


    std::string pause;
    std::cout << "Hit enter to continue. \n";
    std::cin.ignore();
    std::getline(std::cin, pause);
}
