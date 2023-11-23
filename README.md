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

  >Users may enter preferences, tasks, and times not available. Chatplanner will generate a potential schedule for the user with each run.

#### Project Features:
 * generate non rigid schedule for a user based on user input
 * ability to add tasks
 * automatically categorize tasks
 * ability to block out time that is currently busy
 * ability to ask for schedule preferences (ex. night owl, early sleeper, procrastinator)
 * check off tasks as day goes on
 * save schedule to a log.txt file
 * look at past events
 * delete and edit task features TBA

## User Interface Specification

### Navigation Diagram
ChatPlanner will begin by prompting users for personal scheduling preferences on one (text) screen within the terminal. The next screen will ask for an event and any associated details such as priority, description, etc. User may terminate task input and generate a schedule, go back to adding tasks (then regenerate), finish a task, or save the schedule to a personal file to terminate the program. 

### Screen Layouts
 ![nav (1)](https://github.com/cs100/final-project-alin157-mrela001-abequ001-sjeon065/assets/117532511/e5a737cc-c166-458a-b494-42da698e9e5b)


## Class Diagram
Users will be prompted for schedule preferences and their choices will be stored within a vector of bools within the schedule class, returned by AskPreferences() from the RawInput class. Users will then create tasks from prompts described in the navigation diagram. Tasks will be objects of the event class, and pushed into the unsorted tasks vector of the "Schedule" class, again through the "RawInput" class's AskTasks(). The Schedule class will use the unsorted tasks vector to generate a sorted schedule of events specific to the users preferences, stored in the 'hours' vector of Events. The displaySchedule function is used for printing and design purposes for the user, as represented by the display/menu section of the navigation diagram. The schedule class may also use the writeToFile function to save a user's' most recently generated schedule to a .txt file and "end" the day. ![chat planner-uml 11 22 drawio](https://github.com/cs100/final-project-alin157-mrela001-abequ001-sjeon065/assets/116844248/e84e0013-1eb8-43db-b09f-997af6c0bada)

### Previous class diagram
![image](https://github.com/cs100/final-project-alin157-mrela001-abequ001-sjeon065/assets/116844248/ee0bc048-3b92-4c51-8b4e-385b5bb575c1)



 
  ## Phase III
  * We made the following changes to our class diagram:
  * Display_Schedule and Save_Schedule are now inside the Schedule class
     * We applied SRP in a reverse way to fix our Schedule class. Display and Save are functions that the Schedule class should be responsible for, and not their own classes. Now Schedule is responsible for all functions requiring a Schedule. This reduces the amount of classes we have and makes the UML and code easier to read. It also reduces the amount of times a vector has to be passed into functions during the program.
  * Schedule now contains 3 vectors, a list of tasks, a list of hours and a list of preferences
     * We applied OCP to the schedule class. Before, we had these vectors inside a RawInput class (class to ask for user input). This meant that whenever we wanted to add another vector of variable for a preference(ie a boolean for whether or not you are a procrastinator) we had to change a member variable outside of Schedule. This is also an example of SRP because now RawInput only takes input, and Schedule is self contained with all the data it needs to run. This makes our code easier to debug and read because, for example, we don't have to pass in a taskList from an outside class when it should be accessible from Schedule itself.
  * Event is now an abstract base class with specific event classes derived from it
     * We applied ISP to the Event class. Before, every type of event(work, free, busy) had to have a priority and description field when that didn't make sense for events as a null event for time already busy. To solve this, instead of having a category member variable we made subtypes to keep track of the different types of events instead. This makes the code more organized as different kinds of events are defined by their object type, and not by a string member variable entered by the user. This also satisfies the Liskov substution principle. Any type of Event can be valid when an Event is needed. For example, any kind of Event can be added to the hours vector. By seperating Event types, it allows us to create seperate printEvent() functions for each subtype. It doesn't make sense to have the same printEvent for each type of Event(Work Event has a priority variable, while leisure does not). This also satisfies Liskov's substitution principle because any Event can use the printEvent() function. 
  * Perform a new sprint plan like you did in Phase II.
  * You should also make sure that your README file (and Project board) are up-to-date reflecting the current status of your project and the most recent class diagram. Previous versions of the README file should still be visible through your commit history.
 
 During the meeting with your reader you will discuss: 
  * How effective your last sprint was (each member should talk about what they did)
  * Any tasks that did not get completed last sprint, and how you took them into consideration for this sprint
  * Any bugs you've identified and created issues for during the sprint. Do you plan on fixing them in the next sprint or are they lower priority?
  * What tasks you are planning for this next sprint.

 
  ## Final deliverable
  All group members will give a demo to the reader during lab time. ou should schedule your demo on Calendly with the same reader who took your second scrum meeting. The reader will check the demo and the project GitHub repository and ask a few questions to all the team members. 
  Before the demo, you should do the following:
  * Complete the sections below (i.e. Screenshots, Installation/Usage, Testing)
  * Plan one more sprint (that you will not necessarily complete before the end of the quarter). Your In-progress and In-testing columns should be empty (you are not doing more work currently) but your TODO column should have a full sprint plan in it as you have done before. This should include any known bugs (there should be some) or new features you would like to add. These should appear as issues/cards on your Project board.
  * Make sure your README file and Project board are up-to-date reflecting the current status of your project (e.g. any changes that you have made during the project such as changes to your class diagram). Previous versions should still be visible through your commit history. 
 
 ## Screenshots
  Screenshots of the input/output after running your application
 ## Installation/Usage
  Instructions on installing and running your application
 ## Testing
  How was your project tested/validated? If you used CI, you should have a "build passing" badge in this README.
 
