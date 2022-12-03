#pragma once
#include "paint.h"//base class

class Eggshell :public paint
{
    public:
        void help() {cout<<"\nEggshell paint is more durable that flat paint and has slightly more luster.  This \ntype of paint is great for places that experience low or medium traffic.\n";}
    
    Eggshell():paint()
    {   
        cout<<"\nInvoking the Eggshell default constructor.\n";
        
    }
    Eggshell(string color, double gloss_level):paint (color , gloss_level)
    {
        cout<<"\n Invoking the Eggshell two argument constructor.\n";
    }
    Eggshell(string color,double gloss_level,double inventory):paint(color,gloss_level,inventory)
    {
        cout<<"\n Invoking the Eggshell three argument constructor.\n";
    }
    
    

};