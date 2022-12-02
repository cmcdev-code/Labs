#include "class.h"
#include <fstream>
#define elif else if

using namespace std;
void readInFromFile(string arrayOfColors[],string arrayOfGlossLvl[],string arrayOfInventory[]);
void loopThroughFile(string arrayOfColors[],string arrayOfGlossLvl[],string arrayOfInventory[],ifstream& in);
bool validDatainFile(string dataFromFiile[],int length);

paint* typeCreation(string color,double gloss_level,double inventory);

int main(void)
{

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

            if(validDatainFile(arrayOfGlossLvl,3)&& validDatainFile(arrayOfInventory,3)){
            break;}
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
        getline(in>>ws,arrayOfGlossLvl[i]);
        getline(in>>ws,arrayOfInventory[i]);
        getline(in>>ws,emptyString);
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