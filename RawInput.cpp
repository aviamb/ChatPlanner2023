// #include "RawInput.h"
// #include <iostream>

// using namespace std;

// RawInput::RawInput() { }

// vector<bool> RawInput::askPreferences()
// {
//     string userInput = "";

//     cout << "Do you not want to do nothing today? (Yes or No)" << endl;

//     cin >> userInput;

//     for (auto &character : userInput)
//     {
//         character = tolower(character);
//     }
//     this->prefList.push_back(userInput == "yes"); // if the userInput is yes, it will add true, else otherwiese.

//     if (userInput == "no") // if the user wants to do tasks today, then we ask the rest of the questions.
//     {
//         cout << "Do you feel lazy today? (Yes or No)" << endl; // We discuss what we do for this later
//         cin >> userInput;

//         for (auto &character : userInput)
//         {
//             character = tolower(character);
//         }
//         this->prefList.push_back(userInput == "yes");

//         cout << "Do you feel being silly today? (Yes or No)" << endl; // We flip the order to least important to most important
//         cin >> userInput;

//         for (auto &character : userInput)
//         {
//             character = tolower(character);
//         }
//         this->prefList.push_back(userInput == "yes");
//     }
    
//     /*for(bool preference : prefList) //TestFunction to check inside the vector.
//     {
//         if(preference)
//         {
//             cout << "Yes" << endl;
//         }
//         else
//         {
//             cout << "No" << endl;
//         }
//     }
//     */
//     return prefList;
// }

// vector<Event> RawInput::askTasks() {
//     char userDecision;

//     string name;
//     string category;
//     string description;
//     int priority;

//     do {
//         cout << "Enter task name: ";
//         cin >> name;
//         cout << endl;

//         cout << "Enter task category: ";
//         cin >> category;
//         cout << endl; 

//         cout << "Enter task priority (1 = most, 5 = least): " ;
//         cin >> priority;
//         cout << endl;

//         cout << "Enter task description: ";
//         cin >> description;

//         Event currEvent(name, category, priority, description);
//         rawTaskList.push_back(currEvent);

//         cout << "Press q to quit. Any other key to continue. . ." << endl;
//         cin >> userDecision;
//         cout << endl;

//     } while (userDecision != 'q');

//     /*for (int i = 0; i < rawTaskList.size(); i++) {
//         rawTaskList.at(i).printTask();
//     }*/ //testing code
  
// //function currently doesn't accomodate other constructors.
// //function currently doesn't use input validation.
// //function doesn't use getline yet.
//     return rawTaskList;
// }
