#include "RawInput.h"
#include <iostream>

// using namespace std;

RawInput::RawInput() { 
    
}

vector<bool> RawInput::askBusyTimes(){

    vector <bool> busyTimes(24);
    int input;
    cout<<"Enter hour that you are already busy (enter number 1-24)"<<endl;
    cin>>input;
    busyTimes.at(input)=true;
    while(input!=0){
        cout<<"Continue entering hours that you are busy, or enter 0 to quit"<<endl;
        cin>>input;
        busyTimes.at(input)=true;
    }
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
