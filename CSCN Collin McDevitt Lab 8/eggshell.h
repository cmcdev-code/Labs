#pragma once
#include <random>
#include "paint.h"//base class

class Eggshell :public paint
{
    public:
        void help() {cout<<"\nEggshell paint is more durable that flat paint and has slightly more luster.  This \ntype of paint is great for places that experience low or medium traffic.\n";}
    
    Eggshell():paint()
    {   std::random_device rd;
        std::default_random_engine num(rd());
        std::uniform_real_distribution<double> randomNum(10.5, 25);
        setGlossLevel(randomNum(num));
        cout<<"\nInvoking the Eggshell default constructor.\n";
        
    }
    Eggshell(string color, double gloss_level):paint (color , gloss_level)
    {
        cout<<"\n Invoking the Eggshell two argument constructor.\n";
    }
    
    

};