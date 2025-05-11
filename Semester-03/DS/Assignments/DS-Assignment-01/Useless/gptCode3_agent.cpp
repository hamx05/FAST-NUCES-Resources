#include <iostream>
#include <chrono>
#include <ctime>
#include <vector>
using namespace std;

// ------------------------------ Part 01: Tickets ------------------------------

string getCurrTime() {
    auto timenow = chrono::system_clock::now();
    time_t currentTime = chrono::system_clock::to_time_t(timenow);
    string readableCurrTime = ctime(&currentTime);
    readableCurrTime.erase(readableCurrTime.length() - 1); // erase new line
    return readableCurrTime;
}

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
    Ticket() : instanceTicketID(++numTickets), customerName(""), priority(0), requestDescription(""), ticketOpenTime(""), ticketCloseTime(""), status("Closed") {}
    Ticket(string customerName, int priority, string requestDescription) {
        instanceTicketID = ++numTickets;
        this->customerName = customerName;
        this->priority = priority;
        this->requestDescription = requestDescription;
        this->ticketOpenTime = getCurrTime();
        this->ticketCloseTime = "Active Currently";
        this->status = "Open";
    }

    ~Ticket() {
        ticketCloseTime = getCurrTime();
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

    void setStatus(string newStatus) {
        status = newStatus;
    }
};

int Ticket::numTickets = 0;

// ------------------------------ Part 02: Agent ------------------------------

class Agent {
private:
    int agentID;
    string agentName;
    vector<int> assignedTickets; // List of Ticket IDs
    bool availability;
    string status;

public:
    static int numAgents;
    Agent() : agentID(++numAgents), agentName(""), availability(true), status("Available") {}
    Agent(string agentName) : agentID(++numAgents), agentName(agentName), availability(true), status("Available") {}

    int getAgentID() const {
        return agentID;
    }

    string getAgentName() const {
        return agentName;
    }

    bool isAvailable() const {
        return availability;
    }

    string getStatus() const {
        return status;
    }

    void assignTicket(int ticketID) {
        if (assignedTickets.size() < 5) { // Max 5 open tickets allowed
            assignedTickets.push_back(ticketID);
            if (assignedTickets.size() == 5) {
                availability = false;
                status = "Unavailable";
            }
        } else {
            availability = false;
            status = "Unavailable";
        }
    }

    int getAssignedTicketCount() const {
        return assignedTickets.size();
    }

    void printAssignedTickets() const {
        cout << "Agent " << agentName << " has the following tickets assigned: ";
        for (int id : assignedTickets) {
            cout << id << " ";
        }
        cout << endl;
    }
};

int Agent::numAgents = 0;

// ------------------------------ Part 03: Agent Management System ------------------------------

class AgentManagement {
private:
    vector<Agent> agents;

public:
    // Add an Agent
    void addAgent(Agent &newAgent) {
        // Agent newAgent(agentName);
        agents.push_back(newAgent);
        // cout << "Added Agent: " << agents.end() << endl;
    }

    // Assign Ticket to an Agent based on priority and availability
    void assignTicket(Ticket &ticket) {
        int minTickets = 6; // Start higher than max allowed tickets
        Agent *selectedAgent = nullptr;

        // Find an available agent with the least number of tickets
        for (Agent &agent : agents) {
            if (agent.isAvailable() && agent.getAssignedTicketCount() < minTickets) {
                minTickets = agent.getAssignedTicketCount();
                selectedAgent = &agent;
            }
        }

        if (selectedAgent != nullptr) {
            selectedAgent->assignTicket(ticket.getInstanceTicketID());
            cout << "Assigned Ticket " << ticket.getInstanceTicketID() << " to Agent " << selectedAgent->getAgentName() << endl;
        } else {
            cout << "No available agents to assign the ticket!" << endl;
        }
    }

    // Print all agents and their status
    void printAgents() {
        for (Agent &agent : agents) {
            cout << "Agent ID: " << agent.getAgentID() << ", Name: " << agent.getAgentName()
                 << ", Status: " << agent.getStatus() << ", Tickets Assigned: " << agent.getAssignedTicketCount() << endl;
        }
    }
};

// ------------------------------ Part 04: Main ------------------------------

int main() {
    Ticket t1("Hammond", 5, "Issue A");
    Ticket t2("Duke", 3, "Issue B");
    Ticket t3("MJ", 4, "Issue C");
    Ticket t4("Amy", 1, "Issue D");
    Ticket t5("Oliver", 2, "Issue E");

    // Agent Management System
    Agent a1("PD");
    Agent a2("FBI");
    Agent a3("ARES");
    AgentManagement agentManagement;
    agentManagement.addAgent(a1);
    agentManagement.addAgent(a2);
    agentManagement.addAgent(a3);

    // Assign Tickets
    agentManagement.assignTicket(t1);
    agentManagement.assignTicket(t2);
    agentManagement.assignTicket(t3);
    agentManagement.assignTicket(t4);
    agentManagement.assignTicket(t5);

    // Print Agent Status
    agentManagement.printAgents();
    agent.printAssignedTickets();
    return 0;
}
