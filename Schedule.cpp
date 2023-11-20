#include "Schedule.h"
#include "Event.h"
#include <iostream>

void Schedule::saveSchedule(){
    //open file
    ofstream outFS;
    string str;
    outFS.open("log.txt");
    if(!outFS.is_open()){
        cout<<"error opening log"<<endl;
    }

    for(int i=0; i<hours.size();i++){
        outFS<<hours.at(i).getName()<<" - "<<hours.at(i).getDescription()<<endl;
    }
}
