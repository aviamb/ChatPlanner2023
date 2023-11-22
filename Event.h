#ifndef __EVENT_H__
#define __EVENT_H__

#include <string>
#include <iostream>
#include <fstream>
using namespace std;

class Event{
    public:
        Event();
        virtual void printEvent(){}
        const string getName();
        const string getDescription();
        void setName(string);
        void setDescription(string);
    protected:
        string name;
        string description;
};

class Work: public Event{
    public:
        void printEvent(ostream & out);
        Work(string,int,string);
        int priority;
};

class Leisure: public Event{
    public:
        void printEvent(ostream & out);
        Leisure(string,string);
};

class Taken: public Event{
    public:
        void printEvent(ostream & out);
        Taken();
};

#endif