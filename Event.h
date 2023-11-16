#ifndef __EVENT_H__
#define __EVENT_H__

#include <string>
#include <iostream>
using namespace std;

class Event{
    public:
        Event();
        virtual void printEvent();
    protected:
        string name;
        string description;
};

class Work: public Event{
    public:
        void printEvent();
        Work(string,int,string);
        int priority;
};

class Leisure: public Event{
    public:
        void printEvent();
        Leisure(string,string);
};

class Taken: public Event{
    public:
        void printEvent();
        Taken();
};

#endif
