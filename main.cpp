#include "Event.h"
#include "Schedule.h"
#include "RawInput.h"
#include <iostream>
#include <string>

using namespace std;

void printMenu(){
    cout<<"a: to add another task"<<endl;
    cout<<"c: to check off a task"<<endl;
    cout<<"s: to save and end program"<<endl;
}

int main(){

    // Event e();
    // Work w("do hw",2,"i hate hw");
    // Leisure l("go to the mall","going with bill to get pastrami");
    // Taken t;
    // w.printEvent();
    // l.printEvent();
    // t.printEvent();
    // return 1;

    char input;
    Event dummy;
    Schedule s;
    RawInput rawInput;

    s.setTaskList(rawInput.askTasks());
    s.setPreferences(rawInput.askPreferences());

    while(input!='s'){

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