#ifndef TICKET_RESOLUTION_LOGS_H
#define TICKET_RESOLUTION_LOGS_H

#include <iostream>
#include <string>
#include <fstream>
#include "Tickets.h"

class NodeStack {
public:
    Ticket ticket;
    NodeStack *next;

    NodeStack(Ticket &newTicket);
};

class TicketStack {
public:
    NodeStack *top;
    int numProcessedTickets;

    TicketStack();
    void pushTicket(Ticket &incTicket);
    void peekTicketStack();
    void printTicketStack();
};

class NodeQueue {
public:
    Ticket ticket;
    NodeQueue *next;

    NodeQueue(Ticket &newTicket);
};

class TicketQueue {
public:
    NodeQueue *head;
    NodeQueue *tail;
    int numPendingTickets;
    static int count;

    TicketQueue();
    void createTicket(TicketsList& TL);
    void enqueueTicket(Ticket &incTicket);
    void dequeueTicket();
    Ticket peekTicket();
    void printTicketQueue();
    void removeTicket(int targetID);
    void silentRemoveTicket(int targetID);
    Ticket findTicket(int targetID);
    
    void sortTicketQueue();
    void silentSortTicketQueue(char ch);
    void bubbleSortTicketQueue(char ch);
    void insertionSortTicketQueue(char ch);
    void selectionSortTicketQueue(char ch);
    
    void searchTicket();
    Ticket binarySearchTicketByID(int targetID);
    Ticket binarySearchTicketByName(std::string targetName);
    Ticket interpolationSearchTicketByID(int targetID);
    int countNodesBetween(NodeQueue* start, NodeQueue* end);
    NodeQueue* moveForward(NodeQueue* start, int pos);
    Ticket linearSearchTicketByName(std::string targetName);
};

#endif // TICKET_RESOLUTION_LOGS_H