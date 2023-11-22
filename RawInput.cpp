#include "RawInput.h"
#include <iostream>

// using namespace std;

RawInput::RawInput() { 
    
}

vector<bool> RawInput::askBusyTimes(istream & in){

    vector <bool> busyTimes(24);
    string input;
    bool endUserInput=false;
    
    while(!endUserInput){
        cout<<"Enter hour(1-24) that you are already busy (enter 0 to stop)"<<endl;
        in>>input;
        if(isdigit(input[0])){
            if(stoi(input)==0){
            endUserInput=true;
            }
            else if(stoi(input)>25){
                cout<<"there are only 24 hours in a day"<<endl;
                input="0";
            }else{
                busyTimes.at(stoi(input)-1)=true;
            }   
        }else{
            cout<<"please enter an integer"<<endl;
        }
    }
    cout<<"You have entered all the time you are already busy"<<endl;
    return busyTimes;
}

vector<bool> RawInput::askPreferences()
{
    vector<bool> b;
    return b;
}

vector<Event> RawInput::askTasks() {
    vector<Event> e;
    return e;    
}
