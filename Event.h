#ifndef __EVENT_H__
#define __EVENT_H__

#include <string>
#include <iostream>
#include <fstream>
using namespace std;

class Event{
    public:
        Event();
        virtual ostream printEvent();
        string getName();
        string getDescription();
    protected:
        string name;
        string description;
};

class Work: public Event{
    public:
        ostream printEvent();
        Work(string,int,string);
        int priority;
};

class Leisure: public Event{
    public:
        ostream printEvent();
        Leisure(string,string);
};

class Taken: public Event{
    public:
        ostream printEvent();
        Taken();
};

#endif
