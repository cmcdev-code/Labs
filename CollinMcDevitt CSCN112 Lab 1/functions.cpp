#include "declarations.h"
#include <cmath>
#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

//*******************************************
//Function Declerations

//method that will take in input and error check it 
double debtor::inOfPrincipalAmmount() {
    double input_of_principal = 0;
    bool validInput = false;//bool so that there can be error checking
    while (!validInput) {
        cout << "How much money will you be borrowing? Please enter a rational positive number.\n";
        cin >> input_of_principal;
        if ((input_of_principal > 1) && (input_of_principal < 100000000) && !(cin.fail())) {//input has to be between 1 and 100,000,000(seems like a reasonable price to pay for painting!)
            validInput = true;//while loop will exit 
        }
        else {
            cin.clear();//https://stackoverflow.com/questions/5131647/why-would-we-call-cin-clear-and-cin-ignore-after-reading-input
            validInput = false;//Already is false if this case happens, but will make it clear that this is an error to anyone reading the source code.
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Error please enter how much the loan will be for.\n";
        }
    }
    return input_of_principal;
}
//Method that will ask for the yearly intrest and return the number also will do error checking
double debtor::inYearlyIntrest() {
    double input_of_yearly_intrest = 0;
    bool validInput = false;//bool so that there can be error checking
    while (!validInput) {
        cout << "What will the intrest be on the loan?\n";
        cin >> input_of_yearly_intrest;
        if ((input_of_yearly_intrest > 0.001) && (input_of_yearly_intrest < 391) && !(cin.fail())) {//input has to be between 0.001 and 391% https://www.nerdwallet.com/article/loans/personal-loans/what-is-predatory-lending
            validInput = true;//while loop will exit 
        }
        else {
            cin.clear();
            validInput = false;//Already is false if this case happens, but will make it clear that this is an error to anyone reading the source code.
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Error please enter how much the intrest is. Please enter the ammount such as 10 would be 10% and 4.5 would be 4.5%.\n";
        }
    }
    return input_of_yearly_intrest;
}
//method that will ask for the loan option that they want
int debtor::inLoanOption() {
    int input_of_loan_option = 1;
    bool validInput = false;//bool so that there can be error checking
    while (!validInput) {
        cout << "We offer a 5, 10, or 15-year loan. Which loan option do you want?\n";
        cin >> input_of_loan_option;
        if ((input_of_loan_option == 5 || input_of_loan_option == 10 || input_of_loan_option == 15) && !(cin.fail())) {//input has to either be an integer that is 5,10,or 15.
            validInput = true;//while loop will exit
        }
        else {
            cin.clear();
            validInput = false;//Already is false if this case happens, but will make it clear that this is an error to anyone reading the source code.
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Error please enter an integer that is either 5, 10, or 15. \n";
        }
    }
    return input_of_loan_option;
}
//method that will call on the user inputs and set the numbers in the class = to them
void debtor::calling_all_user_inputs() {
    setLoanAmmount(inOfPrincipalAmmount());//method that is a paramter of the other method will ask for the user how much money the loan will be 
    setYearlyIntrest(inYearlyIntrest());//method that is a paramter of the other method will ask for the user what the yearly intrest will be
    setLoanOption(inLoanOption());//method that is a paramter of the other method will ask for the user which loan option they want 

}

//Method that returns the monthly payment
double debtor::amortizationCalc(double principle, double intrest, int year)
{
    double commonThing = pow((1 + (intrest / 12)), (year * 12));
    return principle * ((intrest / 12 * commonThing) / (commonThing - 1));
}
//Method that set member variables
void debtor::setLoanOption(int loanOption) {//method that sets member variable for the loan option
    this->loanOption = loanOption;//saw the 'this' in this youtube video and thought that this(haha) would be a good use for it https://www.youtube.com/watch?v=Z_hPJ_EhceI
}
void debtor::setLoanAmmount(double loanAmmount) {//method that sets member variable for the loan ammount
    this->loanAmmount = loanAmmount;
}
void debtor::setYearlyIntrest(double yearlyIntrest) {//method that sets member variable for the yearly intrest
    this->yearlyIntrest = yearlyIntrest / 100;
}
void debtor::setPaymemtPeriods(int paymentPeriods) {//method that sets member variable for the payment periods
    this->paymentPeriods = paymentPeriods;
}
void debtor::setMonthlyPayment(double monthlyPayment) {//method that sets member variable for the monthly payment
    this->monthlyPayment = monthlyPayment;
}
//method that will return the member variable 
int debtor::getLoanOption() {//method that will return the member variable value of the loan option
    return loanOption;
}
double debtor::getLoanAmmount() {//method that will return the member variable value for the loan ammount 
    return loanAmmount;
}
int debtor::getPaymentPeriods() {//method that will return the member variable value for payment periods
    return paymentPeriods;
}
double debtor::getYearlyIntrest() {//method that will return the member variable value for the yearly intrest
    return yearlyIntrest;
}
double debtor::getMonthlyPayment() {//method that will return the member variable value for the monthly payment
    return monthlyPayment;
}

