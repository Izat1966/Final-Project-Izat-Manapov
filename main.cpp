/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream> //library iostream to use basic data structures
#include <string> //library string to use classes string
#include <vector> //library vector to use class vectors
#include <fstream> //library fstream to use ofstream and ifstream

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
        cout << "Extra Details: " << event.extra << endl;
    }
}

void addEvent(Event& event) { //function to user could cin events details by him/herself
    cout << "Enter event name: ";
    getline(cin, event.name);
    cout << "Enter event date (Date/Month/Year): ";
    getline(cin, event.date);
    cout << "Enter event time: ";
    getline(cin, event.time);
    cout << "Enter event location: ";
    getline(cin, event.location);

    char anss;
    cout << "Do you have some extra details? Y/N: ";
    cin >> anss;
    cin.ignore();
    if (anss == 'Y' || anss == 'y') {
        cout << "Enter event extra: ";
        getline(cin, event.extra);
        event.IsExtraExists = true;
    } else {
        event.IsExtraExists = false;
        event.extra = "";
    }
}

void saveEventsToFile(const vector<Event>& events, const string& filename) { //function to allow user to save their data if they want
    ofstream file(filename);
    if (!file.is_open()) {
        cerr << "Unable to open file for writing.\n";
        return;
    }

    for (const auto& event : events) {
        file << event.name << '\n'
             << event.date << '\n'
             << event.time << '\n'
             << event.location << '\n'
             << event.IsExtraExists << '\n';
        if (event.IsExtraExists) {
            file << event.extra << '\n';
        }
        file << "\n"; //to separate events
    }

    file.close();
    cout << "Events saved to file successfully.\n";
}

void loadEventsFromFile(vector<Event>& events, const string& filename) { //function to allow user read data from file
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Unable to open file for reading.\n";
        return;
    }
    Event doaer;
    string line;
    while (getline(file, doaer.name)) {
        getline(file, doaer.date);
        getline(file, doaer.time);
        getline(file, doaer.location);
        file >> doaer.IsExtraExists;
        file.ignore();
        if (doaer.IsExtraExists) {
            getline(file, doaer.extra);
        } else {
            doaer.extra = " ";
        }
        getline(file, line); // read space between line (" ")
        events.push_back(doaer);
    }

    file.close();
    cout << "Events loaded from file successfully.\n";
}

void displayAllEvents(const vector<Event>& events) { //function to display all events 
    for (int i = 0; i < events.size(); i++) {
        cout << "\nEvent " << i + 1 << " Details:\n";
        displayEvent(events[i]);
    }
}

void updateEvent(vector<Event>& events) { //function to allow user change event, if something were written incorrectly
    int index;
    cout << "Enter the event number to update: ";
    cin >> index;
    cin.ignore();
    if (index > 0 && index <= events.size()) {
        cout << "Updating event " << index << ":\n";
        addEvent(events[index - 1]);
    } else {
        cout << "Invalid event number.\n";
    }
}

void deleteEvent(vector<Event>& events) { //function to allow user delete event
    int index;
    cout << "Enter the event number to delete: ";
    cin >> index;
    cin.ignore();
    if (index > 0 && index <= events.size()) {
        events.erase(events.begin() + index - 1);
        cout << "Event " << index << " deleted.\n";
    } else {
        cout << "Invalid event number.\n";
    }
}

int main() {
    vector<Event> events;
    string filename = "events.txt";
    char choice; //char choise to give user choise 
    
    loadEventsFromFile(events, filename);

    do {
        cout << "\nMenu:\n";
        cout << "1. Add Event\n";
        cout << "2. View All Events\n";
        cout << "3. Update Event\n";
        cout << "4. Delete Event\n";
        cout << "5. Save and Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) { //class switch to give a choise user
            case '1': {
                Event newEvent;
                addEvent(newEvent);
                events.push_back(newEvent);
                break;
            }
            case '2':
                displayAllEvents(events);
                break;
            case '3':
                updateEvent(events);
                break;
            case '4':
                deleteEvent(events);
                break;
            case '5':
                saveEventsToFile(events, filename);
                cout << "Events saved to file. Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != '5'); //will continue untill choise is not 5

    return 0;
}
