#include <iostream>
#include <chrono>
#include <ctime>
using namespace std;

// Helper function to get the current system time
string getCurrTime() {
    auto timenow = chrono::system_clock::now();
    time_t currentTime = chrono::system_clock::to_time_t(timenow);
    string readableCurrTime = ctime(&currentTime);
    readableCurrTime.erase(readableCurrTime.length() - 1); // Remove trailing newline
    return readableCurrTime;
}

class Ticket {
public:
    static int ticketID; // Static id counter
    int instanceTicketID; // Unique id for each ticket
    string customerName;
    int priority;
    string requestDescription;
    string ticketOpenTime;
    string ticketCloseTime;
    string status;

    // Default constructor
    Ticket() : instanceTicketID(++ticketID), customerName(""), priority(0), requestDescription(""),
               ticketOpenTime(""), ticketCloseTime(""), status("Closed") {}

    // Parameterized constructor
    Ticket(string customerName, int priority, string requestDescription) {
        instanceTicketID = ++ticketID;
        this->customerName = customerName;
        this->priority = priority;
        this->requestDescription = requestDescription;
        this->ticketOpenTime = getCurrTime();
        this->ticketCloseTime = "Active Currently";
        this->status = "Open";
    }

    // Destructor
    ~Ticket() {
        ticketCloseTime = getCurrTime();
    }
};
int Ticket::ticketID = 0;

class Node {
public:
    Ticket data;
    Node *next;

    Node() : next(NULL) {}
    Node(Ticket &newTicket) {
        data = newTicket;
        next = NULL;
    }
};

class LL {
public:
    Node *head;
    Node *tail;

    LL() : head(NULL), tail(NULL) {}
    LL(Ticket &newTicket) {
        head = new Node(newTicket);
        tail = head;
        tail->next = head;
    }

    void addTicket(Ticket &newTicket) {
        Node *newnode = new Node(newTicket);
        if (head == NULL) {
            head = newnode;
            tail = head;
            tail->next = head;
        } else {
            tail->next = newnode;
            tail = newnode;
            tail->next = head;
        }
    }

    // Shell Sort Function
    void shellSort(Ticket tickets[], int n, char ch) {
        for (int gap = n / 2; gap > 0; gap /= 2) {
            for (int i = gap; i < n; i++) {
                Ticket temp = tickets[i];
                int j;

                // Sorting by the selected criteria
                for (j = i; j >= gap; j -= gap) {
                    bool condition;
                    if (ch == 'p') { // Sort by priority (higher priority comes first)
                        condition = temp.priority > tickets[j - gap].priority;
                    } else if (ch == 'n') { // Sort by customer name
                        condition = temp.customerName < tickets[j - gap].customerName;
                    } else { // Default to sorting by ticket open time (earliest comes first)
                        condition = temp.ticketOpenTime < tickets[j - gap].ticketOpenTime;
                    }

                    if (condition) {
                        tickets[j] = tickets[j - gap];
                    } else {
                        break;
                    }
                }
                tickets[j] = temp;
            }
        }
        updateTicketList(tickets, n);
    }

    // Update the Linked List with sorted tickets array
    void updateTicketList(Ticket tickets[], int n) {
        Node *temp = head;
        for (int i = 0; i < n; i++) {
            temp->data = tickets[i];
            temp = temp->next;
        }
    }

    void print() {
        if (head == NULL) {
            cout << "List is empty." << endl;
            return;
        }

        Node *temp = head;
        do {
            cout << "Ticket ID: " << temp->data.instanceTicketID << endl;
            cout << "Customer Name: " << temp->data.customerName << endl;
            cout << "Priority: " << temp->data.priority << endl;
            cout << "Support Request Description: " << temp->data.requestDescription << endl;
            cout << "Ticket Open Time: " << temp->data.ticketOpenTime << endl;
            cout << "Ticket Close Time: " << temp->data.ticketCloseTime << endl;
            cout << "Status: " << temp->data.status << endl;
            temp = temp->next;
            cout << endl;
        } while (temp != head);
    }
};

int main() {
    // Create multiple Ticket objects
    Ticket t1("Hammond", 5, "Issue A");
    Ticket t2("Duke", 3, "Issue B");
    Ticket t3("MJ", 4, "Issue C");
    Ticket t4("Amy", 1, "Issue D");
    Ticket t5("Oliver", 2, "Issue E");

    // Array of tickets to sort
    Ticket tickets[] = {t1, t2, t3, t4, t5};
    int n = sizeof(tickets) / sizeof(tickets[0]);

    // Create Ticket list and add tickets
    LL l1;
    l1.addTicket(t1);
    l1.addTicket(t2);
    l1.addTicket(t3);
    l1.addTicket(t4);
    l1.addTicket(t5);

    // Print tickets before sorting
    cout << "Before Sorting:\n";
    l1.print();

    // Sorting criteria: 'p' for priority, 'n' for name, 't' for time
    char sortOption;
    cout << "\nEnter sorting criteria (p for Priority, n for Name, t for Ticket Open Time): ";
    cin >> sortOption;

    // Sort the tickets based on the chosen attribute
    l1.shellSort(tickets, n, sortOption);

    // Update the Ticket list with the sorted ticket data
    // l1.updateTicketList(tickets, n);

    // Print the sorted tickets
    cout << "\nAfter Sorting:\n";
    l1.print();

    return 0;
}
