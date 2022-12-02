#pragma once
#include "paint.h"//base class
#include <random>

class flat :public paint
{
    public:
        void help() {cout<<"\nFlat paint is less durable with less shine but will provide the most coverage.  This \ntype of paint is best for low traffic areas\n";}
    
    flat():paint()
    {
        cout<<"\nInvoking the flat default constructor.\n";
        std::random_device rd;
        std::default_random_engine num(rd());
        std::uniform_real_distribution<double> randomNum(0.1, 5.0);
        setGlossLevel(randomNum(num));
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