#include <iostream>
#include <chrono>
#include <ctime>
using namespace std;

// ------------------------------ Part 01: Tickets ------------------------------

// Function to get the current time
string getCurrTime() {
    auto timenow = chrono::system_clock::now();
    time_t currentTime = chrono::system_clock::to_time_t(timenow);
    string readableCurrTime = ctime(&currentTime);
    readableCurrTime.erase(readableCurrTime.length() - 1); // remove the new line
    return readableCurrTime;
}

class Ticket {
    private:
        int instanceTicketID;
        string customerName;
        int priority;
        string requestDescription;
        string ticketOpenTime;
        string ticketCloseTime;
        string status;

    public:
        static int numTickets;
        Ticket() : instanceTicketID(++numTickets), customerName(""), priority(0), requestDescription(""), ticketOpenTime(""), ticketCloseTime("Closed"), status("Closed") {}
        Ticket(string customerName, int priority, string requestDescription) {
            instanceTicketID = ++numTickets;
            this->customerName = customerName;
            this->priority = priority;
            this->requestDescription = requestDescription;
            this->ticketOpenTime = getCurrTime();
            this->ticketCloseTime = "Active Currently";
            this->status = "Open";
        }

        int getInstanceTicketID() const { return instanceTicketID; }
        string getCustomerName() const { return customerName; }
        int getPriority() const { return priority; }
        string getRequestDescription() const { return requestDescription; }
        string getTicketOpenTime() const { return ticketOpenTime; }
        string getTicketCloseTime() const { return ticketCloseTime; }
        string getStatus() const { return status; }
        void setStatus(string newStatus) { status = newStatus; }
};
int Ticket::numTickets = 0;

// ------------------------------ Part 02: Agent ------------------------------

class Agent {
    private:
        int agentID;
        string agentName;
        bool availability;
        string status;
        Ticket* assignedTickets; // Dynamic array to store assigned tickets
        int numAssignedTickets;
        int maxCapacity;

    public:
        static int numAgents;
        Agent() : agentID(++numAgents), agentName(""), availability(true), status("Available"), numAssignedTickets(0), maxCapacity(5) {
            assignedTickets = new Ticket[maxCapacity]; // Initialize dynamic array
        }
        Agent(string agentName) : agentID(++numAgents), agentName(agentName), availability(true), status("Available"), numAssignedTickets(0), maxCapacity(5) {
            assignedTickets = new Ticket[maxCapacity];
        }
        ~Agent() {
            delete[] assignedTickets;
        }

        // Assign a ticket to the agent
        void assignTicket(Ticket &ticket) {
            if (numAssignedTickets == maxCapacity) {
                cout << "Agent " << agentName << " has reached maximum ticket capacity.\n";
                markUnavailable();
            } else {
                assignedTickets[numAssignedTickets++] = ticket;
                cout << "Ticket " << ticket.getInstanceTicketID() << " assigned to Agent " << agentName << endl;
            }
        }

        int getAssignedTicketCount() const { return numAssignedTickets; }
        int getAgentID() const { return agentID; }
        string getAgentName() const { return agentName; }
        bool isAvailable() const { return availability; }
        string getStatus() const { return status; }
        void markUnavailable() { availability = false; status = "Unavailable"; }
};
int Agent::numAgents = 0;

// ------------------------------ Part 03: Dynamic Array of Agents (DA) ------------------------------

class DA {
    private:
        Agent* agents; // Dynamic array of agents
        int size;
        int capacity;

    public:
        DA() : size(0), capacity(2) {
            agents = new Agent[capacity]; // Initial capacity
        }

        ~DA() {
            delete[] agents;
        }

        // Add an agent (resize if necessary)
        void addAgent(Agent &newAgent) {
            if (size == capacity) {
                resize(); // Resize if array is full
            }
            agents[size++] = newAgent;
        }

        // Resize the dynamic array of agents
        void resize() {
            capacity += 5; // increasing capacity by 5 so it can handle atleast 5 more new agents
            Agent* newAgents = new Agent[capacity];
            for (int i = 0; i < size; i++) {
                newAgents[i] = agents[i];
            }
            delete[] agents;
            agents = newAgents;
        }

        // Assign tickets to the available agent with the fewest tickets
        void assignTicketToAgent(Ticket &ticket) {
            int minTickets = 6; // A value higher than the max capacity of tickets
            Agent* selectedAgent = nullptr;

            // Find an available agent with the least number of tickets
            for (int i = 0; i < size; i++) {
                if (agents[i].isAvailable() && agents[i].getAssignedTicketCount() < minTickets) {
                    minTickets = agents[i].getAssignedTicketCount();
                    selectedAgent = &agents[i];
                }
            }

            if (selectedAgent) {
                selectedAgent->assignTicket(ticket);
            } else {
                cout << "No available agents to assign ticket " << ticket.getInstanceTicketID() << endl;
            }
        }

        void printAgents() {
            for (int i = 0; i < size; i++) {
                cout << "Agent ID: " << agents[i].getAgentID() << ", Name: " << agents[i].getAgentName()
                     << ", Status: " << agents[i].getStatus() << ", Tickets Assigned: " << agents[i].getAssignedTicketCount() << endl;
            }
        }
};

int main() {
    Ticket t1("Hammond", 5, "Issue A");
    Ticket t2("Duke", 3, "Issue B");
    Ticket t3("MJ", 4, "Issue C");

    Agent a1("Agent A");
    Agent a2("Agent B");
    Agent a3("Agent C");
    Agent a4("Agent D");
    Agent a5("Agent E");
    Agent a6("Agent F");
    Agent a7("Agent G");
    Agent a8("Agent H");

    DA da;
    da.addAgent(a1);
    da.addAgent(a2);
    // da.addAgent(a3);
    // da.addAgent(a4);
    // da.addAgent(a5);
    // da.addAgent(a6);
    // da.addAgent(a7);
    // da.addAgent(a8);


    da.assignTicketToAgent(t1);
    da.assignTicketToAgent(t2);
    da.assignTicketToAgent(t3);

    da.printAgents();

    return 0;
}
