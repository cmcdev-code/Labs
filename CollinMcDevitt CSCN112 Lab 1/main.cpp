#include "declarations.h"
#include <iostream>
#include <cmath> 
#include <iomanip>
#include <fstream>

using namespace std;

int main() {
    cout << "Collin McDevitt CSCN 112 Lab 1!!\n";
    debtor user;//creating object 

    user.calling_all_user_inputs();//Method that will call for the users inputs 
    user.setMonthlyPayment(user.callOfAmortizationCalc());//Set Monthly Payment just takes a paramter stores it in the object call of amortization calc will just return the amortization calc value it gets the values from the object
    user.driverFunction();//function that will output to the screen and also call recursive function


    system("pause");
    return 0;
}