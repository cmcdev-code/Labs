#pragma once
//Collin McDevitt header file that will hold the object rooms


class rooms {

public:
    rooms();//constructur that will initialize the variables 
    //3 argument constructor
    rooms(double length,double height,double width);


    void setLength(double length);//method that will set the length
    double getLength() const;//method that will get the length 

    void setWidth(double width);//method that will set the width 
    double getWidth() const;// method that will get the width

    void setHeight(double height);// method that will set the height
    double getHeight() const;//method that will get the height 

    void setVolume();//method that will set the volume 
    double getVolume() const;//method that will get the volume 

 
    void setPaintNeeded();//method that will set the ammount of paint needed
    double getPaintNeeded() const;//method that will will get the ammount of paint needed in total 

    void setNumberOfCoats(int numberOfCoats);//method that will set the number of coats
    int getNumbeOfCoats() const;//method that will get the number of roomss 


    double inputFromUserLength();//will ask for the user input and error check for the length 
    double inputFromUserWidth();//will ask for the user input and error check for the width 
    double inputFromUserHeight();//will ask for the user input and error check for the height
    double inputFromUserNumCoats();//will get the number of coats needed 


    double getSurfaceArea() const;
   
private:

    // member variables
    double length;
    double height;
    double width;
    double volume;
    double paintNeeded;//Will store the ammount of paint that will be used total 
    int numberOfCoats;
    

};

