#include "flat.h"
#include "eggshell.h"
#include "satin.h"
#include "semigloss.h"
#include "highgloss.h"
#include <fstream>
#include <random>
#define elif else if


using namespace std;
//function to read in from the file
void readInFromFile(string arrayOfColors[],string arrayOfGlossLvl[],string arrayOfInventory[]);
//function to loop through the file  and store the data in into the arrays
void loopThroughFile(string arrayOfColors[],string arrayOfGlossLvl[],string arrayOfInventory[],ifstream& in);
//function that checks wheather the data that is in the arrays can be converted to a double
bool validDatainFile(string dataFromFiile[],int length);
//function that checks wheather the array has values that can actually be the gloss level of the paint
bool validGlossLvl(string glossLvl[],int length);
//function that will ask for the paint color 
string askForPaintColor();
//function that will make a random number between the lower and upper bounds 
double rngNum(double lower,double upper);

//dynamically creates object depending on the choice or depending on the gloss level from the file
paint* typeCreation(string color,double gloss_level,double inventory);
paint* typeCreation(int choice);

//error checks user input
double userInput(string txtOut,double lower,double upper);
int userInput(string txtOut,int lower,int upper);

//will output the different paint types and will output the option to get the paint types from a file if the flag is ==0 
void userChoiceOfPaint(int flag);
//menu that will be outputed after the array is full of the different objects
void menuAfterChoice();
//will output the current inventory for the paint
void printAllPaints(paint* paintArray[],int length);
//will output the data to a file that is in the correct format
void printToFile(paint* paintArray[],int length);

int main()
{
    //array of pointers to the base class that will hold the classes that inherit from the base class
    paint *  allPaintStuff[7];
    

    cout<<"Please choose from the following options: \n";
    for(int i=0;i<7;i++)
    {   
        //prints the options avaliable to the user
        userChoiceOfPaint(i);

                                                            //will only ouput 6 if it is on the first loop
        int userChoice=userInput("Please enter your choice: ",1,(i==0) ? 6:5);
        if(userChoice==6){
            //creating array of strings to hold the data that is read in from the file into 
            string arrayOfColors[7];string arrayOfGlossLvl[7];string arrayOfInventory[7];
            //reading the data in from the file and will ask the user for the name of the file and do the error checking 
            readInFromFile(arrayOfColors,arrayOfGlossLvl,arrayOfInventory);
            
            //after the data is read in from the file then it will dynamicly create the objects 
            for(int i=0;i<7;i++)
            {
                allPaintStuff[i]=typeCreation(arrayOfColors[i],stod(arrayOfGlossLvl[i]),stod(arrayOfInventory[i]));
            }break;//breaks out of the loop 
        }
        else {//if they 1-5 then it will just ask the user for the inventory
            allPaintStuff[i]=typeCreation(userChoice);
        }
    }
    
    while(true){
        //menu that is after the array is filled with objects
        menuAfterChoice();
        //asking for user input and error checking it in the range 
        int userChoice=userInput("Please enter your choice: ",1,5);
        if(userChoice==1){
            cout<<"\n Which Object (1-7) do you wish to adjust the inventory of?\n";
            printAllPaints(allPaintStuff,7);//prints the whole inventory 
            //asks for which inventory number they want to ajust and also asks for the new inventory and will store it in the corresponding number 
            allPaintStuff[userInput("Please enter your choice: ",1,7)-1]->setInventory(userInput("How many cans should be in inventory for this paint:",0.0f,1000000.0f));
        }
        if(userChoice==2){
            cout<<"\n Which inventory item do you want to see the inventory help on?\n";
            //will ask for which item they want to see the help on and will print the help for that item 
            allPaintStuff[userInput("Please enter your choice: ",1,7)-1]->help();
        }
        if(userChoice==3){
            //will print out the whole current inventory 
            cout<<"\n Current inventory\n";
            printAllPaints(allPaintStuff,7);
        }
        if(userChoice==4){
            //will print the whole inventory to a file in the same format that files are read in as 
            printToFile(allPaintStuff,7);
        }
        if(userChoice==5){
            //prints all the help of the inventory 
            for(int i=0;i<7;i++)
            {
                allPaintStuff[i]->help();
            }
            //prints the whole inventory 
            printAllPaints(allPaintStuff,7);
            break;
        }
    
    }

    
    for(int i=0;i<7;i++){
        delete allPaintStuff[i];
    }

    return 0;
}


void readInFromFile(string arrayOfColors[],string arrayOfGlossLvl[],string arrayOfInventory[])
{

    string Fname;
    while(true){
    cout<<"\nWhat is the name of the file?\n";
    getline(cin>>ws,Fname);
    ifstream in;
    in.open(Fname);
        if(in.fail()){
        cout<<"Couldn't open the file. Please try again.\n";
        }else{
            loopThroughFile(arrayOfColors,arrayOfGlossLvl,arrayOfInventory,in);
            
            if(validDatainFile(arrayOfGlossLvl,7)&& validDatainFile(arrayOfInventory,7)){
                if(validGlossLvl(arrayOfGlossLvl,7)){
                    break;
                }
                cout<<"One of the numbers in the file is wrong please edit or try to open a different file.\n";
            }
            else{
            cout<<"Invalid data was in the file. Please try again.\n";
            }
        }
        in.close();
    }

}

