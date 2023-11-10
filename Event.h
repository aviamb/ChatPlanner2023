#ifndef __EVENT_H__
#define __EVENT_H__

#include <string>
using namespace std;

class Event{
    public:        
        Event(string name, string category,int priority,string description);
        Event(string name, string category,int priority);
        Event(string name, string category);
        Event(string name);
        Event();
        void printTask();
    private: 
        string name;
        string category;
        int priority;
        string description; 
    
};

#endif
