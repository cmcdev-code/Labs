#pragma once
#include "paint.h"//base class

class highGloss :public paint
{
    public:
    //virtual function in the base class
        void help() {cout<<"\nHigh-gloss is the shiniest type of paint we offer, and also the most durable and washable.It can also be used as an outdoor paint!  It is best for doors, trim, and cabinetry as it can show many imperfections if applied incorrectly\n";}
    
    //constructor
    highGloss():paint()
    {
        cout<<"\nInvoking the high-gloss default constructor.\n";
    }
    //two argument constructor
    highGloss(string color, double gloss_level):paint (color , gloss_level)
    {
        cout<<"\n Invoking the high-gloss two argument constructor.\n";
    }
    //three argument constructor
    highGloss(string color,double gloss_level,double inventory):paint(color,gloss_level,inventory)
    {
        cout<<"\n Invoking the high-gloss three argument constructor.\n";
    }
    //destructor
    ~highGloss()
    {
        cout<<"\nInvoking the high-gloss destructor.\n";
    }

};