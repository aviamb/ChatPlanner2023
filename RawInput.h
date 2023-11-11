#ifndef __RAWINPUT_H__
#define __RAWINPUT_H__

#include <vector>

class RawInput{
    private:
    vector<Event> rawTaskList;
    vector<bool> prefList;
    
    public: 
    RawInput();
    void askPreferences(); 
    void askTasks(); //terminated by q
};

#endif

//preferences order:
