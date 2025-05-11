#include <iostream>
#include <vector>
using namespace std;

class Ticket {
public:
    int instanceTicketID;
    string customerName;
    int priority;
    string requestDescription;

    Ticket(int id, string name, int priority, string description) 
        : instanceTicketID(id), customerName(name), priority(priority), requestDescription(description) {}

    int getTicketID() const {
        return instanceTicketID;
    }

    int getPriority() const {
        return priority;
    }
};

class Agent {
private:
    int agentID;
    string agentName;
    vector<int> assignedTickets; // Dynamic array of assigned ticket IDs
    bool availability;
    static const int MAX_CAPACITY = 5; // Max capacity of tickets an agent can handle
    string status;

public:
    static int numAgents;

    // Constructor for Agent
    Agent(string name) 
        : agentID(++numAgents), agentName(name), availability(true), status("Available") {}

    // Add a ticket to the agent
    void assignTicket(int ticketID) {
        if (assignedTickets.size() < MAX_CAPACITY) {
            assignedTickets.push_back(ticketID);
            cout << "Ticket ID " << ticketID << " assigned to Agent " << agentName << endl;
        }
        if (assignedTickets.size() == MAX_CAPACITY) {
            markUnavailable();
        }
    }

    // Mark agent as unavailable when capacity is full
    void markUnavailable() {
        availability = false;
        status = "Unavailable";
        cout << "Agent " << agentName << " is now unavailable (Full capacity)." << endl;
    }

    // Check if the agent is available
    bool isAvailable() const {
        return availability;
    }

    // Get the number of assigned tickets
    int getAssignedTicketsCount() const {
        return assignedTickets.size();
    }

    // Get the agent's name
    string getName() const {
        return agentName;
    }

    // Get the agent's ID
    int getAgentID() const {
        return agentID;
    }
};
int Agent::numAgents = 0;

class AgentManager {
private:
    Agent** agents;  // Dynamic array of Agent pointers
    int capacity;    // Capacity of the array
    int count;       // Number of agents currently in the array

public:
    AgentManager() : agents(nullptr), capacity(0), count(0) {}

    // Add a new agent
    void addAgent(Agent* newAgent) {
        if (count == capacity) {
            resize();
        }
        agents[count] = newAgent;
        count++;
        cout << "Agent " << newAgent->getName() << " added to the system." << endl;
    }

    // Resize the dynamic array to accommodate more agents
    void resize() {
        int newCapacity = (capacity == 0) ? 1 : capacity * 2;
        Agent** newAgents = new Agent*[newCapacity];

        for (int i = 0; i < count; i++) {
            newAgents[i] = agents[i];
        }

        delete[] agents;
        agents = newAgents;
        capacity = newCapacity;
    }

    // Automatically assign tickets based on priority and availability
    void assignTicketToAgent(Ticket& ticket) {
        Agent* bestAgent = nullptr;
        for (int i = 0; i < count; i++) {
            if (agents[i]->isAvailable()) {
                if (bestAgent == nullptr || agents[i]->getAssignedTicketsCount() < bestAgent->getAssignedTicketsCount()) {
                    bestAgent = agents[i];
                }
            }
        }
        if (bestAgent != nullptr) {
            bestAgent->assignTicket(ticket.getTicketID());
        } else {
            cout << "No available agents to assign Ticket ID " << ticket.getTicketID() << endl;
        }
    }

    // Print the status of all agents
    void printAgentStatus() {
        cout << "Agent Status Report:" << endl;
        for (int i = 0; i < count; i++) {
            cout << "Agent ID: " << agents[i]->getAgentID() << " | Name: " << agents[i]->getName()
                 << " | Tickets Assigned: " << agents[i]->getAssignedTicketsCount()
                 << " | Status: " << (agents[i]->isAvailable() ? "Available" : "Unavailable") << endl;
        }
    }

    ~AgentManager() {
        for (int i = 0; i < count; i++) {
            delete agents[i];
        }
        delete[] agents;
    }
};

int main() {
    // Creating some sample tickets
    Ticket t1(1, "Alice", 5, "Issue A");
    Ticket t2(2, "Bob", 3, "Issue B");
    Ticket t3(3, "Charlie", 1, "Issue C");
    Ticket t4(4, "David", 4, "Issue D");
    Ticket t5(5, "Eve", 2, "Issue E");

    // Creating the agent manager
    AgentManager manager;

    // Adding agents
    Agent* agent1 = new Agent("Agent 1");
    Agent* agent2 = new Agent("Agent 2");
    Agent* agent3 = new Agent("Agent 3");

    manager.addAgent(agent1);
    manager.addAgent(agent2);
    manager.addAgent(agent3);

    // Assigning tickets based on availability and capacity
    manager.assignTicketToAgent(t1);
    manager.assignTicketToAgent(t2);
    manager.assignTicketToAgent(t3);
    manager.assignTicketToAgent(t4);
    manager.assignTicketToAgent(t5);

    // Displaying the status of all agents
    manager.printAgentStatus();

    return 0;
}
