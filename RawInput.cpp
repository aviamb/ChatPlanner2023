#include "RawInput.h"
#include <iostream>

using namespace std;
RawInput::RawInput()
{
}

void RawInput::askPreferences()
{
    string userInput = "";

    cout << "Do you not want to do nothing today? (Yes or No)" << endl;

    cin >> userInput;

    for (auto &character : userInput)
    {
        character = tolower(character);
    }
    this->prefList.push_back(userInput == "yes"); // if the userInput is yes, it will add true, else otherwiese.

    if (userInput == "no") // if the user wants to do tasks today, then we ask the rest of the questions.
    {
        cout << "Do you feel lazy today? (Yes or No)" << endl; // We discuss what we do for this later
        cin >> userInput;

        for (auto &character : userInput)
        {
            character = tolower(character);
        }
        this->prefList.push_back(userInput == "yes");

        cout << "Do you feel being silly today? (Yes or No)" << endl; // We flip the order to least important to most important
        cin >> userInput;

        for (auto &character : userInput)
        {
            character = tolower(character);
        }
        this->prefList.push_back(userInput == "yes");
    }
    
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

int main()
{
    RawInput rawInput;
    rawInput.askPreferences();
    
    return 0;
}