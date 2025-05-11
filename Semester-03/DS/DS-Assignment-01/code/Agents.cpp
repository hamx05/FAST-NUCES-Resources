#include "Agents.h"
using namespace std;

int Agent::numAgents = 0;

// Agent class implementation
Agent::Agent() : agentID(++numAgents), agentName(""), availability(1), status("Available"), numAssignedTickets(0), maxCapacity(5), numResolvedTickets(0) {
    assignedTickets = new Ticket[maxCapacity];
    resolvedTickets = new Ticket[maxCapacity];
}

Agent::Agent(string newAgentName) : agentID(++numAgents), agentName(newAgentName), availability(1), status("Available"), numAssignedTickets(0), maxCapacity(5), numResolvedTickets(0) {
    assignedTickets = new Ticket[maxCapacity];
    resolvedTickets = new Ticket[maxCapacity];
}

void Agent::setAgentName(string name) {
    agentName = name;
}

int Agent::getAgentID() const {
    return agentID;
}

string Agent::getAgentName() const {
    return agentName;
}

bool Agent::isAvailable() const {
    return availability;
}

string Agent::getStatus() const {
    return status;
}

int Agent::getAssignedTicketCount() const {
    return numAssignedTickets;
}

void Agent::markUnavailable() {
    availability = false;
    status = "Unavailable";
    cout << "Agent " << agentName << " is now unavailable (Full capacity)." << endl;
}

void Agent::decNumAssignedTickets() {
    numAssignedTickets--;
}

void Agent::setAvailability(bool newAvailability) {
    availability = newAvailability;
    status = newAvailability ? "Available" : "Unavailable";
}

void Agent::setStatus(const string& newStatus) {
    status = newStatus;
}

int Agent::getMaxCapacity() const {
    return maxCapacity;
}

void Agent::incNumResolvedTickets() {
    numResolvedTickets++;
}

int Agent::getNumResolvedTickets() {
    return numResolvedTickets;
}

void Agent::assignTicket(Ticket ticket, TicketQueue &ticketQueue) {
    if (ticketQueue.numPendingTickets == 0) {
        cout << "There is no pending ticket to be assigned at the moment." << endl;
        return;
    }

    if (numAssignedTickets == maxCapacity) {
        cout << "Agent " << agentName << " has reached maximum ticket capacity." << endl;
        // markUnavailable();
    } else {
        assignedTickets[numAssignedTickets] = ticket;
        cout << "Ticket " << ticket.getInstanceTicketID() << " assigned to Agent " << agentName << endl;
        numAssignedTickets++;
        ticketQueue.dequeueTicket();
        if (numAssignedTickets == maxCapacity) { // set agent as unavailable if he has 5 tickets
            markUnavailable();
        }
    }
}

void Agent::displayAgentsTickets() {
    cout<<"_____________ " << numAssignedTickets << " Ticket(s) Assigned to Agent '" << agentName << "' _____________" << endl;
    for (int i=0; i<numAssignedTickets; i++) {
        assignedTickets[i].printTicketDetails();
    }
    cout<<endl;
}

Ticket Agent::getAssignedTicket(int index) {
    if (index >= 0 && index < numAssignedTickets) {
        return assignedTickets[index];
    }
    throw std::out_of_range("Invalid ticket index");
}

bool Agent::hasTicket(Ticket &ticket) {
    for (int i = 0; i < numAssignedTickets; i++) {
        if (assignedTickets[i].getInstanceTicketID() == ticket.getInstanceTicketID()) {
            return true;
        }
    }
    return false;
}

void Agent::displayDetails() {
    cout << "Agent ID: " << agentID << endl; 
    cout << "Agent Name: " << agentName << endl;
    cout << "Status: " << status << endl;
    cout << "Availability: " << availability << endl;
    cout << "Assigned Tickets: " << numAssignedTickets << endl;
    cout << "Resolved Tickets: " << numResolvedTickets << endl << endl;
}

int AgentsList::totalSize = 0;

// AgentsList class implementation
AgentsList::AgentsList() : size(0) {}

AgentsList::~AgentsList() {
    delete[] agents;
}

void AgentsList::createAgent() {
    Agent newAgent;
    string name, status;
    bool availability;

    cout<<"Enter Agent Name: ";
    cin.ignore();
    getline(cin, name);
    newAgent.setAgentName(name);

    addAgent(newAgent);
}

