#include "Tickets.h"
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

int Ticket::numTickets = 0;

// Ticket class implementation
Ticket::Ticket() : customerName(""), priority(0), requestDescription(""), ticketOpenTime(""), ticketCloseTime(""), status("Open") {}

Ticket::Ticket(string customerName, int priority, string requestDescription) {
    instanceTicketID = ++numTickets;
    this->customerName = customerName;
    this->priority = priority;
    this->requestDescription = requestDescription;
    this->ticketOpenTime = getCurrTime();
    this->ticketCloseTime = "Active Currently";
    this->status = "Open";
}

// copy constructor for deep copy
Ticket::Ticket(const Ticket &other) : customerName(other.customerName), priority(other.priority), 
    requestDescription(other.requestDescription), status(other.status), 
    ticketOpenTime(other.ticketOpenTime), ticketCloseTime(other.ticketCloseTime), 
    instanceTicketID(other.instanceTicketID) {}

// copy assignment operator
Ticket& Ticket::operator=(const Ticket &other) {
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

void Ticket::initiateTicketID() {
    instanceTicketID = ++numTickets;
}

void Ticket::setTicketID(int newID) {
    instanceTicketID = newID;
}

void Ticket::setCustomerName(const std::string& name) {
    customerName = name;
}

void Ticket::setPriority(int p) {
    priority = p;
}

void Ticket::setStatusOpen() {
    status = "Open";
}

void Ticket::setStatus(string newStatus) {
    status = newStatus;
}

void Ticket::setRequestDescription(const std::string& description) {
    requestDescription = description;
}

void Ticket::setTicketOpenTime() {
    ticketOpenTime = getCurrTime();
}

void Ticket::setTicketCloseTime(string time) {
    ticketCloseTime = time;
}

int Ticket::getInstanceTicketID() const {
    return instanceTicketID;
}

string Ticket::getCustomerName() const {
    return customerName;
}

int Ticket::getPriority() const {
    return priority;
}

string Ticket::getRequestDescription() const {
    return requestDescription;
}

string Ticket::getTicketOpenTime() const {
    return ticketOpenTime;
}

string Ticket::getTicketCloseTime() const {
    return ticketCloseTime;
}

string Ticket::getStatus() const {
    return status;
}

void Ticket::printTicketDetails() {
    cout << "Ticket ID: " << getInstanceTicketID() << endl;
    cout << "Customer Name: " << getCustomerName()<< endl;
    cout << "Priority: " << getPriority() << endl;
    cout << "Support Request Description: " << getRequestDescription() << endl;
    cout << "Ticket Open Time: " << getTicketOpenTime()<< endl;
    cout << "Ticket Close Time: " << getTicketCloseTime() << endl;
    cout << "Status: " << getStatus() << endl << endl;
}

// Node class implementation
Node::Node() : next(NULL) {}

Node::Node(Ticket &newTicket) {
    ticket = newTicket;
    next = NULL;
}

// TicketsList class implementation
TicketsList::TicketsList() : head(NULL), tail(NULL), numAllTickets(0) {}

void TicketsList::addTicket(Ticket& newTicket) {
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

void TicketsList::displayTickets() {
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