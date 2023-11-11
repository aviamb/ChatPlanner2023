#include "RawInput.h"
using namespace std;

RawInput::RawInput() { }

void RawInput::askTasks() {
    char userDecision;

    string name;
    string category;
    string description;
    int priority;

    do {
        cout << "Enter task name: ";
        cin >> name;
        cout << endl;

        cout << "Enter task category: ";
        cin >> category;
        cout << endl; 

        cout << "Enter task priority (1 = most, 5 = least): " ;
        cin >> priority;
        cout << endl;

        cout << "Enter task description: ";
        cin >> description;

        Event currEvent(name, category, priority, description);
        rawTaskList.push_back(currEvent);

        cout << "Press q to quit. Any other key to continue. . ." << endl;
        cin >> userDecision;
        cout << endl;

    } while (userDecision != 'q');

    /*for (int i = 0; i < rawTaskList.size(); i++) {
        rawTaskList.at(i).printTask();
    }*/ //testing code
}

//function currently doesn't accomodate other constructors.
//function currently doesn't use input validation.
//function doesn't use getline yet.