/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream> //library iostream to use basic data structures
#include <string> //library string to use classes string
using namespace std; 

struct Event { //Created class structure called event 
    string name; 
    string date; 
    string time; 
    string location; 
    string extra; 
    bool IsExtraExists; 
};

void displayEvent(const Event& event) { //Created this function to display event details after user fill it
    cout << "Event Name: " << event.name << endl; 
    cout << "Date: " << event.date << endl; 
    cout << "Time: " << event.time << endl;
    cout << "Location: " << event.location << endl; 
    if (event.IsExtraExists) {
      cout << "Extra Details: " << event.extra <<endl; 
    }
}

void addEvent(Event& event) { //function to user could cin events details by him/herself
    cout << "Enter event name: "; 
    getline(cin, event.name); //cin 
    cout << "Enter event date (Date/Month/Year): "; 
    getline(cin, event.date); 
    cout << "Enter event time: "; 
    getline(cin, event.time); 
    cout << "Enter event location: "; 
    getline(cin, event.location); 

    char anss; // char anss to allow user optionally add extra details
    cout << "Do you have some extra details ? Y/N: "; //print
    cin >> anss; 
    cin.ignore(); 
    if (anss == 'Y' || anss == 'y') { 
      cout << "Enter event extra: "; 
      getline(cin, event.extra); 
      event.IsExtraExists = true; 
    }else {
      event.IsExtraExists = false; //otherwise false
    }
}

int main() {
    char ans ='Y'; //char ans to allow user give choise of continuing , intially define once to run while loop , otherwise as there no Y it will not output anything
    
    while (ans == 'Y' || ans == 'y') {  //loop while will run untill user choose to continue
        Event EventsOfUsers;
        addEvent(EventsOfUsers);
        cout << "\nEvent Details:\n"; 
        displayEvent(EventsOfUsers); 
        cout << "\nDo you want to add one more time ? Y/N: "; // choise
        cin >> ans; //cin of choise
        cin.ignore(); 
        
    }
    return 0;
}
