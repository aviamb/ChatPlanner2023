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

Work::Work(string name,int priority,string description){ //Default constructor 
    this->name=name;
    this->priority=priority;
    this->description=description;
}
void Work::printEvent(ostream & out){
    out<<"* "<<name<<" *"<<endl;
    out<<"- "<<description<<" -"<<endl;
}

string Work::getType(){
    return "Work";
}

Leisure::Leisure(string name, string description){
    this->name=name;
    this->description=description;
}
void Leisure::printEvent(ostream & out){
    out<<name<<endl;
    out<<"- "<<description<<" -"<<endl; 
}

string Leisure::getType(){
    return "Leisure";
}
Taken::Taken(){
    this->name="-------";
    this->description="";
}
void Taken::printEvent(ostream & out){
    out<<"-------------------"<<endl;
}
string Taken::getType(){
    return "Taken";
}
