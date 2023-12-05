#include "RawInput.h"
#include <iostream>

// using namespace std;

RawInput::RawInput() { }

int RawInput::askTimeNow(){
    bool endUserInput=false;
    string timeNow;
    while(!endUserInput){
        cout<<"What hour is it now? Enter an hour from 1-24"<<endl;
        cin>>timeNow;
        if(isdigit(timeNow[0])){
            if(stoi(timeNow)>25){
                cout<<"there are only 24 hours in a day"<<endl;
                timeNow="0";
            }else{
                return stoi(timeNow);
            }
            
        }else{
            cout<<"please enter an integer"<<endl;
            cin>>timeNow;
        }
    }
    return -1;
}
int RawInput::askSleepTime(){
    string sleepTime;
    bool endUserInput=false;
    while(!endUserInput){
        cout<<"Enter what time you want to sleep (must be no later than 24:00)"<<endl;
        cin>>sleepTime;
        if(isdigit(sleepTime[0])){
            if(stoi(sleepTime)>24){
                cout<<"there are only 24 hours in a day"<<endl;
                sleepTime="0";
            }else{
                return stoi(sleepTime);
            }
        }else{
            cout<<"please enter an integer"<<endl;
            cin>>sleepTime;
        }
    }
    return -1;
}


vector<bool> RawInput::askBusyTimes(int currentTime,int sleepTime,istream & in){

    vector <bool> busyTimes(24);
    string input;
    bool endUserInput=false;
    
    while(!endUserInput){
        cout<<"Enter hours (after the current hour) that you are already busy (enter 0 to stop)"<<endl;
        in>>input;
        if(isdigit(input[0])){
            if(stoi(input)==0){
            endUserInput=true;
            }
            else if(stoi(input)<currentTime){
                cout<<"that is less than the current Time"<<endl;
            }
            else if(stoi(input)>=sleepTime){
                if(stoi(input)>25){
                    cout<<"there are only 24 hours in a day"<<endl;

                }else{
                    cout<<"You should be asleep by that time"<<endl;

                }
            }else{
                busyTimes.at(stoi(input)-1)=true;
            }   
        }else{
            cout<<"please enter an integer"<<endl;
            in>>input;
        }
    }
    cout<<"You have entered all the time you are already busy"<<endl;
    return busyTimes;
}

vector<bool> RawInput::askPreferences(istream &in)
{
    vector<bool> prefList;
    string userInput = "";

    cout << "Do you not want to do nothing today? (Yes or No)" << endl;

    in >> userInput;

    for (auto &character : userInput)
    {
        character = tolower(character);
    }
    prefList.push_back(userInput == "yes"); // if the userInput is yes, it will add true, else otherwiese.

    if (userInput == "no") // if the user wants to do tasks today, then we ask the rest of the questions.
    {
        cout << "Do you feel lazy today? (Yes or No)" << endl; // We discuss what we do for this later
        in >> userInput;

        for (auto &character : userInput)
        {
            character = tolower(character);
        }
        prefList.push_back(userInput == "yes");

        cout << "Do you feel being silly today? (Yes or No)" << endl; // We flip the order to least important to most important
        in >> userInput;

        for (auto &character : userInput)
        {
            character = tolower(character);
        }
        prefList.push_back(userInput == "yes");
    }
    
    return prefList;

}



vector<Event> RawInput::askTasks(istream &in) {
    string userDecision;
    vector<Event> rawTaskList;

    string name;
    string category;
    string description;
    int priority = 0;

    do {
        cout << "Enter task name: ";
        getline(in, name);
        cout << endl;

        cout << "Enter task description: ";
        getline(in >> ws, description);
        cout << endl;

        cout << "Is this task work-related? (y/n): ";
        
        while (in >> category) {
            if (category != "y" && category != "Y" && category != "n" && category != "N") {
                cout << "Not a valid input. " << endl;
                cout << "Is this task work-related? (y/n): ";
            }
            else if (category == "y" || category == "Y") {
                cout << "Enter task priority (1 = most, 3 = least): " ;

                in >> priority;
                while (in.fail() || (priority < 1 || priority > 3)) {
                    cout << "Not a valid input. " << endl;
                    cout << "Enter task priority (1 = most, 3 = least): ";
                    in.clear();
                    in.ignore();
                    in >> priority;
                    cout << endl;
                }

                Work currWorkEvent(name, priority, description);
                rawTaskList.push_back(currWorkEvent);
                break;
            } 
            else {
          (name, description);
                rawTaskList.push_back(cu      Leisure currLeisureEventrrLeisureEvent);
                break;
            } 
            in.clear();
        }
        
        cout << "Task added successfully!" << endl;
        cout << "Press q to quit. Any other key to continue. . ." << endl;
        in >> userDecision;
        cout << endl;
        in.ignore();
    } while (userDecision != "q" && userDecision != "Q");

    return rawTaskList;
}
