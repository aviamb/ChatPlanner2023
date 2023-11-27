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
    cout<<"s: to save and end day"<<endl;
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
    char input;
    Event dummy;
    Schedule s;
    RawInput r;
    int dayCounter=0;
    bool dayIsOver=false;

    while(true){
        cout<<"DAY - "<<dayCounter<<endl;
        s.setPreferences(r.askPreferences());
        s.setBusyTimes(r.askBusyTimes(cin));
        cin.ignore();
        s.setTaskList(r.askTasks());

        while(input!='s'){

            s.makeSchedule();
            s.displaySchedule(cout);
            printMenu();

            cin>>input;

            if(input=='a'){
                s.addTask(cin);
            }else if(input=='c'){
                s.checkOffTask();
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
    }
    return 1;
};

