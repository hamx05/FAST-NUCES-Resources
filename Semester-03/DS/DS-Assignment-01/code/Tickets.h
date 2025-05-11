#ifndef TICKETS_H
#define TICKETS_H

#include <iostream>
#include <string>
#include <chrono>
#include <ctime>
#include <limits>

std::string getCurrTime();
int get_int();

class Ticket {
private:    
    int instanceTicketID; // unique id for each customer
    std::string customerName;
    int priority;
    std::string requestDescription;
    std::string ticketOpenTime;
    std::string ticketCloseTime;
    std::string status;

public:
    static int numTickets; // static id counter
    Ticket();
    Ticket(std::string customerName, int priority, std::string requestDescription);
    
    // copy constructor for deep copy
    Ticket(const Ticket &other);

    // copy assignment operator
    Ticket& operator=(const Ticket &other);

    void initiateTicketID();
    void setTicketID(int newID);
    void setCustomerName(const std::string& name);
    void setPriority(int p);
    void setStatusOpen();
    void setStatus(std::string newStatus);
    void setRequestDescription(const std::string& description);
    void setTicketOpenTime();
    void setTicketCloseTime(std::string time);

    int getInstanceTicketID() const;
    std::string getCustomerName() const;
    int getPriority() const;
    std::string getRequestDescription() const;
    std::string getTicketOpenTime() const;
    std::string getTicketCloseTime() const;
    std::string getStatus() const;

    void printTicketDetails();
};

// This class stores all the tickets that were ever created. No matter if they are currently open, closed, resolved, etc.
class Node {
public:
    Ticket ticket;
    Node *next;

    Node();
    Node(Ticket &newTicket);
};

class TicketsList {
public:
    Node *head;
    Node *tail;
    int numAllTickets;

    TicketsList();
    void addTicket(Ticket& newTicket);
    void displayTickets();
};

#endif // TICKETS_H