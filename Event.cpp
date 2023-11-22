#include "Event.h"
#include <iostream>
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
void Work::printEvent(){
    cout<<"* "<<name<<" *"<<endl;
    cout<<"- "<<description<<" - ";
    if(priority=1){
        cout<<"high priority"<<endl;
    } else if(priority=2){
        cout<<"middle priority"<<endl;
    }else{
        cout<<"low priority"<<endl;
    }
}

Leisure::Leisure(string name, string description){
    this->name=name;
    this->description=description;
}
void Leisure::printEvent(){
    cout<<"* "<<name<<" *"<<endl;
    cout<<"- "<<description<<" -"<<endl; 
}
Taken::Taken(){
    this->name="";
    this->description="";
}
void Taken::printEvent(){
    cout<<"-------------------"<<endl;
}
