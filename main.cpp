#include "Event.h"
#include "Schedule.h"
#include "RawInput.h"
#include <iostream>
#include <string>
//  #include "gtest/gtest.h"

using namespace std;

void printMenu(){
    cout<<"d: to delete a task"<<endl;
}

int main(){
    Schedule s;
    RawInput r;
    char input;
    int dayCounter = 0;
    
    while(true){
        s.setTaskList(r.askTasks());
        s.setPreferences(r.askPreferences());
        cin >> input;
        while(input!='s'){
            cout<<"DAY - "<<dayCounter<<endl;

            s.makeSchedule();
            s.displaySchedule(cout);
            printMenu();

            cin>>input;

            if(input == 'd')
            {
                s.deleteTask();
            }
            else
            {
                cout<<"not a valid choice, try again"<<endl;
            }
        }
    }
    return 1;
};

