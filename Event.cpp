#include "Event.h"
#include <iostream>
#include <fstream>
using namespace std;
Event::Event(){
    this->name="dummy";
    this->description="dummy description";
}

string Event::getName(){
    return name;
}
string Event::getDescription(){
    return description;
}

Work::Work(string name,int priority,string description){ //Default constructor 
    this->name=name;
    this->priority=priority;
    this->description=description;
}
ostream Work::printEvent(){
    ostream s;
    s<<"* "<<name<<" *"<<endl;
    s<<"- "<<description<<" - ";
    if(priority=1){
        s<<"high priority"<<endl;
    } else if(priority=2){
        s<<"middle priority"<<endl;
    }else{
        s<<"low priority"<<endl;
    }
    return s;
}

Leisure::Leisure(string name, string description){
    this->name=name;
    this->description=description;
}
ostream Leisure::printEvent(){
    ostream s;
    s<<"* "<<name<<" *"<<endl;
    s<<"- "<<description<<" -"<<endl; 
    return s;

}
Taken::Taken(){
    this->name="";
    this->description="";
}
ostream Taken::printEvent(){
    ostream s;

    s<<"-------------------"<<endl;
    return s;

}