//*******************************************
//Method that will call on the method bellow and also use the get methods 
double debtor::callOfAmortizationCalc() {
    double principle = getLoanAmmount();//getting the member variables so i can pass them into the amortization calc as paramters without effecting the member variables 
    double intrest = getYearlyIntrest();
    int year = getLoanOption();
    return amortizationCalc(principle, intrest, year);
}

//Method that will return the monthly payment that is happening on the principal
double debtor::monthlyPaymentOfPrincipal(double principle, double intrest, int number__of_payments) {
    double payment = 0.0f;//itializing the variable 
    return(payment = getMonthlyPayment() - principle * intrest);
}
double debtor::callOfMonthlyPayment() {
    double principle = getLoanAmmount();//setting the variables like this will make the calculations easier 
    double intrest = getYearlyIntrest() / 12;
    int number__of_payments = getPaymentPeriods();
    return monthlyPaymentOfPrincipal(principle, intrest, number__of_payments);
}
void debtor::recur(std::ofstream& file) {
    setPaymemtPeriods(getPaymentPeriods() + 1);//have this outside so that when the function is called the first payment is not the 0 payment, but is instead the 1st payment 
    cout << fixed << setprecision(2) << setw(10) << getPaymentPeriods() << setw(15) << getMonthlyPayment() << setw(15) << callOfMonthlyPayment() << setw(15) << getMonthlyPayment() - callOfMonthlyPayment() << setw(15) <<
        getLoanAmmount() - callOfMonthlyPayment() << '\n';

    file << fixed << setprecision(2) << getPaymentPeriods() << ',' << getMonthlyPayment() << ',' << callOfMonthlyPayment() << ',' << //outputing in csv format 
        getMonthlyPayment() - callOfMonthlyPayment() << ',' << getLoanAmmount() - callOfMonthlyPayment() << '\n';

    if (getLoanAmmount() > 0) {//checks if the loan ammount is negative
        setLoanAmmount(getLoanAmmount() - callOfMonthlyPayment());//Subtracts the monthlyPayment of the principal from the principal
        if (getLoanAmmount() < 0) {
            setMonthlyPayment(getLoanAmmount() + getMonthlyPayment());
            setLoanAmmount(0.001);//have this value as this somewhat small decimal number due to the impercisions associated with the floating point number 

        }if (getLoanAmmount() == 0 || (getLoanAmmount() > -0.01 && (getLoanAmmount() < 0.01))) {//error in floating point
            return;
        }
        recur(file);
    }
}
//method that will call the recursive function and then also create the .csv file and will output the formating for the top of the table
void debtor::driverFunction() {
    cout << "Loan Application-Amortization Schedule\n";
    cout << setw(40) << left << "Principal:" << fixed << setprecision(2) << right << getLoanAmmount() << '\n';
    cout << setw(40) << left << "Life of loan (5,10, or 15 years): " << right << fixed << setprecision(2) << getLoanOption() << '\n';
    cout << setw(40) << left << "Annual intrest rate:" << fixed << setprecision(1) << right << getYearlyIntrest() * 100 << "%\n";
    cout << setw(40) << left << "Monthly Payment:" << fixed << setprecision(2) << right << getMonthlyPayment() << '\n';
    ofstream out("user.csv");//csv file that will hold the output bello so it can be oppened in excel
    cout << setw(10) << "Payment " << setw(15) << "Ammount" << setw(15) << "Principal" << setw(15) << "Intrest" << setw(15) << "Balance " << '\n';
    out << "Payment, Ammount,Principal,Intrest,Balance \n";
    cout << fixed << setprecision(2) << setw(70) << getLoanAmmount() << '\n';
    recur(out);
    out.close();
}