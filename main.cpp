#include "Event.h"
#include "Schedule.h"
#include "RawInput.h"
#include <iostream>
#include <string>
//  #include "gtest/gtest.h"


using namespace std;

void printMenu(){
    cout<<"a: to add another task"<<endl;
    cout<<"c: to check off a task"<<endl;
    cout<<"s: to save and end program"<<endl;
}


int main(){

    char input;
    Event dummy;
    Schedule s;
    RawInput r;


    Work w1("hw",2,"due tomorrow");
    Work w2("mow lawn",1,"ew");
    Work w3("study",2,"due in two days");

    s.addTask(w1);
    s.addTask(w2);
    s.addTask(w3);

    s.makeSchedule();
    s.saveSchedule();

    s.setTaskList(r.askTasks());
    s.setPreferences(r.askPreferences());
    s.setBusyTimes(r.askBusyTimes());

    return 0;


    while(input!='s'){
        s.makeSchedule();
        s.displaySchedule();
        printMenu();

        cin>>input;

        if(input=='a'){
            s.addTask(dummy);
        }else if(input=='c'){
            s.checkOffTask("dummy");
        }else if(input=='s'){
            s.saveSchedule();
            break;
        }else{
            cout<<"not a valid input, try again"<<endl;
        }
    }
    return 1;
};

