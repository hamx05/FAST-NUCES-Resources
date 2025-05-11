#include "ReportingAndAnalytics.h"
using namespace std;

void displaySystemStatistics(TicketsList& TL, TicketQueue& TQ, TicketStack& TS, AgentsList& AL) {
    cout << "\n---------------------- System Statistics ----------------------\n";
    cout << "Total Tickets Created: " << TL.numAllTickets << endl;
    cout << "Pending Tickets: " << TQ.numPendingTickets << endl;
    cout << "Resolved Tickets: " << TS.numProcessedTickets << endl;
    cout << "----------------------------------------------------------------\n";
}

void displayOpenTickets(TicketQueue& TQ) {
    cout << "\n---------------------- Open Tickets ----------------------\n";
    TQ.printTicketQueue();
    cout << "-----------------------------------------------------------\n";
}

void displayAgentTicketLoad(AgentsList& AL) {
    cout << "\n---------------------- Agent Ticket Load ----------------------\n";
    AL.displayAllAssignedTickets();
    cout << "--------------------------------------------------------------\n";
}

void displayTicketResolutionHistory(TicketStack& TS) {
    cout << "\n---------------------- Ticket Resolution History ----------------------\n";
    TS.printTicketStack();
    cout << "--------------------------------------------------------------------\n";
}