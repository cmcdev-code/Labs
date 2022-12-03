#pragma once
#include "paint.h"//base class

class Eggshell :public paint
{
    public:
    //virtual function in the base class
        void help() {cout<<"\nEggshell paint is more durable that flat paint and has slightly more luster.  This type of paint is great for places that experience low or medium traffic.\n";}
    
    //constructor
    Eggshell():paint()
    {   
        cout<<"\nInvoking the Eggshell default constructor.\n";
    }
    //two argument constructor
    Eggshell(string color, double gloss_level):paint (color , gloss_level)
    {
        cout<<"\n Invoking the Eggshell two argument constructor.\n";
    }
    //three argument constructor
    Eggshell(string color,double gloss_level,double inventory):paint(color,gloss_level,inventory)
    {
        cout<<"\n Invoking the Eggshell three argument constructor.\n";
    }
    
    

};