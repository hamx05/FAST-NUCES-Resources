#include <iostream>
#include <fstream>
#include <chrono>
#include <ctime>
#include <string>
#include <utility> // for std::pair
#include "Agents.cpp"
using namespace std;

int get_int() {
    int n;
    for (;;) {
        if (cin >> n) {
            return n;
        }
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid entry. Please re-enter: ";
    }
}

string getCurrTime() {
    auto timenow = chrono::system_clock::now();
    // Convert to time_t to work with C-style time functions
    time_t currentTime = chrono::system_clock::to_time_t(timenow);
    string readableCurrTime = ctime(&currentTime);
    readableCurrTime.erase(readableCurrTime.length() - 1); // erase new line
    return readableCurrTime;
}


class NodeQueue {
    public:
        Ticket ticket;
        NodeQueue *next;

        NodeQueue (Ticket &newTicket) : ticket(newTicket), next(NULL) {}
};

class TicketQueue { // circular queue
    public:
        NodeQueue *head;
        NodeQueue *tail;
        int numPendingTickets;
        static int count;

        TicketQueue () : head(NULL), tail(NULL), numPendingTickets(0) {}

        void createTicket (TicketsList& TL) {
            Ticket newTicket;
            string name, req;
            int pr;

            newTicket.initiateTicketID();

            cout<<"Enter customer name: ";
            cin.ignore();
            getline(cin, name);
            newTicket.setCustomerName(name);

            cout<<"Enter priority: ";
            pr = get_int();
            newTicket.setPriority(pr);

            cout<<"Enter Support Request Description: ";
            cin.ignore();
            getline(cin, req);
            newTicket.setRequestDescription(req);
            newTicket.setTicketOpenTime();
            newTicket.setTicketCloseTime("Active Currently");

            enqueueTicket(newTicket);
            TL.addTicket(newTicket); // adding it into all the tickets created today 
        }

        void enqueueTicket (Ticket &incTicket) {
            cout << "Ticket ID " << incTicket.getInstanceTicketID() << " has been added." << endl;
            if (head == NULL) {
                head = new NodeQueue(incTicket);
                tail = head;
                tail->next = head;
            } else {
                NodeQueue *temp = tail;
                temp->next = new NodeQueue(incTicket);
                tail = temp->next;
                tail->next = head;
            }
            numPendingTickets++;

            // Everytime a new ticket is added, make sure to put it at its correct place (sorted by priority)
            silentSortTicketQueue('p');
        }

        void dequeueTicket () {
            if (head == NULL) {
                cout<<"\nTicket's queue is already empty, no ticket can be popped." << endl;
                return;
            }
            
            cout << "Ticket ID " << peekTicket().getInstanceTicketID() << " has been dequeued from the Ticket Quuee." << endl;
            numPendingTickets--;
            if (head->next == head) {
            	delete head;
            	head = NULL;
            	tail = NULL;
            	return;
			}

            NodeQueue *temp = head;
            head = head->next;
            tail->next = head;
            delete temp;
        }

        Ticket peekTicket () {
            if (head == NULL) {
                Ticket invalidTicket;
                invalidTicket.setTicketID(-1);
                return invalidTicket;
            }

            return head->ticket;
        }

        void printTicketQueue() {
        	if (head == NULL) {
        		cout<<"Ticket Queue is empty. Nothing to print." << endl;
        		return;
			}
			
            NodeQueue *temp = head;
            cout << "_____________ Displaying " << numPendingTickets << " Tickets Pending Agent Assignment _____________ " << endl;
            do {
                temp->ticket.printTicketDetails();
                temp = temp->next;
            } while (temp != head);
            
            cout<< endl;
        }

