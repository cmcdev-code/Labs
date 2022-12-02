#pragma once
#include "paint.h"//base class
#include <random>

class semiGloss :public paint
{
    public:
        void help() {cout<<"Semi-gloss is a very shiny and reflective paint.  It is durable and resistant to \nmildew, but will show more imperfections than flat, eggshell, or satin paint. This type of paint is \ngreat for rooms that have high moisture or high levels of wear and tear.\n";}
    
    semiGloss():paint()
    {
        cout<<"\nInvoking the Semi-gloss default constructor.\n";
        std::random_device rd;
        std::default_random_engine num(rd());
        std::uniform_real_distribution<double> randomNum(35.5, 70);
        setGlossLevel(randomNum(num));
    }
    semiGloss(string color, double gloss_level):paint (color , gloss_level)
    {
        cout<<"\n Invoking the Semi-gloss two argument constructor.\n";
    }
    semiGloss(string color,double gloss_level,double inventory):paint(color,gloss_level,inventory)
    {
        cout<<"\n Invoking the Semi-gloss three argument constructor.\n";
    }

};