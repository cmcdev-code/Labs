#include "class.h"
#include <fstream>
#define elif else if

using namespace std;
void readInFromFile(string arrayOfColors[],string arrayOfGlossLvl[],string arrayOfInventory[]);
void loopThroughFile(string arrayOfColors[],string arrayOfGlossLvl[],string arrayOfInventory[],ifstream& in);
bool validDatainFile(string dataFromFiile[],int length);
string askForPaintColor();
double rngNum(double lower,double upper);
bool validGlossLvl(string glossLvl[],int length);

paint* typeCreation(string color,double gloss_level,double inventory);
paint* typeCreation(int choice);

double userInput(string txtOut,double lower,double upper);
int userInput(string txtOut,int lower,int upper);
void userChoiceOfPaint(int flag);
 
int main(void)
{
    paint *  allPaintStuff[7];
    
    cout<<"Please choose from the following options: \n";
    for(int i=0;i<7;i++)
    {
        userChoiceOfPaint(i);
        int userChoice=userInput("Please enter your choice: ",1,(i==0) ? 6:5);
        if(userChoice==6){
            
            string arrayOfColors[7];string arrayOfGlossLvl[7];string arrayOfInventory[7];
            readInFromFile(arrayOfColors,arrayOfGlossLvl,arrayOfInventory);
            for(int i=0;i<7;i++)
            {
                allPaintStuff[i]=typeCreation(arrayOfColors[i],stod(arrayOfGlossLvl[i]),stod(arrayOfInventory[i]));
            }break;
        }
        else {
            allPaintStuff[i]=typeCreation(userChoice);
        }
    }






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
            for(int i=0;i<7;i++){
                cout<<arrayOfColors[i]<<" "<<arrayOfInventory[i]<<" "<<arrayOfGlossLvl[i]<<endl;
            }
            if(validDatainFile(arrayOfGlossLvl,7)&& validDatainFile(arrayOfInventory,7)){
                if(validGlossLvl(arrayOfGlossLvl,7)){
                    break;
                }
            }
            else{
            cout<<"Invalid data was in the file. Please try again.\n";
            }
        }
    }

}

void loopThroughFile(string arrayOfColors[],string arrayOfGlossLvl[],string arrayOfInventory[],ifstream& in)
{
    string emptyString="";

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
    if(gloss_level>=0.1 && gloss_level<=5.0){
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