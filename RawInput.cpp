#include "RawInput.h"
#include <iostream>

using namespace std;

RawInput::RawInput() { }

vector<bool> RawInput::askPreferences()
{
    vector<bool> prefList;
    string userInput = "";

    cout << "Do you not want to do nothing today? (Yes or No)" << endl;

    cin >> userInput;

    for (auto &character : userInput)
    {
        character = tolower(character);
    }
    prefList.push_back(userInput == "yes"); // if the userInput is yes, it will add true, else otherwiese.

    if (userInput == "no") // if the user wants to do tasks today, then we ask the rest of the questions.
    {
        cout << "Do you feel lazy today? (Yes or No)" << endl; // We discuss what we do for this later
        cin >> userInput;

        for (auto &character : userInput)
        {
            character = tolower(character);
        }
        prefList.push_back(userInput == "yes");

        cout << "Do you feel being silly today? (Yes or No)" << endl; // We flip the order to least important to most important
        cin >> userInput;

        for (auto &character : userInput)
        {
            character = tolower(character);
        }
        prefList.push_back(userInput == "yes");
    }
    
    return prefList;
    
    /*for(bool preference : prefList) //TestFunction to check inside the vector.
    {
        if(preference)
        {
            cout << "Yes" << endl;
        }
        else
        {
            cout << "No" << endl;
        }
    }
    */
}

vector<Event> RawInput::askTasks() {
    char userDecision;
    vector<Event> rawTaskList;

    string name;
    char category;
    string description;
    int priority = 0;

    do {
        cout << "Enter task name: ";
        getline(cin, name);
        cout << endl;

        cout << "Enter task description: ";
        getline(cin >> ws, description);
        cout << endl;

        cout << "Is this task work-related? (y/n): ";
        
        while (cin >> category) {
            if (category == 'y' || category == 'Y') {
                cout << "Enter task priority (1 = most, 3 = least): " ;

                cin >> priority;
                while (cin.fail() || (priority < 1 || priority > 3)) {
                    cout << "Not a valid input. " << endl;
                    cout << "Enter task priority (1 = most, 3 = least): ";
                    cin.clear();
                    cin.ignore();
                    cin >> priority;
                    cout << endl;
                }

                Work currWorkEvent(name, priority, description);
                rawTaskList.push_back(currWorkEvent);
                break;
            } 
            else if (category == 'n' || category == 'N') {
                Leisure currLeisureEventLeisure(name, description);
                rawTaskList.push_back(currLeisureEvent);
                break;
            } 
            else {
                cout << "Not a valid input. " << endl;
                cout << "Is this task work-related? (y/n): ";
            }
            cin.clear();
            //break;
        }
        
        cout << "Task added successfully!" << endl;
        cout << "Press q to quit. Any other key to continue. . ." << endl;
        cin >> userDecision;
        cout << endl;
        cin.ignore();
    } while (userDecision != 'q' && userDecision != 'Q');


     /*for (int i = 0; i < rawTaskList.size(); i++) {
        rawTaskList.at(i)->printEvent();
        cout << endl;
    }  //testing code */
  
    return rawTaskList;
}
