#ifndef __RAWINPUT_H__
#define __RAWINPUT_H__
#include "Event.h"
#include <iostream>
#include<vector>
using namespace std;

class RawInput{
    public:
        vector<Event> askTasks(){
            cout<<"ask for user input here"<<endl;
            vector<Event> dummy;
            return dummy;
        }
        vector<bool> askPreferences(){
            cout<<"ask for user preferences here"<<endl;
            vector<bool> dummy;
            return dummy;
        }

};

#endif