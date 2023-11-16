#ifndef __EVENT_H__
#define __EVENT_H__

#include <string>
#include <iostream>
using namespace std;

class Event{
    public:
        void printTask();

    private:
        string name;
        string category;
        int priority;
        string description; 
    
};

#endif
