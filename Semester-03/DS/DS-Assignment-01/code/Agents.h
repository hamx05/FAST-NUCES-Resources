#ifndef AGENTS_H
#define AGENTS_H

#include <iostream>
#include <string>
#include <fstream>
#include "Tickets.h"
#include "TicketResolutionLogs.h"

class Agent {
private:
    int agentID;
    std::string agentName;
    bool availability;
    std::string status;
    int maxCapacity;
    int numAssignedTickets;
    int numResolvedTickets;

public:
    Ticket* assignedTickets; // tickets that have been assigned to an agent
    Ticket* resolvedTickets; // tickets that have been resolved by an agent
    static int numAgents;
    
    Agent();
    Agent(std::string newAgentName);
    
    void setAgentName(std::string name);
    int getAgentID() const;
    std::string getAgentName() const;
    bool isAvailable() const;
    std::string getStatus() const;
    int getAssignedTicketCount() const;
    void markUnavailable();
    void decNumAssignedTickets();
    void setAvailability(bool newAvailability);
    void setStatus(const std::string& newStatus);
    int getMaxCapacity() const;
    void incNumResolvedTickets();
    int getNumResolvedTickets();

    void assignTicket(Ticket ticket, class TicketQueue &ticketQueue);
    void displayAgentsTickets();
    Ticket getAssignedTicket(int index);
    bool hasTicket(Ticket &ticket);
    void displayDetails();
};

class AgentsList {
private:
    int size;
    static int totalSize;
    Agent* agents;

public:
    AgentsList();
    ~AgentsList();

    void createAgent();
    void addAgent(Agent &newAgent);
    void assignTicketToAgent(class TicketQueue &ticketQueue);
    void resolveTicket(class TicketQueue &ticketQueue, class TicketStack &ticketStack);
    void logResolvedTicket(Ticket &ticket, class TicketStack &ticketStack);
    
    void sortAgents();
    void bubbleSortAgents();
    void insertionSortAgents();
    void selectionSortAgents();
    int partitionAgents(Agent agents[], int low, int high);
    void quickSortAgents(Agent agents[], int low, int high);
    void mergeAgents(Agent agents[], int left, int mid, int right);
    void mergeSortAgents(Agent agents[], int left, int right);
    
    void displayAgents();
    void displaySpecificAgentTicket(int ID);
    void displayAllAssignedTickets();
};

#endif // AGENTS_H