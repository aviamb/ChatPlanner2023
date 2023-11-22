#ifndef __RAWINPUT_H__
#define __RAWINPUT_H__

using namespace std;
#include <vector>
#include <iostream>
#include "Event.h"

class RawInput{
    public: 
    RawInput();
    vector<bool> askPreferences(); 
    vector<Event> askTasks(); 
};

#endif

//preferences order:
