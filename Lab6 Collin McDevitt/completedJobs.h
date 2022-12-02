#pragma once 
#include <string>


using std::string;

//class
class completeJobs {

public:
    //constructor 
    completeJobs();
    //destructor 
    ~completeJobs();
    //get methods
    string getClientName() const;

    int getRoomsPainted() const;
    double getLaborCharges() const;
    int getNumPaintCans() const;
    double getProductCharges() const;
    int getMileage() const;
    double getTravelCharges() const;
    int getInvoiceNumber() const;

    void setRandNum(int);

    //functions that will ask for that specific member variable and error check it and set it 
    void askForClientName();

    void askForNumRoomsPainted();

    void askForLaborCharges();

    void askForNumPaintCans();

    void askForProductCharges();

    void askForMileage();

    void askForTravelCharges();

    void printCompleteJob() const;

    void printCompleteJob(std::ofstream& out) const;

    void readInFile();


    
    double totalPriceStuff() const;

private:
    //set methods 
    void setClientName(string);
    void setRoomsPainted(int);
    void setLaborCharges(double);
    void setNumPaintCans(int);
    void setProductCharges(double);
    void setMileage(int);
    void setTravelCharges(double);
    void setValuesNull();

    string clientName;//

    int invoiceNumber;

    int roomsPainted;//

    double laborCharges;//

    int numPaintCans;//

    double productCharges;//

    int mileage;//

    double travelCharges;
};