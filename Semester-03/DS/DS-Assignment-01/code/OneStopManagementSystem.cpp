#include <iostream>
#include "Tickets.h"
#include "Agents.h"
#include "TicketResolutionLogs.h"
#include "ReportingAndAnalytics.h"

using namespace std;

int main() {
    int choice;
    bool again = true;

    AgentsList AL;
    TicketQueue TQ;
    TicketStack TS;
    TicketsList TL;

    while (again) {
        cout << "\n------------------ Muhammad Hammad || 23K-2005 -------------------";
        cout << "\n---------------------- One-Stop System Menu ----------------------\n";
        cout << "1. Add Ticket\n";
        cout << "2. Remove Ticket\n";
        cout << "3. Search for Ticket\n";
        cout << "4. Sort Tickets\n";
        cout << "5. Display Pending Tickets\n";
        cout << "6. Display All Tickets created today\n";
        cout << "7. Add Agent\n";
        cout << "8. Sort Agent by number of Tickets Assigned\n";
        cout << "9. Display all Agents\n";
        cout << "10. Assign Ticket to Agent\n";
        cout << "11. Resolve Ticket\n";
        cout << "12. Show Recent Ticket Log\n";
        cout << "13. Show All Ticket Logs\n";
        cout << "14. Exit\n";
        cout << "Choose an option: ";
        choice = get_int();

        switch (choice) {
            case 1: {
                // Create a ticket
                TQ.createTicket(TL);
                break;
            }
            case 2: {
                // Remove a ticket
                int ticketID;
                cout << "Enter Ticket ID to remove: ";
                ticketID = get_int();
                TQ.removeTicket(ticketID);
                break;
            }
            case 3: {
                // Search for a ticket
                TQ.searchTicket();
                break;
            }
            case 4: {
                // Sort the Tickets Queue
                TQ.sortTicketQueue();
                break;
            }
            case 5: {
                // Display pending tickets (ticket queue)
                TQ.printTicketQueue();
                break;
            }
            case 6: {
                // Display all tickets created today (tickets list)
                TL.displayTickets();
                break;
            }
            case 7: {
                AL.createAgent();
                break;
            }
            case 8: {
                // Sort Agents by Numer of Tickets Assigned
                AL.sortAgents();
                break;
            }
            case 9: {
                // Display Agents
                AL.displayAgents();
                break;
            }
            case 10: {
                // Assign a ticket to an agent
                AL.assignTicketToAgent(TQ);
                break;
            }
            case 11: {
                // Resolve a ticket
                AL.resolveTicket(TQ, TS);
                break;
            }
            case 12: {
                // Show recent ticket log (top of the stack)
                TS.peekTicketStack();
                break;
            }
            case 13: {
                // Show all ticket logs (entire stack)
                TS.printTicketStack();
                break;
            }
            
            case 14: {
                // Exit the program
                again = false;
                cout << "Exiting program. Ba-bye!\n";
                break;
            }
            default:
                cout << "Invalid option. Please try again.\n";
        }
    }

    return 0;
}