        void removeTicket(int targetID) {
            if (head == nullptr) {
                cout << "Ticket list is empty." << endl;
                return;
            }

            NodeQueue *curr = head;
            NodeQueue *prev = nullptr;
            bool removed = false;
            string tempName;

            do {
                if (targetID == curr->ticket.getInstanceTicketID()) {
                    removed = true;
                    tempName = curr->ticket.getCustomerName();

                    if (curr == head && curr->next == head) { // Only one element in the list
                        delete head;
                        head = NULL; // update head to nullptr as the list is now empty
                    } else if (curr == head) { // Target is at the head and there are other elements
                        // Update head to the next NodeQueue
                        NodeQueue *tail = head;
                        while (tail->next != head) {
                            tail = tail->next;
                        }
                        head = head->next;
                        tail->next = head;
                        delete curr;
                    } else { // Target is not at the head
                        prev->next = curr->next;
                        delete curr;
                    }
                    break;
                }
                prev = curr;
                curr = curr->next;
            } while (curr != head);

            if (removed) {
                cout << "Ticket ID " << targetID << " registered under the name '" << tempName << "' has been removed from the tickets list." << endl;
            } else {
                cout << "Ticket ID " << targetID << " does not exist." << endl;
            }
        }

        void silentRemoveTicket(int targetID) {
            if (head == nullptr) {
                cout << "Ticket list is empty." << endl;
                return;
            }

            NodeQueue *curr = head;
            NodeQueue *prev = nullptr;
            bool removed = false;
            string tempName;

            do {
                if (targetID == curr->ticket.getInstanceTicketID()) {
                    removed = true;
                    tempName = curr->ticket.getCustomerName();

                    if (curr == head && curr->next == head) { // Only one element in the list
                        delete head;
                        head = NULL; // update head to nullptr as the list is now empty
                    } else if (curr == head) { // Target is at the head and there are other elements
                        // Update head to the next NodeQueue
                        NodeQueue *tail = head;
                        while (tail->next != head) {
                            tail = tail->next;
                        }
                        head = head->next;
                        tail->next = head;
                        delete curr;
                    } else { // Target is not at the head
                        prev->next = curr->next;
                        delete curr;
                    }
                    break;
                }
                prev = curr;
                curr = curr->next;
            } while (curr != head);            
        }

        Ticket findTicket(int targetID) {
            NodeQueue *temp = head;
            do {
                if (targetID == temp->ticket.getInstanceTicketID()) {
                    return temp->ticket;
                }
                temp = temp->next;
            } while (temp != head);

            Ticket invalidTicket;
            invalidTicket.setTicketID(-1);
            return invalidTicket;
        }

        void sortTicketQueue() {

            ifstream inputFromFile;
            inputFromFile.open("config.txt");

            if (!inputFromFile) {
                cout<< "Error opening the file." << endl;
                return;
            }

            char ch;
            cout << "\nEnter sorting criteria (p for Priority, n for Name, t for Ticket Open Time): ";
            cin >> ch;

            if (ch != 'p' && ch != 'n' && ch != 't') {
                cout << "Tickets' sorting failed. Invalid sorting selection." << endl;
                return;
            }

            string algoChoice;
            getline(inputFromFile, algoChoice);

            if (algoChoice == "bubblesort") bubbleSortTicketQueue(ch);
            else if (algoChoice == "insertionsort") insertionSortTicketQueue(ch);
            else if (algoChoice == "selectionsort") selectionSortTicketQueue(ch);
            else if (algoChoice == "quicksort" || algoChoice == "mergesort") {
                cout << "Quick Sort and Merge Sort cannot be used on Queue (with linked list). Please use another sorting algorithm." << endl;
            }
            // else if (algoChoice == "quicksort") quickSortTickets(ch);
            // else if (algoChoice == "mergesort") mergeSortTickets(tickets, 0, n-1, ch, n);
            else cout << "Invalid sorting choice in the config file." << endl;
        }

        void silentSortTicketQueue(char ch) {
            if (head == NULL || head->next == head) return;

            bool swapped;
            do {
                swapped = false;
                NodeQueue *current = head;

                // we need to break before we return to the head node in a circular list.
                do {
                    NodeQueue *nextNode = current->next;

                    // check if we need to swap based on the chosen criterion
                    bool condition;
                    if (ch == 'p') {
                        condition = current->ticket.getPriority() < nextNode->ticket.getPriority();
                    } else if (ch == 'n') {
                        condition = current->ticket.getCustomerName() > nextNode->ticket.getCustomerName();
                    } else {
                        condition = current->ticket.getTicketOpenTime() > nextNode->ticket.getTicketOpenTime();
                    }

                    // swap ticket data if condition is met
                    if (condition) {
                        swap(current->ticket, nextNode->ticket);
                        swapped = true;
                    }

                    current = current->next;
                } while (current != tail); // stop just before looping back to head for the current pass

            } while (swapped); // keep sorting until no swaps are made in a full pass
        }

        void bubbleSortTicketQueue(char ch) {
            if (head == NULL || head->next == head) return;

            bool swapped;
            do {
                swapped = false;
                NodeQueue *current = head;

                // we need to break before we return to the head node in a circular list.
                do {
                    NodeQueue *nextNode = current->next;

                    // check if we need to swap based on the chosen criterion
                    bool condition;
                    if (ch == 'p') {
                        condition = current->ticket.getPriority() < nextNode->ticket.getPriority();
                    } else if (ch == 'n') {
                        condition = current->ticket.getCustomerName() > nextNode->ticket.getCustomerName();
                    } else {
                        condition = current->ticket.getTicketOpenTime() > nextNode->ticket.getTicketOpenTime();
                    }

                    // swap ticket data if condition is met
                    if (condition) {
                        swap(current->ticket, nextNode->ticket);
                        swapped = true;
                    }

                    current = current->next;
                } while (current != tail); // stop just before looping back to head for the current pass

            } while (swapped); // keep sorting until no swaps are made in a full pass

            cout << "Tickets sorted successfully based on the chosen criterion." << endl;
        }
        
        // Insertion Sort: Alot of it is fixed by gpt, my code had some logic flaws.
        void insertionSortTicketQueue(char ch) {
            if (head == NULL || head->next == head) return;

            // Separate sorted portion starting from `head` itself
            NodeQueue* sortedEnd = head;

            // Start sorting from the second node
            NodeQueue* current = head->next;

            while (current != head) {
                Ticket temp = current->ticket; // The ticket to be inserted into the sorted portion
                NodeQueue* sorted = head;
                NodeQueue* prevSorted = NULL; // Track the node before the insertion point
                bool inserted = false;

                // Traverse the sorted part and find the correct position for `temp`
                while (sorted != current) {
                    bool condition;
                    if (ch == 'p') {
                        condition = sorted->ticket.getPriority() > temp.getPriority();
                    } else if (ch == 'n') {
                        condition = sorted->ticket.getCustomerName() < temp.getCustomerName();
                    } else {
                        condition = sorted->ticket.getTicketOpenTime() < temp.getTicketOpenTime();
                    }

                    if (!condition) break; // Found the insertion point
                    prevSorted = sorted;
                    sorted = sorted->next;
                }

                if (sorted == current) {
                    // Current node is already in the correct position
                    sortedEnd = current;
                    current = current->next;
                } else {
                    // Remove `current` node from its position
                    sortedEnd->next = current->next;

                    // Insert `current` node at the found position
                    if (prevSorted == NULL) {
                        // Insert at the beginning (before head)
                        NodeQueue* tail = head;
                        while (tail->next != head) {
                            tail = tail->next;
                        }
                        tail->next = current;
                        current->next = head;
                        head = current;
                    } else {
                        // Insert between `prevSorted` and `sorted`
                        prevSorted->next = current;
                        current->next = sorted;
                    }
                    current = sortedEnd->next;
                }
            }

            cout << "Tickets sorted successfully using insertion sort based on the chosen criterion." << endl;
        }

        // Selection Sort
        void selectionSortTicketQueue(char ch) {
            if (head == NULL || head->next == head) return; // Empty or single-node list

            NodeQueue* current = head;

            do {
                NodeQueue* minNode = current;
                NodeQueue* iterator = current->next;

                // Find the node with the highest priority or earliest open time in the unsorted portion
                while (iterator != head) {
                    bool condition;
                    if (ch == 'p') {
                        condition = iterator->ticket.getPriority() > minNode->ticket.getPriority();
                    } else if (ch == 'n') {
                        condition = iterator->ticket.getCustomerName() < minNode->ticket.getCustomerName();
                    } else {
                        condition = iterator->ticket.getTicketOpenTime() < minNode->ticket.getTicketOpenTime();
                    }

                    if (condition) {
                        minNode = iterator;
                    }
                    iterator = iterator->next;
                }

                // Swap the tickets if a smaller (or higher priority) ticket is found
                if (minNode != current) {
                    Ticket temp = current->ticket;
                    current->ticket = minNode->ticket;
                    minNode->ticket = temp;
                }

                current = current->next;
            } while (current != head);

            cout << "Tickets sorted successfully using selection sort based on the chosen criterion." << endl;
        }

        void searchTicket () {            
            ifstream inputFromFile;
            inputFromFile.open("config.txt");

            if (!inputFromFile) {
                cout<< "Error opening the file." << endl;
                return;
            }

            string algoChoice;
            inputFromFile >> algoChoice;
            inputFromFile >> algoChoice;
            // getline(inputFromFile, algoChoice); // ignore the first line because it is for sorting algorithm
            // getline(inputFromFile, algoChoice); // fetch algo name from 2nd line

            if (algoChoice != "binarysearch" && algoChoice != "interpolationsearch") {
                cout << "Invalid searching algorithm in the config file." << endl;
                return;
            }

            int choice;
            cout << "How do you want to search for the ticket? " << endl;
            cout << "1. Search by ID\n2. Search by Customer Name" << endl;
            choice = get_int();
            if (choice != 1 && choice != 2) {
                cout<<"Invalid choice." << endl;
                return;
            }

            if (choice == 1) {
                int targetID;
                cout<<"Enter the ticket ID that you wanna search: ";
                targetID = get_int();
                // Sort the ticket queue by time before searching
                // bubbleSortTicketQueue('t');
                if (algoChoice == "binarysearch") binarySearchTicketByID(targetID);
                else interpolationSearchTicketByID(targetID);
                
            }
            else {
                string targetName;
                cin.ignore();
                cout<<"Enter the customer name that you wanna search: ";
                getline(cin, targetName);
                // Sort the ticket queue by name before searching
                bubbleSortTicketQueue('n');
                if (algoChoice == "binarysearch") binarySearchTicketByName(targetName);
                else linearSearchTicketByName(targetName);
                
            }
        }

        Ticket binarySearchTicketByID(int targetID) {
            if (!head) {
                cout << "The ticket queue is empty." << endl;
                Ticket invalidTicket;
                invalidTicket.setTicketID(-1);
                return invalidTicket;
            }

            // Initialize start and end pointers for binary search
            NodeQueue* start = head;
            NodeQueue* end = tail->next;

            do {
                // Find the middle of the current range (start to end)
                NodeQueue* slow = start;
                NodeQueue* fast = start;


                // using two pointer technique to find the middle node
                while (fast != end && fast->next != end) {
                    fast = fast->next->next;
                    slow = slow->next;
                }

                if (slow->ticket.getInstanceTicketID() == targetID) {
                    cout << "Match Found! Customer Details:\n";
                    slow->ticket.printTicketDetails();
                    return slow->ticket;
                }
                else if (slow->ticket.getInstanceTicketID() < targetID) {
                    start = slow->next;
                }
                else {
                    end = slow;
                }
            } while (start != end);

            cout << "Ticket ID " << targetID << " does not exist and is not found in the database." << endl;
            Ticket invalidTicket;
            invalidTicket.setTicketID(-1);
            return invalidTicket;
        }

        Ticket binarySearchTicketByName(string targetName) {
            if (!head) {
                cout << "The ticket queue is empty." << endl;
                Ticket invalidTicket;
                invalidTicket.setTicketID(-1);
                return invalidTicket;
            }

            // Initialize start and end pointers for binary search
            NodeQueue* start = head;
            NodeQueue* end = tail->next;

            do {
                // find the middle of the current range (start to end)
                NodeQueue* slow = start;
                NodeQueue* fast = start;


                // using two pointer technique to find the middle node
                while (fast != end && fast->next != end) {
                    fast = fast->next->next;
                    slow = slow->next;
                }

                if (slow->ticket.getCustomerName() == targetName) {
                    cout << "Match Found! Customer Details:\n";
                    slow->ticket.printTicketDetails();
                    return slow->ticket;
                }
                else if (slow->ticket.getCustomerName() < targetName) {
                    start = slow->next;
                }
                else {
                    end = slow;
                }
            } while (start != end);

            cout << "Custoemr '" << targetName << "' does not exist and is not found in the database." << endl;
            Ticket invalidTicket;
            invalidTicket.setTicketID(-1);
            return invalidTicket;
        }

        Ticket interpolationSearchTicketByID(int targetID) {
            if (!head) {
                cout << "The ticket queue is empty." << endl;
                Ticket invalidTicket;
                invalidTicket.setTicketID(-1);
                return invalidTicket;
            }

            NodeQueue* start = head;
            NodeQueue* end = tail->next; // end points to head due to circular nature

            do {
                int startID = start->ticket.getInstanceTicketID();
                int endID = (end == head ? tail->ticket.getInstanceTicketID() : end->ticket.getInstanceTicketID());

                if (startID == targetID) {
                    cout << "Match Found! Customer Details:\n";
                    start->ticket.printTicketDetails();
                    return start->ticket;
                }
                if (endID == targetID) {
                    cout << "Match Found! Customer Details:\n";
                    tail->ticket.printTicketDetails();
                    return tail->ticket;
                }

                if (startID == endID || targetID < startID || targetID > endID) {
                    break; // Target out of bounds
                }

                // Estimate position using interpolation formula
                int count = countNodesBetween(start, end);
                int pos = (targetID - startID) * count / (endID - startID);
                NodeQueue* mid = moveForward(start, pos);

                if (mid->ticket.getInstanceTicketID() == targetID) {
                    cout << "Match Found! Customer Details:\n";
                    mid->ticket.printTicketDetails();
                    return mid->ticket;
                }
                else if (mid->ticket.getInstanceTicketID() < targetID) {
                    start = mid->next;  // Move start forward, bypassing the interpolated node
                }
                else {
                    end = mid;  // Narrow search to start and mid
                }
            } while (start != end);

            cout << "Ticket ID " << targetID << " does not exist and is not found in the database." << endl;
            Ticket invalidTicket;
            invalidTicket.setTicketID(-1);
            return invalidTicket;
        }

        // Helper function to count nodes between start and end
        int countNodesBetween(NodeQueue* start, NodeQueue* end) {
            int count = 0;
            NodeQueue* temp = start;
            while (temp != end) {
                count++;
                temp = temp->next;
                if (temp == start) break; // loop detected in circular list
            }
            return count;
        }

        // Helper function to move forward by `pos` steps in a circular list
        NodeQueue* moveForward(NodeQueue* start, int pos) {
            NodeQueue* current = start;
            while (pos-- > 0 && current != nullptr) {
                current = current->next;
                if (current == start) break; // Avoid infinite loop in circular list
            }
            return current;
        }

        Ticket linearSearchTicketByName(string targetName) {
            if (!head) {
                cout << "The ticket queue is empty." << endl;
                Ticket invalidTicket;
                invalidTicket.setTicketID(-1);
                return invalidTicket;
            }

            NodeQueue* current = head;
            do {
                if (current->ticket.getCustomerName() == targetName) {
                    cout << "Match Found! Customer Details:\n";
                    current->ticket.printTicketDetails();
                    return current->ticket;
                }
                current = current->next;
            } while (current != head);

            cout << "Customer '" << targetName << "' does not exist and is not found in the database." << endl;
            Ticket invalidTicket;
            invalidTicket.setTicketID(-1);
            return invalidTicket;
        }
};
int TicketQueue::count = 0;
