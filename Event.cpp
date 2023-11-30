#include "Event.h"
#include <iostream>
#include <fstream>
#include <ostream>

using namespace std;
// Event::Event(){
//     // this->name="dummy";
//     // this->description="dummy description";
// }


const string Event::getName(){
    return name;
}
const string Event::getDescription(){
    return description;
}

void Event::setName(string newName){
    name = newName;
}

void Event::setDescription(string newDesc){
    description = newDesc;
}

string Event::getType(){
    return type;
}   

int Event::getPriority(){
    return priority;
}

Work::Work(string name,int priority,string description){ //Default constructor 
    this->name=name;
    this->priority=priority;
    this->description=description;
    this->type="Work";
}
void Work::printEvent(ostream & out){
    out<<"* "<<name<<" *"<<endl;
    out<<"- "<<description<<" -"<<endl;
}

Leisure::Leisure(string name, string description){
    this->name=name;
    this->description=description;
    this->type="Leisure";
    this->priority=0;
}
void Leisure::printEvent(ostream & out){
    out<<name<<endl;
    out<<"- "<<description<<" -"<<endl; 
}


Taken::Taken(){
    this->name="-------";
    this->description="";
    this->type="Taken";
    this->priority=-1;

}
void Taken::printEvent(ostream & out){
    out<<"-------------------"<<endl;
}

