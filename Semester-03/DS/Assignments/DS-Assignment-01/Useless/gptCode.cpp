#include <iostream>
#include <chrono>
#include <ctime>
using namespace std;

string getCurrTime() {
    auto timenow = chrono::system_clock::now();
    // Convert to time_t to work with C-style time functions
    time_t currentTime = chrono::system_clock::to_time_t(timenow);
    string readableCurrTime = ctime(&currentTime);    
    // Remove the trailing newline from the time string
    readableCurrTime.erase(readableCurrTime.length() - 1);
    return readableCurrTime;
}

class Ticket {
    public:
        static int ticketID;       // Static ID counter for all tickets
        int instanceTicketID;      // Unique ID for each ticket instance
        string customerName;
        int priority;
        string requestDescription;
        string ticketOpenTime;
        string ticketCloseTime;
        string status;

        Ticket () : instanceTicketID(++ticketID), customerName(""), priority(0), requestDescription(""), ticketOpenTime(""), ticketCloseTime(""), status("Closed") {}

        Ticket (string customerName, int priority, string requestDescription) 
            : instanceTicketID(++ticketID), customerName(customerName), priority(priority), requestDescription(requestDescription) {
            this->ticketOpenTime = getCurrTime();
            this->ticketCloseTime = "Active Currently";
            this->status = "Open";
        }

        ~Ticket () {
            ticketCloseTime = getCurrTime();
            // Ticket status updated in destructor
        }
};
int Ticket::ticketID = 0;

class Node {
    public:
        Ticket data;
        Node *next;
    
        Node () : next(NULL) {}
        Node (Ticket &newTicket) : data(newTicket), next(NULL) {}
};

class LL {
    public:
        Node *head;
        Node *tail;

        LL () : head(NULL), tail(NULL) {}

        void addTicket (Ticket& newTicket) {
            Node *newnode = new Node(newTicket);
            if (head == NULL) {
                head = newnode;
                tail = head;
                tail->next = head;
            } else {
                tail->next = newnode;
                tail = newnode;
                tail->next = head;
            }
        }

        void removeTicket (int targetID) {
            if (!head) {
                cout << "List is empty, nothing to remove." << endl;
                return;
            }

            Node *curr = head;
            Node *prev = NULL;
            bool removed = false;
            string tempName;

            do {
                if (targetID == curr->data.instanceTicketID) {
                    removed = true;
                    tempName = curr->data.customerName;
                    
                    // If there's only one ticket in the list
                    if (curr == head && head->next == head) {
                        delete head;
                        head = tail = NULL;
                    }
                    else if (curr == head) {  // Removing head
                        head = head->next;
                        tail->next = head;
                        delete curr;
                    } else {  // Removing any other node
                        prev->next = curr->next;
                        if (curr == tail) tail = prev;
                        delete curr;
                    }
                    break;
                }
                prev = curr;
                curr = curr->next;
            } while (curr != head);

            if (removed) 
                cout << "Ticket ID " << targetID << " registered under the name '" << tempName << "' has been removed." << endl;
            else 
                cout << "Ticket ID " << targetID << " does not exist." << endl;
        }

        void searchTicket (int targetID) {
            if (!head) {
                cout << "List is empty." << endl;
                return;
            }

            Node *temp = head;

            do {
                if (targetID == temp->data.instanceTicketID) {
                    cout << "Match Found! Customer Details:\n";
                    cout << "Ticket ID: " << temp->data.instanceTicketID << endl;
                    cout << "Customer Name: " << temp->data.customerName<< endl;
                    cout << "Priority: " << temp->data.priority << endl;
                    cout << "Support Request Description: " << temp->data.requestDescription << endl;
                    cout << "Ticket Open Time: " << temp->data.ticketOpenTime << endl;
                    cout << "Ticket Close Time: " << temp->data.ticketCloseTime << endl;
                    cout << "Status: " << temp->data.status << endl;    
                    return;
                }
                temp = temp->next;
            } while (temp != head);

            cout<<"Ticket ID " << targetID << " does not exist and is not found in the database." << endl;
        }

        void searchTicket (string targetName) {
            if (!head) {
                cout << "List is empty." << endl;
                return;
            }

            Node *temp = head;

            do {
                if (targetName == temp->data.customerName) {
                    cout << "Match Found! Customer Details:\n";
                    cout << "Ticket ID: " << temp->data.instanceTicketID << endl;
                    cout << "Customer Name: " << temp->data.customerName<< endl;
                    cout << "Priority: " << temp->data.priority << endl;
                    cout << "Support Request Description: " << temp->data.requestDescription << endl;
                    cout << "Ticket Open Time: " << temp->data.ticketOpenTime << endl;
                    cout << "Ticket Close Time: " << temp->data.ticketCloseTime << endl;
                    cout << "Status: " << temp->data.status << endl;    
                    return;
                }
                temp = temp->next;
            } while (temp != head);

            cout << "No ticket was found under the name '" << targetName << "' " << endl;
        }

        void print() {
            if (head == NULL) {
                cout<<"List is empty." << endl;
                return;   
            }

            Node *temp = head;
            do {
                cout << "Ticket ID: " << temp->data.instanceTicketID << endl;
                cout << "Customer Name: " << temp->data.customerName<< endl;
                cout << "Priority: " << temp->data.priority << endl;
                cout << "Support Request Description: " << temp->data.requestDescription << endl;
                cout << "Ticket Open Time: " << temp->data.ticketOpenTime << endl;
                cout << "Ticket Close Time: " << temp->data.ticketCloseTime << endl;
                cout << "Status: " << temp->data.status << endl;
                temp = temp->next;
                cout << endl;
            } while (temp != head);
        }
};

int main () {

    Ticket t1("hammond", 2, "aesi hi");
    Ticket t2("duke", 2, "omc");
    Ticket t3("mj", 2, "hh");

    LL l1;
    l1.addTicket(t1);
    l1.addTicket(t2);
    l1.addTicket(t3);
    l1.print();
    l1.removeTicket(1);
    l1.searchTicket("mj");
    l1.searchTicket(3);
    l1.print();

    return 0;
}
