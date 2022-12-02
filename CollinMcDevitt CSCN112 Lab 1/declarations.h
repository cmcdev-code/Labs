#pragma once
#include <iostream>


class debtor
{

private:

    //The Option that the person chose
    int loanOption;

    int paymentPeriods;

    //The loan ammount
    double loanAmmount;

    //The Yearly intrest
    double yearlyIntrest;

    double monthlyPayment;

    //What the monthly payment will be !!!! DOES NOT CHANGE

    //Function that will calc the Monthly payment
    double amortizationCalc(double principle, double intrest, int year);//not ment to be called instead call the double callOfAmortizationCalc();

    //Method that will calculate how much of the monthly payment is being used to pay off the principal
    double monthlyPaymentOfPrincipal(double principle, double intrest, int number__of_payments);//Not ment to be called call the double callOfMonthlyPayment(); instead

public:

    //Constructor to initilize the memory when creating an object of the class 
    debtor()
    {
        loanOption = 10;//Loan Option can't == 0 because then the amortization formula would be dividing by 0 number^0 power would be 1 and the denomanator subtracts 1  
        loanAmmount = 0.0f;//f in order to show that it is a floating point 
        yearlyIntrest = 0.0f;
        monthlyPayment = 0.0f;
        paymentPeriods = 0;
    }
    //Methods that will ask for the user input for the three inputs: principal ammount, loan option, and yearly interest.
    double inOfPrincipalAmmount();
    double inYearlyIntrest();
    int inLoanOption();

    //method that will call all the user inputs and then use the set methods bellow to set tha values to the corisponding ones
    void calling_all_user_inputs();

    //Set and get methods
    //******************************************************************
    void setLoanOption(int loanOption);
    int getLoanOption();

    void setLoanAmmount(double loanAmmount);
    double getLoanAmmount();

    void setYearlyIntrest(double yearlyIntrest);
    double getYearlyIntrest();

    void setPaymemtPeriods(int paymentPeriods);
    int getPaymentPeriods();

    void setMonthlyPayment(double monthlyPayment);//Will store the amortization calc in the clas 
    double getMonthlyPayment();//will get the amortization calc in the clas 

    //******************************************************************

    //Method that will call on the method bellow and also use the get methods 
    double callOfAmortizationCalc();
    double callOfMonthlyPayment();

    //recursive function that will take care of lowering the principal ammount 
    void recur(std::ofstream& file);

    //method that will call the recursive function and then also create the .csv file and will output the formating for the top of the table
    void driverFunction();

};
