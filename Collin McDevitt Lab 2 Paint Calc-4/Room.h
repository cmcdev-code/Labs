#pragma once
//Collin McDevitt header file that will hold the object room


class room {

public:
    room();//constructur that will initialize the variables 

    void setLength(double length);//method that will set the length
    double getLength() const;//method that will get the length 

    void setWidth(double width);//method that will set the width 
    double getWidth() const;// method that will get the width

    void setHeight(double height);// method that will set the height
    double getHeight() const;//method that will get the height 

    void setVolume();//method that will set the volume 
    double getVolume() const;//method that will get the volume 

    void setWantsRoomsPainted(bool wwantsRoomsPainted);//method that will set wheather they still want to have the rooms painted  
    bool getWantsRoomsPainted() const;//methodd that will retrieve the bool to see if thet stil want the rooms painted

    void setPaintNeeded(double painNeeded);//method that will set the ammount of paint needed
    double getPaintNeeded() const;//method that will will get the ammount of paint needed in total 

    void setNumberOfRoomsPainted(int numberOfRoomsPainted);//method that will set the number of rooms 
    int getNumberOfRoomsPainted() const;//method that will get the number of rooms 


    double inputFromUserLength();//will ask for the user input and error check for the length 
    double inputFromUserWidth();//will ask for the user input and error check for the width 
    double inputFromUserHeight();//will ask for the user input and error check for the height

    void showData(double gallonsNeeded, double surface_area) const;//will output the data 

    void setAndCallUserInput();//method that will loop and ask for the user input until they enter a -1 and will also call the show data function 

private:

    // member variables
    double length;
    double height;
    double width;
    double volume;
    bool wantsRoomsPainted;//if false won't will end the function
    double paintNeeded;//Will store the ammount of paint that will be used total 
    int numberOfRoomsPainted;

};