void loopThroughFile(string arrayOfColors[],string arrayOfGlossLvl[],string arrayOfInventory[],ifstream& in)
{

    for(int i=0;i<7;i++)
    {
        getline(in>>ws,arrayOfColors[i]);
        getline(in>>ws,arrayOfInventory[i]);
        getline(in>>ws,arrayOfGlossLvl[i]);

    }
}
bool validDatainFile(string dataFromFile[],int length)
{
    try
    {
     for(int i =0;i<length;i++){
        stod(dataFromFile[i]);
     }
    }
    catch(...)
    {
        cout<<"Invalid data was in the file. \n";
        return false;
    }
    return true;
}
paint* typeCreation(string color,double gloss_level,double inventory)
{
    if(gloss_level>=0.1 and gloss_level<=5.0){
        return new flat(color,gloss_level,inventory);
    }elif(gloss_level>=10.5 and gloss_level<=25.0){
        return new Eggshell(color,gloss_level,inventory);}
    elif(gloss_level>=25.5 and gloss_level<=35.0){
        return new satin(color,gloss_level,inventory);
    }elif(gloss_level>=35.5 and gloss_level<=70.0){
        return new semiGloss(color,gloss_level,inventory);
    }elif(gloss_level>=85.0 and gloss_level<=95.0){
        return new highGloss(color,gloss_level,inventory);}
    else{
        return nullptr;
    }
}
string askForPaintColor()
{
    string color;
    cout<<"\nWhat color is this paint?\n";
    getline(cin>>ws,color);
    return color;
}
double rngNum(double lower,double upper)
{
    std::random_device rd;
    std::default_random_engine num(rd());
    std::uniform_real_distribution<double> randomNum(lower,upper);
    return randomNum(num);
}
bool validGlossLvl(string glossLvl[],int length)
{  bool valid =true;
    for(int i=0;i<length;i++){
        double num=stod(glossLvl[i]);
        if(num<0.1||(num>5 and num<10.5)||(num>25 and num<25.5)||(num>35 and num<35.5)||(num>70 and num<85)||(num>95)){
            valid= false;
        }
    }
    return valid;
}
paint* typeCreation(int choice)
{
    
    string color=askForPaintColor();
    double inventoryLeft=userInput("How much inventory is left?",0,10000);
    if(choice==1){
    return new flat(color,rngNum(0.1,5.0),inventoryLeft);
    }
    elif(choice==2){
    return new Eggshell(color,rngNum(10.5,25.0),inventoryLeft);
    }
    elif(choice==3){
    return new satin(color,rngNum(25.5,35.0),inventoryLeft);
    }
    elif(choice==4){
    return new semiGloss(color,rngNum(35.5,70.0),inventoryLeft);
    }
    elif(choice==5){
    return new highGloss(color,rngNum(85.0,95.0),inventoryLeft);
    }
    else{
        return nullptr;
    }   
}
double userInput(string txtOut,double lower,double upper){
 double userIn;
    while (true)
    {
        cout << txtOut + "\n";
        cin >> userIn;
        if (userIn >= lower && userIn <= upper && !cin.fail())
        {
            break;
        }
        else
        {
            cout << "Invalid input please enter a number between " << lower << " and " << upper << "\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

    }

    return userIn;
}
int userInput(string txtOut,int lower,int upper){
 int userIn;
    while (true)
    {
        cout << txtOut + "\n";
        cin >> userIn;
        if (userIn >= lower && userIn <= upper && !cin.fail())
        {
            break;
        }
        else
        {
            cout << "Invalid input please enter a number between " << lower << " and " << upper << "\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

    }

    return userIn;
}
void userChoiceOfPaint(int flag){
    cout<<"\n(1) Flat Paint\n";
    cout<<"(2) Eggshell Paint\n";
    cout<<"(3) Satin Paint\n";
    cout<<"(4) Semi-Gloss Paint\n";
    cout<<"(5) High-Gloss Paint\n";
    cout<<((flag==0) ? "(6) Load Inventory from a File\n" : "\n");
}

void menuAfterChoice()
{
    cout<<"\n Please choose from one of the following options:\n";
    cout<<"(1) Adjust inventory\n";
    cout<<"(2) View Help for Selection\n";
    cout<<"(3) View Current inventory\n";
    cout<<"(4) Print inventory to File\n";
    cout<<"(5) Quit\n";




}
void printAllPaints(paint* paintArray[],int length)
{cout<<"#:      Paint Color   Number of Cans  Gloss level(%)\n";
for(int i=0;i<length;i++){
    cout<<i+1<<*paintArray[i]<<endl;
}

}
void printToFile(paint* paintArray[],int length)
{
    while(true){
    cout<<"Please enter the file name that you would like to output to.\n";
    ofstream out;
    string nameOfFile="";
    getline(cin>>ws,nameOfFile);

    out.open(nameOfFile);
    if(!out.fail()){
        
    for(int i=0;i<length;i++)
    {
        out<<paintArray[i]->getColor()<<endl;
        out<<paintArray[i]->getInventory()<<endl;
        out<<paintArray[i]->getGlosslvl()<<endl;
        out<<endl;
    }
    out.close();
    break;
        }
    cout<<"Error opening file. Please try again.\n";
    }
    }

