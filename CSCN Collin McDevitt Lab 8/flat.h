#pragma once
#include "paint.h"//base class


class flat :public paint
{
    public:
    //virtual function in the base class
        void help() {cout<<"\nFlat paint is less durable with less shine but will provide the most coverage.  This type of paint is best for low traffic areas\n";}
    
    //constructor
    flat():paint()
    {
        cout<<"\nInvoking the flat default constructor.\n";
    }
    //two argument constructor
    flat(string color, double gloss_level):paint (color , gloss_level)
    {
        cout<<"\n Invoking the flat two argument constructor.\n";
    }
    //three argument constructor
    flat(string color,double gloss_level,double inventory):paint(color,gloss_level,inventory)
    {
        cout<<"\n Invoking the flat three argument constructor.\n";
    }
    //destructor
    ~flat()
    {
        cout<<"\nInvoking the flat destructor.\n";
    }
};