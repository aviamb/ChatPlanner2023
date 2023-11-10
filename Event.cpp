#include "Event.h"
#include <iostream>
using namespace std;

Event::Event(string name, string category,int priority,string description){
    this->name=name;
    this->category=category;
    this->priority=priority;
    this->description=description;
}

Event::Event(string name, string category,int priority){
    this->name=name;
    this->category=category;
    this->priority=priority;
    this->description="";
}

Event::Event(string name, string category){
    this->name=name;
    this->category=category;
    if(category=="work"){
        this->priority=1;
    }else{
        this->priority=3;
    }
    this->description="none";
}

Event::Event(string name){
    this->name=name;
    this->category="uncategorized";
    this->priority=3;
    this->description="none";
}

Event::Event(){
    this->name="null event";
    this->category="uncategorized";
    this->priority=3;
    this->description="none";
}

void Event::printTask(){
    cout<<"*"<<name<<"*"<<endl;
    cout<<"-"<<description<<"-"<<endl;
}
 