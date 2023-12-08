 # ChatPlanner
  > Authors: 
  >Avia Bequette ([https://github.com/aviamb])
  >Sangha Jeon ([https://github.com/sangha0822])
  >Amber Lin ([https://github.com/pilafnoodle])
  >Marcel Relaford ([https://github.com/mouremr])

## Project Description

Chatplanner is an interactive task manager that can help users plan their daily schedule with just a few questions! Rather than a rigid schedule planner where the user manually organizes events, this is a schedule suggester that organizes your tasks based on your personal preferences and time restrictions throughout a day. 

#### Why is this project important to us? 
  As students, we must have organized and optimized schedules. 

  Balancing homework, clubs, meetings, classes, and more can be done efficiently with an optimized and interactive dayplanner.

#### Languages and Input/Output
  Chatplanner will be developed using C++.

  Chatplanner is a textbot and will be executed through the terminal only.

  Users may enter preferences, tasks, and times not available. Chatplanner will generate a potential schedule for the user with each run.

#### Project Features:
 * generate non rigid schedule for a user based on user input
 * ability to add, checkoff, and delete tasks
 * automatically categorize tasks
 * ability to block out time that is currently busy
 * ability to ask for schedule preferences (ex. night owl, early sleeper, procrastinator)
 * check off tasks as day goes on
 * save schedule to a log.txt file
 * look at past events

## User Interface Specification

### Navigation Diagram
ChatPlanner will begin by prompting users for personal scheduling preferences on one (text) screen within the terminal. The next screen will ask for events and any associated details such as priority, description, etc. User may terminate task input and generate a schedule, delete a previously added task, go back to adding tasks (then regenerate), finish a task, or save the schedule to a personal file to terminate the program. 

### Screen Layouts
![nav (2)](https://github.com/cs100/final-project-alin157-mrela001-abequ001-sjeon065/assets/117532511/d98f3f2e-0b01-4fce-bcfa-c2b902bc6e76)

## Class Diagram
Users will be prompted for schedule preferences and their choices will be stored within a vector of bools within the schedule class, returned by AskPreferences() from the RawInput class. Users will then create tasks from prompts described in the navigation diagram. Tasks will be objects of the event class and its subclasses, and pushed into the unsorted tasks vector of the "Schedule" class, again through the "RawInput" class's AskTasks(). The Schedule class will use the unsorted tasks vector to generate a sorted schedule of events specific to the users preferences, stored in the 'hours' vector of Events. Tasks of the "Leisure" class will be sorted as extended Events, while tasks of the Work class will be assigned a priority by the user to move the task up in the day's Schedule. The displaySchedule function is used for printing and design purposes for the user, as represented by the display/menu section of the navigation diagram. The schedule class may also use the saveSchedule() function to save a user's' most recently generated schedule to a .txt file and "end" the day. 
![chatPlannerUML drawio](https://github.com/cs100/final-project-alin157-mrela001-abequ001-sjeon065/assets/117532511/26318ee8-7f03-4a2c-a265-cc402f6ff25e)

### Previous class diagrams
development stage:
![chat planner-uml 11 22 drawio](https://github.com/cs100/final-project-alin157-mrela001-abequ001-sjeon065/assets/116844248/e84e0013-1eb8-43db-b09f-997af6c0bada)

initial stage:
![image](https://github.com/cs100/final-project-alin157-mrela001-abequ001-sjeon065/assets/116844248/ee0bc048-3b92-4c51-8b4e-385b5bb575c1)

 
  ## Phase III
We made the following changes to our initial class diagram :
  * Display_Schedule and Save_Schedule are now inside the Schedule class
     * We applied SRP in a reverse way to fix our Schedule class. Display and Save are functions that the Schedule class should be responsible for, and not their own classes. Now Schedule is responsible for all functions requiring a Schedule. This reduces the amount of classes we have and makes the UML and code easier to read. It also reduces the amount of times a vector has to be passed into functions during the program.
  * Schedule now contains 3 vectors, a list of tasks, a list of hours and a list of preferences
     * We applied OCP to the schedule class. Before, we had these vectors inside a RawInput class (class to ask for user input). This meant that whenever we wanted to add another vector of variable for a preference(ie a boolean for whether or not you are a procrastinator) we had to change a member variable outside of Schedule. This is also an example of SRP because now RawInput only takes input, and Schedule is self contained with all the data it needs to run. This makes our code easier to debug and read because, for example, we don't have to pass in a taskList from an outside class when it should be accessible from Schedule itself.
  * Event is now an abstract base class with specific event classes derived from it
     * We applied ISP to the Event class. Before, every type of event(work, free, busy) had to have a priority and description field when that didn't make sense for events as a null event for time already busy. To solve this, instead of having a category member variable we made subtypes to keep track of the different types of events instead. This makes the code more organized as different kinds of events are defined by their object type, and not by a string member variable entered by the user. This also satisfies the Liskov substution principle. Any type of Event can be valid when an Event is needed. For example, any kind of Event can be added to the hours vector. By seperating Event types, it allows us to create seperate printEvent() functions for each subtype. It doesn't make sense to have the same printEvent for each type of Event(Work Event has a priority variable, while leisure does not). This also satisfies Liskov's substitution principle because any Event can use the printEvent() function. 

*changes apply from initial->development diagrams for Phase III. classes may have extended from these adjustments
 
 ## Screenshots
The user is first prompted with when they want to start and end their day  
![image](https://github.com/cs100/final-project-alin157-mrela001-abequ001-sjeon065/assets/116844248/b6ed8d6c-1387-44bf-b1f8-3c44f1675ab0)  
The user is then prompted for their work habits so that ChatPlanner may create a personalized schedule to their habits!  
![image](https://github.com/cs100/final-project-alin157-mrela001-abequ001-sjeon065/assets/116844248/739498b1-1ac2-4b21-9a63-477dd1da1cd9)  
The user can then enter the tasks they want the program to plan for them 
![image](https://github.com/cs100/final-project-alin157-mrela001-abequ001-sjeon065/assets/116844248/cc08630c-3b9b-4fb2-af00-37074fad5cc2)  
![image](https://github.com/cs100/final-project-alin157-mrela001-abequ001-sjeon065/assets/116844248/153fa49d-da97-46aa-9856-e286af6aaaa3)  
After several more entries, the program displays a suggested schedule based on user preferences. "-----" denotes a time the user already said they were busy.  
![image](https://github.com/cs100/final-project-alin157-mrela001-abequ001-sjeon065/assets/116844248/ddd9d690-ad5b-4e84-a104-dd96438638d4)  
Using the menu, the user can add additional tasks or checkoff tasks  
![image](https://github.com/cs100/final-project-alin157-mrela001-abequ001-sjeon065/assets/116844248/81d536e0-8f1e-4d6b-aef8-25a0cbe42326)
![image](https://github.com/cs100/final-project-alin157-mrela001-abequ001-sjeon065/assets/116844248/a950f550-5bed-416f-89d6-5783de49a6b8)  
Finally, the user can save everything into a log file that gets updated every time the program runs.  
![image](https://github.com/cs100/final-project-alin157-mrela001-abequ001-sjeon065/assets/116844248/83c13802-1b0a-42d1-9ad7-37e5a50c97e2)
  ## Installation/Usage
  * You must have a C++ compiler to use this program
  * To install, clone the repo into a folder
  * The program will ask you for the time now and the time you want to stop planning events and end your day.
  * Then, enter your preferences for the day
  * The program will ask you if you want to do anything today, and your work habits
  * Enter the times you are already busy so the program will not schedule anything during those blocks
  * Enter tasks you would like the program to plan for you
  * After your schedule displays, you can check off, add additional tasks, or save and end the program
  * The program will save a log of what you have done into a txt file that will updated with each day: log.txt
    
 ## Testing
  We used googletest to test our functions before making a pull request. This is to avoid pulling broken code that you didn't mean to push. Our tests consist of making sure bad input is handled, assuring the exact user input enters the stream, and making sure schedules build a certain way after various user-incited function calls.
  ![image](https://github.com/cs100/final-project-alin157-mrela001-abequ001-sjeon065/assets/117532511/fac49d2a-0599-45fb-b15a-e073eaeeaaa4)

  Our program did not use dynamic allocation of memory and is Mem-Check Clean through valgrind: 
 ![memcheck-clean-valgrind-chatplanner](https://github.com/cs100/final-project-alin157-mrela001-abequ001-sjeon065/assets/117532511/9d77df43-41cf-452c-98c2-49fb14a3f3c1)

