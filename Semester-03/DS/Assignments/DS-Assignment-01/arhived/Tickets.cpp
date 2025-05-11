#include <iostream>
#include <fstream>
#include <chrono>
#include <ctime>
#include <string>
#include <utility> // for std::pair
using namespace std;

string getCurrTime() {
    auto timenow = chrono::system_clock::now();
    // Convert to time_t to work with C-style time functions
    time_t currentTime = chrono::system_clock::to_time_t(timenow);
    string readableCurrTime = ctime(&currentTime);
    readableCurrTime.erase(readableCurrTime.length() - 1); // erase new line
    return readableCurrTime;
}
// --------------------------------------------------------------- Part 01: Tickets ---------------------------------------------------------------
class Ticket {
    private:    
        int instanceTicketID; // unique id for each customer
        string customerName;
        int priority;
        string requestDescription;
        string ticketOpenTime;
        string ticketCloseTime;
        string status;

    public:
        static int numTickets; // static id counter
        Ticket () : customerName(""), priority(0), requestDescription(""), ticketOpenTime(""), ticketCloseTime(""), status("Open") {}
        Ticket (string customerName, int priority, string requestDescription) {
            instanceTicketID = ++numTickets;
            this->customerName = customerName;
            this->priority = priority;
            this->requestDescription = requestDescription;
            this->ticketOpenTime = getCurrTime();
            this->ticketCloseTime = "Active Currently";
            this->status = "Open";
        }

        // copy constructor for deep copy
        Ticket(const Ticket &other) : customerName(other.customerName), priority(other.priority), requestDescription(other.requestDescription), status(other.status), 
            ticketOpenTime(other.ticketOpenTime), ticketCloseTime(other.ticketCloseTime), instanceTicketID(other.instanceTicketID) {}

        // copy assignment operator
        Ticket& operator=(const Ticket &other) {
            // Self-assignment check
            if (this == &other) {
                return *this;
            }
            customerName = other.customerName;
            priority = other.priority;
            requestDescription = other.requestDescription;
            status = other.status;
            ticketOpenTime = other.ticketOpenTime;
            ticketCloseTime = other.ticketCloseTime;
            instanceTicketID = other.instanceTicketID;

            return *this;
        }

        void initiateTicketID() {
            instanceTicketID = ++numTickets;
        }
        void setTicketID(int newID) {
            instanceTicketID = newID;
        }

        void setCustomerName(const std::string& name) {
            customerName = name;
        }

        void setPriority(int p) {
            priority = p;
        }
        
        void setStatusOpen() {
            status = "Open";
        }
        void setStatus(string newStatus) {
            status = newStatus;
        }

        void setRequestDescription(const std::string& description) {
            requestDescription = description;
        }

        void setTicketOpenTime() {
            ticketOpenTime = getCurrTime();
        }

        void setTicketCloseTime(string time) {
            ticketCloseTime = time;
        }

        int getInstanceTicketID() const {
            return instanceTicketID;
        }

        string getCustomerName() const {
            return customerName;
        }

        int getPriority() const {
            return priority;
        }

        string getRequestDescription() const {
            return requestDescription;
        }

        string getTicketOpenTime() const {
            return ticketOpenTime;
        }

        string getTicketCloseTime() const {
            return ticketCloseTime;
        }

        string getStatus() const {
            return status;
        }

        void printTicketDetails() {
            cout << "Ticket ID: " << getInstanceTicketID() << endl;
            cout << "Customer Name: " << getCustomerName()<< endl;
            cout << "Priority: " << getPriority() << endl;
            cout << "Support Request Description: " << getRequestDescription() << endl;
            cout << "Ticket Open Time: " << getTicketOpenTime()<< endl;
            cout << "Ticket Close Time: " << getTicketCloseTime() << endl;
            cout << "Status: " << getStatus() << endl << endl;
        }
};
int Ticket::numTickets = 0;

// This class stores all the tickets that were ever created. No matter if they are currently open, closed, resolved, etc.
class Node {
    public:
        Ticket ticket;
        Node *next;
    
        Node () : next(NULL) {}
        Node (Ticket &newTicket) {
            ticket = newTicket;
            next = NULL;
        }
};

class TicketsList {
    public:
        Node *head;
        Node *tail;
        int numAllTickets;

        TicketsList () : head(NULL), tail(NULL), numAllTickets(0) {}

        void addTicket (Ticket& newTicket) {
            Node *newnode = new Node(newTicket);
            numAllTickets++;

            if (head == NULL) {
                head = newnode;
                tail = head;
                tail->next = head;
            } else {
                Node *temp = head;
                while (temp->next != head) {
                    temp = temp->next;
                }
                temp->next = newnode;
                tail = temp->next;
                tail->next = head;
            }
        }

        void displayTickets() {
            if (head == NULL) {
                cout<<"List is empty." << endl;
                return;   
            }

            cout << "_____________ Displaying All " << numAllTickets << " Tickets Created Today (Open/Closed) _____________ " << endl;
            Node *temp = head;
            do {
                temp->ticket.printTicketDetails();
                temp = temp->next;
            } while (temp != head);
        }
};