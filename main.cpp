#include "Event.h"
#include "Schedule.h"
#include "RawInput.h"
#include <iostream>
#include <string>

using namespace std;

void printMenu(){
    cout<<"press a to add another task and c to check off a task and s to save and end program"<<endl;
}

int main(){

    Schedule schedule;
    RawInput rawInput;

    //ask for rawinput
    schedule.taskList=rawInput.askTasks();
    //as for tasks
    schedule.preferences=rawInput.askPreferences();
    
    char input;
    cin>>input;
    while(input!='s'){
        s.displaySchedule();
        //print out menu
        printMenu();
        cin>>input;
        if(input==a){
            s.addTask();
        }else if(input==c){
            s.checkOffTask();
        }else if(input=s){
            s.saveSchedule();
        }

    }

    return 1;
};