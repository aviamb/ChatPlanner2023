#ifndef __RAWINPUT_H__
#define __RAWINPUT_H__
#include "Event.h"
#include <iostream>
#include<vector>
using namespace std;

class RawInput{
    private:
    vector<Event> rawTaskList;
    vector<bool> prefList;
    
    public: 
    RawInput();
    vector<bool> askPreferences(); 
    vector<Event> askTasks(); 
};

#endif

//preferences order:
