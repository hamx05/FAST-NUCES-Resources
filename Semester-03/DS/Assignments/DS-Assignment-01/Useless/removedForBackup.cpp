/*

void addAtSpecificPosition (int ticketID, string customerName, int priority, string requestDescription, string ticketOpenTime, string ticketCloseTime, bool status, int pos) {
            if (pos <= 0) {
                cerr << "Position can not be negative or zero." << endl;
                return;
            }
            if (pos == 1) {
                addAtHead(d);
                return;
            }

            Node *temp = head;
            int i = 1;

            while (temp != NULL && i<pos-1) {
                temp = temp->next;
                i++;
            }
            
            if (temp == NULL) {
                cerr << "Position out of bounds." << endl;
                return;
            }
            
            // we'll reach to 1 node behind the position
            if (temp == tail) { // if we are reached at tail
                addAtTail(d);
                return;
            }

            Node *newnode = new Node(customerName, priority, requestDescription, ticketOpenTime, ticketCloseTime, status);
            newnode->next = temp->next;
            temp->next = newnode;
        }

void addAtHead (Ticket& newTicket) {
            Node *newnode = new Node(newTicket);
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
-------------------------------------- 23/10/2024 ----------------------------------------------
// class AgentsList {
//     int size;
//     static int totalSize;
//     Agent* agents;
//     Ticket tickets[];

//     public:
//         AgentsList () : size(++totalSize) {
//             agents = new Agent[size];
//         }

//         AgentsList (Agent &newAgent) : size(++totalSize) {
//             agents = new Agent[size];
//             agents[size-1] = newAgent;
//         }

//         ~AgentsList() {
//             delete[] agents;
//         }

//         void addAgent (Agent &newAgent) {
//             // Agent temp[size];
//             Agent* temp = new Agent[size];

//             for (int i=0; i<size; i++) {
//                 temp[i] = agents[i];
//             }
//             delete[] agents;
            
//             agents = new Agent[size+1];
//             for (int i=0; i<size; i++) {
//                 agents[i] = temp[i];
//             }

//             agents[size] = newAgent;
//             size++;
//             delete[] temp;
//         }


//         void assignTicketToAgent(Ticket &ticket) {
//             int minTickets = 6; // Start higher than max allowed tickets
//             Agent *selectedAgent = nullptr;

//             // Find an available agent with the least number of tickets
//             for (int i=0; i<size; i++) {
//                 if (agents[i].isAvailable() && agents[i].getAssignedTicketCount() < minTickets) {
//                     minTickets = agents[i].getAssignedTicketCount();
//                     selectedAgent = &agents[i];
//                 }
//             }

//             if (selectedAgent != nullptr) {
//                 selectedAgent->assignTicket(ticket);
//                 cout << "Assigned Ticket " << ticket.getInstanceTicketID() << " to Agent " << selectedAgent->getAgentName() << endl;
//             } else {
//                 cout << "No available agents to assign the ticket!" << endl;
//             }
//         }

//         void printAgents() {
//             for (int i = 0; i < size; i++) {
//                 cout << "Agent ID: " << agents[i].getAgentID() << ", Name: " << agents[i].getAgentName()
//                      << ", Status: " << agents[i].getStatus() << ", Tickets Assigned: " << agents[i].getAssignedTicketCount() << endl;
//             }
//         }
// };
// int DA::totalSize = 0;




*/
