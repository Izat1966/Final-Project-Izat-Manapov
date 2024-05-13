/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <string>
using namespace std;

struct Event {
    string name;
    string date;
    string time;
    string location;
};

void displayEvent(const Event& event) {
    cout << "Event Name: " << event.name << endl;
    cout << "Date: " << event.date << endl;
    cout << "Time: " << event.time << endl;
    cout << "Location: " << event.location << endl;
}

void addEvent(Event& event) {
    cout << "Enter event name: ";
    getline(cin, event.name);
    cout << "Enter event date (Date/Month/Year): ";
    getline(cin, event.date);
    cout << "Enter event time: ";
    getline(cin, event.time);
    cout << "Enter event location: ";
    getline(cin, event.location);
}

int main() {
    char ans ='Y';
    
    while (ans == 'Y' || ans == 'y') {  
        Event EventsOfUsers;
        addEvent(EventsOfUsers);
        cout << "\nEvent Details:\n";
        displayEvent(EventsOfUsers);
        cout << "Do you want to add one more time ? Y/N: ";
        cin >> ans;
        cin.ignore();
        
    }
    return 0;
}
