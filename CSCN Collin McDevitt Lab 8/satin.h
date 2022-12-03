#pragma once
#include "paint.h"//base class

class satin :public paint
{
    public:
    //virtual function in the base class 
        void help() {cout<<"\nSatin paint is the most common interior paint.  It is easier to clean than flat or eggshell, but it can be very tricky to touch-up if errors are made during application. This type of paint is great for high-traffic areas.\n";}
    //constructor 
    satin():paint()
    {
        cout<<"\nInvoking the satin default constructor.\n";
        
    }
    //two argument constructor
    satin(string color, double gloss_level):paint (color , gloss_level)
    {
        cout<<"\n Invoking the satin two argument constructor.\n";
    }
    //three argument constructor
    satin(string color,double gloss_level,double inventory):paint(color,gloss_level,inventory)
    {
        cout<<"\n Invoking the satin three argument constructor.\n";
    }
    //destructor
    ~satin()
    {
        cout<<"\nInvoking the satin destructor.\n";
    }


};

