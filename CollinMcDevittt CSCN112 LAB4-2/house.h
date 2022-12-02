#pragma once

//file that has the class 
#include <vector>
#include <string>
#include "Room.h"

double const HOURLYRATE = 18.50f;
double const COSTOFPAINT = 70.35;
double const MILECHARGE = 0.65;

class house {

public:

    //Method to set the name
    void setName(std::string  namea);
    //method to get the name
    std::string getName() const;

    //method to set the max number of room  s 
    void setNumberOfRooms(int maxRooms);

    //method to get the max number of rooms 
    int getNumberOfRooms() const;

    //method to set the distance traveled 
    void setDistanceTraveled(double distance);

    //method to return the distance travled 
    double getDistanceTraveled() const;



    //constructor
    house();
    //3 argument constructor  
    house(std::string name, int maxNumberOfRooms, double distanceTraveled);

    //function to put a value in the vector
    void vectorPushBack(rooms& localObj);

    //will return the value of the vector at that index 
    rooms vectorAtIndex(int index) const;

    //will get the size of the vector 
    int sizeVectorRooms() const;



    //will print all the info for the house and room 
    void printHouseInfo() const;

    //function that will calc the number of Coats needed
    int getNumberOfCoats() const;

private:
    std::string name;
    int maxNumberOfRooms;
    double distanceTraveled;
    std::vector<rooms> roomVector;
 
};
