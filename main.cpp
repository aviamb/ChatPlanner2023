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
    cout<<"s: to save and end day"<<endl; //input validation broken
}


void clearLog(){
    ofstream outFS;
    outFS.open("log.txt");
    while(outFS.eof()){
        outFS<<"";
    }
}


int main(){
    clearLog();
    Event dummy;
    Schedule s;
    RawInput r;
    int dayCounter=0;
    bool dayIsOver=false;

    while(true){
        cout<<"DAY - "<<dayCounter<<endl;
        s.setTimeNow(r.askTimeNow());
        s.setSleepTime(r.askSleepTime());
        s.setPreferences(r.askPreferences(cin));
        s.setBusyTimes(r.askBusyTimes(s.getTimeNow(),s.getSleepTime(),cin));
        cin.ignore();
        s.setTaskList(r.askTasks(cin));
        s.popOffExtraHours();

        char input='z';
        while(input!='s'){
            s.makeSchedule();
            s.displaySchedule(cout);
            printMenu();

            cin>>input;
            if(input=='a'){
                s.addTask(cin);
            }else if(input=='c'){
                s.checkOffTask(cin);
            }else if(input=='s'){
                s.saveSchedule();
                dayCounter++;
                input=' ';
                cin.ignore();
                break;
            }else{
                cout<<"not a valid choice, try again"<<endl;
            }
        }
        break;
    }
    return 1;
};
