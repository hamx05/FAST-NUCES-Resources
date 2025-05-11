#include <iostream>
#include <chrono>
#include <ctime>
using namespace std;

// ------------------------------ Part 01: Tickets ------------------------------

string getCurrTime() {
    auto timenow = chrono::system_clock::now();
    // Convert to time_t to work with C-style time functions
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
        Ticket () : instanceTicketID(++numTickets),customerName(""), priority(0), requestDescription(""), ticketOpenTime(""), ticketCloseTime(""), status("Closed") {}
        Ticket (string customerName, int priority, string requestDescription) {
            instanceTicketID = ++numTickets;
            this->customerName = customerName;
            this->priority = priority;
            this->requestDescription = requestDescription;
            this->ticketOpenTime = getCurrTime();
            this->ticketCloseTime = "Active Currently";
            this->status = "Open";
        }

        ~Ticket () {
            ticketCloseTime = getCurrTime();
            // cout<<"Ticket ID "<< ticketID << "'s close time: " << ticketCloseTime << endl;
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

class Node {
    public:
        Ticket data;
        Node *next;
    
        Node () : next(NULL) {}
        Node (Ticket &newTicket) {
            data = newTicket;
            next = NULL;
        }
};

class CLL {
    public:
        Node *head;
        Node *tail;

        CLL () : head(NULL), tail(NULL) {}
        CLL (Ticket& newTicket) {
            head = new Node(newTicket);
            tail = head;
            tail->next = head;
        }

        void addTicket (Ticket& newTicket) {
            Node *newnode = new Node(newTicket);
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

        void removeTicket (int targetID) {
            Node *curr = head;
            Node *prev = head;
            bool removed = false;
            string tempName;

            do {
                if (targetID == curr->data.getInstanceTicketID()) {
                    removed = true;
                    tempName = curr->data.getCustomerName();
                    if (prev == curr && prev->next==NULL && curr->next==NULL) { // if the target is at head and there are no other elements in the list
                        delete head;
                    }
                    else { // the target is at head but there are other elements in the list as well
                        prev->next = curr->next;
                        delete curr;
                    }
                    break;
                }
                prev = curr;
                curr = curr->next;
            } while (curr != head);

            if (removed) cout<<"Ticket ID " << targetID << " registered under the name '" << tempName <<"' has been removed." << endl;
            else cout<<"Ticket ID " << targetID << " does not exist." << endl;
        }

        void searchTicket (int targetID) {
            Node *temp = head;

            do {
                if (targetID == temp->data.getInstanceTicketID()) {
                    cout << "Match Found! Customer Details:\n";
                    cout << "Ticket ID: " << temp->data.getInstanceTicketID() << endl;
                    cout << "Customer Name: " << temp->data.getCustomerName()<< endl;
                    cout << "Priority: " << temp->data.getPriority() << endl;
                    cout << "Support Request Description: " << temp->data.getRequestDescription() << endl;
                    cout << "Ticket Open Time: " << temp->data. getTicketOpenTime()<< endl;
                    cout << "Ticket Close Time: " << temp->data.getTicketCloseTime() << endl;
                    cout << "Status: " << temp->data.getStatus() << endl;    
                    return;
                }
                temp = temp->next;
            } while (temp != head);

            cout<<"Ticket ID " << targetID << " does not exist and is not found in the database." << endl;
        }

        void searchTicket (string targetName) {
            Node *temp = head;

            do {
                if (targetName == temp->data.getCustomerName()) {
                    cout << "Match Found! Customer Details:\n";
                    cout << "Ticket ID: " << temp->data.getInstanceTicketID() << endl;
                    cout << "Customer Name: " << temp->data.getCustomerName()<< endl;
                    cout << "Priority: " << temp->data.getPriority() << endl;
                    cout << "Support Request Description: " << temp->data.getRequestDescription() << endl;
                    cout << "Ticket Open Time: " << temp->data.getTicketOpenTime()<< endl;
                    cout << "Ticket Close Time: " << temp->data.getTicketCloseTime() << endl;
                    cout << "Status: " << temp->data.getStatus() << endl;    
                    return;
                }
                temp = temp->next;
            } while (temp != head);

            cout<<"No ticket was found under the name '" << targetName << "' " << endl;
        }

        // using shell sort; some flaws were fixed by gpt
        void sortTickets(Ticket tickets[], int n, char ch) {
            for (int gap = n / 2; gap > 0; gap /= 2) {
                for (int i = gap; i < n; i++) {
                    Ticket temp = tickets[i];
                    int j;

                    for (j = i; j >= gap; j -= gap) {
                        bool condition;
                        if (ch == 'p') { // sort by priority (higher priority comes first)
                            condition = temp.getPriority() > tickets[j - gap].getPriority();
                        } else if (ch == 'n') { // sort by customer name in lexicographical order
                            condition = temp.getCustomerName() < tickets[j - gap].getCustomerName();
                        } else { // sort by time (earliest comes first)
                            condition = temp.getTicketOpenTime() < tickets[j - gap].getTicketOpenTime();
                        }

                        if (condition) tickets[j] = tickets[j - gap];
                        else break;
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
                cout<<"List is empty." << endl;
                return;   
            }

            Node *temp = head;
            do {
                cout << "Ticket ID: " << temp->data.getInstanceTicketID() << endl;
                cout << "Customer Name: " << temp->data.getCustomerName()<< endl;
                cout << "Priority: " << temp->data.getPriority() << endl;
                cout << "Support Request Description: " << temp->data.getRequestDescription() << endl;
                cout << "Ticket Open Time: " << temp->data.getTicketOpenTime()<< endl;
                cout << "Ticket Close Time: " << temp->data.getTicketCloseTime() << endl;
                cout << "Status: " << temp->data.getStatus() << endl;
                temp = temp->next;
                cout<<endl;
            } while (temp != head);
        }
};

// ------------------------------ Part 02: Agent ------------------------------
class Agent {
    private:
        int agentID;
        string agentName;
        Ticket* assignedTickets;
        bool availability;
        string status;
        int numAssignedTickets;
        int maxCapacity;

    public:
        static int numAgents;
        Agent () : agentID(++numAgents),  agentName(""), availability(1), status("Available"), numAssignedTickets(0), maxCapacity(5) {
            assignedTickets = new Ticket[maxCapacity]; // dynamically allocate memory for assignedTickets
        }
        Agent (string newAgentName) : agentID(++numAgents),  agentName(newAgentName), availability(1), status("Available"), numAssignedTickets(0), maxCapacity(5) {
            assignedTickets = new Ticket[maxCapacity]; // dynamically allocate memory for assignedTickets
        }

        int getAgentID() {
            return agentID;
        }
        string getAgentName() {
            return agentName;
        }
        string getAgentStatus() {
            return status;
        }
        bool getAvailability() {
            return availability;
        }
        int getNumAssignedTickets() {
            return numAssignedTickets;
        }

        void assignTicket(Ticket &ticket) {
            if (numAssignedTickets < maxCapacity) {
                assignedTickets[numAssignedTickets++] = ticket;
                status = "Busy";
                cout << "Ticket ID " << ticket.getInstanceTicketID() << " has been assigned to Agent " << agentID << endl;
                if (numAssignedTickets == maxCapacity) {
                    availability = false;
                    status = "Full";
                }
            } else {
                cout << "Agent " << agentID << " is at full capacity. Unable to assign ticket." << endl;
            }
        }

        void printAssignedTickets() {
            cout << "Agent " << agentID << " (" << agentName << ") has " << numAssignedTickets << " tickets assigned." << endl;
            for (int i = 0; i < numAssignedTickets; i++) {
                cout << "Ticket ID: " << assignedTickets[i].getInstanceTicketID() << ", Priority: " << assignedTickets[i].getPriority() << endl;
            }
        }

        void clearAssignedTickets() {
            delete[] assignedTickets;
            assignedTickets = new Ticket[maxCapacity]; // reallocate memory
            numAssignedTickets = 0;
            availability = true;
            status = "Available";
        }

};

int Agent::numAgents = 0;

int main() {
    Ticket ticket1("Alice", 2, "Issue 1");
    Ticket ticket2("Bob", 1, "Issue 2");
    Ticket ticket3("Charlie", 3, "Issue 3");

    CLL ticketList;
    ticketList.addTicket(ticket1);
    ticketList.addTicket(ticket2);
    ticketList.addTicket(ticket3);

    ticketList.print();

    Ticket tickets[] = {ticket1, ticket2, ticket3};
    ticketList.sortTickets(tickets, 3, 'p');  // sorting by priority
    ticketList.print();

    return 0;
}
