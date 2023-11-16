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

  Balancing homework, clubs, meetings, classes, and more can be done efficiently with an optimized and interactive dayplanner

#### Languages and Input/Output
  Chatplanner will be developed using C++.

  Chatplanner is a textbot and will be executed through the terminal only.

  >Users may enter preferences, tasks, and times not available. Chatplanner will generate a potential schedule for the user with each run.

#### Project Features:
 * generate non rigid schedule for a user based on user input
 * ability to add, edit and delete tasks
 * automatically categorize tasks
 * ability to block out time that is currently busy
 * ability to ask for schedule preferences (ex. night owl, early sleeper, procrastinator)
 * check off tasks as day goes on
 * save schedule to a log.txt file
 * look at past events

## User Interface Specification

### Navigation Diagram
ChatPlanner will begin by prompting users for perssonal scheduling preferences on one (text) screen within the terminal. The next screen will ask for an event and any associated details such as priority, description, etc. User may terminate task input and generate a schedule, go back to adding tasks (then regenerate), finish a task, or save the schedule to a personal file to terminate the program. ![chat planner drawio](https://github.com/cs100/final-project-alin157-mrela001-abequ001-sjeon065/assets/116844248/fe5239cf-658d-4cfd-a7dc-830255050fd4)



### Screen Layouts
 ![screen layout](https://github.com/cs100/final-project-alin157-mrela001-abequ001-sjeon065/assets/117532511/1235e14d-0b64-45bd-b6b6-eb39394dafec)

## Class Diagram
Users will be prompted for schedule preferences and their choices will be stored within a vector of bools within the RawInput class. Users will then create tasks from prompts described in the navigation diagram. Tasks will be objects of the event class, and stored in the "RawInput" class in an unsorted schedule of events. The Schedule class will use the unsorted RawInput::tasks vector to generate a sorted schedule of events specific to the users preferences, also stored in RawInput. The Display_schedule class is used for printing and design purposes for the user, as represented by the display/menu section of the navigation diagram. The schedule class may also use the Save-Schedule class to save a user's' most recently generated schedule to a .txt file and "end" the day. 
 ![chat planner uml drawio](https://github.com/cs100/final-project-alin157-mrela001-abequ001-sjeon065/assets/116844248/b34678e0-509a-420e-98fe-15a025f27af5)
 
  ## Phase III
  You will need to schedule a check-in for the second scrum meeting with the same reader you had your first scrum meeting with (using Calendly). Your entire team must be present. This meeting will occur on Zoom and should be conducted by Wednesday of week 8.
 
  BEFORE the meeting you should do the following:
  * Update your class diagram from Phase II to include any feedback you received from your TA/grader.
  * Considering the SOLID design principles, reflect back on your class diagram and think about how you can use the SOLID principles to improve your design. You should then update the README.md file by adding the following:
    * A new class diagram incorporating your changes after considering the SOLID principles.
    * For each update in your class diagram, you must explain in 3-4 sentences:
      * What SOLID principle(s) did you apply?
      * How did you apply it? i.e. describe the change.
      * How did this change help you write better code?
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
 
