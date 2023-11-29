#include "Schedule.h"
#include "Event.h"
#include <vector>
#include <iostream>
#include <sstream>
using namespace std;

Schedule::~Schedule(){
    hours.clear();
    preferences.clear();
    taskList.clear();
    busyTimes.clear();
}

void Schedule::saveSchedule(){
    ofstream outFS;
    string str;
    outFS.open("log.txt",ios::app);
    if(!outFS.is_open()){
        cout<<"error opening log"<<endl;
    }
    for(int i=0; i<hours.size();i++){
        outFS<<hours.at(i).getName()<<" - "<<hours.at(i).getDescription()<<endl;
    }
    outFS.close();
}

    // public: std::vector<Event> hours[24];
void Schedule::makeSchedule(){
    Leisure sleep("go to bed","");
    hours.at(hours.size()-1)=sleep;

    for(unsigned i = 0; i < busyTimes.size(); i++){
        if(busyTimes.at(i) == true){
            Taken e;
            hours.at(i-timeNow)=e;
        }
    } 
    vector<Event> leisureList;
    vector<Event> workList;
    for(int i=0; i<taskList.size();i++){
        if(taskList.at(i).getType()=="Leisure"){
            leisureList.push_back(taskList.at(i));
        }else{
            workList.push_back(taskList.at(i));
        }
    }
    cout<<"leisurelist size is "<<leisureList.size()<<endl;
    cout<<"worklist size is "<<workList.size()<<endl;

    int leisureIndex=0;
    int workIndex=0;
    if(preferences.at(0)==false){//index 0 is hardcoded to doing nothing
        if(preferences.at(1)==true){//true means procrastinator
            cout<<"procrastinator"<<endl;
            for(int i=0; i<hours.size();i++){
                if(leisureList.size()==leisureIndex){//if already at end of list
                    break;
                }
                if(hours.at(i).getName()=="free time"){
                    hours.at(i)=leisureList.at(leisureIndex);
                    leisureIndex++;
                }

            }
            for(int i=hours.size()-1; i>=0;i--){//last element is always go to bed
                cout<<"setting work events"<<endl;
                if(workList.size()==workIndex){//if already at end of list
                    break;
                }
            if( !(hours.at(i).getType()=="Taken"|| (hours.at(i).getType()=="Leisure" && hours.at(i).getName()!="free time"))){//if it is not a user set leisure activity or taken
                    hours.at(i)=workList.at(workIndex);
                    workIndex++;
                }
            }

        }
    }

}

void Schedule::setTimeNow(int t){
    timeNow=t;
}

int Schedule::getTimeNow(){
    return timeNow;
}

void Schedule::setSleepTime(int t){
    sleepTime=t;
}


void Schedule::displaySchedule(ostream & out){

    for(unsigned i=0;i<hours.size();i++){
        out<<"hour "<<1+timeNow+i;
        out<<":00 - " << hours.at(i).getName()<<endl;
    }
    
    // for(int i = 0; i < hours.size(); i++){
    //     out<< "hour ";
        
    //     if(1+timeNow+i >=24){
    //         out<<(1+timeNow+i)-23;
    //     }else{
    //         out<<" "<<1+timeNow+i;
    //     }
    //     out<<":00 - " << hours.at(i).getName()<<endl;
    // }
}

void Schedule::displayDetailedSchedule(ostream &out){
    for(int i = 0; i < hours.size(); i++){
        out << "hour " << i << ":00 - \n";
        hours.at(i).printEvent(out);
    }
}

void Schedule::checkOffTask() {//main
    Event* targetEvent;

    string taskName;
    string newName;
    string newDesc;
    
    do {
        cout << "Enter the current name of your task: ";
        cin.ignore();
        getline(cin, taskName);
        cout << endl;

        targetEvent = checkOffTask(taskName);
        if (targetEvent == nullptr) {
            cout << "Not a valid input." << endl;
        }
    } while (targetEvent == nullptr);

    targetEvent->setDescription("[COMPLETED] " + targetEvent->getDescription());
    cout << targetEvent->getDescription();
    return;
}

Event* Schedule::checkOffTask(const string taskName){//helper
    Event* task = nullptr;
    for(int i = 0; i < taskList.size(); i++) {
        if (taskList.at(i).getName() == taskName) {
            task = &taskList.at(i);
            break;
        }
    }
    return task;
}

void Schedule::setTaskList(vector<Event> e){
    taskList = e;
}
void Schedule::setPreferences(vector<bool> p){
    preferences = p;
}
void Schedule::setBusyTimes(vector<bool> b){
    busyTimes=b;
}
        
void Schedule::addTask(istream &in){
    string name;
    string input;
    string priority;
    string description;
    cout<<"Enter task name"<<endl;
    in.ignore();
    getline(in,name);
    cout<<"Enter description of task"<<endl;
    getline(in,description);

    cout<<"Is this a work task?(yes/no)"<<endl;
    in>>input;
    if(input=="yes"){
        cout<<"Enter priority of task"<<endl;
        in>>priority;
        bool validPriority=false;
        while(!validPriority){
            if(isdigit(priority[0])){
                Work newTask(name,stoi(priority),description);
                taskList.push_back(newTask);
                validPriority=true;
            }else{
                cout<<"please enter an int"<<endl;
                in>>priority;
            }
        }
    }else{
        Leisure newTask(name,description);
        taskList.push_back(newTask);
    }    
}

int Schedule::getTaskListSize(){
    return taskList.size();
}

Schedule::Schedule(){
    for(int i=0; i<24;i++){
        Leisure e("free time"," ");
        hours.push_back(e);
    }

}

void Schedule::popOffExtraHours(){
    for(int i=0; i<timeNow+(24-sleepTime);i++){
        hours.pop_back();
    }
}
