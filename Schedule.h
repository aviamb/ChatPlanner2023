#ifndef __SCHEDULE_H__
#define __SCHEDULE_H__
#include "Event.h"
#include <vector>
using namespace std;
#include <iostream>

class Schedule{

    public:
    
        void setTaskList(vector<Event> cpy){
            taskList=cpy;
        }
        void setPreferences(vector<bool> cpy){
            preferences=cpy;
        }

        void addTask(Event newTask){
            cout<<"task should be added to next available hour slot"<<endl;
        }

        void checkOffTask(string name){
            cout<<"task that has same name as inputted parameter should be removed"<<endl;
        }

        void displaySchedule(){
            cout<<"schedule should display here"<<endl;
        }

        void saveSchedule();
        
    private:
        vector<Event>taskList;
        vector<Event>hours;
        vector<bool>preferences;
        
    
};


#endif