#ifndef __RAWINPUT_H__
#define __RAWINPUT_H__
#include "Event.h"
#include <iostream>
#include<vector>
using namespace std;

class RawInput{
    public: 
    RawInput();
    vector<bool> askPreferences(istream &); 
    vector<Event> askTasks(istream &); 
    vector<bool> askBusyTimes(int,int,istream &);
    int askTimeNow();
    int askSleepTime();
};

#endif

//preferences order:
