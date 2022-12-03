#pragma once
#include "paint.h"//base class

class highGloss :public paint
{
    public:
        void help() {cout<<"High-gloss is the shiniest type of paint we offer, and also the most durable and washable.\nIt can also be used as an outdoor paint!  It is best for doors, trim, and cabinetry\n as it can show many imperfections if applied incorrectly\n";}
    
    highGloss():paint()
    {
        cout<<"\nInvoking the high-gloss default constructor.\n";
  
    }
    highGloss(string color, double gloss_level):paint (color , gloss_level)
    {
        cout<<"\n Invoking the high-gloss two argument constructor.\n";
    }
    highGloss(string color,double gloss_level,double inventory):paint(color,gloss_level,inventory)
    {
        cout<<"\n Invoking the high-gloss three argument constructor.\n";
    }

};