void AgentsList::addAgent(Agent &newAgent) {
    cout << "Agent '" << newAgent.getAgentName() << "' has been added to the database." << endl;
    if (size == 0) {
        size = 1;
        agents = new Agent[size];
        agents[0] = newAgent;
        return;
    }

    Agent* tempAgents = new Agent[size];

    for (int i = 0; i < size; i++) {
        tempAgents[i] = agents[i];
    }

    delete[] agents;

    agents = new Agent[size + 1];
    for (int i = 0; i < size; i++) {
        agents[i] = tempAgents[i];
    }

    agents[size] = newAgent;
    size++;
    delete[] tempAgents;
}

void AgentsList::assignTicketToAgent(TicketQueue &ticketQueue) {
    int minTickets = 6; // Start higher than max allowed tickets
    Agent* selectedAgent = NULL;

    // Find an available agent with the least number of tickets
    for (int i = 0; i < size; i++) {
        if ((agents[i].isAvailable()) && (agents[i].getAssignedTicketCount() < minTickets) && (agents[i].getAssignedTicketCount() >=0 && agents[i].getAssignedTicketCount() < 5)) {
            minTickets = agents[i].getAssignedTicketCount();
            selectedAgent = &agents[i];
        }
    }

    if (selectedAgent != NULL) {
        selectedAgent->assignTicket(ticketQueue.peekTicket(), ticketQueue);
    } else {
        cout << "No available agents to assign the ticket!" << endl;
    }
}

void AgentsList::resolveTicket(TicketQueue &ticketQueue, TicketStack &ticketStack) {
    // cout << "Resolving the highest priority ticket..." << endl;

    Ticket highestPriorityTicket;
    highestPriorityTicket.setPriority(0);
    Agent* selectedAgent = NULL;
    bool ticketFound = false;

    // Loop through all agents to find the highest priority ticket
    for (int k = 0; k < size; k++) {
        for (int i = 0; i < agents[k].getAssignedTicketCount(); i++) {
            Ticket currentTicket = agents[k].assignedTickets[i];

            cout << "test resolve " << endl;
            // Check if this is the highest priority ticket found so far
            if (!ticketFound || currentTicket.getPriority() > highestPriorityTicket.getPriority()) {
                highestPriorityTicket = currentTicket;
                selectedAgent = &agents[k];
                ticketFound = true;
            }
        }
    }

    // If no ticket was found, print a message and return
    if (!ticketFound) {
        cout << "No tickets or No Agents available to resolve!" << endl;
        cout << "You must add a ticket and an agent to continue, also make sure the ticket is first assigned to an agent." << endl;
        return;
    }

    cout << "Resolving Ticket ID " << highestPriorityTicket.getInstanceTicketID() << "..." << endl;
    Ticket ticket;

    // Remove the ticket from the agent's assignedTickets array
    for (int i = 0; i < selectedAgent->getAssignedTicketCount(); i++) {
        if (selectedAgent->assignedTickets[i].getInstanceTicketID() == highestPriorityTicket.getInstanceTicketID()) {
            ticket = selectedAgent->assignedTickets[i];
            // Shift the tickets to remove the resolved one
            for (int j = i; j < selectedAgent->getAssignedTicketCount() - 1; j++) {
                selectedAgent->assignedTickets[j] = selectedAgent->assignedTickets[j + 1];
            }
            selectedAgent->decNumAssignedTickets(); // decrease assigned tickets count
            break;
        }
    }

    if (ticket.getInstanceTicketID() != -1) {
        // Set ticket status to closed and update ticketCloseTime
        ticket.setStatus("Closed");
        ticket.setTicketCloseTime(getCurrTime());

        // Change agent status to available if max capacity was reached
        if (selectedAgent->getAssignedTicketCount() < selectedAgent->getMaxCapacity()) {
            selectedAgent->setStatus("Available");
            selectedAgent->setAvailability(true);
        }

        // Push the resolved ticket into TicketStack
        ticketStack.pushTicket(ticket);

        cout << "Ticket ID " << ticket.getInstanceTicketID() << " has been resolved and logged." << endl;
    } else {
        cout << "Ticket not found!" << endl;
    }
}

void AgentsList::logResolvedTicket(Ticket &ticket, TicketStack &ticketStack) {
    ticketStack.pushTicket(ticket);
}

void AgentsList::sortAgents() {
    if (size == 0) {
        cout << "No agents added right now. Sorting cannot be done." << endl;
        return;
    }
    cout << "Starting the sort." << endl;
    ifstream inputFromFile;
    inputFromFile.open("config.txt");

    if (!inputFromFile) {
        cout<< "Error opening the file." << endl;
        return;
    }

    string algoChoice;
    getline(inputFromFile, algoChoice);

    if (algoChoice == "bubblesort") bubbleSortAgents();
    else if (algoChoice == "insertionsort") insertionSortAgents();
    else if (algoChoice == "selectionsort") selectionSortAgents();
    else if (algoChoice == "quicksort") quickSortAgents(agents, 0, size-1);
    else if (algoChoice == "mergesort") mergeSortAgents(agents, 0, size-1);
    else cout << "Invalid sorting choice in the config file." << endl;
}

