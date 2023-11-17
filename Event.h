#ifndef __EVENT_H__
#define __EVENT_H__
#include <vector>
#include <string>


class Event{
    public:
        // string name;
        // string category;
        // int priority;
        // string description;
        string getName();
        string printEvent();
        Event();
};

#endif
