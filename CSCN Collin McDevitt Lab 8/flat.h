#pragma once
#include "paint.h"//base class


class flat :public paint
{
    public:
        void help() {cout<<"\nFlat paint is less durable with less shine but will provide the most coverage.  This \ntype of paint is best for low traffic areas\n";}
    
    flat():paint()
    {
        cout<<"\nInvoking the flat default constructor.\n";
       
    }
    flat(string color, double gloss_level):paint (color , gloss_level)
    {
        cout<<"\n Invoking the flat two argument constructor.\n";
    }
    flat(string color,double gloss_level,double inventory):paint(color,gloss_level,inventory)
    {
        cout<<"\n Invoking the flat three argument constructor.\n";
    }

};