#pragma once
#include "paint.h"//base class
#include <random>

class satin :public paint
{
    public:
        void help() {cout<<"Satin paint is the most common interior paint.  It is easier to clean than flat or \neggshell, but it can be very tricky to touch-up if errors are made during application.\n  This type of paint is great for high-traffic areas.\n";}
    
    satin():paint()
    {
        cout<<"\nInvoking the satin default constructor.\n";
        std::random_device rd;
        std::default_random_engine num(rd());
        std::uniform_real_distribution<double> randomNum(25.5, 35);
        setGlossLevel(randomNum(num));
    }
    satin(string color, double gloss_level):paint (color , gloss_level)
    {
        cout<<"\n Invoking the satin two argument constructor.\n";
    }
    satin(string color,double gloss_level,double inventory):paint(color,gloss_level,inventory)
    {
        cout<<"\n Invoking the satin three argument constructor.\n";
    }



};

