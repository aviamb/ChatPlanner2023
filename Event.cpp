#include "Event.h"
#include <iostream>
#include <fstream>
#include <ostream>

using namespace std;
// Event::Event(){
//     // this->name="dummy";
//     // this->description="dummy description";
// }

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
void Work::printEvent(ostream & out){
    out<<"* "<<name<<" *"<<endl;
    out<<"- "<<description<<" -"<<endl;
}

Leisure::Leisure(string name, string description){
    this->name=name;
    this->description=description;
}
void Leisure::printEvent(ostream & out){
    out<<name<<endl;
    out<<"- "<<description<<" -"<<endl; 
}
Taken::Taken(){
    this->name="";
    this->description="";
}
void Taken::printEvent(ostream & out){
    out<<"-------------------"<<endl;
}

