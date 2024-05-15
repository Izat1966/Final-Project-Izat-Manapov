/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream> //library iostream to use basic data structures
#include <string> //library string to use classes string
using namespace std; //to read basic data structures

struct Event { //Created class structure called event 
    string name; //Created string name to allow user call Event name
    string date; //Created string date to allow user choose date of Event
    string time; //Created string time to allow user choose time of Event
    string location; //Created string location to allow user choose location of Event
    string extra; //Update and add one more data of class structure defined as string extra to allow user add some extra detail
    bool IsExtraExists; //Created bool extra as last option extra is optional and users decide by themselves whether they to add some additional info , therefore to check if user decide to add extra info or not 
};

void displayEvent(const Event& event) { //Created this function to display event details after user fill it
    cout << "Event Name: " << event.name << endl; //Display event's name
    cout << "Date: " << event.date << endl; //Display event's date
    cout << "Time: " << event.time << endl; //Display event's time
    cout << "Location: " << event.location << endl; //Display event's location
    if (event.IsExtraExists) { //Checks if extra info about event added or not
      cout << "Extra Details: " << event.extra <<endl; //if it is added , will display it
    }
}

void addEvent(Event& event) { //function to user could cin events details by him/herself
    cout << "Enter event name: "; //print 
    getline(cin, event.name); //cin event's name
    cout << "Enter event date (Date/Month/Year): "; //print
    getline(cin, event.date); //cin event's date
    cout << "Enter event time: "; //print
    getline(cin, event.time); //cin event's time
    cout << "Enter event location: "; //print
    getline(cin, event.location); //cin event's location

    char anss; // char anss to allow user optionally add extra details
    cout << "Do you have some extra details ? Y/N: "; //print
    cin >> anss; //cin anss
    cin.ignore(); //to wipe out input that was after first line otherwise it will jump to continue option
    if (anss == 'Y' || anss == 'y') { //chechks user's choise
      cout << "Enter event extra: "; //print if user choose to add extra
      getline(cin, event.extra); // cout extra if user choose to add extra
      event.IsExtraExists = true; //if user choose to add extra boolean will be equal to true
    }else {
      event.IsExtraExists = false; //otherwise false
    }
}

int main() {
    char ans ='Y'; //char ans to allow user give choise of continuing , intially define once to run while loop , otherwise as there no Y it will not output anything
    
    while (ans == 'Y' || ans == 'y') {  //loop while will run untill user choose to continue
        Event EventsOfUsers; //add event called EventsOfUsers
        addEvent(EventsOfUsers); //allow users to fill event details by themselve
        cout << "\nEvent Details:\n"; //print text Event details above event details
        displayEvent(EventsOfUsers); // dispplay event details 
        cout << "\nDo you want to add one more time ? Y/N: "; // choise
        cin >> ans; //cin of choise
        cin.ignore(); //to take away input after while loop , otherwise it may repeat some input right after choise
        
    }
    return 0;
}
