#include <iostream>
using namespace std;

class Node {
    public:
        static int ticketID;
        string customerName;
        int priority;
        string requestDescription;
        string ticketOpenTime;
        string ticketCloseTime;
        bool status;

        Node *next;
    
        Node () : customerName(""), priority(0), requestDescription(""), ticketOpenTime(""), ticketCloseTime(""), status(0), next(NULL) {
            ticketID++;
        }
        Node (string customerName, int priority, string requestDescription, string ticketOpenTime, string ticketCloseTime, bool status) {
            ticketID++;
            this->customerName = customerName;
            this->priority = priority;
            this->requestDescription = requestDescription;
            this->ticketOpenTime = ticketOpenTime;
            this->ticketCloseTime = ticketCloseTime;
            this->status = status;
            next = NULL;
        }
};

int Node::ticketID = 0;

class Ticket {
    public:
        Node *head;
        Node *tail;

        Ticket () : head(NULL), tail(NULL) {}
        Ticket (string customerName, int priority, string requestDescription, string ticketOpenTime, string ticketCloseTime, bool status) {
            head = new Node(customerName, priority, requestDescription, ticketOpenTime, ticketCloseTime, status);
            tail = head;
            tail->next = head;
        }

        void addAtHead (string customerName, int priority, string requestDescription, string ticketOpenTime, string ticketCloseTime, bool status) {
            Node *newnode = new Node(customerName, priority, requestDescription, ticketOpenTime, ticketCloseTime, status);
            if (head == NULL) {
                head = newnode;
                tail = head;
                tail->next = head;
            }
            else {
                Node *oldHead = head;
                head = newnode;
                head->next = oldHead;
                tail->next = head;
            }
        }

        void addTicket (string customerName, int priority, string requestDescription, string ticketOpenTime, string ticketCloseTime, bool status) {
            Node::ticketID++;
            Node *newnode = new Node(customerName, priority, requestDescription, ticketOpenTime, ticketCloseTime, status);
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

        void print() {
            if (head == NULL) {
                cout<<"List is empty." << endl;
                return;   
            }

            Node *temp = head;
            
            do {
                cout << "Ticket ID: " << temp->ticketID << endl;
                cout << "Customer Name: " << temp-> customerName<< endl;
                cout << "Priority: " << temp->priority << endl;
                cout << "Support Request Description: " << temp->requestDescription << endl;
                cout << "Ticket Open Time: " << temp-> ticketOpenTime<< endl;
                cout << "Ticket Close Time: " << temp->ticketCloseTime << endl;
                cout << "Status: " << temp->status << endl;
                temp = temp->next;
                cout<<endl;
            } while (temp != head);
        }
};

int main () {
    
    Ticket l1;
    l1.addTicket("Hammad", 2, "aesi hi", "12/10/2024",  "13/10/2024", true);
    l1.addTicket("duke", 2, "omc", "12/10/2024",  "13/10/2024", true);
    l1.addTicket("mj", 2, "hh", "12/10/2024",  "13/10/2024", true);
    l1.addTicket("xander", 2, "tc", "12/10/2024",  "13/10/2024", true);
    // l1.deleteNode(7);
    // l1.updateValue(123, 1);
    l1.print();
    cout<<endl;
    // l1.print();
	
	
	

    return 0;
}
