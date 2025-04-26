#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

struct Event {
    char eventName[100];
    char date[20];
    char venue[100];
    char organizer[100];
};

Event* events = nullptr;
int totalEvents = 0;

void DisplayEvents() {
    cout << "All Events:\n";
    for (int i = 0; i < totalEvents; ++i) {
        cout << "Event " << i + 1 << ":\n";
        cout << "Name: " << events[i].eventName << endl;
        cout << "Date: " << events[i].date << endl;
        cout << "Venue: " << events[i].venue << endl;
        cout << "Organizer: " << events[i].organizer << endl << endl;
    }
}

void AddEvent() {
    int numAddEvents;

    Event* temp = (Event*)realloc(events, totalEvents * sizeof(Event));
    if (temp == nullptr) {
        cout << "Memory reallocation failed!\n";
        return;
    }
    events = temp;

    cout<<"Enter the number of events you want to add: "; cin>>numAddEvents;
    for (int i=0; i<numAddEvents; i++) {
        totalEvents++;
        cout << "Enter details for Event " << totalEvents << ":\n";
        cout << "Event Name: ";
        cin.ignore();
        cin.getline(events[totalEvents - 1].eventName, 100);
        cout << "Date: ";
        cin.getline(events[totalEvents - 1].date, 20);
        cout << "Venue: ";
        cin.getline(events[totalEvents - 1].venue, 100);
        cout << "Organizer: ";
        cin.getline(events[totalEvents - 1].organizer, 100);
    }
}

void SearchEvent() {
    char searchDate[20];
    cout << "Enter the date to search for events: ";
    cin >> searchDate;

    cout << "Events on " << searchDate << ":\n";
    bool found = false;
    for (int i = 0; i < totalEvents; ++i) {
        if (strcmp(events[i].date, searchDate) == 0) {
            cout << "Event " << i + 1 << ":\n";
            cout << "Name: " << events[i].eventName << endl;
            cout << "Date: " << events[i].date << endl;
            cout << "Venue: " << events[i].venue << endl;
            cout << "Organizer: " << events[i].organizer << endl << endl;
            found = true;
        }
    }
    if (!found) {
        cout << "No events found on " << searchDate << endl;
    }
}

int main () {
    int choice;

    cout << "Hello, welcome to my program.\n";

    do {
        cout << "\nChoose from the following operations:\n";
        cout << "1. Display events\n2. Add event\n3. Search event\n4. Exit program\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                if (totalEvents == 0) {
                    cout << "No events added yet.\n";
                } else {
                    DisplayEvents();
                }
                break;
            case 2:
                AddEvent();
                break;
            case 3:
                if (totalEvents == 0) {
                    cout << "No events added yet.\n";
                } else {
                    SearchEvent();
                }
                break;
            case 4:
                cout << "The program has exited. Thank you for using the program!\n";
                free(events);
                exit(0);
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 4);

    return 0;
}
