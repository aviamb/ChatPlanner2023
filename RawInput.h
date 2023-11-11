#ifndef __RAWINPUT_H__
#define __RAWINPUT_H__

using namespace std;
#include <vector>
#include <iostream>

class RawInput{
    private:
    //vector<Event> rawTaskList;
    vector<bool> prefList;
    
    public: 
    RawInput();
    void askPreferences(); 
    void askTasks(); //terminated by q
};

#endif

//preferences order:
