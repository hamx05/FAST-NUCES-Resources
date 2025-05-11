#include <iostream>
#include <chrono>
#include <ctime>
using namespace std;

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
        static int ticketID; // static id counter
        int instanceTicketID; // unique id for each customer
        string customerName;
        int priority;
        string requestDescription;
        string ticketOpenTime;
        string ticketCloseTime;
        string status;

    public:
        Ticket () : instanceTicketID(++ticketID),customerName(""), priority(0), requestDescription(""), ticketOpenTime(""), ticketCloseTime(""), status("Closed") {}
        Ticket (string customerName, int priority, string requestDescription) {
            instanceTicketID = ++ticketID;
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
int Ticket::ticketID = 0;

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
                    if (prev == curr && prev->next==NULL && curr->next==NULL) { // // if the target is at head and there are no other elements in the list
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

int main () {

    Ticket t1("Hammond", 5, "Issue A");
    Ticket t2("Duke", 3, "Issue B");
    Ticket t3("MJ", 4, "Issue C");
    Ticket t4("Amy", 1, "Issue D");
    Ticket t5("Oliver", 2, "Issue E");

    Ticket tickets[] = {t1, t2, t3, t4, t5};
    int n = sizeof(tickets) / sizeof(tickets[0]);


    CLL l1;
    l1.addTicket(t1);
    l1.addTicket(t2);
    l1.addTicket(t3);
    l1.addTicket(t4);
    l1.addTicket(t5);

    cout << "Before Sorting:\n";
    l1.print();

    char sortOption;
    cout << "\nEnter sorting criteria (p for Priority, n for Name, t for Ticket Open Time): ";
    cin >> sortOption;

    // Sort the tickets based on the chosen attribute
    l1.sortTickets(tickets, n, sortOption);

    // Print the sorted tickets
    cout << "\nAfter Sorting:\n";
    l1.print();


    return 0;
}