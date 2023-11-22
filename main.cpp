#include <iostream>
#include "RawInput.cpp"

using namespace std;

int main()
{
    RawInput raw;
    vector <bool> rawTest = raw.askPreferences();
    
    for(bool preference : rawTest) //TestFunction to check inside the vector.
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
    return 0;
}
