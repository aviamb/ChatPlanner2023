#ifndef __EVENT_H__
#define __EVENT_H__

#include <string>
#include <iostream>
#include <fstream>
using namespace std;

class Event{
    public:
        ~Event(){}
        Event(){}
        virtual void printEvent(ostream &){}
        const string getName();
        const string getDescription();
        void setName(string);
        void setDescription(string);
        string getType();
        int getPriority();

    protected:
        string name;
        string description;
        string type;
        int priority;
};

class Work: public Event{
    public:
        void printEvent(ostream & out);
        Work(string,int,string);
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