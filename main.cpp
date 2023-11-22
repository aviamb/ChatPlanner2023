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

// int main(int argc, char **argv){
//     ::testing::InitGoogleTest(&argc,argv);
//     return RUN_ALL_TESTS();
// }
int main(){

    RawInput r;
    //r.askPreferences();
    r.askTasks();

};
