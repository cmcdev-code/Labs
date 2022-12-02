#pragma once
#include <string>
#include <iostream>
#include <iomanip>
using std::string;
using std::cout;


class paint{

public:
//default constructor
paint()
{
cout<<"\nInvoking the default Paint constructor.\n";
this->color="";
this->inventory=0.0f;
this->gloss_level=0.0f;
}
paint(string color, double gloss_level)
{
    cout<<"\nInvoking the two argument constructor.\n";
    this->color=color;
    this->gloss_level=gloss_level;
    this->inventory=0;
}



void setInventory(double inventory){this->inventory=inventory;}
void setColor(string color){this->color=color;}
void setGlossLevel(double gloss_level){this->gloss_level=gloss_level;}

string getColor() const{return this->color;}
double getGlosslvl() const{return this->gloss_level;}
double getInventory() const{return this->inventory;}


//virtual function 
virtual void help()=0;

//overloading the << operator
friend std::ostream& operator<<(std::ostream& out,const paint& localObj)
{
    out<<std::setw(15)<<std::right<<localObj.getColor()<<std::setw(15)<<std::right<<localObj.getInventory()<<std::setw(15)<<std::right<<std::fixed<<std::setprecision(6)<<localObj.getGlosslvl();
    return out;

}

private:
    string color;   
    double gloss_level;
    double inventory;

};