void AgentsList::bubbleSortAgents() {
    for (int i = 0; i < size; i++) {
        bool flagSwap = false;
        for (int j = 0; j < size - i - 1; j++) {
            if (agents[j].getAssignedTicketCount() < agents[j + 1].getAssignedTicketCount()) {
                swap(agents[j], agents[j + 1]);
                flagSwap = true;
            }
        }
        if (!flagSwap) break;
    } 
}

void AgentsList::insertionSortAgents() {
    for (int i = 1; i < size; i++) {
        Agent temp = agents[i];
        int j = i - 1;

        while (j >= 0 && agents[j].getAssignedTicketCount() < temp.getAssignedTicketCount()) {
            agents[j + 1] = agents[j];
            j--;
        }
        agents[j + 1] = temp;
    }
}

void AgentsList::selectionSortAgents() {
    for (int i = 0; i < size; i++) {
        int minIndex = i;

        for (int j = i + 1; j < size; j++) {
            if (agents[j].getAssignedTicketCount() > agents[minIndex].getAssignedTicketCount()) {
                minIndex = j;
            }

        }
        if (minIndex != i) swap(agents[i], agents[minIndex]);
    }
}

int AgentsList::partitionAgents(Agent agents[], int low, int high) {
    Agent pivot = agents[low];
    int start = low, end = high;

    while (start < end) {
        // move start pointer to the right until we find an element less than pivot
        while (start <= high && agents[start].getAssignedTicketCount() >= pivot.getAssignedTicketCount()) {
            start++;
        }

        // move end pointer to the left until we find an element greater than pivot
        while (end >= low && agents[end].getAssignedTicketCount() < pivot.getAssignedTicketCount()) {
            end--;
        }

        // if start is still less than end, swap elements at start and end
        if (start < end) {
            swap(agents[start], agents[end]);
        }
    }

    // place pivot element in the correct position
    swap(agents[low], agents[end]);
    return end;
}

void AgentsList::quickSortAgents(Agent agents[], int low, int high) {
    if (low < high) {
        int pIndex = partitionAgents(agents, low, high);
        quickSortAgents(agents, low, pIndex - 1);
        quickSortAgents(agents, pIndex + 1, high);
    }
}

void AgentsList::mergeAgents(Agent agents[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    Agent* leftArr = new Agent[n1];
    Agent* rightArr = new Agent[n2];

    for (int i = 0; i < n1; i++) leftArr[i] = agents[left + i];
    for (int j = 0; j < n2; j++) rightArr[j] = agents[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        // Sorting by descending ticket count
        if (leftArr[i].getAssignedTicketCount() > rightArr[j].getAssignedTicketCount()) {
            agents[k++] = leftArr[i++];
        } else if (leftArr[i].getAssignedTicketCount() == rightArr[j].getAssignedTicketCount()) {
            // Secondary sort by name length if ticket counts are equal
            if (leftArr[i].getAgentName().length() >= rightArr[j].getAgentName().length()) {
                agents[k++] = leftArr[i++];
            } else {
                agents[k++] = rightArr[j++];
            }
        } else {
            agents[k++] = rightArr[j++];
        }
    }

    while (i < n1) agents[k++] = leftArr[i++];

    while (j < n2) agents[k++] = rightArr[j++];

    delete[] leftArr;
    delete[] rightArr;
}

void AgentsList::mergeSortAgents(Agent agents[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSortAgents(agents, left, mid);
        mergeSortAgents(agents, mid + 1, right);
        mergeAgents(agents, left, mid, right);
    }
}

void AgentsList::displayAgents() {
    if (size == 0) {
        cout << "No Agents added in the database at the moment." << endl;
        return;
    }

    cout<<"_____________ Displaying Agents: " << size << " _____________" << endl;
    for (int i=0; i<size; i++) {
        agents[i].displayDetails();
    }
}

void AgentsList::displaySpecificAgentTicket(int ID) {
    if (ID <= 0 || ID > size) {
        cout<<"Invalid Agent ID. Such Agent does not exist." << endl;
        return;
    }
    agents[ID-1].displayAgentsTickets();
}

void AgentsList::displayAllAssignedTickets() {
    for (int i = 0; i < size; i++) {
        if (agents[i].getAssignedTicketCount() != 0) {
            agents[i].displayAgentsTickets();
        }
    }
}