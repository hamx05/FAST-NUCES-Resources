#include <iostream>
#include <fstream>
#include <chrono>
#include <ctime>
#include <string>
#include <utility> // for std::pair
#include "Agents.cpp"
using namespace std;

int get_int() {
    int n;
    for (;;) {
        if (cin >> n) {
            return n;
        }
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid entry. Please re-enter: ";
    }
}

string getCurrTime() {
    auto timenow = chrono::system_clock::now();
    // Convert to time_t to work with C-style time functions
    time_t currentTime = chrono::system_clock::to_time_t(timenow);
    string readableCurrTime = ctime(&currentTime);
    readableCurrTime.erase(readableCurrTime.length() - 1); // erase new line
    return readableCurrTime;
}

// -------------------------------------------------- Part 03 & 04: Ticket Resolution Log & Ticket Queue --------------------------------------------------
class NodeStack {
    public:
        Ticket ticket;
        NodeStack *next;

        NodeStack (Ticket &newTicket) : next(NULL), ticket(newTicket) {}
};

class TicketStack {
    public:
        NodeStack *top;
        int numProcessedTickets;

        TicketStack () : top(NULL), numProcessedTickets(0) {}

        void pushTicket (Ticket &incTicket) {
            numProcessedTickets++;
            if (top == NULL) {
                top = new NodeStack(incTicket);
                return;
            }

            NodeStack *newnode = new NodeStack(incTicket);
            newnode->next = top;
            
            top = newnode;
        }

        void peekTicketStack () {
            if (top == NULL) {
                cout<<"No processed ticket as of now. Nothing to print." << endl;
                return;
            }

            cout << "_____________ Displaying Most Recent Ticket Log _____________ " << endl;
            top->ticket.printTicketDetails();
        }

        void printTicketStack () {
            if (top == NULL) {
                cout << "Cannot print ticket stack. No record in the processed tickets at the momment." << endl;
                return;
            }

            cout << "_____________ Displaying " << numProcessedTickets << " Resolved Tickets _____________ " << endl;
            NodeStack *temp = top;
            while (temp != NULL) {
                temp->ticket.printTicketDetails();
                temp = temp->next;
            }
        }
};
